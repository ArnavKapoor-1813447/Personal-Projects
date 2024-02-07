#include "Protect.h"

// Default constructor for protect move.
Protect::Protect(){
  name = "Character";
  type = "Fire";
  level = 50;
  health = 100;
  p_attack = 100;
  m_attack = 100;
  p_defence = 100;
  m_defence = 100;
  speed = 100;
  accuracy = 100;
  uses = 15;
  consecutive = 0;
  protect = false;
  move_name = "Protect";
}

// constructor for protect move.
Protect::Protect(string para_name, string para_type, int para_level, int para_health, int para_p_attack, int para_m_attack, int para_p_defence, int para_m_defence, int para_speed) {
  name = para_name;
  type = para_type;
  level = para_level;
  health = para_health;
  p_attack = para_p_attack;
  m_attack = para_m_attack;
  p_defence = para_p_defence;
  m_defence = para_m_defence;
  speed = para_speed;
  accuracy = 100;
  uses = 15;
  consecutive = 0;
  protect = false;
  move_name = "Protect";
}

// set consecutive variable.
void Protect::set_consecutive() { consecutive = 0; }

// set uses variable.
void Protect::set_uses() {
  int integerInput;
  // ensuring user input is within bounds.
  while (
      (cout << "Change the number of times you can use this move (1-15): ") &&
      (!(cin >> integerInput) || integerInput < 1 || integerInput > 15)) {
    cout << "Invalid Input. Input must be between 1-15 inclusive." << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  uses = integerInput;
}

void Protect::play() {
  protect = false;
  if (uses == 0) {
    cout << "Your Protect Move ran out of uses!";
  } else {
    if ((rand() & 100) < (accuracy - (uses * 2) - (consecutive * 33))) {
      uses - 1;
      consecutive++;
      protect = true;
    } else {
      cout << "Protect Move Missed!" << endl;
    }
  }
}