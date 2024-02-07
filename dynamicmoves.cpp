// can put the move defintions anywhere
std::vector<Move> moveSet1 = {
    Move("Move 1", 30, 90),
    Move("Move 2", 25, 85),
    Move("Move 3", 40, 95),
    Move("Move 4", 20, 80)
};

std::vector<Move> moveSet2 = {
    Move("Move A", 35, 85),
    Move("Move B", 28, 88),
    Move("Move C", 42, 92),
    Move("Move D", 22, 82)
};


class Character {
public:
    Character(const std::string& name) : name(name) {}

    void chooseMoveSet(const std::vector<Move>& selectedMoveSet) {
        this->moveSet = selectedMoveSet;
    }

    // Other character attributes and methods
private:
    std::string name;
    std::vector<Move> moveSet;
};

int main() {
    Character player1("Player 1");
    Character player2("Player 2");

    player1.chooseMoveSet(moveSet1);
    player2.chooseMoveSet(moveSet2);

    // Now, player1 and player2 have their selected move sets with four moves each.

    return 0;
}


