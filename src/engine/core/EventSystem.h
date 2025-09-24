#pragma once

#include <typeindex>
#include <unordered_map>
#include <functional>
#include <vector>

namespace nova {

class EventSystem {
public:
    static EventSystem& Instance() {
        static EventSystem system;
        return system;
    }
    template<typename EventType>
    void Subscribe(std::function<void(const EventType&)> callback) {
        auto typeIndex = std::type_index(typeid(EventType));
        m_subscribers[typeIndex].push_back([callback](const void* event) {
            callback(*static_cast<const EventType*>(event)); 
        });
    }

    template<typename EventType>
    void Notify(const EventType& event) {
        auto typeIndex = std::type_index(typeid(EventType));
        auto it = m_subscribers.find(typeIndex);
        if(it != m_subscribers.end()) {
            for (auto& callback : it->second) {
                callback(&event);
            }
        }
    }

private:
    using EventCallback = std::function<void(const void*)>;
    std::unordered_map<std::type_index, std::vector<EventCallback>> m_subscribers;
};

}