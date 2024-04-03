#include <iostream>
#include <stack>
#include <tuple>
using namespace std;

struct Move {
    int disk;
    int source;
    int target;
    int auxiliary;

    Move(int d, int s, int t, int a)
        : disk(d), source(s), target(t), auxiliary(a) {}
};

void hanoi(int n, int source, int target, int auxiliary) {
    std::stack<Move> moves;
    moves.push(Move(n, source, target, auxiliary));

    while (!moves.empty()) {
        Move current = moves.top();
        moves.pop();

        int disk = current.disk;
        int source = current.source;
        int target = current.target;
        int auxiliary = current.auxiliary;

        if (disk == 1) {
            std::cout << "Di chuyen dia tu cot " << source << " sang cot " << target << std::endl;
        }
        else {
            moves.push(Move(disk - 1, auxiliary, target, source));
            Move temp = moves.top();
            cout << temp.disk << " " << temp.source << " " << temp.target << " " << temp.auxiliary << endl;
            moves.push(Move(1, source, target, auxiliary));
            temp = moves.top();
            cout << temp.disk << " " << temp.source << " " << temp.target << " " << temp.auxiliary << endl;
            moves.push(Move(disk - 1, source, auxiliary, target));
            temp = moves.top();
            cout << temp.disk << " " << temp.source << " " << temp.target << " " << temp.auxiliary << endl;
        }
    }
}

int main() {
    int n = 3;
    int source = 1;
    int target = 3;
    int auxiliary = 2;

    hanoi(n, source, target, auxiliary);

    return 0;
}