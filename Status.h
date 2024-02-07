#ifndef Status_H
#define Status_H
#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include "Moves.h"
#include "Character.h"

class Status: public Moves {
 protected:
  float modifier;
  string stat;

 public:
  Status();
  Status(string para_name, string para_type, int para_level, int para_health,
         int para_p_attack, int para_m_attack, int para_p_defence,
         int para_m_defence, int para_speed);
  int get_uses();
  string get_stat();
  int get_modifier();
  int get_accuracy();
  void set_accuracy();
  void set_uses();
  void set_stat();
  void play();
};
#endif