#include "headers/Board.h"

#include <iostream>
#include <vector>
#include <iomanip> //add support for - setw
#include <string> //add suport for - std::string, std::stoi
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

//Constructor: Generates the 2D array and game grid
Board::Board() {
    // Two for loops to count up the rows and columns. First for loop counts row, second counts columns
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = '0'; // ~ is the default look of water so the array is full of "water"
        }
    }
}

// drawGrid()
// Draws the battleship grid by labeling axis and then coloring in coordinates based on their value
void Board::drawGrid(int showShips) {
    char y_cords[] = {'A','B','C','D','E','F','G','H','I','J'};
    cout << "  0 1 2 3 4 5 6 7 8 9" << endl; // X-cords
    for (int i = 0; i < 10; i++) {
        cout << y_cords[i] << " ";
        for (int j = 0; j < 10; j++) {
            
            if (grid[i][j] == '0') { // 0 means not hit
                cout << "\E[0;37m" << "\E[44m" << grid[i][j] << " " << "\E[0m";
            }
            if (grid[i][j] == '#') { // # means miss
                cout << "\E[0;31m" << "\E[44m" << grid[i][j] << " " << "\E[0m";
            }
            if (grid[i][j] == 'X') { // X means hit
                cout << "\E[0;31m" << "\E[47m" << grid[i][j] << " " << "\E[0m";
            }
            if (grid[i][j] == '+') { // + means there is a ship
                if (showShips == 1)
                    cout << "\E[1;37m" << "\E[47m" << grid[i][j] << " " << "\E[0m";
                else
                    cout << "\E[0;37m" << "\E[44m" << "0" << " " << "\E[0m";
            }
        }
        cout << endl;
    }
}

void Board::playerGuess(char y, char x) {
    int x_cord = x - '0'; //Converts char to int
    char y_cords[] = {'A','B','C','D','E','F','G','H','I','J'};

    //So the X cords already int. This for loop goes through y_cords[] to find the proper y value
    //because the y value is passed to the function as a letter
    for (int i = 0; i < 10; i++) {
        if (y_cords[i] == y) {
            if (grid[i][x_cord] == '0') { grid[i][x_cord] = '#'; } // If you guess water, show no hit
            if (grid[i][x_cord] == '+') { grid[i][x_cord] = 'X'; } // If you guess the ship, you hit!
        }
    }
    drawGrid(0);
}

//placeShip()
//Works essentially the same as playerGuess but with heading and length to affect multiple array locations.
void Board::placeShip(char y, char x, char heading, int length) {
    int y_cord;
    int x_cord = x - '0';
    char y_cords[] = {'A','B','C','D','E','F','G','H','I','J'};

    for (int i = 0; i < 10; i++) {
        if (y_cords[i] == y) {
            grid[i][x_cord] = '+';


            if (heading == 'N') {
                //This 'draws' the full ship on the screen by drawing each square a specific length
                //away from the actual cordinates in a specific direction.
                for (length; length > 0; length--) {
                    grid[i-(length-1)][x_cord] = '+'; //Subtracting the Y value goes North
                }
            }
            if (heading == 'E') {
                for (length; length > 0; length--) {
                    grid[i][x_cord+(length-1)] = '+'; //Adding to the X value goes East
                }
            }
            if (heading == 'S') {
                for (length; length > 0; length--) {
                    grid[i+(length-1)][x_cord] = '+'; //Adding to the Y value goes South
                }
            }
            if (heading == 'W') {
                for (length; length > 0; length--) {
                    grid[i][x_cord-(length-1)] = '+'; //Subtracting the X values goes West
                }
            }
        }
    }
    drawGrid(1);
}

int Board::gameOver() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == '+') {
                return 0;
            }
        }
    }
    return 1;
}








