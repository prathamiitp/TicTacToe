#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

void initGame(vector<vector<char>>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[0].size(); ++j) {
            arr[i][j] = '1' + i * 3 + j;
        }
    }
}

void playTurn(vector<vector<char>>& arr, bool player) {
    int placeVal, x, y;
    char mark = player ? 'O' : 'X';
    cout << endl
         << "Player [" << player + 1 << "]: enter the tile no. to put [" << mark << "]: ";
    cin >> placeVal;
    x = (placeVal - 1) / 3;
    y = (placeVal - 1) % 3;
    if ((placeVal >= 1 && placeVal <= 9) && (arr[x][y] != 'X' && arr[x][y] != 'O'))
        arr[x][y] = mark;
    else {
        cout << "Invalid selection... Try again";
        playTurn(arr, player);
    }
}

void cpuTurn(vector<vector<char>>& arr, bool player) {
    int placeVal, x, y;
    char mark = player ? 'O' : 'X';
}

void dspGame(vector<vector<char>>& arr) {
    system("clear");

    cout << endl
         << "Player [1] is [X] : Player [2] is [O]" << endl
         << endl;

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[0].size(); ++j) {
            cout << arr[i][j];
            if (j != arr[0].size() - 1)
                cout << " : ";
        }
        if (i != arr.size() - 1)
            cout << endl
                 << "--:---:--" << endl;
    }

    cout << endl;
}

bool fullGame(vector<vector<char>>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        for (int j = 0; j < arr[0].size(); ++j)
            if (arr[i][j] != 'X' && arr[i][j] != 'O')
                return 0;
    return 1;
}

int win(vector<vector<char>>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
            cout << endl
                 << "Row [" << i + 1 << "]";
            return arr[i][0] == 'X' ? 1 : 2;
        }
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {
            cout << endl
                 << "Column [" << i + 1 << "]";
            return arr[0][i] == 'X' ? 1 : 2;
        }
    }

    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
        cout << endl
             << "Backward digonal \\";
        return arr[1][1] == 'X' ? 1 : 2;
    }
    
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
        cout << endl
             << "Forward digonal /";
        return arr[1][1] == 'X' ? 1 : 2;
    }
    return 0;
}

int main() {
    vector<vector<char>> grid(3, vector<char>(3));
    system("clear");

    initGame(grid);
    dspGame(grid);

    int player = 0;
    int winCheck = 0;
    while (!fullGame(grid)) {
        playTurn(grid, player);
        dspGame(grid);
        player = !player;

        winCheck = win(grid);
        if (winCheck) {
            break;
        }
    }

    if (winCheck)
        cout << endl
             << "Player [" << winCheck << "] won the game ! ! !";
    else
        cout << endl
             << "Match draw!!";

    return 0;
}