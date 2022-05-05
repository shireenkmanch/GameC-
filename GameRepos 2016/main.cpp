/* 
 * main.cpp
 *
 * This is the file that runs the program
 * It allows the player to specify the size of the board ( x( row ) by y( columns ) )
 * Vector STL is used in the implementation of the board
 * 
 * On initialization of the game, the user is allowed to specify the size of the board
 * The game elements are then randomly created and placed on the squares of the board
 * stored in vector lists
 *
 * Options are provided to the player to perform various operations:
 * 1. Move north ( n ), south ( s ), east ( e ) or west ( w )
 * 2. Pick up an item ( p )
 * 3. Drop an item ( d )
 * 4. Attack an enemy ( a )
 * 5. Print out information about current location ( l )
 * 6. Print out amount of of items the player is carrying and gold collected ( i )
 * 7. Exit the game ( x )
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 15, 2016
 */


#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

#include "gameelement.h"
#include "board.h"
#include "empty.h"
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


/* 
 * char chooseRace( char raceCharacter )
 *
 * function to allow the player to choose which character to play the game with
 * parameter: character ( raceCharacter )
 * return type: char ( character )
 */
char chooseRace( char raceCharacter );


/*
 * void displayOptions();
 *
 * function to print out the character options available to the player
 * parameter: nothing
 * return type: void ( nothing )
 */
void displayOptions();


/*
 * void playGame( Race * playerRace, int rowDimension, int columnDimension, 
 * vector <vector< Board* >> squares )
 * 
 * parameters:
 * playerRace ( Race * ): point to variable of type Race to hold player object
 * rowDimension ( int ): variable of type integer to hold the row dimensions of the board
 * columnDimension ( int ): variable of type integer to hold the column dimensions of the board
 * squares( vector<vector< Board* >>): two dimensional vector ( STL container ) of type Board 
 * which hold the squares of the game board and contain the game elements
 *
 * function called to play the game
 * returns type: void ( nothing )
 */ 
void playGame( Race * playerRace, int rowDimension, int columnDimension, vector< vector< Board* > > squares );


/*
 * main function
 */
