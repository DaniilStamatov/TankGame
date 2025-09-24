#pragma once
namespace tanks {

struct TankComponent {
  int hp = 100;
  float speed = 2.0f;
  float fireRate = 1.0f;
  float bulletSpeed = 5.0f;
  float damage = 10.0f;
};

} // namespace tanks
