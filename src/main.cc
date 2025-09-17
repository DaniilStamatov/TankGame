#include "game/entities/Tank.h"
#include "engine/core/Application.h"
#include "game/Game.h"
int main() {
    game::Game game({1, 0, 0}, 100);
    Application app(800, 600, "TankGame", game);
    app.Run();
    return 0;
}