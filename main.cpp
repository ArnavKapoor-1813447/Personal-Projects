#include <unistd.h>
#include "Attack.h"
#include "Character.h"
#include "MagicalAttack.h"
#include "Movepool.h"
#include "Moves.h"
#include "PhysicalAttack.h"
#include "Protect.h"
#include "SpecialAttack.h"
#include "Status.h"

int main(void) {
  Character player1 = Character();
  Character player2 = Character();
  cout << "Welcome to 1 v 1 Battle Simulation! The Battle Simulation has "
          "two players customise two characters to fight."
       << endl;
  sleep(2);
  cout << "First, each player may give their character a name." << endl;
  sleep(2);
  cout << "Next, each player will determine their character type; Fire, Water "
          "or Grass."
       << endl;
  sleep(2);
  cout << "Fire attacks do more damage to Grass characters." << endl;
  cout << "Grass attacks do more damage to Water characters." << endl;
  cout << "Water attacks do more damage to Fire characters." << endl;
  sleep(2);
  cout << "Lastly, each player will allocate 600 points to 6 individual stats."
       << endl;
  sleep(2);
  cout << "Each Stat can be allocated a value between 1 to 250." << endl;
  sleep(2);
  cout << "Stat 1-Health: Health determines your character's healthpoint stat"
       << endl;
  sleep(2);
  cout << "Stat 2-Physical Attack: This attack determines how much physical "
          "attack damage your character will inflect on your opponent."
       << endl;
  sleep(2);
  cout << "Stat 3-Physical Defence: This defence determines how well you "
          "resist physical attack."
       << endl;
  sleep(2);
  cout << "Stat 4-Magical Attack: This attack determines how much magical "
          "attack damage your character will inflect on your opponent."
       << endl;
  sleep(2);
  cout << "Stat 5-Magical Defence: This defence determines how well you "
          "resist magical attack."
       << endl;
  cout << "Stat 6-Speed: Speed determines which character goes first" << endl;
  sleep(2);
  cout << "Each player will begin with a default character with pre-set values."
       << endl;

  cout << "--------------------------------------------------------" << endl;
  int menuInput;
  int valueInput;
  int stat_total;

  cout << "Current Player 1 Character Information" << endl;
  cout << "(1)-Name: " << player1.get_name() << endl;
  cout << "(2)-Type: " << player1.get_type() << endl;
  cout << "(3)-Level: " << player1.get_level() << endl;
  cout << "(4)-Health: " << player1.get_health() << endl;
  cout << "(5)-Physical Attack: " << player1.get_p_attack() << endl;
  cout << "(6)-Magical Attack: " << player1.get_m_attack() << endl;
  cout << "(7)-Physical Defence: " << player1.get_p_defence() << endl;
  cout << "(8)-Magical Defence: " << player1.get_m_defence() << endl;
  cout << "(9)-Speed: " << player1.get_speed() << endl;
  cout << "Press 0 when you are ready. Press 1-9 to change the corresponding "
          "value or stat. Press 10 to see updated character information. "
       << endl;

  bool ready = false;
  while (ready == false) {
    cout << "--------------------------------------------------------" << endl;
    stat_total = player1.get_health() + player1.get_p_attack() +
                 player1.get_m_attack() + player1.get_p_defence() +
                 player1.get_m_defence() + player1.get_speed();
    cout << "Current Stat Total (Aim for 600): " << stat_total << endl;
    while ((cout << "Finished (0), Change Stats(1-9), View Stats(10): ") &&
           (!(cin >> menuInput) || menuInput < 0 || menuInput > 10)) {
      cout << "Invalid Input. Input must be between 0-10 inclusive." << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (menuInput == 0) {
      if (stat_total != 600) {
        cout << "Your stat total doesn't equal 600. Please change your stats "
                "to equal 600"
             << endl;
        cout << "--------------------------------------------------------"
             << endl;
        cout << "Current Stats" << endl;
        cout << "Health: " << player1.get_health() << endl;
        cout << "Physical Attack: " << player1.get_p_attack() << endl;
        cout << "Magical Attack: " << player1.get_m_attack() << endl;
        cout << "Physical Defence: " << player1.get_p_defence() << endl;
        cout << "Magical Defence: " << player1.get_m_defence() << endl;
        cout << "Speed: " << player1.get_speed() << endl;
      }
      if (stat_total == 600) {
        cout << "--------------------------------------------------------"
             << endl;
        cout << "Current Player 1 Character Information" << endl;
        cout << "(1)-Name: " << player1.get_name() << endl;
        cout << "(2)-Type: " << player1.get_type() << endl;
        cout << "(3)-Level: " << player1.get_level() << endl;
        cout << "(4)-Health: " << player1.get_health() << endl;
        cout << "(5)-Physical Attack: " << player1.get_p_attack() << endl;
        cout << "(6)-Magical Attack: " << player1.get_m_attack() << endl;
        cout << "(7)-Physical Defence: " << player1.get_p_defence() << endl;
        cout << "(8)-Magical Defence: " << player1.get_m_defence() << endl;
        cout << "(9)-Speed: " << player1.get_speed() << endl;
        cout << "--------------------------------------------------------"
             << endl;
        while ((cout << "Confirm Your Character. Press 1 to Confirm. Press 0 "
                        "if you want to continuing editing: ") &&
               (!(cin >> valueInput) || valueInput < 0 || valueInput > 1)) {
          cout << "Invalid Input. Input must be between 0-1 inclusive." << endl;
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (valueInput == 1) {
          ready = true;
          player1.set_stats();
          break;
        }
      }
    } else if (menuInput == 1) {
      player1.set_name();
    } else if (menuInput == 2) {
      player1.set_type();
    } else if (menuInput == 3) {
      while ((cout << "New Level (1-100): ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 100)) {
        cout << "Invalid Input. Input must be between 1-100 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      player1.set_level(valueInput);
    } else if (menuInput == 4) {
      while ((cout << "New Health Stat (1-250): ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 250)) {
        cout << "Invalid Input. Input must be between 1-250 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      player1.set_health(valueInput);
    } else if (menuInput == 5) {
      while ((cout << "New Physical Attack Stat (1-250): ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 250)) {
        cout << "Invalid Input. Input must be between 1-250 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      player1.set_p_attack(valueInput);
    } else if (menuInput == 6) {
      while ((cout << "New Magical Attack Stat (1-250): ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 250)) {
        cout << "Invalid Input. Input must be between 1-250 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      player1.set_m_attack(valueInput);
    } else if (menuInput == 7) {
      while ((cout << "New Physical Defence Stat (1-250): ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 250)) {
        cout << "Invalid Input. Input must be between 1-250 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      player1.set_p_defence(valueInput);
    } else if (menuInput == 8) {
      while ((cout << "New Magical Defence Stat (1-250): ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 250)) {
        cout << "Invalid Input. Input must be between 1-250 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      player1.set_m_defence(valueInput);
    } else if (menuInput == 9) {
      while ((cout << "New Speed Stat (1-250): ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 250)) {
        cout << "Invalid Input. Input must be between 1-250 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      player1.set_speed(valueInput);
    } else if (menuInput == 10) {
      cout << "--------------------------------------------------------"
           << endl;
      cout << "Current Player 1 Character Stats" << endl;
      cout << "(1)Name: " << player1.get_name() << endl;
      cout << "(2)Type: " << player1.get_type() << endl;
      cout << "(3)Level: " << player1.get_level() << endl;
      cout << "(4)Health: " << player1.get_health() << endl;
      cout << "(5)Physical Attack: " << player1.get_p_attack() << endl;
      cout << "(6)Magical Attack: " << player1.get_m_attack() << endl;
      cout << "(7)Physical Defence: " << player1.get_p_defence() << endl;
      cout << "(8)Magical Defence: " << player1.get_m_defence() << endl;
      cout << "(9)Speed: " << player1.get_speed() << endl;
      cout << "--------------------------------------------------------"
           << endl;
    } else {
      cout << "Invalid Input. Input must be between 0-10 inclusive." << endl;
    }
  }
  cout << "Current Player 2 Character Information" << endl;
  cout << "(1)-Name: " << player2.get_name() << endl;
  cout << "(2)-Type: " << player2.get_type() << endl;
  cout << "(3)-Level: " << player2.get_level() << endl;
  cout << "(4)-Health: " << player2.get_health() << endl;
  cout << "(5)-Physical Attack: " << player2.get_p_attack() << endl;
  cout << "(6)-Magical Attack: " << player2.get_m_attack() << endl;
  cout << "(7)-Physical Defence: " << player2.get_p_defence() << endl;
  cout << "(8)-Magical Defence: " << player2.get_m_defence() << endl;
  cout << "(9)-Speed: " << player2.get_speed() << endl;
  cout << "Press 0 when you are ready. Press 1-9 to change the corresponding "
          "value or stat. Press 10 to see updated character information. "
       << endl;

  ready = false;
  while (ready == false) {
    cout << "--------------------------------------------------------" << endl;
    stat_total = player2.get_health() + player2.get_p_attack() +
                 player2.get_m_attack() + player2.get_p_defence() +
                 player2.get_m_defence() + player2.get_speed();
    cout << "Current Stat Total (Aim for 600): " << stat_total << endl;
    while ((cout << "Finished (0), Change Stats(1-9), View Stats(10): ") &&
           (!(cin >> menuInput) || menuInput < 0 || menuInput > 10)) {
      cout << "Invalid Input. Input must be between 0-10 inclusive." << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (menuInput == 0) {
      if (stat_total != 600) {
        cout << "Your stat total doesn't equal 600. Please change your stats "
                "to equal 600"
             << endl;
        cout << "--------------------------------------------------------"
             << endl;
        cout << "Current Stats" << endl;
        cout << "Health: " << player2.get_health() << endl;
        cout << "Physical Attack: " << player2.get_p_attack() << endl;
        cout << "Magical Attack: " << player2.get_m_attack() << endl;
        cout << "Physical Defence: " << player2.get_p_defence() << endl;
        cout << "Magical Defence: " << player2.get_m_defence() << endl;
        cout << "Speed: " << player2.get_speed() << endl;
      }
      if (stat_total == 600) {
        cout << "--------------------------------------------------------"
             << endl;
        cout << "Current Player 2 Character Information" << endl;
        cout << "(1)Name: " << player2.get_name() << endl;
        cout << "(2)Type: " << player2.get_type() << endl;
        cout << "(3)Level: " << player2.get_level() << endl;
        cout << "(4)Health: " << player2.get_health() << endl;
        cout << "(5)Physical Attack: " << player2.get_p_attack() << endl;
        cout << "(6)Magical Attack: " << player2.get_m_attack() << endl;
        cout << "(7)Physical Defence: " << player2.get_p_defence() << endl;
        cout << "(8)Magical Defence: " << player2.get_m_defence() << endl;
        cout << "(9)Speed: " << player2.get_speed() << endl;
        cout << "--------------------------------------------------------"
             << endl;
        while ((cout << "Confirm Your Character. Press 1 to Confirm. Press 0 "
                        "if you want to continuing editing: ") &&
               (!(cin >> valueInput) || valueInput < 0 || valueInput > 1)) {
          cout << "Invalid Input. Input must be between 0-1 inclusive." << endl;
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (valueInput == 1) {
          ready = true;
          player2.set_stats();
          break;
        }
      }
    } else if (menuInput == 1) {
      player2.set_name();
    } else if (menuInput == 2) {
      player2.set_type();
    } else if (menuInput == 3) {
      while ((cout << "New Level (1-100): ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 100)) {
        cout << "Invalid Input. Input must be between 1-100 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      player2.set_level(valueInput);
    } else if (menuInput == 4) {
      while ((cout << "New Health Stat (1-250): ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 250)) {
        cout << "Invalid Input. Input must be between 1-250 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      player2.set_health(valueInput);
    } else if (menuInput == 5) {
      while ((cout << "New Physical Attack Stat (1-250): ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 250)) {
        cout << "Invalid Input. Input must be between 1-250 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      player2.set_p_attack(valueInput);
    } else if (menuInput == 6) {
      while ((cout << "New Magical Attack Stat (1-250): ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 250)) {
        cout << "Invalid Input. Input must be between 1-250 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      player2.set_m_attack(valueInput);
    } else if (menuInput == 7) {
      while ((cout << "New Physical Defence Stat (1-250): ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 250)) {
        cout << "Invalid Input. Input must be between 1-250 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      player2.set_p_defence(valueInput);
    } else if (menuInput == 8) {
      while ((cout << "New Magical Defence Stat (1-250): ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 250)) {
        cout << "Invalid Input. Input must be between 1-250 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      player2.set_m_defence(valueInput);
    } else if (menuInput == 9) {
      while ((cout << "New Speed Stat (1-250): ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 250)) {
        cout << "Invalid Input. Input must be between 1-250 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      player2.set_speed(valueInput);
    } else if (menuInput == 10) {
      cout << "--------------------------------------------------------"
           << endl;
      cout << "Current Player 1 Character Stats" << endl;
      cout << "(1)Name: " << player2.get_name() << endl;
      cout << "(2)Type: " << player2.get_type() << endl;
      cout << "(3)Level: " << player2.get_level() << endl;
      cout << "(4)Health: " << player2.get_health() << endl;
      cout << "(5)Physical Attack: " << player2.get_p_attack() << endl;
      cout << "(6)Magical Attack: " << player2.get_m_attack() << endl;
      cout << "(7)Physical Defence: " << player2.get_p_defence() << endl;
      cout << "(8)Magical Defence: " << player2.get_m_defence() << endl;
      cout << "(9)Speed: " << player2.get_speed() << endl;
      cout << "--------------------------------------------------------"
           << endl;
    } else {
      cout << "Invalid Input. Input must be between 0-10 inclusive." << endl;
    }
  }
  Movepool player1Moves = Movepool(
      player1.get_name(), player1.get_type(), player1.get_level(),
      player1.get_health(), player1.get_p_attack(), player1.get_m_attack(),
      player1.get_p_defence(), player1.get_m_defence(), player1.get_speed());
  Movepool player2Moves = Movepool(
      player1.get_name(), player1.get_type(), player1.get_level(),
      player1.get_health(), player1.get_p_attack(), player1.get_m_attack(),
      player1.get_p_defence(), player1.get_m_defence(), player1.get_speed());

  cout << "--------------------------------------------------------" << endl;
  cout << "Each player gets 5 moves. 3 Moves can be customised." << endl;
  sleep(2);
  cout << "Move 1 - Physical Attack: Inflicts damage on your "
          "opponent using your Physical Attack Stat."
       << endl;
  sleep(2);
  cout << "Move 2 - Magical Attack: Inflicts damage on your "
          "opponent using your Magical Attack Stat."
       << endl;
  sleep(2);
  cout << "Move 3 - Protect: Protects you from your opponents attacking move."
       << endl;
  sleep(2);
  cout << "Move 4 - Status: Boost a stat of your choosing." << endl;
  sleep(2);
  cout << "Move 5 - Special Attack: A one time high attack move which cannot "
          "be customised."
       << endl;
  sleep(2);
  cout << "--------------------------------------------------------" << endl;
  cout << "Physical and Magical Attack have the following modifiable values; "
          "Power and Type."
       << endl;
  sleep(2);
  cout << "Power can be increased to increase damage output." << endl;
  cout << "However, any power increase will decrease accuracy, giving the move "
          "a probability of missing."
       << endl;
  sleep(2);
  cout << "---" << endl;
  cout << "Similar to your character type, a move can be of type Fire, Water "
          "or Grass."
       << endl;
  cout << "Your attack damage increases if the move type and character type "
          "matches."
       << endl;
  cout << "Your attack damage also increase if your move type is "
          "super-effective against your opponent character type."
       << endl;
  sleep(2);
  cout << "--------------------------------------------------------" << endl;
  cout << "Status move have the following modifiable values; Accuracy and "
          "Stat Type."
       << endl;
  sleep(2);
  cout << "The Stat_type determines which stat is boosted by the move. Every "
          "stat, execept health can be boosted."
       << endl;
  cout << "---" << endl;
  cout << "A decrease in Status move accuracy increases how big the stat boost "
          "is."
       << endl;
  cout << "--------------------------------------------------------" << endl;
  sleep(2);
  cout << "Current Player 1 Modifiable Move Information" << endl;

  cout << "---" << endl;
  cout << "(1)-PhysicalAttack: " << endl;
  cout << "Power: " <<          // player1.move_set[0].get_power() << endl;
      cout << "Accuracy: " <<   // player1.move_set[0].get_accuracy() << endl;
      cout << "Move Type: " <<  // player1.move_set[0].get_attack_type()<< endl;

      cout << "---" << endl;
  cout << "(2)-MagicalAttack: " << endl;
  cout << "Power: " <<          // player1.move_set[1].get_power() << endl;
      cout << "Accuracy: " <<   // player1.move_set[1].get_accuracy() << endl;
      cout << "Move Type: " <<  // player1.move_set[1].get_attack_type()<< endl;

      cout << "---" << endl;
  cout << "(3)-Status: " << endl;
  cout << "Stat: " <<          // player1.move_set[3].get_stat() << endl;
      cout << "Accuracy: " <<  // player1.move_set[3].get_accuracy() << endl;

      cout << "---" << endl;
  cout << "Press 0 when you are ready. Press 1-3 to change the corresponding "
          "move. Press 4 to see updated character information. "
       << endl;
  ready = false;
  while (ready == false) {
    cout << "--------------------------------------------------------" << endl;
    while ((cout << "Finished (0), Change Moves(1-3), View Moves(4): ") &&
           (!(cin >> menuInput) || menuInput < 0 || menuInput > 4)) {
      cout << "Invalid Input. Input must be between 0-4 inclusive." << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (menuInput == 0) {
      cout << "Current Player 1 Modifiable Move Information" << endl;
      cout << "---" << endl;
      cout << "(1)-PhysicalAttack: " << endl;
      cout << "Power: " <<  // player1.move_set[0].get_power() << endl;
          cout
           << "Accuracy: " <<  // player1.move_set[0].get_accuracy() << endl;
          cout
           << "Move Type: " <<  // player1.move_set[0].get_attack_type()<< endl;

          cout << "---" << endl;
      cout << "(2)-MagicalAttack: " << endl;
      cout << "Power: " <<  // player1.move_set[1].get_power() << endl;
          cout
           << "Accuracy: " <<  // player1.move_set[1].get_accuracy() << endl;
          cout
           << "Move Type: " <<  // player1.move_set[1].get_attack_type()<< endl;

          cout << "---" << endl;
      cout << "(3)-Status: " << endl;
      cout << "Stat: " <<  // player1.move_set[3].get_stat() << endl;
          cout
           << "Accuracy: " <<  // player1.move_set[3].get_accuracy() << endl;

          cout << "--------------------------------------------------------"
           << endl;
      while ((cout << "Confirm Your Moves. Press 1 to Confirm. Press 0 "
                      "if you want to continuing editing: ") &&
             (!(cin >> valueInput) || valueInput < 0 || valueInput > 1)) {
        cout << "Invalid Input. Input must be between 0-1 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      if (valueInput == 1) {
        ready = true;
        break;
      }
    } else if (menuInput == 1) {
      cout << "--------------------------------------------------------"
           << endl;
      while ((cout << "Type 1 to change Physical Power & Accuracy. Type 2 for "
                      "change Move Type: ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 2)) {
        cout << "Invalid Input. Input must be between 1-2 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      if (valueInput == 1) {
        // player1.move_set.Move_Set[0].set_accuracy();
      }
      if (valueInput == 2) {
        // player1.move_set.Move_Set[0].set_attack_type();
      }
    } else if (menuInput == 2) {
      cout << "--------------------------------------------------------"
           << endl;
      while ((cout << "Type 1 to change Magical Power & Accuracy. Type 2 for "
                      "change Move Type: ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 2)) {
        cout << "Invalid Input. Input must be between 1-2 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      if (valueInput == 1) {
        // player1.move_set[1].set_accuracy();
      }
      if (valueInput == 2) {
        // player1.move_set[1].set_attack_type();
      }
    } else if (menuInput == 3) {
      cout << "--------------------------------------------------------"
           << endl;
      while ((cout << "Type 1 to change the boosted Stat. Type 2 for change "
                      "Accuracy: ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 2)) {
        cout << "Invalid Input. Input must be between 1-2 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      if (valueInput == 1) {
        // player1.move_set[3].set_stat();
      }
      if (valueInput == 2) {
        // player1.move_set[3].set_accuracy();
      }
    } else if (menuInput == 4) {
      cout << "Current Player 1 Modifiable Move Information" << endl;
      cout << "---" << endl;
      cout << "(1)-PhysicalAttack: " << endl;
      cout << "Power: " <<  // player1.move_set[0].get_power() << endl;
          cout
           << "Accuracy: " <<  // player1.move_set[0].get_accuracy() << endl;
          cout
           << "Move Type: " <<  // player1.move_set[0].get_attack_type()<< endl;

          cout << "---" << endl;
      cout << "(2)-MagicalAttack: " << endl;
      cout << "Power: " <<  // player1.move_set[1].get_power() << endl;
          cout
           << "Accuracy: " <<  // player1.move_set[1].get_accuracy() << endl;
          cout
           << "Move Type: " <<  // player1.move_set[1].get_attack_type()<< endl;

          cout << "---" << endl;
      cout << "(3)-Status: " << endl;
      cout << "Stat: " <<  // player1.move_set[3].get_stat() << endl;
          cout
           << "Accuracy: " <<  // player1.move_set[3].get_accuracy() << endl;
    }
  }

  cout << "Current Player 2 Modifiable Move Information" << endl;

  cout << "---" << endl;
  cout << "(1)-PhysicalAttack: " << endl;
  cout << "Power: " <<          // player2.move_set[0].get_power() << endl;
      cout << "Accuracy: " <<   // player2.move_set[0].get_accuracy() << endl;
      cout << "Move Type: " <<  // player2.move_set[0].get_attack_type()<< endl;

      cout << "---" << endl;
  cout << "(2)-MagicalAttack: " << endl;
  cout << "Power: " <<          // player2.move_set[1].get_power() << endl;
      cout << "Accuracy: " <<   // player2.move_set[1].get_accuracy() << endl;
      cout << "Move Type: " <<  // playe21.move_set[1].get_attack_type()<< endl;

      cout << "---" << endl;
  cout << "(3)-Status: " << endl;
  cout << "Stat: " <<          // player2.move_set[3].get_stat() << endl;
      cout << "Accuracy: " <<  // player2.move_set[3].get_accuracy() << endl;

      cout << "---" << endl;
  cout << "Press 0 when you are ready. Press 1-3 to change the corresponding "
          "move. Press 4 to see updated character information. "
       << endl;
  ready = false;
  while (ready == false) {
    cout << "--------------------------------------------------------" << endl;
    while ((cout << "Finished (0), Change Moves(1-3), View Moves(4): ") &&
           (!(cin >> menuInput) || menuInput < 0 || menuInput > 4)) {
      cout << "Invalid Input. Input must be between 0-4 inclusive." << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (menuInput == 0) {
      cout << "Current Player 1 Modifiable Move Information" << endl;
      cout << "---" << endl;
      cout << "(1)-PhysicalAttack: " << endl;
      cout << "Power: " <<  // player2.move_set[0].get_power() << endl;
          cout
           << "Accuracy: " <<  // player2.move_set[0].get_accuracy() << endl;
          cout
           << "Move Type: " <<  // player2.move_set[0].get_attack_type()<< endl;

          cout << "---" << endl;
      cout << "(2)-MagicalAttack: " << endl;
      cout << "Power: " <<  // player2.move_set[1].get_power() << endl;
          cout
           << "Accuracy: " <<  // player2.move_set[1].get_accuracy() << endl;
          cout
           << "Move Type: " <<  // player2.move_set[1].get_attack_type()<< endl;

          cout << "---" << endl;
      cout << "(3)-Status: " << endl;
      cout << "Stat: " <<  // player2.move_set[3].get_stat() << endl;
          cout
           << "Accuracy: " <<  // player2.move_set[3].get_accuracy() << endl;

          cout << "--------------------------------------------------------"
           << endl;
      while ((cout << "Confirm Your Moves. Press 1 to Confirm. Press 0 "
                      "if you want to continuing editing: ") &&
             (!(cin >> valueInput) || valueInput < 0 || valueInput > 1)) {
        cout << "Invalid Input. Input must be between 0-1 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      if (valueInput == 1) {
        ready = true;
        break;
      }
    } else if (menuInput == 1) {
      cout << "--------------------------------------------------------"
           << endl;
      while ((cout << "Type 1 to change Physical Power & Accuracy. Type 2 for "
                      "change Move Type: ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 2)) {
        cout << "Invalid Input. Input must be between 1-2 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      if (valueInput == 1) {
        // player2.move_set.Move_Set[0].set_accuracy();
      }
      if (valueInput == 2) {
        // player2.move_set.Move_Set[0].set_attack_type();
      }
    } else if (menuInput == 2) {
      cout << "--------------------------------------------------------"
           << endl;
      while ((cout << "Type 1 to change Magical Power & Accuracy. Type 2 for "
                      "change Move Type: ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 2)) {
        cout << "Invalid Input. Input must be between 1-2 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      if (valueInput == 1) {
        // player2.move_set[1].set_accuracy();
      }
      if (valueInput == 2) {
        // player2.move_set[1].set_attack_type();
      }
    } else if (menuInput == 3) {
      cout << "--------------------------------------------------------"
           << endl;
      while ((cout << "Type 1 to change the boosted Stat. Type 2 for change "
                      "Accuracy: ") &&
             (!(cin >> valueInput) || valueInput < 1 || valueInput > 2)) {
        cout << "Invalid Input. Input must be between 1-2 inclusive." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      if (valueInput == 1) {
        // player2.move_set[3].set_stat();
      }
      if (valueInput == 2) {
        // player2.move_set[3].set_accuracy();
      }
    } else if (menuInput == 4) {
      cout << "Current Player 1 Modifiable Move Information" << endl;
      cout << "---" << endl;
      cout << "(1)-PhysicalAttack: " << endl;
      cout << "Power: " <<  // player2.move_set[0].get_power() << endl;
          cout
           << "Accuracy: " <<  // player2.move_set[0].get_accuracy() << endl;
          cout
           << "Move Type: " <<  // player2.move_set[0].get_attack_type()<< endl;

          cout << "---" << endl;
      cout << "(2)-MagicalAttack: " << endl;
      cout << "Power: " <<  // player2.move_set[1].get_power() << endl;
          cout
           << "Accuracy: " <<  // player2.move_set[1].get_accuracy() << endl;
          cout
           << "Move Type: " <<  // player2.move_set[1].get_attack_type()<< endl;

          cout << "---" << endl;
      cout << "(3)-Status: " << endl;
      cout << "Stat: " <<  // player2.move_set[3].get_stat() << endl;
          cout
           << "Accuracy: " <<  // player2.move_set[3].get_accuracy() << endl;
    }
  }
  cout << "--------------------------------------------------------" << endl;
  cout << "Let the Fight Begin!" << endl;
  int index1;
  int index2;
  if (player1.get_speed() >= player2.get_speed()) {
    cout << "Player 1 Goes First!" << endl;
  } else {
    cout << "Player 2 Goes First!" << endl;
  }

  while (player1.get_health() > 0 && player2.get_health() > 0) {
    if (player1.get_speed() >= player2.get_speed()) {
      index1 = player1.play_move();
      index2 = player2.play_move();
      if (index1 == 3 && index2 == 3) {
        cout << "Both players uses Protect. Move Fail" << endl;
      }
      if ((index2 == 1 || index2 == 2 || index2 == 4 || index2 == 5) &&
          index1 == 3) {
        if (index2 == 1) {
          // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
        } else if (index2 == 2) {
          // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
        } else if (index2 == 5) {
          // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence(),
          // player1.get_m_defence);
        }

        // cout << "Player 1 uses " <<
        // player1Moves.move_set[index].get_move_name() << endl;
        // player1Moves.move_set[index].play();

        // cout << "Player 2 uses " <<
        // player2Moves.move_set[index].get_move_name() << endl;
        // player2Moves.move_set[index].play();
        if (index2 == 1 || index2 == 2 || index2 == 5) {
          // player1.set_health(player1Moves.move_set[index].get_opponent_health)
          if (player1.get_health() == 0 || player2.get_health() == 0) {
            break;
          }
        }
      }
      if ((index1 == 1 || index1 == 2 || index1 == 4 || index1 == 5) &&
          index2 == 3) {
        if (index1 == 1) {
          // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
        } else if (index1 == 2) {
          // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
        } else if (index1 == 5) {
          // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence(),
          // player1.get_m_defence);
        }

        // cout << "Player 2 uses " <<
        // player2Moves.move_set[index].get_move_name() << endl;
        // player2Moves.move_set[index].play();

        // cout << "Player 1 uses " <<
        // player1Moves.move_set[index].get_move_name() << endl;
        // player1Moves.move_set[index].play();
        if (index1 == 1 || index1 == 2 || index1 == 5) {
          // player1.set_health(player1Moves.move_set[index].get_opponent_health)
          if (player1.get_health() == 0 || player2.get_health() == 0) {
            break;
          }
        }
      }

      if ((index1 == 1 || index1 == 2 || index1 == 4 || index1 == 5) &&
          index2 != 3) {
        if (index1 == 1) {
          // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
        } else if (index1 == 2) {
          // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
        } else if (index1 == 5) {
          // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence(),
          // player1.get_m_defence);
        }

        // cout << "Player 1 uses " <<
        // player1Moves.move_set[index].get_move_name()<< endl;
        //  player1Moves.move_set[index1].play() << endl;
        if (index1 == 1 || index1 == 2 || index1 == 5) {
          // player1.set_health(player1Moves.move_set[index].get_opponent_health)
          if (player1.get_health() == 0 || player2.get_health() == 0) {
            break;
          }
        }
      }
      if ((index2 == 1 || index2 == 2 || index2 == 4 || index2 == 5) &&
          index1 != 3) {
        if (index2 == 1) {
          // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
        } else if (index2 == 2) {
          // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
        } else if (index2 == 5) {
          // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence(),
          // player1.get_m_defence);
        }

        // cout << "Player 2 uses " <<
        // player2Moves.move_set[index].get_move_name()<< endl;
        // player2Moves.move_set[index1].play() << endl;
        if (index2 == 1 || index2 == 2 || index2 == 5) {
          // player1.set_health(player1Moves.move_set[index].get_opponent_health)
          if (player1.get_health() == 0 || player2.get_health() == 0) {
            break;
          }
        }
      }
      cout << "Player 1 Health: " << player1.get_health() << endl;
      cout << "Player 2 Health: " << player1.get_health() << endl;

    } else
      (player1.get_speed() > player2.get_speed()) {
        index2 = player2.play_move();
        index1 = player1.play_move();
        if (index1 == 3 && index2 == 3) {
          cout << "Both players uses Protect. Move Fail" << endl;
        }
        if ((index2 == 1 || index2 == 2 || index2 == 4 || index2 == 5) &&
            index1 == 3) {
          if (index2 == 1) {
            // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
          } else if (index2 == 2) {
            // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
          } else if (index2 == 5) {
            // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence(),
            // player1.get_m_defence);
          }

          // cout << "Player 1 uses " <<
          // player1Moves.move_set[index].get_move_name() << endl;
          // player1Moves.move_set[index].play();

          // cout << "Player 2 uses " <<
          // player2Moves.move_set[index].get_move_name() << endl;
          // player2Moves.move_set[index].play();
          if (index2 == 1 || index2 == 2 || index2 == 5) {
            // player1.set_health(player1Moves.move_set[index].get_opponent_health)
            if (player1.get_health() == 0 || player2.get_health() == 0) {
              break;
            }
          }
        }
        if ((index1 == 1 || index1 == 2 || index1 == 4 || index1 == 5) &&
            index2 == 3) {
          if (index1 == 1) {
            // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
          } else if (index1 == 2) {
            // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
          } else if (index1 == 5) {
            // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence(),
            // player1.get_m_defence);
          }

          // cout << "Player 2 uses " <<
          // player2Moves.move_set[index].get_move_name() << endl;
          // player2Moves.move_set[index].play();

          // cout << "Player 1 uses " <<
          // player1Moves.move_set[index].get_move_name() << endl;
          // player1Moves.move_set[index].play();
          if (index1 == 1 || index1 == 2 || index1 == 5) {
            // player1.set_health(player1Moves.move_set[index].get_opponent_health)
            if (player1.get_health() == 0 || player2.get_health() == 0) {
              break;
            }
          }
        }

        if ((index2 == 1 || index2 == 2 || index2 == 4 || index2 == 5) &&
            index1 != 3) {
          if (index2 == 1) {
            // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
          } else if (index2 == 2) {
            // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
          } else if (index2 == 5) {
            // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence(),
            // player1.get_m_defence);
          }

          // cout << "Player 2 uses " <<
          // player2Moves.move_set[index].get_move_name()<< endl;
          // player2Moves.move_set[index1].play() << endl;
          if (index2 == 1 || index2 == 2 || index2 == 5) {
            // player1.set_health(player1Moves.move_set[index].get_opponent_health)
            if (player1.get_health() == 0 || player2.get_health() == 0) {
              break;
            }
          }
          if ((index1 == 1 || index1 == 2 || index1 == 4 || index1 == 5) &&
              index2 != 3) {
            if (index1 == 1) {
              // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
            } else if (index1 == 2) {
              // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence());
            } else if (index1 == 5) {
              // player2Moves.move_set[index].set_opponent(player1.get_type(),player1.get_health(),player1.get_p_defence(),
              // player1.get_m_defence);
            }

            // cout << "Player 1 uses " <<
            // player1Moves.move_set[index].get_move_name()<< endl;
            //  player1Moves.move_set[index1].play() << endl;
            if (index1 == 1 || index1 == 2 || index1 == 5) {
              // player1.set_health(player1Moves.move_set[index].get_opponent_health)
              if (player1.get_health() == 0 || player2.get_health() == 0) {
                break;
              }
            }
          }
          cout << "Player 1 Health: " << player1.get_health() << endl;
          cout << "Player 2 Health: " << player1.get_health() << endl;
        }
      }
  }
  if (player1.get_health() == 0) {
    cout << "Player 2 Won" << endl;
    return 0;
  }
  if (player2.get_health() == 0) {
    cout << "Player 1 Won" << endl;
  }
}