int main() {
  
  // set the seed of the random number generator to the system clock
  srand( time( NULL ));
  
  // player: character variable as input parameter for chooseRace() function
  // character value initialized to 0
  char player = 0;
  
  // playerValue: character variable to store choice of player race for game
  // character value initialized to 0
  char playerValue = 0;

  // integer variables to store player input rows and columns of board 
  // integer values initialized to zero
  int rowDimension = 0, columnDimension = 0;
  
  // display output on console to user
  cout<< "Enter the dimensions of the board: \n";

  // check if parameters entered are valid:
  // ( either row or column cannot be less than 1 )
  // the value entered must be an integer
  // do..while loops used to check the validity of player's input

  // boolean variable to store the state of validity of user input
  // if user input is not an integer, variable is false, else true
  // variable initialized to true
  bool checkUserEntry = true;
  
  // for columns

  do {

    cout<< "Enter the number of columns (Must be greater than 0): ";
    cin>> columnDimension;
    // check if the value entered is of a correct type (integer)
    // if not, return true, otherwise return false
    if (cin.fail()){
      // if not, alert the user
      cout<<"Wrong input!"<<endl
          <<"The value entered must be an integer"<<endl;
      // correct the stream and skip the left over stream data
      cin.clear();
      cin.ignore();

      // assign true to the variable check user entry if value is an integer
      checkUserEntry = true;
    } else{

      // assign false to the variable check user entry if value is an integer
      checkUserEntry = false;
    }

  } while (columnDimension < 1 || checkUserEntry == true);
  // if both conditions are met, the player can proceed
  // else, go back to meet conditions

  // for rows
  do {

    cout<< "Enter the number of rows (Must be greater than 0): ";
    cin>> rowDimension;
    // check if the value entered is of a correct type (integer)
    // if not, return true, otherwise return false
    if (cin.fail()){
      // if not, alert the user
      cout<<"Wrong input!"<<endl
          <<"The value entered must be an integer"<<endl;
      // correct the stream and skip the left over stream data
      cin.clear();
      cin.ignore();

      // assign true to the variable check user entry if value is not an integer
      checkUserEntry = true;
    } else{

      // assign false to the variable check user entry if value is an integer
      checkUserEntry = false;
    }

  } while ( rowDimension < 1 || checkUserEntry == true);
  // if both conditions are met, the player can proceed
  // else, go back to meet conditions



  // initialize board dimensions to size of row and column dimensions
  // entered by player
 
  // use STL vector to store 2D array of type Board
  // create vector of vectors (of type Board)
  // set size to dimensions entered by user
  // squares: point variable of type Board
  vector< vector< Board* > > squares( rowDimension, vector< Board* >( columnDimension, new Board ));  
	
  // STL vector to store other game elements on the board
  vector< vector< GameElement > > gameElement( rowDimension, vector< GameElement >( columnDimension,GameElement() ));

  vector< vector< string > > board( rowDimension, vector< string >( columnDimension,string() ));
  
  // integer variable to hold random number generated from function
  int assignment = 0;

  // loop control variables (unsigned integers)
  // variables hold the dimensions (rows & colunms) of the board
  unsigned int i;
  unsigned int j;
  
  /* loop is used in the assignment of game elements to various squares on the Board
   * the board has one of two states:
   * either (1) it is empty or (2) it contains an element (a race or an item)
   *
   * two random numbers are generated - 0 and 1
   * if the number is 0, the square is empty, else it contains an element
   * for the element could either be: (1) a race or (2) an item
   * random numbers are generated in nested loops in that order for allocations
   */
  
  for( i=0 ; i <squares.size(); i++ ) {

    for( j=0; j < squares[i].size(); j++ ) {
    
      // generate random integers between 0 and 1 inclusive
      assignment = rand()%2;

      // if number generated is 0, the square with row index i and column j
      // is empty
      if( assignment == 0 ) {

	//set square i, j to be empty
	gameElement[i][j] = Empty();
	squares[i][j] = new Empty();
	
      } else {

	// number generated is 1, so the square with row index i and column j
	// is assigned a game element (race or item)
	
	// generate random integers between 0 and 1 to decide if the element is
	// an item or an enemy
	assignment = rand()%2;
	
	if( assignment == 0 ) {

	  // if number generated is 0, the square with row index i and column j
	  // is assigned a race element
	  
	  gameElement[i][j] = Race();
	  squares[i][j] = new Race();
	  
          /* for the 5 available races in the game, generate random integers
           * numbers should be between 0 and 4 to decide the race
           * 0 = human
           * 1 = elf
           * 2 = dwarf
           * 3 = orc
           * 4 = hobbit
           */
	  assignment = rand()%5;
	  
	  if( assignment == 0 ) {
	  
	    // assign a human to the square
	    
	    gameElement[i][j] = Human();
	    squares[i][j] = new Human();
	    
	  } else if( assignment == 1 ) {
	  
	    // assign an elf to the square
	    
	    gameElement[i][j] =  Elf();
	    squares[i][j] = new Elf();
	    
	  } else if( assignment == 2 ) {
	  
	    // assign a dwarf to the square
	    
	    gameElement[i][j] = Dwarf();
	    squares[i][j] = new Dwarf();
	    
	  } else if( assignment == 3 ) {
	  
	    // assign an orc to the square
	    
	    gameElement[i][j] = Orc();
	    squares[i][j] = new Orc;
	    
	  } else {
	    // assign a hobbit to the square
	    
	    gameElement[i][j] = Hobbit();
	    squares[i][j] = new Hobbit();
	    
	  }
	} else {
	  // number generated is 1, the square with row index i and column j
	  // is assigned an item element

	  gameElement[i][j] = Item();
	  squares[i][j] = new Item();
	  
	  /* generate random integers between 0 and 3 inclusive to randomly
	   * allocate an item element to the board square
	   * 0 = weapon
	   * 1 = armour
	   * 2 = shield
	   * 3 = ring
	   */
	  assignment = rand()%4;
	  
	  if( assignment == 0 ) {
	    // assign a weapon to the square

	    /* generate random integers between 0 and 1 inclusive to randomly
	     * allocate a weapon to the board square
	     * 0 = sword
	     * 1 = dagger
	     */
	     
	    assignment = rand()%2;
	    
	    /* if number generated is 0, the square with row index i and column
	     * j is assigned a sword
	     * else, it is assigned a dagger
	     */
	     
	    if( assignment == 0 ) {
	    
	      // assign a sword
	      
	      gameElement[i][j] = Sword();
	      squares[i][j] = new Sword();
	      
	    } else {
	    
	      // assign a dagger
	      
	      gameElement[i][j] = Dagger();
	      squares[i][j] = new Dagger();
	    }
	  } else if( assignment == 1 ) {
	  	
	    // assign an armour to the square

	    /* generate random integers between 0 and 1 inclusive to randomly
	     * allocate an armour to the board square
	     * if 0 the square with row index i and column is assigned a plate armour
	     * else, assign a leather armour
	     */
	    assignment = rand()%2;
	    
	    if( assignment == 0 ) {
	    
	      // assign a plate armour
	      
	      gameElement[i][j] = Plate();
	      squares[i][j] = new Plate();
	      
	    } else {
	    
	      // assign a leather armour
	      
	      gameElement[i][j] = Leather();
	      squares[i][j] = new Leather();
	      
	    }
	  } else if( assignment == 2 ) {

	    // assign a shield to the square

	    /* generate random integers between 0 and 1 inclusive to randomly
	     * allocate a shield to the board square
	     * if the number is 0, the square with row index i and column j
	     * is assigned a large shield
	     * else, it is assigned a small shield
	     */
	    assignment = rand()%2;
	    
	    if( assignment == 0 ) {
	    
	      // assign a large shield
	      
	      gameElement[i][j] = LargeShield();
	      squares[i][j] = new LargeShield();

	    } else {
	    
	      // assign a small shield
	      
	      gameElement[i][j] = SmallShield();
	      squares[i][j] = new SmallShield();
	      
	    }

	  } else {
	    // assign a ring to the square
	    
	    /* generate random integers between 0 and 1 inclusive to randomly
	     * allocate weapon item to the board square
	     * if the number is 0, the square with row index i and column j
	     * is assigned a ring of life
	     * else, it is assigned a ring of strength
	     */
	    assignment = rand()%2;
	    
	    if( assignment == 0 ) {

	      // assign ring of life
	      gameElement[i][j] = RingLife();
	      squares[i][j] = new RingLife();
	      
	    } else {

	      // assign ring of strength

	      gameElement[i][j] = RingStrength();
	      squares[i][j] = new RingStrength();

	    }

	  }

	}

      }

      gameElement[i][j].setLocation(i,j);
      //cout<<"\nSquare Allocations: "<<squares[i][j]->getElementType();

    }

  }
  

  // call chooseRace(char) function for player to choose the race to play with
  // store character choice of player in character variable playerValue
  playerValue = chooseRace( player );
  
  // depending on choice of player, assign the corresponding race character
  // then call playGame(Race *, int, int, vector< vector< Board * > >) function
  
  if( playerValue == '1' ) {

    Human * playerRace = new Human();
    playGame(playerRace, rowDimension, columnDimension, squares);

  } else if( playerValue == '2' ) {

    Elf * playerRace = new Elf();
    playGame( playerRace, rowDimension, columnDimension, squares );

  } else if( playerValue == '3' ) {

    Dwarf * playerRace = new Dwarf();
    playGame( playerRace, rowDimension, columnDimension, squares );

  } else if( playerValue == '4' ) {

    Orc * playerRace = new Orc();
    playGame( playerRace, rowDimension, columnDimension, squares );

  } else if( playerValue == '5' ) {

    Hobbit * playerRace = new Hobbit();
    playGame( playerRace, rowDimension, columnDimension, squares );

  } 
  
  // exit main
  return EXIT_SUCCESS;
}


