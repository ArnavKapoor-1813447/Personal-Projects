#ifndef Movepool_H
#define Movepool_H
#include <vector>
#include <memory>
#include <variant>
#include "Moves.h"
#include "Attack.h"
#include "PhysicalAttack.h"
#include "MagicalAttack.h"
#include "SpecialAttack.h"
#include "Protect.h"
#include "Status.h"

// Moves Vector
class Movepool: public PhysicalAttack, public MagicalAttack, public Status, public Protect, public SpecialAttack{ 
 public:
  std::vector<variant<PhysicalAttack, MagicalAttack, Status, Protect,SpecialAttack>> move_set;
  //  vector<std::shared_ptr<Moves> > move_set;
  Movepool(string para_name, string para_type, int para_level, int para_health,
           int para_p_attack, int para_m_attack, int para_p_defence,
           int para_m_defence, int para_speed);
  ~Movepool();
};
#endif