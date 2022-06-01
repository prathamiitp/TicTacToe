// for arr[row][column], row=y(top to bottom), column=x(left to right)

#include <bits/stdc++.h>
using namespace std;

void printGrid(int xoGrid[3][3]) {
    cout << endl;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            // printing x,o corrspondingly else printing the box no for the grid
            if (xoGrid[y][x] == 1) {
                cout << " X";
            } else if (xoGrid[y][x] == 2 || xoGrid[y][x] == -1) {
                cout << " O";
            } else {
                cout << " " << (3 * y) + x + 1;
            }

            if (x != 2) {
                cout << " |";
            } else {
                cout << endl;
            }
        }
        if (y != 2) {
            cout << "-----------\n";
        }
    }
    cout << endl;
}

// winning cases
bool ifWon(int xoGrid[3][3]) {
    // equal digonal, but not equal to default case(0)
    if ((xoGrid[0][0] == xoGrid[1][1] && xoGrid[1][1] == xoGrid[2][2] && xoGrid[1][1]) || (xoGrid[0][2] == xoGrid[1][1] && xoGrid[1][1] == xoGrid[2][0] && xoGrid[1][1])) {
        if (xoGrid[1][1])
            cout << "Player " << xoGrid[1][1] << " Won!!!\n\n";
        return 1;
    } else if {
        for (int y = 0; y < 3; y++) {
            // equal horizontal line but not equal to 0
            if (xoGrid[y][0] == xoGrid[y][1] && xoGrid[y][1] == xoGrid[y][2] && xoGrid[y][0]) {
                cout << "Player " << xoGrid[y][0] << " Won!!!\n\n";
                return 1;
            }
            // equal vertical line but not equal to 0
            else if (xoGrid[0][y] == xoGrid[1][y] && xoGrid[1][y] == xoGrid[2][y] && xoGrid[0][y]) {
                cout << "Player " << xoGrid[0][y] << " Won!!!\n\n";
                return 1;
            }
        }
    }
    return 0;
}

// check if player want to play again
bool ifRematch() {
    char rematch = 0;
retry:  // could have used while(true) as well
    cout << "Rematch? enter y/n for yes or no:";
    cin >> rematch;
    if (rematch == 'n' || rematch == 'N') {
        return 0;
    } else if (rematch != 'y' || rematch != 'Y') {
        cout << "Invalid Input. try again!\n";
        goto retry;
    }
    return 1;
}

void move(int xoGrid[][], int player) {
    while (1) {
        int move = 0;
        cout << "Player " << player << ", enter a valid move: ";
        cin >> move;
        if (move <= 9 && move >= 1 && xoGrid[(move - 1) / 3][(move - 1) % 3] == 0) {
            xoGrid[(move - 1) / 3][(move - 1) % 3] = player;
            break;
        } else {
            cout << "Invalid input, try again!\n";
        }
    }
}

int main() {
    system("CLS");
    cout << "(V/S Human, V/S Computer) select 1,2 corresponding to given choices: ";
    int mode;
    cin >> mode;

    if (mode == 1) {
        for (int round = 1; round; round++) {
            system("CLS");
            cout << "See the grid below, to play your move to any of the box, enter its box no. between 1-9\n";
            int player = 1;
            int xoGrid[3][3] = {0};

            for (int run = 1; run <= 10; run++) {
                // printing the current xo grid
                printGrid(xoGrid);

                if (ifwon(xoGrid)) {
                    if (!ifRematch()) {
                        round = -1;
                    }
                    break;
                }

                // Draw case, 9 moves and no one won
                if (run == 10) {
                    cout << "!!This Match is a Draw!!\n";
                    if (!ifRematch()) {
                        round = -1;
                    }
                    break;
                }

                // to record players move
                move(xoGrid, player);

                // make the other player as current player
                player = player == 2 ? 1 : 2;

                // clear the screen
                system("CLS");
            }
        }
    // } else if (mode == 2) {
    //     int xoGrid[3][3] = {0};
    //     int move;
    // retry:
    //     cout << "What would you like to play?\n(Move 1st, Move 2nd, Toss) select 1,2,3 corresponding to given choices: ";
    //     cin >> move;
    //     if (move == 3) {
    //         srand(time(0));
    //         move = rand() % 2 + 1;
    //     }
    //     if (move == 1) {
    //         cout << "Yours is the 1st move, See the grid below, to play your move to any of the box, enter its box no. between 1-9\n";

    //     } else if (move == 2) {
    //         cout << "Yours is the 2nd move, See the grid below, to play your move to any of the box, enter its box no. between 1-9\n";
    //     } else {
    //         cout << "Inappropriate input, try again.";
    //         goto retry;
    //     }

    //     printGrid(xoGrid);
    } else {
        cout << "Inappropriate Input.\nExitting Programn...\n";
    }

    return 0;
}