#include <unistd.h>

#include "Attack.h"
#include "Character.h"
#include "MagicalAttack.h"
#include "Movepool.h"
#include "Moves.h"
#include "PhysicalAttack.h"
#include "Protect.h"
#include "Status.h"
#include "SpecialAttack.h"

int main(void) {
  Character player1 = Character();
  player1.set_health(40);

  Status move1(player1.get_name(),player1.get_type(),player1.get_level(),player1.get_health(),player1.get_p_attack(),player1.get_m_attack(),player1.get_p_defence(),player1.get_m_defence(),player1.get_speed());
  cout << move1.get_health() << endl;

  Movepool player1Moves = Movepool(player1.get_name(), player1.get_type(), player1.get_level(),
      player1.get_health(), player1.get_p_attack(), 150,
      player1.get_p_defence(), player1.get_m_defence(), player1.get_speed());
  cout << player1Moves.move_set[3].get_health() << endl;
  cout << player1Moves.move_set[3].get_stat() << endl;
}