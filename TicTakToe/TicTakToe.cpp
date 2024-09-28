// TicTakToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

#define GRID_ROW 3
#define GRID_COL 3
vector<vector<char>> matrix(GRID_ROW, vector<char>(GRID_COL, ' '));

void drawGrid()
{
    cout << "-------------" << endl;
    for (auto vec : matrix)
    {
        cout << "| ";
        for (auto col : vec)
        {
            cout << col << " | ";
        }
        cout << "\n-------------" << endl;
    }
}

bool isSuccess(char player)
{
    for (int i = 0; i < GRID_ROW; i++)
    {
        for (int j = 0; j < GRID_COL; j++)
        {
            // Check if there is a match horizontally or vertically
            if ((matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == player)
                || (matrix[0][i] == player && matrix[1][i] == player && matrix[2][i] == player))
                return true;
        }
    }
    // Check if there is a match diagonally
    if ((matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player)
        || (matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player))
        return true;

    return false;
}

int main()
{
    char player = 'X';
    int row=0, col = 0;
    cout << "Welcome to Tic-Tak-Toe game!!!" << endl;
    cout << "There will be 2 players X and O. Please take turns to enter " << endl;
    cout << "row & col values with a space in between them." << endl;
    cout << "Goodluck!!" << endl;
    for (int i=0;i<GRID_COL*GRID_ROW;i++)
    {
        drawGrid();
        while (true)
        {
            cout << "Player " << player << ". Please enter values between 1-3 for row & col with a space in-between: " << endl;
            cin >> row >> col;
            if (row <= 0 || row > 3 || col <= 0 || col > 3)
                cout << "Invalid input. Please enter in the correct range" << endl;
            else
                break;
        }
        matrix[row-1][col-1] = player;
        bool bSuccess = isSuccess(player);
        if (bSuccess)
        {
            cout << "Player " << player << " has won!!" << endl;
            cout << "Game End!!" << endl;
            break;
        }
        player = (player == 'X') ? 'O':'X';
    }
}
