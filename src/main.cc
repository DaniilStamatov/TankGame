#include "game/entities/Tank.h"
#include "engine/core/Application.h"
#include "game/Game.h"
int main() {
    tanks::Game game({100, 100, 0}, 100);
    Application app(800, 600, "TankGame", game);
    app.Run();
    return 0;
}