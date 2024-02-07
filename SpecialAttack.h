#ifndef SpecialAttack_H
#define SpecialAttack_H
#include <iostream>
#include <string>
#include <limits>
#include "MagicalAttack.h"
#include "PhysicalAttack.h"

class SpecialAttack: public Attack{
 protected:
  int opponent_p_defence;
  int opponent_m_defence;
 public:
  SpecialAttack();
  SpecialAttack(string para_name, string para_type, int para_level,
                int para_health, int para_p_attack, int para_m_attack,
                int para_p_defence, int para_m_defence, int para_speed);
  void play(bool protect);
  void set_opponent(string para_type, int health, int para_p_defence, int para_m_defence);
};
#endif