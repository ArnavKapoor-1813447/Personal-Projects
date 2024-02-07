#include "Moves.h"
#include "Attack.h"
#include "Character.h"

// virtual function.
int Attack::damage_calc() {return 0;}

// return attack_type variable.
string Attack::get_attack_type() { return attack_type; }

// return accuracy variable.
int Attack::get_accuracy() { return accuracy; }

// return power variable.
int Attack::get_power() { return power; }

// return opponent health variable.
int Attack::get_opponent_health() { return opponent_health; }

// set opponent_health.
void Attack::set_opponent(string para_type, int para_health, int para_defence) {
  opponent_type = para_type;
  opponent_health = para_defence;
  opponent_health = para_health;
}

// set move accuracy and subsequent power.
void Attack::set_accuracy(){
 cout << "Decreasing accuracy increases the power of the attack." << endl;
 cout << "Base Power Move of 50 can increase up to 125 by decreasing accuracy "
         "up to 50 percent." << endl;
 int integerInput;
 while ((cout << "Change Accuracy to (50-100): ") &&
        (!(cin >> integerInput) || integerInput < 50 || integerInput > 100)) {
   cout << "Invalid Input. Input must be between 50-100 inclusive." << endl;
   cin.clear();
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
 }
 accuracy = integerInput;
 power = 50 + 1.5 * (100 - accuracy);
}

// set attack type.
void Attack::set_attack_type(){
  cout << "Select 1 For Fire" << endl;
  cout << "Select 2 For Grass" << endl;
  cout << "Select 3 For Water" << endl;
  int integerInput;
  while ((cout << "Change Type (1-3): ") && (!(cin >> integerInput) || integerInput < 1 || integerInput > 3)){
      cout << "Invalid Input. Input must be between 1-3 inclusive." << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  if (integerInput == 1){
    attack_type = "Fire";
    cout << "Sucessfully changed type to Fire." << endl;
  } else if (integerInput == 2) {
    attack_type = "Grass";
    cout << "Sucessfully changed type to Grass." << endl;
  } else if (integerInput == 3) {
    attack_type = "Water";
    cout << "Sucessfully changed type to Water." << endl;
  } else {
    cout << "Invalid Input. Input must be 1,2 or 3." << endl;
  }
}
