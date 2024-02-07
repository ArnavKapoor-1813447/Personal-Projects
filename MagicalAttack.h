#ifndef MagicalAttack_H
#define MagicalAttack_H
#include <iostream>
#include <string>
#include <limits>
#include "Attack.h"

class MagicalAttack: public Attack {
 protected:
  int opponent_m_defence;
 public:
  MagicalAttack();
  MagicalAttack(string para_name, string para_type, int para_level,
                int para_health, int para_p_attack, int para_m_attack,
                int para_p_defence, int para_m_defence, int para_speed);
  void play(bool protect);
  void set_opponent(string para_type, int para_health, int para_m_defence);
};
#endif