#include "Movepool.h"

Movepool::Movepool(string para_name, string para_type, int para_level,
                   int para_health, int para_p_attack, int para_m_attack,
                   int para_p_defence, int para_m_defence, int para_speed) {
  PhysicalAttack move1(para_name, para_type, para_level, para_health, para_p_attack,para_m_attack, para_p_defence, para_m_defence, para_speed);
  MagicalAttack move2(para_name, para_type, para_level, para_health, para_p_attack,para_m_attack, para_p_defence, para_m_defence, para_speed);
  Protect move3(para_name, para_type, para_level, para_health, para_p_attack, para_m_attack, para_p_defence, para_m_defence, para_speed);
  Status move4(para_name, para_type, para_level, para_health, para_p_attack, para_m_attack, para_p_defence, para_m_defence, para_speed);
  SpecialAttack move5(para_name, para_type, para_level, para_health, para_p_attack, para_m_attack, para_p_defence, para_m_defence, para_speed);

  //move_set.push_back(shared_ptr<Moves>(new PhysicalAttack(
      //para_name, para_type, para_level, para_health, para_p_attack,
      //para_m_attack, para_p_defence, para_m_defence, para_speed()));
  //move_set.push_back(shared_ptr<Moves>(new MagicalAttack(
      //para_name, para_type, para_level, para_health, para_p_attack,
      //para_m_attack, para_p_defence, para_m_defence, para_speed)));
  //move_set.push_back(shared_ptr<Moves>(
      //new Protect(para_name, para_type, para_level, para_health, para_p_attack,
                  //para_m_attack, para_p_defence, para_m_defence, para_speed)));
  //move_set.push_back(shared_ptr<Moves>(
      //new Status(para_name, para_type, para_level, para_health, para_p_attack,
                 //para_m_attack, para_p_defence, para_m_defence, para_speed)));
  //move_set.push_back(shared_ptr<Moves>(new SpecialAttack(
      //para_name, para_type, para_level, para_health, para_p_attack,
      //para_m_attack, para_p_defence, para_m_defence, para_speed)));
  move_set.push_back(move1);
  move_set.push_back(std::get<MagicalAttack>(move2));
  move_set.push_back(std::get<Protect>(move3));
  move_set.push_back(std::get<Status>(move4));
  move_set.push_back(std::get<SpecialAttack>(move5));
}
Movepool::~Movepool() {move_set.clear();}