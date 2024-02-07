#ifndef PhysicalAttack_H
#define PhysicalAttack_H
#include <iostream>
#include <string>
#include <limits>
#include "Attack.h"

class PhysicalAttack: public Attack {
 protected:
  int opponent_p_defence;
 public:
  PhysicalAttack();
  PhysicalAttack(string para_name, string para_type, int para_level,
                 int para_health, int para_p_attack, int para_m_attack,
                 int para_p_defence, int para_m_defence, int para_speed);
  void play(bool protect);
  void set_opponent(string para_type, int para_health, int para_p_defence);
};
#endif