#ifndef Protect_H
#define Protect_H
#include <iostream>
#include <string>
#include <limits>
#include "Moves.h"

class Protect : public Moves {
 protected:
  int consecutive;
  bool protect;
 public:
  void set_uses();
  void set_consecutive();
  Protect();
  Protect(string para_name, string para_type, int para_level, int para_health,
          int para_p_attack, int para_m_attack, int para_p_defence,
          int para_m_defence, int para_speed);
  void play();
};

#endif