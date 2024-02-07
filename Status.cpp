#include "Status.h"

// default move constructor for status.
Status::Status() {
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
  modifier = 2.0;
  stat = "p_attack";
  move_name = "Status";
}

// status move constructor.
Status::Status(string para_name, string para_type, int para_level,
               int para_health, int para_p_attack, int para_m_attack,
               int para_p_defence, int para_m_defence, int para_speed) {
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
  modifier = 2.0;
  stat = "p_attack";
  move_name = "Status";
}

// return uses variable.
int Status::get_uses() { return uses; }

// return modifier variable.
int Status::get_modifier() { return modifier; }

// return stat variable.
string Status::get_stat() { return stat; }

// return accuracy.
int Status::get_accuracy() { return accuracy; }

// prompt users to customise move accuracy.
void Status::set_accuracy() {
  cout
      << "Select 1 to have status increase by 1 stage for 100 percent accuracy."
      << endl;
  cout
      << "Select 2 to have status increase by 2 stages for 70 percent accuracy."
      << endl;
  cout
      << "Select 3 to have status increase by 3 stages for 40 percent accuracy."
      << endl;

  int integerInput;
  // ensuring user input is within bounds.
  while ((cout << "Change accuracy (1-3): ") &&
         (!(cin >> integerInput) || integerInput < 1 || integerInput > 3)) {
    cout << "Invalid Input. Input must be between 1-3 inclusive." << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  // sets accuracy base on user choice.
  if (integerInput == 1) {
    accuracy = 100;
    cout << "Sucessfully changed accuracy to 100 with stat boost of 1 stage."
         << endl;
  } else if (integerInput == 2) {
    accuracy = 70;
    cout << "Sucessfully changed accuracy to 70 with stat boost of 2 stages."
         << endl;
  } else if (integerInput == 3) {
    cout << "Sucessfully changed accuracy to 40 with stat boost of 3 stages."
         << endl;
    accuracy = 40;
  }
}

// prompt uses to customise number of times move can be used.
void Status::set_uses() {
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

// prompt user to choose which stat to increase.
void Status::set_stat() {
  cout << "Select 1 to have status increase your Physical Attack." << endl;
  cout << "Select 2 to have status increase your Magical Defence. " << endl;
  cout << "Select 3 to have status increase your Physical Defence. " << endl;
  cout << "Select 4 to have status increase your Magical Defence. " << endl;
  cout << "Select 5 to have status increase your Speed. " << endl;

  int integerInput;
  // ensuring input is within bounds.
  while ((cout << "Change status move type (1-5): ") &&
         (!(cin >> integerInput) || integerInput < 1 || integerInput > 5)) {
    cout << "Invalid Input. Input must be between 1-5 inclusive." << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  // selecting stat based on user input
  if (integerInput == 1) {
    stat = "p_attack";
    cout << "Sucessfully changed status move to increase Physical Attack."
         << endl;
  } else if (integerInput == 2) {
    stat = "m_attack";
    cout << "Sucessfully changed status move to increase Mhysical Attack."
         << endl;
  } else if (integerInput == 3) {
    stat = "p_defence";
    cout << "Sucessfully changed status move to increase Physical Defence."
         << endl;
  } else if (integerInput == 4) {
    stat = "m_defence";
    cout << "Sucessfully changed status move to increase Magical Defence."
         << endl;
  } else if (integerInput == 5) {
    stat = "speed";
    cout << "Sucessfully changed status move to increase Speed." << endl;
  } else {
    cout << "Invalid Input. Input must be 1-5 inclusive." << endl;
  }
}

// determines which stats increase and by how many stages.
void Status::play() {
  float result;
  if (uses == 0) {
    cout << "Your Status move ran out of uses!" << endl;
  } else {
    if ((rand() & 100) <= accuracy && accuracy == 40) {
      modifier = modifier + 3;
      if (stat == "p_attack" && modifier <= 8) {
        result = p_attack * (modifier / 2) / ((modifier - 3) / 2);
        set_p_attack(result);
        cout << "Physical Attack has drastically increased!" << endl;
        uses = uses - 1;

      } else if (stat == "m_attack" && modifier <= 8) {
        result = m_attack * (modifier / 2) / ((modifier - 3) / 2);
        set_m_attack(result);
        cout << "Magical Attack has drastically increased!" << endl;
        uses = uses - 1;

      } else if (stat == "p_defence" && modifier <= 8) {
        result = p_defence * (modifier / 2) / ((modifier - 3) / 2);
        set_p_defence(result);
        cout << "Physical Defence has drastically increased!" << endl;
        uses = uses - 1;

      } else if (stat == "m_defence" && modifier <= 8) {
        result = m_defence * (modifier / 2) / ((modifier - 3) / 2);
        set_m_defence(result);
        cout << "Magical Defence has drastically increased!" << endl;
        uses = uses - 1;

      } else if (stat == "speed" && modifier <= 8) {
        result = speed * (modifier / 2) / ((modifier - 3) / 2);
        set_speed(result);
        cout << "Speed has drastically increased!" << endl;
        uses = uses - 1;
      }
    } else if ((rand() & 100) <= accuracy && accuracy == 70) {
      modifier = modifier + 2;
      if (stat == "p_attack" && modifier <= 8) {
        result = p_attack * (modifier / 2) / ((modifier - 2) / 2);
        set_p_attack(result);
        cout << "Physical Attack has greatly increased!" << endl;
        uses = uses - 1;

      } else if (stat == "m_attack" && modifier <= 8) {
        result = m_attack * (modifier / 2) / ((modifier - 2) / 2);
        set_m_attack(result);
        cout << "Magical Attack has greatly increased!" << endl;
        uses = uses - 1;

      } else if (stat == "p_defence" && modifier <= 8) {
        result = p_defence * (modifier / 2) / ((modifier - 2) / 2);
        set_p_defence(result);
        cout << "Physical Defence has greatly increased!" << endl;
        uses = uses - 1;

      } else if (stat == "m_defence" && modifier <= 8) {
        result = m_defence * (modifier / 2) / ((modifier - 2) / 2);
        set_m_defence(result);
        cout << "Magical Defence has greatly increased!" << endl;
        uses = uses - 1;

      } else if (stat == "speed" && modifier <= 8) {
        result = speed * (modifier / 2) / ((modifier - 2) / 2);
        set_speed(result);
        cout << "Speed has greatly increased!" << endl;
        uses = uses - 1;
      }
    } else if ((rand() & 100) <= accuracy && accuracy == 100) {
      modifier = modifier + 1;
      if (stat == "p_attack" && modifier <= 8) {
        result = p_attack * (modifier / 2) / ((modifier - 1) / 2);
        set_p_attack(result);
        cout << "Physical Attack has increased!" << endl;
        uses = uses - 1;

      } else if (stat == "m_attack" && modifier <= 8) {
        result = m_attack * (modifier / 2) / ((modifier - 1) / 2);
        set_m_attack(result);
        cout << "Magical Attack has increased!" << endl;
        uses = uses - 1;

      } else if (stat == "p_defence" && modifier <= 8) {
        result = p_defence * (modifier / 2) / ((modifier - 1) / 2);
        set_p_defence(result);
        cout << "Physical Defence has increased!" << endl;
        uses = uses - 1;

      } else if (stat == "m_defence" && modifier <= 8) {
        result = m_defence * (modifier / 2) / ((modifier - 1) / 2);
        set_m_defence(result);
        cout << "Magical Defence has increased!" << endl;
        uses = uses - 1;

      } else if (stat == "speed" && modifier <= 8) {
        result = speed * (modifier / 2) / ((modifier - 1) / 2);
        set_speed(result);
        cout << "Speed has increased!" << endl;
        uses = uses - 1;
      }
    } else {
      cout << "Status Move Missed!" << endl;
    }
    if (modifier == 8) {
      cout << "Your can't increase this stat any further!" << endl;
    }
  }
}
