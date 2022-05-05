/* main.cpp
 *
 * This is the file that runs the program
 * It allows the player to specify the size of the board (x(row) by y(colums))
 * Options are provided to the player to perform various operations:
 * 1. move north (n), south (s), east (e) or west (w)
 * 2. pick up an item (p)
 * 3. drop an item (d)
 * 4. attack an enemy (a)
 * 5. print out information about current location (l)
 * 6. print out amount of of items the player is carrying and gold collect (i)
 * 7. exit the game (x)
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

#include "gameelement.h"
#include "board.h"
#include "race.h"
#include "human.h"
#include "elf.h"
#include "dwarf.h"
#include "orc.h"
#include "hobbit.h"
#include "Item.h"
#include "Weapon.h"
#include "Dagger.h"
#include "Shield.h"
#include "Ring.h"
#include "Armour.h"
#include "SmallShield.h"
#include "LargeShield.h"
#include "Plate.h"
#include "Sword.h"
#include "Leather.h"
#include "RingLife.h"
#include "RingStrength.h"

using namespace std;

char chooseRace(char raceCharacter);
void displayOptions();
void playGame(Race playerRace, int rowDimension, int columnDimension);
Race look(int totalRaceCount);

// initilize squares on the board
Board squares[1000];

int main(){
  
  // set the seed of the random number generator to the system clock
  srand(time(NULL));
  
  // character variable to store choice of player
  char player = 0;
  char playerValue = 0;

  // variables to store rows and columns of board initialized to zero
  int rowDimension = 0, columnDimension = 0;
  
  cout<< "Enter the dimensions of the board: \n";

  // check if parameters entered are valid
  // (either row or column cannot be less than 1)
  // for columns

  do{
    cout<< "Enter the number of columns (Must be greater than 0): ";
    cin>> columnDimension;
  } while (columnDimension < 1);

  // for rows
  do{
    cout<< "Enter the number of rows (Must be greater than 0): ";
    cin>> rowDimension;
  } while (rowDimension < 1);

  // initialize board dimensions to size of row and column dimensions
  // entered by player
  // to be change to GameElement type
  string board[rowDimension][columnDimension];

  int numberOfGameElements = rowDimension*columnDimension;
  GameElement gameElement[numberOfGameElements];
  //Board squares[numberOfGameElements];

  // static integer variable to index game elements on the board
  static int gameElementIndex = 0;

  // integer variable to hold random number generated from function
  int assignment = 0;

  // loop control variables to hold the dimensions (rows & colunms)  of the board
  int i, j; 
  for(i = 0; i < rowDimension; i++){
    for(j = 0; j < columnDimension; j++){
      
      // generate random integers between 0 and 1 inclusive
      assignment = rand()%2;

      // if number generated is 0, the square with row index i and column j
      // is not assigned a game element (empty)
      if(assignment == 0){
	
				board[i][j] = "Empty";
				//set square i, j to be empty
				gameElement[gameElementIndex].setLocation(i,j);
				gameElement[gameElementIndex].setElementType(0);
				squares[gameElementIndex].setElementType(0);
						} else{
	// number generated is 1, so the square with row index i and column j
	// is assigned a game element (race or item)
	// generate random integers between 0 and 1 to decide if the element is
	// an item or an enemy

	assignment = rand()%2;
	
	if(assignment == 0){
	  // if number generated is 0, the square with row index i and column j
	  // is assigned a race element

	  gameElement[gameElementIndex].setElementType(1);
	  squares[gameElementIndex].setElementType(1);
	  // generate random integers between 0 and 4 inclusive to randomly
	  // allocate race elements to the board square
	  // a human, an elf, a dwarf, an orc or a hobbit

	  assignment = rand()%5;
	  
	  if(assignment == 0){
	    // assign a human to the square
	    board[i][j] = "Human"; //human
	    gameElement[gameElementIndex].setLocation(i,j);
	  } else if(assignment == 1){
	    // assign an elf to the square
	    board[i][j] = "Elf"; //elf
	    gameElement[gameElementIndex].setLocation(i,j);
	  } else if(assignment == 2){
	    // assign a dwarf to the square
	    board[i][j] = "Dwarf"; //dwarf
	    gameElement[gameElementIndex].setLocation(i,j);
	  } else if(assignment == 3){
	    // assign an orc to the square
	    board[i][j] = "Orc"; //orc
	    gameElement[gameElementIndex].setLocation(i,j);
	  } else{
	    // assign a hobbit to the square
	    board[i][j] = "Hobbit"; //hobbit
	    gameElement[gameElementIndex].setLocation(i,j);
	  }
	} else{
	  // number generated is 1, the square with row index i and column j
	  // is assigned an item element

	  gameElement[gameElementIndex].setElementType(2);
	  squares[gameElementIndex].setElementType(2);
	  // generate random integers between 0 and 3 inclusive to randomly
	  // allocate an item element to the board square
	  // a weapon, an armour, a shield or a ring

	  assignment = rand()%4;
	  if(assignment == 0){
	    // assign a weapon to the square

	    // generate random integers between 0 and 1 inclusive to randomly
	    // allocate a weapon to the board square

	    assignment = rand()%2;
	    // if number generated is 0, the square with row index i and column
	    // j is assigned a sword
	    // else it is assigned a dagger
	    
	    if(assignment == 0){
	      // 
	      board[i][j] = "Sword"; //sword
	      gameElement[gameElementIndex].setLocation(i,j);
	    } else{
	      board[i][j] = "Dagger"; //dagger
	      gameElement[gameElementIndex].setLocation(i,j);
	    }
	  	} else if(assignment == 1){
	    // assign an armour to the square

	    // generate random integers between 0 and 1 inclusive to randomly
	    // allocate an armour to the board square

	    assignment = rand()%2;
	    // if number generated is 0, the square with row index i and column
	    // j is assigned a plate armour
	    // else it is assigned a leather armour
	    
	    if(assignment == 0){
	      // 
	      board[i][j] = "Plate Armour"; //plate armour
	      gameElement[gameElementIndex].setLocation(i,j);
	    } else{
	      board[i][j] = "Leather Armour"; //leather armour
	      gameElement[gameElementIndex].setLocation(i,j);
	    }
	  	} else if(assignment == 2){
	    // assign a shield to the square

	    // generate random integers between 0 and 1 inclusive to randomly
	    // allocate a shield to the board square

	    assignment = rand()%2;

	    // if number generated is 0, the square with row index i and column
	    // j is assigned a large shield
	    // else it is assigned a small shield
	    
	    if(assignment == 0){
	      // 
	      board[i][j] = "Large shield"; //large shield
	      gameElement[gameElementIndex].setLocation(i,j);
	    } else{
	      board[i][j] = "Small shield"; //small shield
	      gameElement[gameElementIndex].setLocation(i,j);
	    }
	  } else{
	    // assign a ring to the square
	    
	    // generate random integers between 0 and 1 inclusive to randomly
	    // allocate weapon item to the board square

	    assignment = rand()%2;

	    // if number generated is 0, the square with row index i and column
	    // j is assigned a ring of life
	    // else it is assigned a ring of strength
	    
	    if(assignment == 0){
	      // 
	      board[i][j] = "Ring of Life"; //life
	      gameElement[gameElementIndex].setLocation(i,j);
	    } else{
	      board[i][j] = "Ring of strength"; //strength
	      gameElement[gameElementIndex].setLocation(i,j);
	    }
	  }
	}
      }
      // increment gameElementIndex by 1 after an element has been assigned
      // to a square
      gameElementIndex ++;
      squares[gameElementIndex].setSquarePosition(i,j);
    }
  }

  for(i = 0; i < rowDimension; i++){
    for(j = 0; j < columnDimension; j++){
      cout<<"Number : "<<board[i][j]<<endl;
    }
  }

  playerValue = chooseRace(player);
  
  if(playerValue == '1'){
    Human playerRace;
    playGame(playerRace, rowDimension, columnDimension);
  } else if(playerValue == '2'){
    Elf playerRace;
    playGame(playerRace, rowDimension, columnDimension);
  } else if(playerValue == '3'){
    Dwarf playerRace;
    playGame(playerRace, rowDimension, columnDimension);
  } else if(playerValue == '4'){
    Orc playerRace;
    playGame(playerRace, rowDimension, columnDimension);
  } else if(playerValue == '5'){
    Hobbit playerRace;
    playGame(playerRace, rowDimension, columnDimension);
  } else{
    cout<<"Player value not found"<<endl;
  }


  
  return EXIT_SUCCESS;
}


/* void display()
 * The function takes no parameters
 * The function does not return anything (void)
 * 
 * The function provides a display of the various actions the player  can perform
 */
