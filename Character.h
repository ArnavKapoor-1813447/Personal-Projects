#ifndef Character_H
#define Character_H
#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Character {
 protected:
  string name;
  string type;
  int level;
  int health;
  int p_attack;
  int m_attack;
  int p_defence;
  int m_defence;
  int speed;

 public:
  Character();
  Character(string para_name, string Para_type, int para_level, int para_health, int para_p_attack, int para_m_attack,
            int para_p_defence, int para_m_defence, int para_speed);
  void set_name();
  void set_type();
  void set_level(int level);
  void set_health(int para_health);
  void set_p_attack(int para_p_attack);
  void set_m_attack(int para_m_attack);
  void set_p_defence(int para_p_defence);
  void set_m_defence(int para_m_defence);
  void set_speed(int para_speed);
  void set_stats(int para_level, int para_health, int para_p_attack, int para_m_attack,
                 int para_p_defence, int para_m_defence, int para_speed);
  string get_name();
  string get_type();
  int get_level();
  int get_health();
  int get_p_attack();
  int get_m_attack();
  int get_p_defence();
  int get_m_defence();
  int get_speed();
};
#endif
