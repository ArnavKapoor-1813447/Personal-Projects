#include "Character.h"
#include <iostream>

// Function to test the default constructor
bool testDefaultConstructor() {
    Character player;
    return (player.get_health() == 100) && (player.get_name() == "Character") &&
        (player.get_type() == "Fire") && (player.get_level() == 50) &&
        (player.get_p_attack() == 100) && (player.get_m_attack() == 100) &&
        (player.get_p_defence() == 100) && (player.get_m_defence() == 100) &&
        (player.get_speed() == 100);
}

// Function to test the custom constructor
bool testCustomConstructor() {
   Character player("John", "Fire", 50, 60, 70, 80, 90, 100, 100);
    return (player.get_name() == "John") && (player.get_type() == "Fire");
    
}


int main() {
    int passed = 0;
    int total = 2;

    if (testDefaultConstructor()) {
        std::cout << "Default Constructor Test: Passed" << std::endl;
        passed++;
    } else {
        std::cout << "Default Constructor Test: Failed" << std::endl;
    }

    if (testCustomConstructor()) {
        std::cout << "Custom Constructor Test: Passed" << std::endl;
        passed++;
    } else {
        std::cout << "Custom Constructor Test: Failed" << std::endl;
    }

    std::cout << "Passed " << passed << " out of " << total << " tests." << std::endl;

    return 0;
}
