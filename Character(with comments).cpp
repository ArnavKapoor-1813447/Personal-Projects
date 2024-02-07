#include "Character.h"

//Default constructor with initialised default values
Character::Character() {
  name = "Character";
  type = "Fire";
  level = 50;
  health = 100;
  p_attack = 100;
  m_attack = 100;
  p_defence = 100;
  m_defence = 100;
  speed = 100;
}
//Constructor with initialised vallues
Character::Character(string para_name, string para_type, int para_level, int para_health, int para_p_attack, int para_m_attack, int para_p_defence, int para_m_defence, int para_speed) {
  name = para_name;
  type = para_type;
  level = para_level;
  health = para_health;
  p_attack = para_p_attack;
  m_attack = para_m_attack;
  p_defence = para_p_defence;
  m_defence = para_m_defence;
  speed = para_speed;
}
//Setter for Character Name
void Character::set_name() {
  cout << "New Name: ";
  string stringInput;
  cin >> stringInput;
  name = stringInput;
}
//Setter for Character Type
void Character::set_type() { 
  cout << "Select 1 For Fire" << endl;
  cout << "Select 2 For Grass" << endl;
  cout << "Select 3 For Water" << endl;
  int integerInput;
  //Getting and validating user input
  while ((cout << "Change Type (1-3): ") && (!(cin >> integerInput) || integerInput < 1 || integerInput > 3)){
      cout << "Invalid Input. Input must be between 1-3 inclusive." << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  if (integerInput == 1){
    type = "Fire";
    cout << "Sucessfully changed type to Fire." << endl;
  } else if (integerInput == 2) {
    type = "Grass";
    cout << "Sucessfully changed type to Grass." << endl;
  } else if (integerInput == 3) {
    type = "Water";
    cout << "Sucessfully changed type to Water." << endl;
  } else {
    cout << "Invalid Input. Input must be 1,2 or 3." << endl;
  }
}
//Setter for Character level
void Character::set_level(int para_level) {
  if (para_level >= 1 && para_level <= 100) {
    level = para_level;
    cout << "Sucessfully changed level to " << para_level << endl;
  } else {
    cout << "Invalid Value. Level must be between 1 and 100 inclusive." << endl;
  }
}
//Setter for Chracter health
void Character::set_health(int para_health) {
  if (para_health >= 1 && para_health <= 250) {
    health = para_health;
    cout << "Sucessfully changed health to " << para_health << endl;
  } else {
    cout << "Invalid Value. Health must be between 1 and 250 inclusive."
         << endl;
  }
}
//Setter for Physical Attack 
void Character::set_p_attack(int para_p_attack) {
  if (para_p_attack >= 1 && para_p_attack <= 250) {
    p_attack = para_p_attack;
    cout << "Sucessfully changed physical attack to " << para_p_attack << endl;
  } else {
    cout
        << "Invalid Value. Physical Attack must be between 1 and 250 inclusive."
        << endl;
  }
}
//Setter for Magical Attack
void Character::set_m_attack(int para_m_attack) {
  if (para_m_attack >= 1 && para_m_attack <= 250) {
    m_attack = para_m_attack;
    cout << "Sucessfully changed magical attack to " << para_m_attack << endl;
  } else {
    cout << "Invalid Value. Magical Attack must be between 1 and 250 inclusive."
         << endl;
  }
}
//Setter for Physical Defense
void Character::set_p_defence(int para_p_defence) {
  if (para_p_defence >= 1 && para_p_defence <= 250) {
    p_defence = para_p_defence;
    cout << "Sucessfully changed physical defence to " << para_p_defence << endl;
  } else {
    cout << "Invalid Value. Physical Defence must be between 1 and 250 "
            "inclusive."
         << endl;
  }
}
//Setter for Magical Defense
void Character::set_m_defence(int para_m_defence) {
  cout << "Sucessfully changed magical defence to " << para_m_defence << endl;
  if (para_m_defence >= 1 && para_m_defence <= 250) {
    m_defence = para_m_defence;
  } else {
    cout
        << "Invalid Value. Magical Defence must be between 1 and 250 inclusive."
        << endl;
  }
}
//Setter for Speed
void Character::set_speed(int para_speed) {
  if (para_speed >= 1 && para_speed <= 250) {
    speed = para_speed;
    cout << "Sucessfully changed speed to " << para_speed << endl;
  } else {
    cout << "Invalid Value. Speed must be between 1 and 250 inclusive." << endl;
  }
}
//Setter for all stats 
void Character::set_stats(int para_level, int para_health, int para_p_attack, int para_m_attack, int para_p_defence, int para_m_defence, int para_speed){
  health = (((2 * para_health * level) / 100) + level + 10);
  p_attack = (((2 * para_p_attack * level) / 100) + 5);
  m_attack = (((2 * para_m_attack * level) / 100) + 5);
  p_defence = (((2 * para_p_defence * level) / 100) + 5);
  m_defence = (((2 * para_m_defence * level) / 100) + 5);
  speed =(((2 * para_speed * level) / 100) + 5);
}
//Getters for all setters
string Character::get_name() { return name; }
string Character::get_type() { return type; }
int Character::get_level() { return level; }
int Character::get_health() { return health; }
int Character::get_p_attack() { return p_attack; }
int Character::get_m_attack() { return m_attack; }
int Character::get_p_defence() { return p_defence; }
int Character::get_m_defence() { return m_defence; }
int Character::get_speed() { return speed; }