void displayOptions(){
  cout<<"\n\nPlease choose direction: "
      <<"N: North, "
      <<"S: South, "
      <<"E: East or "
      <<"W: West OR \n"
      <<"Choose a command: "
      <<"P: Pick, "
      <<"D: Drop, "
      <<"A: Attack, "
      <<"L: Look, "
      <<"I: Inventory or "
      <<"X: Exit\n";
}


/* void choosePlayer()
 * The function takes no parameters
 * The function returns the character the player entered
 * 
 * 
 */

char chooseRace(char raceCharacter){
  
  // variable to determine is entry of race  chosen by player is a valid choice
  bool raceValid = false;
  
  do{
    
    cout<<"\nPlease choose your character: "
      <<"\n(1) Human"
      <<"\n(2) Elf"
      <<"\n(3) Dwarf"
      <<"\n(4) Orc"
      <<"\n(5) Hobbit"
      <<"\nPlease enter 1-5: ";
    cin>>raceCharacter;
    
    switch(raceCharacter){
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
	raceValid = true;
	break;
      default:
	raceValid = false;
	cout<<"\nIllegal choice, please try again";
    }
  }  while (raceValid == false);
  
  return raceCharacter;
}


void playGame(Race playerRace, int rowDimension, int columnDimension){

  // create an object of the class board and set its maximum dimensions
  // rows and columns are used in obtaining the index of squares
  Board localSquare;
  localSquare.setMaxX(rowDimension);
  localSquare.setMaxY(columnDimension);
  
  // declare and initialize static variable to keep count of number of
  // commands player enters
  static int commandCount = 0;

  // variables to store coordinates of rows and columns of player on board
  // initialized to zero
  int rowCoordinate = 0, columnCoordinate = 0;
  
  // variable to store player's input initialized to 0
  char playerEntry = 0;
    
  // loops till user enters the exit character (x)
  do{
    
    playerRace.showPlayerInformation();
    // accept player input from the player

    // call display function to provide options for entry to player
    displayOptions();
    
    cin>> playerEntry;
    
    // perform operations on the game based on the player's input
    switch(playerEntry){
      // check if player entered either 'w' or 'W' (irrespective of the case)
      case 'w':
      case 'W':
	if(columnCoordinate > 0){
	  --columnCoordinate;
	  playerRace.setLocation(rowCoordinate, columnCoordinate);
	} else{
	  cout<<"Player cannot move west"<<endl;
	}
	break;
       
      // check if player entered either 'e' or 'E'
      case 'e':
      case 'E':
	if(columnCoordinate < (columnDimension-1) ){
	  ++columnCoordinate;
	  playerRace.setLocation(rowCoordinate, columnCoordinate);
	} else{
	  cout<<"Player cannot move east"<<endl;
	}
	break;

      // check if player entered either 's' or 's'
      case 's':
      case 'S':
	if(rowCoordinate < (rowDimension-1)){
	  ++rowCoordinate;
	  playerRace.setLocation(rowCoordinate, columnCoordinate);
	  cout<<"Attack chance: "<<playerRace.getAttackChance();
	  cout<<"Defense chance: "<<playerRace.getDefenseChance();
	} else{
	  cout<<"Player cannot move south"<<endl;
	}
	break;

      // check if player entered either 'n' or 'N'
      case 'n':
      case 'N':
	if(rowCoordinate > 0){
	  --rowCoordinate;
	  playerRace.setLocation(rowCoordinate, columnCoordinate);
	} else{
	  cout<<"Player cannot move north"<<endl;
	}
	break;

      // check if player entered either 'p' or 'P'
      case 'p':
      case 'P':
	cout<<"\nPick option chosen";
	//call Race::pick method
	int xCoordinate;
	int yCoordinate;
	xCoordinate = playerRace.getRowCoordinate();
	yCoordinate = playerRace.getColumnCoordinate();
	playerRace.pick(squares[localSquare.getSquareIndex(xCoordinate, yCoordinate)]);
	break;

      // check if player entered either 'd' or 'D'
      case 'd':
      case 'D':
	cout<<"\nDrop option selected";

	// integer variables to hold row and column coordinates of player
	//int xCoordinate;
	//int yCoordinate;

	// get the row and column coordinates of player and store in variables

	// check if player has an item to be dropped
	// if yes, allow player to choose
	// if not, notify player and ignore command
	xCoordinate = playerRace.getRowCoordinate();
	yCoordinate = playerRace.getColumnCoordinate();
	if (squares[localSquare.getSquareIndex(xCoordinate, yCoordinate)].look() == 0){
	  // square is empty and player can drop item
	  playerRace.drop();
	  // update square value
	} else{
	  cout<<"\nYou cannot drop an item at this location";
	  squares[localSquare.getSquareIndex(xCoordinate, yCoordinate)].look();
	}
        
	break;

      // check if player entered either 'a' or 'A'
      case 'a':
      case 'A':
	cout<<"\nAttack option selected";
	// should accept square.getElement() instead of playerRace;
	playerRace.combatRound(playerRace);
	break;

      // check if player entered either 'l' or 'L'
      case 'l':
      case 'L':
	cout<<"\nLook option selected";
	
	// integer variables to hold row and column coordinates of player
	//int xCoordinate;
	//int yCoordinate;
  
	// get the row and column coordinates of player and store in variables
	xCoordinate = playerRace.getRowCoordinate();
	yCoordinate = playerRace.getColumnCoordinate();
	squares[localSquare.getSquareIndex(xCoordinate, yCoordinate)].look();
	
	break;

      // check if player entered either 'i' or 'I'
      case 'i':
      case 'I':
	cout<<"\nInventory option selected";
	playerRace.inventory();
	break;
	
      // check if player entered either 'x' or 'X'
      case 'x':
      case 'X':
	cout<<"You're exiting the game...Thanks for playing!\n";
	break;
      
      default:
	cout<<"Invalid entry! You entered "<<playerEntry<<"\n";
        cout<<"Please make a valid choice from the  options\n";
    }
    // increment command count
    ++commandCount;
    playerRace.setCommandCount(commandCount);
    if((commandCount%5) == 0){
      playerRace.switchMode();
    }
  } while(playerEntry != 'x' && playerEntry != 'X');
  //allow player input till user chooses to exit or till the game ends
}
