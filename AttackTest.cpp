#include <iostream>
#include <sstream>
#include <cmath>
#include "Attack.h"

class UnitTest {
public:
    void runTests() {
        testDamageCalculation();
        testAccuracySetting();
        testAttackTypeSetting();
    }

private:
    void assertEqual(const std::string& actual, const std::string& expected, const std::string& message) {
        if (actual != expected) {
            std::cout << "Test failed: " << message << std::endl;
        }
    }

    void assertEqual(int actual, int expected, const std::string& message) {
        if (actual != expected) {
            std::cout << "Test failed: " << message << std::endl;
        }
    }

    void assertApproxEqual(double actual, double expected, double epsilon, const std::string& message) {
        if (fabs(actual - expected) >= epsilon) {
            std::cout << "Test failed: " << message << std::endl;
        }
    }

    void testDamageCalculation() {
        Attack attack;
        assertEqual(attack.damage_calc(), 0, "Default Constructor Test - Damage Calculation");
    }

    void testAccuracySetting() {
        Attack attack;

        std::stringstream input_stream("75\n");
        std::streambuf* old_cin = std::cin.rdbuf(input_stream.rdbuf());

        attack.set_accuracy();


        std::cin.rdbuf(old_cin);

        assertEqual(attack.get_accuracy(), 75, "Set Accuracy Test");
    }

    void testAttackTypeSetting() {
        Attack attack;

        std::stringstream input_stream("2\n");
        std::streambuf* old_cin = std::cin.rdbuf(input_stream.rdbuf());

        attack.set_attack_type();


        std::cin.rdbuf(old_cin);

        assertEqual(attack.get_attack_type(), "Grass", "Set Attack Type Test");
    }


};

int main() {
    UnitTest unitTest;
    unitTest.runTests();

    return 0;
}
