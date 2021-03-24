# AdaShipsRepo

## Read me file

Overall summary - Summary and review of the problem, overall proposed solution.
The task proposed in the document below is a clone of the of the classic game Battleships. This variation is called AdaShips which is a two-player game that can be played against a person or a computer. The aim of the game is to destroy all of the opponents placed ships before the ships you have placed on your board are destroyed. The game is won when one player has sunk all the other players ships. My initial proposal to the solution is to allow the player to setup his own board by placing multiple ships of different sizes. I would also need to generate a board which can be dynamically sized within a file containing the rules. The player would then need to fire a ‘torpedo’  at a specific coordinate which will be classified as a ‘hit’ or ‘miss’ depending on whether the ‘torpedo’ hits the opponent’s ships. A winner will then be decided when all of one player’s ships have been sunk by the other player. To destroy a ship the player would have to enter all the coordinates of a specific ship. The player would then need to be indicated of this on the console.

UML design which is in the power point
 

## Working Plan/Approach/Strategy/Quality control

The approach I took throughout the project was using a mix of mainly a waterfall approach which allowed me to complete tasks in a step by step fashion but also added some agile thinking when developing software and making changes to the code. This allows me to work in iterative cycles at certain stages of the project when approaching certain problems. Using an agile methodology also allowed me to make use of epics and stories when breaking down the problem into smaller tasks. When creating the software, I was able to ensure quality control by testing each piece of code after a specific task was completed. Testing the code allowed me to verify that each task is completed to the standards of the requirement. 
OOP design ideas and breakdown from epics to stories
### Epics 
-	Load Game Rules and Board.
-	Allow users and computer to place ships.
-	Allow users and computer to fire at ships.
-	Win conditions of the game. 
### Stories 
-	As a user, I want to start a game against a computer. 
-	As a user, I want to start a game against another player.
-	As a user, I want to place a ship on a board.
-	As a user, I want to fire a torpedo at an opponent’s board.
-	As a user, I want to be alerted when I win or lose the game.
-	As user, I want to know when a specific ship has been hit.
-	As user, I want to know when a specific ship has been fully destroyed.
Once I had a list of main epics and stories I broke these down into a list of tasks to create the main OOP design ideas and requirements

### OOP design ideas and tasks
-	Load game board and ships from a config file. 
-	The user should have the ability to change the size of the board and ships. 
-	Allow players to place ships of specific sizes on a board.
-	The player should be able to fire at the opponents ships on a turn by turn basis.
-	If the player hits or misses a ship they should be alerted.
-	If an opponent’s ship is hit or missed they should be alerted. 
-	If an opponent’s ship is destroyed they should be alerted. 
-	An overall scoreboard should be displayed throughout the game. 
-	When all ships are destroyed player either wins or loses.

## Task/Code Review and code changes 
An important design pattern used within the project is the Singleton pattern. This will ensure that there is only one instance of the class. This is important when loading the game board information from the ada_configs.ini file.
 

This an example function where the code reads the .ini file and uses a function I created within the file to split the text in the file. Once the text is split by a specific delimiter; in this case it is an equal sign
The ada_configs.ini file contains the game configurations. I then created methods to extract the height and width values of the board and the name and size of each ship from the config file. These values are then saved into structs. Using structs were useful as they allowed me to group specific information in collections and assign data to a specific struct. In this case information about the patrol boat is passed into the Patrol struct in two parts. 



## OOP
When creating most of the main functions for the game I added a new Board.cpp file. The writing of these functions outside of the main file allowed me to break down the code into smaller objects rather than one long line of code in the main function. Using classes and objects allowed me to utilise the OOP features. Using a constructor in the board.cpp when creating the functions for the board creation allows the constructor to always be called when I created the object for the class.

 

This allowed me to create different objects depending on the player playing the game. When two players play against each other the program will create  two objects. One for each player.
 

