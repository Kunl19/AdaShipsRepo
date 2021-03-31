#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <ctime>
#include <limits>
#include <string>
#include <iomanip>
#include "headers/Board.h"

using namespace std;

//information from the ini file

using namespace std;

std::vector<std::string> split(const std::string& str, const std::string& delim) {
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

class singleton {
private:

    struct Board {
        string height;
        string width;
    };

    /*struct Boat {
        string length;
        string name;
    };*/

    struct Carrier {
        string length;
        string name;
    };

    struct Battleship {
        string length;
        string name;
    };

    struct Submarine {
        string length;
        string name;
    };

    struct Destroyer {
        string length;
        string name;
    };

    struct Patrol {
        string length;
        string name;
    };

    //std::vector<Boat> boats = {};

    Board board_;

    const int width = 10;
    const int height = 10;

    singleton(const std::string reference, const int value) :
        reference_(reference), //initialise the variable 'singleton::reference_' with the value passed as 'reference' 
        value_(value)
    {
        //possible constructor code
        cout << "\nsingleton contructor code started";
    }

    static singleton* inst_; //a pointer to the 'one' cached (single) instance

protected: //essentially, protected means that members of subclasses are also allowed
    std::string reference_;
    int value_;

public:

    struct BoardData
    {
        Board board;
        //Boat boat;
    };

    struct CarrierData {
        Carrier carrier;
    };

    struct BattleshipData {
        Battleship battleship;
    };

    struct SubmarineData {
        Submarine submarine;
    };

    struct DestroyerData {
        Destroyer destroyer;
    };

    struct PatrolData {
        Patrol patrol;
    };

    static singleton* getInstance(const std::string& reference, const int& value);

    singleton* read_config(string config);

    std::string businessLogic(std::string data) {
        //...
        return "doing something really useful: " + data;
    }

    std::string reference() const {
        return reference_;
    }

    int value() const {
        return value_;
    }

    //used two config files initially but managed to reduce it to using one by spliting the boat file using split function

    //Reads information about the game board
    BoardData read_Board() {
        BoardData data = BoardData();
        std::string line;
        std::ifstream boatFile("adaship_config.ini");
        if (boatFile.is_open()) {
            while (getline(boatFile, line)) {
                std::vector<std::string> parts = split(line, "=");
                if (parts[0] == "board") {
                    Board board = Board();
                    board.height = split(parts[1], "X")[0];
                    board.width = split(parts[1], "X")[1];
                    data.board = board;
                }
            }
            boatFile.close();
        }

        return data;
    }

    //Reads Carrier information from file
    CarrierData read_Carriers() {
        CarrierData data = CarrierData();
        std::string line;
        std::ifstream boatFile("adaship_config.ini");
        if (boatFile.is_open()) {
            while (getline(boatFile, line)) {
                std::vector<std::string> parts = split(line, "=");
                if (parts[0] == "carrier") {
                    Carrier carrier = Carrier();
                    carrier.name = parts[0];
                    carrier.length = parts[1];
                    data.carrier = carrier;
                }
            }
            boatFile.close();
        }

        return data;
    }

    //Reads Battleship information from file
    BattleshipData read_Battleships() {
        BattleshipData data = BattleshipData();
        std::string line;
        std::ifstream boatFile("adaship_config.ini");
        if (boatFile.is_open()) {
            while (getline(boatFile, line)) {
                std::vector<std::string> parts = split(line, "=");
                if (parts[0] == "battleship") {
                    Battleship battleship = Battleship();
                    battleship.name = parts[0];
                    battleship.length = parts[1];
                    data.battleship = battleship;
                }
            }
            boatFile.close();
        }

        return data;
    }

    //Reads submarine information from file
    SubmarineData read_Submarines() {
        SubmarineData data = SubmarineData();
        std::string line;
        std::ifstream boatFile("adaship_config.ini");
        if (boatFile.is_open()) {
            while (getline(boatFile, line)) {
                std::vector<std::string> parts = split(line, "=");
                if (parts[0] == "submarine") {
                    Submarine submarine = Submarine();
                    submarine.name = parts[0];
                    submarine.length = parts[1];
                    data.submarine = submarine;
                }
            }
            boatFile.close();
        }

        return data;
    }

    DestroyerData read_Destroyers() {
        DestroyerData data = DestroyerData();
        std::string line;
        std::ifstream boatFile("adaship_config.ini");
        if (boatFile.is_open()) {
            while (getline(boatFile, line)) {
                std::vector<std::string> parts = split(line, "=");
                if (parts[0] == "destroyer") {
                    Destroyer destroyer = Destroyer();
                    destroyer.name = parts[0];
                    destroyer.length = parts[1];
                    data.destroyer = destroyer;
                }
            }
            boatFile.close();
        }

        return data;
    }

    PatrolData read_Patrols() {
        PatrolData data = PatrolData();
        std::string line;
        std::ifstream boatFile("adaship_config.ini");
        if (boatFile.is_open()) {
            while (getline(boatFile, line)) {
                std::vector<std::string> parts = split(line, "=");
                if (parts[0] == "patrol") {
                    Patrol patrol = Patrol();
                    patrol.name = parts[0];
                    patrol.length = parts[1];
                    data.patrol = patrol;
                }
            }
            boatFile.close();
        }

        return data;
    }
};

singleton* singleton::inst_ = nullptr;


singleton* singleton::getInstance(const std::string& reference, const int& value) {

    if (inst_ == nullptr) {
        inst_ = new singleton(reference, value); //no previous instance stored, create and store the original
    }
    return inst_; //return the stored instance
};

//Gets user input for where they want to place the battleship and returns a string

string getShipPlacement(int shipLength, string shipName) {
    string place;

    cout << "Length of ship: " << shipLength << endl;
    cout << "Length of ship: " << shipName << endl;
    cout << "Location and heading for ship placement (ex. D4E where D and 4 are coordinates and E is a direction): ";
    cin >> place;

    return place;
}

//Random area to place ships on board 

string getRandomShipPlacement() {
    string randomplace;
    char heading;
    char y;
    char x;

    //computer enters random values here 
    char y_cords[10] = { 'A','B','C','D','E','F','G','H','I','J' };
    int RandY = rand() % 10;
    y = y_cords[RandY];

    //char x_cords[] = {'0','1','2','3','4','5','6','7','8','9'};
    char headings[4] = { 'N','E','S','W' };
    int RandIndex = rand() % 4;
    heading = headings[RandIndex];

    //random value of y between 0 - 9    
    int index = rand() % 10;
    x = index;

    randomplace = heading + x + y;

    return randomplace;
}

//Generates random coordinates for computer guess

string getRandomGuess() {
    string guess;

    char y;
    char x;

    int index = rand() % 10;
    x = index;

    char y_cords[10] = { 'A','B','C','D','E','F','G','H','I','J' };
    int RandY = rand() % 10;
    y = y_cords[RandY];

    guess = x + y;

    return guess;

}
int main() {

    singleton* instanceFoo = singleton::getInstance("foo", 101);
    singleton* instanceBar = singleton::getInstance("bar", 101);

    singleton::BoardData data = instanceFoo->read_Board();
    singleton::CarrierData cdata = instanceFoo->read_Carriers();
    singleton::BattleshipData bdata = instanceFoo->read_Battleships();
    singleton::DestroyerData ddata = instanceFoo->read_Destroyers();
    singleton::SubmarineData sdata = instanceFoo->read_Submarines();
    singleton::PatrolData pdata = instanceFoo->read_Patrols();


    //Passes values from ada config file to create the boards sizing 

    int width = stoi(data.board.width);
    int height = stoi(data.board.height);

    //Read carriers
    int carrierLength = stoi(cdata.carrier.length);
    string carrierName = cdata.carrier.name;

    // Read battleships
    int battleshipLength = stoi(bdata.battleship.length);
    string battleshipName = bdata.battleship.name;

    // Read destroyers
    int destroyerLength = stoi(ddata.destroyer.length);
    string destroyerName = ddata.destroyer.name;

    // Read submarines
    int submarineLength = stoi(sdata.submarine.length);
    string submarineName = sdata.submarine.name;

    // Read patrols
    int patrolLength = stoi(pdata.patrol.length);
    string patrolName = pdata.patrol.name;

    string guess, place; //Initialze variables
    int rand1, rand2;
    int shipLengthArray[] = { carrierLength, battleshipLength, destroyerLength,submarineLength,patrolLength };
    string shipNamesArray[] = { carrierName , battleshipName , destroyerName , submarineName, patrolName };

    //Put this all in a menu function

    cout << "\n" << "    ======= WELCOME TO BATTLESHIP! =======" << "\n\n\n";
    //start menu
    string user;
    cout << "Enter 1 To view rules" << "\n";
    cout << "Enter any letter to start the game" << "\n";

    cin >> user;
    system("clear");

    if (user == "1") {

        cout << "\nGame symbols" << endl;
        cout << "    Water/Empty Space: " << "\E[0;37m" << "\E[44m" << "0 " << "\E[0m" << endl;
        cout << "    Missed Guess: " << "\E[0;31m" << "\E[44m" << "# " << "\E[0m" << endl;
        cout << "    Battleship Hit: " << "\E[0;31m" << "\E[47m" << "X " << "\E[0m" << endl;
        cout << "    Battleship Not Hit: " << "\E[1;37m" << "\E[47m" << "+ " << "\E[0m" << endl;
        cout << "Entering coordinates" << "\n";
        cout << "example - enter B2E which targets coordinates B2 and the ship is placed east: " << "\n";
        cout << "example - enter A0S which targets coordinates A0 and the ship is placed south: " << "\n";
        cout << "example - enter F5N which targets coordinates F5 and the ship is placed north: " << "\n";
        cout << "example - enter C8W which targets coordinates C8 and the ship is placed west: " << "\n";

        int clear;
        cout << "click any number to continue: ";
        cin >> clear;
        system("clear");
        //click keyboard to clear and continue 
    }


    string type;
    cout << "Enter number for specifc game type" << "\n";
    cout << "Enter 1: Player vs Player" << "\n";
    cout << "Enter 2: Player vs CPU" << "\n";
    cout << "Enter 3 to quit the game" << "\n";
    cin >> type;

    if (type == "1") {
        while (type == "1") {
            //player 1
            string place;
            cout << "You are playing player vs player" << "\n";
            cout << "Player 1 place ships" << "\n";

            Board player1_grid;
            player1_grid.drawGrid(1);
            //change to array size
            for (int i = 0; i < 5; i++) {
                place = getShipPlacement(shipLengthArray[i], shipNamesArray[i]);
                player1_grid.placeShip(place[0], place[1], place[2], shipLengthArray[i]);
            }

            system("clear");
            cout << "Player 1 has placed. Leave so Player 2 can place ships. DO NOT scroll up\n";

            Board player2_grid;
            player2_grid.drawGrid(1);
            for (int i = 0; i < 5; i++) {
                place = getShipPlacement(shipLengthArray[i], shipNamesArray[i]);
                //Entered wrong method on original commit 
                player2_grid.placeShip(place[0], place[1], place[2], shipLengthArray[i]);
            }

            int count = 1;
            string next;

            while (true) {
                if (player1_grid.gameOver() == 1) {
                    cout << "\n\nPLAYER 2 WINS!!!" << endl;
                    break;
                }
                if (player2_grid.gameOver() == 1) {
                    cout << "\n\nPLAYER 1 WINS!!!" << endl;
                    break;
                }
                else if (count % 2 == 1) {
                    cout << "It is player 1s turn to guess. Input any character and press enter to continue.";
                    cin >> next;
                    for (int i = 0; i < 100; i++) {
                        cout << " " << endl;
                    }
                    cout << "\nYour Board: " << endl;
                    player1_grid.drawGrid(1);
                    cout << "\nYour Guesses on Player 2s Board: " << endl;
                    player2_grid.drawGrid(0);
                    cout << "Player 1 New Guess (ex. D4): ";
                    cin >> guess;
                    cout << "\nYour Updated Guesses:" << endl;
                    player2_grid.playerGuess(guess[0], guess[1]);
                    count++;
                }
                else if (count % 2 == 0) {
                    cout << "It is player 2s turn to guess. Input any character and press enter to continue.";
                    cin >> next;
                    for (int i = 0; i < 100; i++) {
                        cout << " " << endl;
                    }
                    cout << "\nYour Board: " << endl;
                    player2_grid.drawGrid(1);
                    cout << "\nYour Guesses on Players 1s Board: " << endl;
                    player1_grid.drawGrid(0);
                    cout << "Player 2 New Guess (ex. D4): ";
                    cin >> guess;
                    cout << "\nYour Updated Guesses:" << endl;
                    player1_grid.playerGuess(guess[0], guess[1]);
                    count++;
                }
            }
        }
    }
    else if (type == "2") {
        while (type == "2") {
            string place;
            string randomplace;
            cout << "You are playing player vs computer" << "\n";
            cout << "Your turn to place ships on the board" << "\n";

            Board player1_grid;
            player1_grid.drawGrid(1);
            for (int i = 0; i < 5; i++) {
                place = getShipPlacement(shipLengthArray[i], shipNamesArray[i]);
                player1_grid.placeShip(place[0], place[1], place[2], shipLengthArray[i]);
            }

            system("clear");
            cout << "Player has placed ships. Computer is now placing ships" << "\n";
            //Computer place ships method

            Board computer_grid;
            computer_grid.drawGrid(1);
            for (int i = 0; i < 5; i++) {
                randomplace = getRandomShipPlacement();
                computer_grid.placeShip(randomplace[0], randomplace[1], randomplace[2], shipLengthArray[i]);

            }

            int count = 3;
            string next;

            while (true) {
                if (player1_grid.gameOver() == 1) {
                    cout << "\n\nComputer Wins" << endl;
                    break;
                }
                if (computer_grid.gameOver() == 1) {
                    cout << "\n\nPLAYER 1 WINS!!!" << endl;
                    break;
                }
                if (count % 2 == 1) {
                    cout << "It is your turn to guess. Input any character and press enter to continue.";
                    cin >> next;
                    for (int i = 0; i < 100; i++) {
                        cout << " " << endl;
                    }
                    cout << "\nYour Board: " << endl;
                    player1_grid.drawGrid(1);
                    cout << "\nYour Guesses on Player 2s Board: " << endl;
                    computer_grid.drawGrid(0);
                    cout << "Player 1 New Guess (ex. D4): ";
                    cin >> guess;
                    cout << "\nYour Updated Guesses:" << endl;
                    computer_grid.playerGuess(guess[0], guess[1]);
                    count++;
                }
                else if (count % 2 == 0) {
                    cout << "It is the computers turn to guess. Input any character and press enter to continue.";
                    cin >> next;
                    for (int i = 0; i < 100; i++) {
                        cout << " " << endl;
                    }
                    cout << "\nYour Board: " << endl;
                    computer_grid.drawGrid(0);
                    //Hide the computer grid to the user
                    cout << "\nYour Guesses on the Computers Board : " << endl;
                    player1_grid.drawGrid(1);
                    cout << "computer New Guess (ex. D4): ";
                    //random guess value
                    guess = getRandomGuess();
                    cout << "\nYour Updated Guesses:" << endl;
                    player1_grid.playerGuess(guess[0], guess[1]);
                    count++;
                }
            }

        }
    }
    else {
        cout << "You quit";        
    }
    cout << "\n\nThank you for playing." << endl;

    return 0;
}
