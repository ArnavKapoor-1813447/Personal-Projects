#ifndef Attack_H
#define Attack_H
#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <ctime>
#include "Character.h"
#include "Moves.h"

class Attack : public Moves{
 protected:
  string attack_type;
  int power;
  string opponent_type;
  int opponent_health;
  float damage;

 public:
  virtual int damage_calc();
  string get_attack_type();
  int get_accuracy();
  int get_power();
  int get_opponent_health();
  virtual void set_opponent(string para_type, int para_health, int para_defence);
  void set_accuracy();
  void set_attack_type();
};

#endif