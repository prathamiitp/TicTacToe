#include <bits/stdc++.h>
using namespace std;

enum TicTacToe { EMPTY = ' ',
                 PLAYER_X = 'X',
                 PLAYER_O = 'O' };

class TicTacToeBoard {
   public:
    TicTacToeBoard() : board(3, vector<TicTacToe>(3, EMPTY)) {}

    void displayBoard() const {
        system("clear");  // You may use "cls" for Windows systems

        cout << endl
             << "Player [1] is [X] : Player [2] is [O]" << endl
             << endl;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                cout << static_cast<char>(board[i][j]);
                if (j != board[0].size() - 1)
                    cout << " : ";
            }
            if (i != board.size() - 1)
                cout << endl
                     << "--:---:--" << endl;
        }

        cout << endl;
    }

   private:
    vector<vector<TicTacToe>> board;
};

int main() {
    TicTacToeBoard gameBoard();
    gameBoard.displayBoard();

    return 0;
}
