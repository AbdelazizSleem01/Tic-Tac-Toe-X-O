#include <iostream>
using namespace std;

bool equal_3(char x, char y, char z)
{
    if (x == y && y == z && x != ' ')
    {
        return true;
    }
    return false;
};
int winnerCheck(char board[3][3])
{
    // 2 : X Winner
    // -2 : O Winner
    // 0 : Tie
    // 1 : No Winner

    // in the rows case
    for (int i = 0; i < 3; i++)
    {
        if (equal_3(board[i][0], board[i][1], board[i][2]))
        {
            return board[i][0] == 'X' ? 2 : -2;
        };
    }
    // in columns case
    for (int i = 0; i < 3; i++)
    {
        if (equal_3(board[0][i], board[1][i], board[2][i]))
        {
            return board[0][i] == 'X' ? 2 : -2;
        };
    }
    // for Diameter one
    if (equal_3(board[0][0], board[1][1], board[2][2]))
    {
        return board[0][0] == 'X' ? 2 : -2;
    }
    // for Diameter two

    if (equal_3(board[0][2], board[1][1], board[2][0]))
    {
        return board[2][0] == 'X' ? 2 : -2;
    }
    // for tie
    bool tie = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                tie = false;
            }
        }
    }
    if (tie)
        return 0;
    // Else
    return 1;
};
void DrawBoard(char board[3][3])
{
    cout << "-------------------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "|" << " " << " " << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " " << " " << " | " << " " << " ";
        }
        cout << "\n"
             << "-------------------------" << endl;
    }
}

int main()
{
    cout << "============== 😍Tic-Tac-Toe😍 ================"<<endl;
    cout << "Enter the X Position"<<endl;
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int x, y;
    bool Winner = false;
    char player_X = 'X';
    while (!Winner)
    {
        cin >> x >> y;
        if (board[x][y] == ' ')
        {
            board[x][y] = player_X;
            player_X == 'X' ? player_X = 'O' : player_X = 'X';
            DrawBoard(board);
            Winner = winnerCheck(board) != 1;
        }
        else
        {
            cout << "This Field Not Available" << endl;
        }
    };
    int result = winnerCheck(board);
    if (result == 0)
    {
        cout << "Tie" << endl;
    }
    else
    {
        cout << ((result == 2) ? 'X' : 'O') << ": Is Winneeeeeeeeeeeer💯👏" << endl;
    }
    return 0;
}