#include <iostream>
#include <cctype>

using namespace std;

char board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove(char);
char checkWinner();
void printWinner(char);

int main()
{
    char winner = ' ';
    char response = ' ';

    do
    {
        winner = ' ';
        response = ' ';
        resetBoard();

        while (winner == ' ' && checkFreeSpaces() != 0)
        {
            printBoard();


            cout << "Player 1's move (X):" << endl;
            playerMove(PLAYER1);
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }

            printBoard();


            cout << "Player 2's move (O):" << endl;
            playerMove(PLAYER2);
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }
        }

        printBoard();
        printWinner(winner);

        cout << "\nWould you like to play again? (Y/N): ";
        cin >> response;
        response = toupper(response);
    } while (response == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

int checkFreeSpaces()
{
    int freeSpaces = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove(char player)
{
    int x, y;

    do
    {
        cout << "Enter row #(1-3): ";
        cin >> x;
        cout << "Enter column #(1-3): ";
        cin >> y;

        if (x < 1 || x > 3 || y < 1 || y > 3)
        {
            cout << "Invalid input! Please enter a number between 1 and 3." << endl;
        }
        else if (board[x - 1][y - 1] != ' ')
        {
            cout << "Invalid move! The position is already occupied." << endl;
        }
        else
        {
            board[x - 1][y - 1] = player;
            break;
        }
    } while (true);
}


char checkWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';
}

void printWinner(char winner)
{
    if (winner == PLAYER1)
    {
        cout << "Player 1 (X) WINS!" << endl;
    }
    else if (winner == PLAYER2)
    {
        cout << "Player 2 (O) WINS!" << endl;
    }
    else
    {
        cout << "IT'S A TIE!" << endl;
    }
}