/* 
 * void display()
 *
 * The function takes no parameters
 * return type: void (nothing)
 * 
 * The function provides a display of the various choices the player can make
 */
void displayOptions() {

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


/* 
 * void choosePlayer()
 *
 * The function accepts an input parameters: 
 * raceCharacter: (char) this is the value entered by the user at the console
 *
 * The function returns the character the player entered
 * 
 */
char chooseRace( char raceCharacter ) {
  
  // boolean variable to determine is entry of race chosen by player is a valid choice
  // variable initialized to false (not a valid choice)
  bool raceValid = false;
  
  // loop to run at least once to allow for user input
  // allows user to enter an input till valid, then raceValid variable becomes true
  
  do {
    
    cout<<"\nPlease choose your character: "
      <<"\n(1) Human"
      <<"\n(2) Elf"
      <<"\n(3) Dwarf"
      <<"\n(4) Orc"
      <<"\n(5) Hobbit"
      <<"\nPlease enter 1-5: ";
    cin>>raceCharacter;
    
    // switch control to allow response of user input
    // if input is between 1 and 5 inclusive, input is valid
    // raceValid variable becomes true and the loop exits
    // else the user is allowed to enter an input over and over again till valid
    switch( raceCharacter ) {

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
  
  // returns a value raceCharacter of the player's valid input
  return raceCharacter;

}


/* 
 * void playGame( Race * playerRace, int rowDimension, int columnDimension, 
 * vector <vector<Board*>> squares )
 * 
 * function called to play the game
 * returns type: void ( nothing )
 *
 * accepts parameters:
 *
 * playerRace (Race * ): pointer variable of type Race to hold player object
 * rowDimension (int): variable of type integer to hold the row dimensions of the board
 * columnDimension (int): variable of type integer to hold the column dimensions of the board
 * squares( vector< vector< Board* > > ): two dimensional vector (STL container) of type Board 
 * which hold the squares of the game board and contain the game elements
 *
 * the function calls various methods from the various classes in the project depending
 * on the input of the user
 *
 * player enters an input ( n, s, e, w, a, d, p, l, i, x ) corresponding to various commands
 * (north, south, east, west ( navigation ) and attack, drop, pick, look, inventory and exit)
 * irrespective of the case ( upper or lower ) entered by the user, the program processes it
 * and does a corresponding action
 *
 * the user cannnot navigate outside the dimensions of the board 
 * a warning is issued in such a case
 *
 * the game ends when a player's health reaches 0
 * 
 */
void playGame( Race * playerRace, int rowDimension, int columnDimension, vector< vector<Board* > > squares ) {
  
  // static integer variable declared and initialized to 0 
  // used to keep count of number of commands player enters
  static int commandCount = 0;
  
  // integer variables to store coordinates of rows and columns of player on board
  // initialized to zero
  int rowCoordinate = 0, columnCoordinate = 0;

  // initialize the player's position to the starting square at the start
  // the starting square is (0,0)
  playerRace->setLocation(rowCoordinate, columnCoordinate);
  
  // variable to store player's input initialized to 0
  char playerEntry = 0;
  
  // string to store element type in current square
  string type; 
    
  // loops till user enters the exit character ('x' or 'X' ) or player health is 0
  // run at least once
  
  do {
  
    // set command count in Race::setCommandCount( int ) method
    playerRace->setCommandCount( commandCount );

    // show the game environment information ( time of day and coordinates of player )
    playerRace->showGameEnvironmentInformation();
    
    // show player information
    playerRace->showPlayerInformation();

    // call display function to provide options for entry to player
    displayOptions();
    
    // allow player input (accepts one character)
    cin>> playerEntry;
    
    // perform operations on the game based on the player's input
    switch( playerEntry ) {

      // check if player entered either 'w' or 'W'
      case 'w':
      case 'W':

      // check if the column coordinate is greater than 0
      // if yes, allow the player and set the new coordinates
	if( columnCoordinate > 0 )  {

	  --columnCoordinate;
	  playerRace->setLocation( rowCoordinate, columnCoordinate );
	} else {

	  // if not, the player cannot move to that direction
	  cout<<"Player cannot move west"<<endl;

	}

	break;
      
 
      // check if player entered either 'e' or 'E'
      case 'e':
      case 'E':

      // check if the row coordinate is greater 
      // than the maximum row dimension of the board
      // if yes, allow the player and set the new coordinates
      // if not, the player cannot move to that direction
	if( columnCoordinate < ( columnDimension-1 ) ) {

	  ++columnCoordinate;
	  playerRace->setLocation( rowCoordinate, columnCoordinate );
	} else {

	  // if not, the player cannot move to that direction
	  cout<<"Player cannot move east"<<endl;

	}

	break;


      // check if player entered either 's' or 's'
      case 's':
      case 'S':

      // check if the column coordinate of the player
      // is greater than the maximum column dimension of the board
      // if yes, allow the player and set the new coordinates
	if( rowCoordinate < ( rowDimension-1 ) ) {

	  ++rowCoordinate;
	  playerRace->setLocation(rowCoordinate, columnCoordinate);
	} else {

	  // if not, the player cannot move to that direction
	  cout<<"Player cannot move south"<<endl; 

	}

	break;


      // check if player entered either 'n' or 'N'
      case 'n':
      case 'N':

      // check if the row coordinate is greater than 0
      // if yes, allow the player and set the new coordinates
	if( rowCoordinate > 0 ) {

	  --rowCoordinate;
	  playerRace->setLocation( rowCoordinate, columnCoordinate );
	} else {

	  // if not, the player cannot move to that direction
	  cout<<"Player cannot move north"<<endl;
	}

	break;


      // check if player entered either 'p' or 'P'
      case 'p':
      case 'P':

	cout<<"Picking..."<<endl;

	// call Race::pick method
 
        // integer variables to store coordinates of player's current position
	int xCoordinate;
	int yCoordinate;

        // boolean variable to check if picking was successful (true) or not (false)
	bool picked; 

	// player's current row
	xCoordinate = playerRace->getRowCoordinate();
	// player's current column
	yCoordinate = playerRace->getColumnCoordinate();
	type=squares[xCoordinate][yCoordinate]->getElementType();
	// check if element in current square is an item
	// if so call Race::pick() method
	if( type=="Human"||type=="Dwarf"||type=="Orc"||type=="Hobbit"||type=="Elf"||type=="Empty" ) {
	  cout<<"You cannot pick from this square";

	} else {
	  // store boolean value returned by pick()
	  picked=playerRace->pick( squares[xCoordinate][yCoordinate]->getElementType() );
	}

	// if item was picked( picked==true ), set current square to empty
	if( picked==true ) {

	  squares[xCoordinate][yCoordinate]= new Empty();	

	}
	
	break;


      // check if player entered either 'd' or 'D'
      case 'd':
      case 'D':

	cout<<"Dropping..."<<endl;

	// get the row and column coordinates of player and store in variables
	// players current row
  	xCoordinate = playerRace->getRowCoordinate();
  	// players current column
	yCoordinate = playerRace->getColumnCoordinate();	
	// check if the square is empty
	if( squares[xCoordinate][yCoordinate]->getElementType()!="Empty" ) {

	  cout<<"You cannot drop an item here!"<<endl;

	} else {

	  // if the square is empty, allow the player to choose the item to drop; call drop()
	  
	  // drop returns a string; use string to set element in the square
	  // string variable to store item that was dropped in the method drop()
	  string dropped; 

	  // call drop() and return element type
	  dropped=playerRace->drop();

	  // assign the current square the object that was dropped
	  squares[xCoordinate][yCoordinate]->setElementType(dropped);
	}
	        
	break;


      // check if player entered either 'a' or 'A'
      case 'a':
      case 'A':

	cout<<"Attacking..."<<endl;

        // check the player's coordinates and store in integer variables
	xCoordinate = playerRace->getRowCoordinate();
	yCoordinate = playerRace->getColumnCoordinate();
	
	// check if the square of the player's coordinates contains a race 
	// if yes, player can attack
	if ( squares[xCoordinate][yCoordinate]->getElementType() == "Human" || 
	squares[xCoordinate][yCoordinate]->getElementType() == "Elf" || 
	squares[xCoordinate][yCoordinate]->getElementType() == "Dwarf" ||
	squares[xCoordinate][yCoordinate]->getElementType() == "Orc" ||
	squares[xCoordinate][yCoordinate]->getElementType() == "Hobbit" ) {
 
	  // cast Board * to Race pointer type and pass to Race::combatRound(Race) method
	  // a round is initiated
	  // method Race::combatRound(Race) is called
	  // method takes a race object
	  // item square is carrying is casted to a race object
	  playerRace->combatRound( dynamic_cast<Race*>( squares[xCoordinate][yCoordinate] ) );
	  
	  // if the enemy's health reaches 0, the enemy is removed from board
	  // player's gold increases according to amount gained from enemy's defense value
	  if( dynamic_cast<Race*>( squares[xCoordinate][yCoordinate] )->getHealthValue() <= 0 ) {

	    // add player's defense value to inventory
	    playerRace->setGold(dynamic_cast<Race*>( squares[xCoordinate][yCoordinate])->getDefenseValue() );
	    // print out alert to the player
	    cout<<"\nCongratulations, you killed "
		<<dynamic_cast<Race*>(squares[xCoordinate][yCoordinate])->getName()
		<<" and earned "<<dynamic_cast<Race*>( squares[xCoordinate][yCoordinate])->getDefenseValue()
		<<" gold pieces"<<endl;
	    dynamic_cast<Race*>(squares[xCoordinate][yCoordinate])->showPlayerInformation();
	    // set square to empty
	    squares[xCoordinate][yCoordinate] = new Empty();

	  }

	} else {

	  // square does not contain a race, notify player
	  cout<<"\nLocation does not contain a race."
	      <<"\nYou cannot attack at this location";

	}

	break;


      // check if player entered either 'l' or 'L'
      case 'l':
      case 'L':
	cout<<"Looking..."<<endl;
  
	// get the current row and column coordinates of player and store in variables
	xCoordinate = playerRace->getRowCoordinate();
	yCoordinate = playerRace->getColumnCoordinate();
	
	// if square is empty, notify player
	if ( squares[xCoordinate][yCoordinate]->getElementType() == "Empty" ) {

	  cout<<"\nThis location is empty"<<endl;

	} else {
 
	// notify player of the element on the square
	  cout<<"\nLocation contains a(n) "<<squares[xCoordinate][yCoordinate]->getElementType();

	}

	break;


      // check if player entered either 'i' or 'I'
      case 'i':
      case 'I':

	cout<<"Checking Inventory..."<<endl;

        // call Race::inventory()
	playerRace->inventory();

	break;
	

      // check if player entered either 'x' or 'X'
      case 'x':
      case 'X':

        // alert the player of the amount of gold collected
        cout<<"\nThe amount of gold you earned is "<<playerRace->getGold()<<" pieces"<<endl;
	cout<<"You're exiting the game...Thanks for playing!\n";

	break;
      

      default:

	cout<<"Invalid entry! You entered "<<playerEntry<<"\n";
        cout<<"Please make a valid choice from the  options\n";
 
    }

    // increment command count
    ++commandCount;
    
    // for every 5 commands, the value sets to 0 and the mode is shifted
    // ( day to night or vice versa )
    if( ( commandCount%5 ) == 0 ) {

      // switch mode from night to day or day to night
      playerRace->switchMode();
      
      // set special race abilities for races with special abilities at different times
      // orc benefits from this method
      // other races do no have special abilities and method does not implement any difference
      playerRace->setElementCharacteristics();

      
      // loop control integer variables i and j initialized to 0
      int i = 0; 
      int j = 0;
      
      // set board to night mode so elements with special characteristics change attributes
      for ( i = 0; i < rowDimension; i ++ ) {

        for ( j = 0; j < columnDimension; j ++ ) {
        
          // check if square contains orc
          // if yes, set alternate mode for special attributes
          if ( squares[i][j]->getElementType() == "Orc" ) {

            // set orc's special attributes based on time of the day
            squares[i][j]->setElementCharacteristics();

          } 

          // else do nothing

        }

      }
 
    }
    
    // for every option selected by player, check if player's health is <= 0
    if( playerRace->getHealthValue() <= 0 ) {

    // if yes, print the amount of gold earned and end the game
      cout<<"\nGame over. "<<playerRace->getName()<<"\'s health has reached 0"
          <<"\nThe amount of gold you earned is "
	  <<playerRace->getGold()<<" pieces"<<endl;
    }

  } while( playerEntry != 'x' && playerEntry != 'X' && playerRace->getHealthValue() > 0 );
  // allow player input till player chooses to exit or till the game ends
  // or player's health reaches 0

}