Above I created an object called player1_grid. This then allows me to access the drawgrid() method and within the for loop the placeShip() method. Both these methods are within the Board class. The first method (drawgrid(1)) in the code above draws the battleship grid and displays certain icons on the coordinates depending on their values. An example of this is when a coordinate is hit or missed. The parameter within the drawgrid method is either 1 or 0 depending on whether the parameter within the class showShips is equal to 1.

 
## Embedded Innovations
When showShips(param) param == 1 this displays the values of the ships you have placed on the board. When it is your turn to guess the coordinates of your opponent’s ships the parameter within show ships becomes zero. This then hides your opponent’s ships hence not giving away the coordinate values.

 


The code above is within the placeShip method inside the Board.cpp file. It is a key component in allowing a player or computer to place ships on the board. It is within the function below which takes four parameters that control the ships placement. Char y and char x control the coordinates of chosen to place the first point of the boat. The value from int length is passed depending on which ship is placed. If the ship length of the carrier is given as a parameter which has a length of 5 points, the size of the ship placed would be 5. One of the most innovative parts of the code is within the for loop in the image above. Depending on the length and heading which is the direction the ship coordinates would be placed from the original coordinate input. 

 

Using the example board above to explain this idea. If I wanted to place a ship at point A0 where the red X is located. The value of the heading value would be ‘W’ as a ship that is length 4 is four coordinates to the west of the points A0. Therefore, in the program when placing a ship, you format would be as such – A04.
Originally I was only able to place a single coordinate on to a board per users turn. The placeShip method has made it quicker and easier for a player to enter coordinates on the board.

## Quality when making changes and bugs 
Another issue I was able to resolve was creating a method that decided the outcome of a game once it had been completed. The code created for hand meant the user had to manually quit the game and a winner was not awarded. 
Using an object orientated approach allowed me to create an object and assign it to an integer value returned from a method within the Board class. The method which is called isLoser() returns the integer value 1.
The nested loop within the function checks through all the coordinates in the grid looking for the + symbol. This symbol in the grid represents the coordinates of a ships on the board. If there are no more ships left the if statement is exited and a value of 1 is returned. 
 

Using the object below to access the isLoser() method, if it is equal to the integer value of 1 the loop breaks and the game ends.

 

## Code Modularisation 
Another programming technique I had to take into account when creating this project was code modularisation which is the idea of separating code functionality into different class depending on the use of the code.
This is technique was displayed when creating the class containing the functionality relevant to the creation and use of the board at the start and during the game. This separation is important is it is easier to identify problems that need fixing in a specific area of the code. It also makes the code more testable and easier to read when incorporated with header folders. 












## Code Reuse // Random ship method – talk about finding random ship values 
I was able to reuse functions within the Board class, so the computer AI was able guess position of ships on the players board. The function getRandomGuess() displayed below allows the computer to generate a random coordinate on the board. It selects a random integer value between 0 and 9 then stores the value into char x.  A random letter is then stored within char y. I then concatenated the values into the string guess with is return. 

 

The code below show how the return string is used within the player guess method. The random string created is indexed and passed into playerGuess() function as a parameter. This functionality allows the computer AI to place random coordinates on the players grid.

 

This same method is reused in the code to allow the computer AI to place its ships on the board. In this case I created a function called getRandomShipPlacement() which passes randomly generated values into the parameters of the placeShip() function.





## Reflective Reviews 
During the course of the project I was able to work using an agile methodology, writing part of the code in iterations and improving on it with new information and ideas. I was able to implement the ADA Ships game where 2 human players are able to play against each other making use of functions that allow users to place, guess and target ships on a board. 
The interface implemented also allows the user to play against a computer AI who has the ability to place random ships and guess random coordinates on the players board. This part of the program is an area that I could improve due to the issues that arose when targeting and auto placing ships when it was the computer AIs turn to do so.
Another area where I could improve the projects is to make use of more advanced programming design patterns. The observer pattern could have been useful to notify the players of the changes of state that could occur while playing the game. An example of this would be when a user’s ship is fully destroyed. The state of this ship would then change therefore players of the game would be notified . I was able to make the user aware of the change in turn by outputting the name of the current player who’s turn it is using ‘cout’ but in certain instances other design patterns could have been affective.
Through this reflective review I was able to identify areas of development and more research into these area can be done to improve the quality of my code. 
