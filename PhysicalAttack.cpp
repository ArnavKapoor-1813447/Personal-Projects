#include "PhysicalAttack.h"

// Default constructor for physical attack move.
PhysicalAttack::PhysicalAttack(){
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
  attack_type = type;
  power = 50;
  move_name = "PhysicalAttack";
}

// constructor for physical attack move.
PhysicalAttack::PhysicalAttack(string para_name, string para_type, int para_level, int para_health, int para_p_attack, int para_m_attack, int para_p_defence, int para_m_defence, int para_speed){
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
  attack_type = type;
  power = 50;
  move_name = "PhysicalAttack";
}

// calculate damage variable using formula.
void PhysicalAttack::play(bool protect){
  int effective = 1;
  damage = (((2 * level * 1.0) / 5 + 2) * power * (p_attack * 1.0 / opponent_p_defence)) / 50 + 2;
  if (attack_type == type){
    damage = damage * 1.5;
  }
  if (attack_type == "Fire"){
    if (opponent_type == "Water"){
      effective = 0.5;
      damage = damage * 0.5;
    }
    if (opponent_type == "Grass"){
      effective = 2;
      damage = damage * 2;
    }
  }
  if (attack_type == "Water"){
    if (opponent_type == "Grass"){
      effective = 0.5;
      damage = damage * 0.5;
    }
    if (opponent_type == "Fire"){
      effective = 2;
      damage = damage * 2;
    }
  }
  if (attack_type == "Grass"){
    if (opponent_type == "Fire"){
      effective = 0.5;
      damage = damage * 0.5;
    }
    if (opponent_type == "Water"){
      effective = 2;
      damage = damage * 2;
    }
  }
  srand(time(NULL));
  damage = damage * ((rand() % 15 + 85) * 1.0 /100);
  if (protect == true) {
    damage = 0;
    protect = false;
    effective = 0;
  }
  opponent_health = round(opponent_health - damage);
  if (opponent_health < 0){
    opponent_health = 0;
  }
  if (effective == 0.5){
      cout << "Physical Attack wasn't very effective. " << endl;
    } else if (effective == 1){
      cout << "Physical Attack was effective. " << endl;
    } else if (effective == 2){
      cout << "Physical Attack was super effective! " << endl;
  } else if (effective == 0){
    cout << "Physical Attack blocked by protect!" << endl;
  }
}

// set opponent stats.
void PhysicalAttack::set_opponent(string para_type, int para_health, int para_p_defence){
  opponent_type = para_type;
  opponent_health = para_health;
  opponent_p_defence = para_p_defence;
}
