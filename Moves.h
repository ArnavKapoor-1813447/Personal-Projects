#ifndef Moves_H
#define Moves_H
#include "Character.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Moves: public Character {
 protected:
  int accuracy;
  int uses;
  string move_name;
 public:
  virtual void set_uses();
  virtual void play();
  virtual void set_accuracy();
};
#endif
