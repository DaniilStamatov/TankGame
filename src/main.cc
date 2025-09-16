#include "game/entities/Tank.h"
#include "engine/core/Application.h"
int main() {
     Application app(800, 600, "TankGame");
    app.Run();
    game::Tank testTank({100, 100, 0}, 100);
    testTank.move(1.0f, 1.0f);
    testTank.rotate(90.0f);
    testTank.shoot();
    return 0;
}