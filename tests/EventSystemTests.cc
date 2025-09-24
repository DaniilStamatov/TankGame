#include "engine/core/EventSystem.h"
#include <gtest/gtest.h>

namespace tests {

struct TestEvent {
    int value;
    std::string message;
};

struct AnotherEvent {
    float data;
};

class EventSystemTest : public ::testing::Test {
protected:
    void SetUp() override {
        nova::EventSystem::Instance() = nova::EventSystem();
    }
};

TEST_F(EventSystemTest, SubscribeAndNotify) {
    auto& eventSystem = nova::EventSystem::Instance();
    bool callbackCalled = false;
    TestEvent receivedEvent;
    
    eventSystem.Subscribe<TestEvent>([&](const TestEvent& event) {
        callbackCalled = true;
        receivedEvent = event;
    });
    
    TestEvent sentEvent{42, "Hello"};
    eventSystem.Notify(sentEvent);
    
    EXPECT_TRUE(callbackCalled);
    EXPECT_EQ(receivedEvent.value, 42);
    EXPECT_EQ(receivedEvent.message, "Hello");
}

TEST_F(EventSystemTest, MultipleSubscribers) {
    auto& eventSystem = nova::EventSystem::Instance();
    int callback1Count = 0;
    int callback2Count = 0;
    
    eventSystem.Subscribe<TestEvent>([&](const TestEvent&) { callback1Count++; });
    eventSystem.Subscribe<TestEvent>([&](const TestEvent&) { callback2Count++; });
    
    eventSystem.Notify(TestEvent{1, "test"});
    
    EXPECT_EQ(callback1Count, 1);
    EXPECT_EQ(callback2Count, 1);
}

TEST_F(EventSystemTest, DifferentEventTypes) {
    auto& eventSystem = nova::EventSystem::Instance();
    bool testEventCalled = false;
    bool anotherEventCalled = false;
    
    eventSystem.Subscribe<TestEvent>([&](const TestEvent&) { testEventCalled = true; });
    eventSystem.Subscribe<AnotherEvent>([&](const AnotherEvent&) { anotherEventCalled = true; });
    
    eventSystem.Notify(TestEvent{1, "test"});
    
    EXPECT_TRUE(testEventCalled);
    EXPECT_FALSE(anotherEventCalled);
}

} // namespace tests