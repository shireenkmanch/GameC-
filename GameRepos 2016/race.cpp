/*
 * race.cpp
 *
 * Class Race 
 * Base class from which human, elf, hobbit, orc and dwarf classes inherit
 * Defines methods for races
 * Inherits from the Board class
 *
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 25, 2016
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "race.h"
#include "gameelement.h"
#include "board.h"


/*
 * Race::Race()
 *
 * generic constructor for race
 * sets most attributes to 0 when the race object is created
 */
Race::Race(): attackValue( 0 ), defenseValue( 0 ), healthValue( 0 ), strengthValue( 0 ), countOfCommands( 0 ), weightCarried( 0 ), gold( 0 ), dayMode( true ), damageLevel( 0 ) {
  
  setElementType("Race");

}


// destructor
Race::~Race() {
}


/*
 * void Race::setName( string newName )
 *
 * mutator method for name
 * sets the value of private variable 'name' to the string provided as input
 *
 * input parameter: string
 * return type: void (nothing)
 *
 */

void Race::setName( string newName ) {
  
  name = newName;

}


/*
 * string Race::getName()
 *
 * accessor method for name
 * returns the value of the name of the race as a string
 * 
 * input parameter: void (nothing)
 * return type: string (name of race)
 *
 */
string Race::getName() {
  
  return name;

}


/*
 * void Race::setRaceType( int newRaceType )
 * mutator method for race type
 * sets the value of private variable 'raceType' to the integer provided as input
 *
 * input parameter: integer
 * return type: void (nothing)
 */
void Race::setRaceType( int newRaceType ) {
  
  raceType = newRaceType;

}


/*
 * int Race::getRaceType()
 * accessor method for race type
 * returns the value of the race type as an integer
 * return type: integer (type of race (0 - 4))
 * 0 = human
 * 1 = elf
 * 2 = dwarf
 * 3 = orc
 * 4 = hobbit
 * input parameter: void (nothing)
 *
 */
int Race::getRaceType() {
  
  return raceType;

}


/*
 * void Race::setAttackValue( int newAttackValue )
 * mutator method for attack
 * sets the value of private variable 'attackValue' to the integer provided as input
 *
 * input parameter: integer (attack value of race)
 * return type: void
 */
void Race::setAttackValue( int newAttackValue ) {
  
  attackValue = newAttackValue;

}


/*
 * int Race::getAttackValue()
 * accessor method for attack
 * returns the attack value of the race as an integer
 *
 * input parameter: void (nothing)
 * return type: integer (attack value of race)
 */
int Race::getAttackValue() {
  
  return attackValue;

}


/*
 * void Race::setAttackChance( int newAttackSuccess, int newTotalAttackProbability )
 * mutator method for attack chance
 * accepts two input parameters of integer value
 *
 * input parameters: integers (2)
 * newAttackSuccess - the number of success(es)
 * newTotalAttackProbability - the total number of events (success or failure)
 * return type: void (nothing)
 *
 * method is used to create the probability of a success or failure in an attack
 * a random seed is set by initializing the seed to a value by the system clock
 */
void Race::setAttackChance( int newAttackSuccess, int newTotalAttackProbability ) {
  
  /*
   * allow the computer to set the seed value of the random number
   * the seed value is set to the system's clock
   */
  srand(time(NULL));

  
  // assign input integer newAttackSuccess to attackSuccess
  attackSuccess = newAttackSuccess;

  
  // assign input integer newTotalAttackProbability to totalAttackProbability
  totalAttackProbability = newTotalAttackProbability;

  
  // loop-control variable declared and initialized to 0
  int i = 0;

  
  // create an array of booleans - the size of the array should be totalAttackProbability
  for(i = 0; i < totalAttackProbability; i++) {
    
    // populate the number of 'attackSuccess'es  with true
    if(i < attackSuccess) {
      
      attackProbability[i] = true;
      
    } else {
      
      // populate the remainder of the array with false
      attackProbability[i] = false;
      
    }
  }

  
  /*
   * use the random function from the C library to create a random number to use as index
   * the attackChance (true or false) is the value of the index of the array
   */
  attackChance = attackProbability[ rand() % totalAttackProbability ];
  
}



/*
 * bool Race::getAttackChance()
 *
 * calls the setAttackChance(int, int) method and returns the boolean value of its index
 * input parameter: void
 * return type: boolean (true or false)
 */
bool Race::getAttackChance() {
  
  /*
   * calls setAttackChance(int, int) method
   * allows a random value of success or failure to be set for each attack
   */
  setAttackChance( attackSuccess, totalAttackProbability );
  
  return attackChance;
  
}



/*
 * void Race::setDefenseValue( int newDefenseValue )
 * mutator method for defense
 * sets the value of private variable 'defenseValue' to the integer provided as input
 *
 * input parameter: integer (defense value of race)
 * return type: void
 */
void Race::setDefenseValue( int newDefenseValue ) {
  
  defenseValue = newDefenseValue;

}



/*
 * int Race::getDefenseValue()
 * accessor method for defense
 * returns the defense value of the race as an integer
 *
 * input parameter: void (nothing)
 * return type: integer (attack value of race)
 */
int Race::getDefenseValue() {
  
  return defenseValue;

}



/*
 * void Race::setDefenseChance( int newDefenseSuccess, int newTotalDefenseProbability )
 * mutator method for defense chance
 * accepts two input parameters of integer value
 *
 * input parameters: integers (2)
 * newDefenseSuccess - the number of success(es)
 * newTotalDefenseProbability - the total number of events (success or failure)
 * return type: void (nothing)
 *
 * method is used to create the probability of a success or failure in an attack
 * a random seed is set by initializing the seed to a value by the system clock
 */
void Race::setDefenseChance( int newDefenseSuccess, int newTotalDefenseProbability ) {
  
  /* allow the computer to set the seed value of the random number
   * the seed value is set to the system's clock
   */
  srand(time(NULL));

  
  // assign input integer newDefenseSuccess to defenseSuccess
  defenseSuccess = newDefenseSuccess;

  
  // assign input integer newTotalDefenseProbability to totalDefenseProbability
  totalDefenseProbability = newTotalDefenseProbability;

  
  // loop-control variable declared and initialized to 0
  int i = 0;

  
  // create an array of booleans - the size of the array should be totalDefenseProbability
  for(i = 0; i < totalDefenseProbability; i++) {
    
    if(i < defenseSuccess) {
      
      // populate the number of 'defenseSuccess'es  with true
      defenseProbability[i] = true;
      
    } else {
      
      // populate the remainder of the array with false
      defenseProbability[i] = false;
      
    }
  }
  
  /* use the random function from the C library to create a random number to use as index
   * the attackChance (true or false) is the value of the index of the array
   */
  defenseChance = defenseProbability[rand()%totalDefenseProbability];

}



/*
 * bool Race::getDefenseChance()
 *
 * calls the setDefenseChance( int, int ) method and returns the boolean value of its index
 * input parameter: void
 * return type: boolean (true or false)
 */
bool Race::getDefenseChance() {
  
  /* calls setDefenseChance( int, int ) method
   * allows a random value of success or failure to be set for each defense
   */
  setDefenseChance( defenseSuccess, totalDefenseProbability );
  
  return defenseChance;

}



/*
 * void Race::setHealthValue( int newHealthValue )
 * mutator for health value of the race class
 * updates the value of race health attribute by increasing health according to the integer
 *
 * input parameter: integer (health value of race)
 * return type: void
 */
void Race::setHealthValue( int newHealthValue ) {
  
  healthValue += newHealthValue;

}



/*
 * int Race::getHealthValue()
 * accessor method to retrieve health value of race
 *
 * input parameter: void
 * return type: integer (health value of race)
 */
int Race::getHealthValue() {
  
  return healthValue;

}



/*
 * void Race::setStrengthValue( int newStrengthValue )
 * mutator for setting strength value of the race class
 * strength value is affected according to the items picked up by player
 *
 * input parameter: integer (strength of race)
 * return type: void
 */
void Race::setStrengthValue( int newStrengthValue ) {
  
  strengthValue += newStrengthValue;

}



/*
 * int Race::getStrengthValue()
 * accessor method to retrieve strength value attribute
 * updates the value of race strength attribute by increasing strength according to the integer
 *
 * input parameter: void
 * return type: integer (strength value)
 */
int Race::getStrengthValue() {
  
  return strengthValue;

}



/*
 * void Race::setWeightCarried( int newWeightCarried )
 * mutator method for settinig weight carried by the race class
 * update race's weight attribute according to the value of items picked up by player
 *
 * input parameter: integer
 * return type: void
 */
void Race::setWeightCarried( int newWeightCarried ) {
  
  weightCarried += newWeightCarried;

}



/*
 * int Race::getWeightCarried()
 * accessor method to retrieve weight carried attribute
 * 
 * input parameter: void
 * returns type: integer
 */
int Race::getWeightCarried() {
  
  return weightCarried;

}



/*
 * void Race::showGameEnvironmentInformation()
 * method to print out information on the race location and time of day
 * 
 * input parameter: void
 * return type: void
 */
void Race::showGameEnvironmentInformation() {
  
  // get information from player calling method and print it out
  cout<<"\n\n["<<this->getRowCoordinate()<<"]["
      <<this->getColumnCoordinate()
      <<"] is the position on the board"
      <<"\nIt is "
      <<this->getModeOfDay()<<" ("
      <<this->getCommandCount()<<")\n";

}



/*
 * void Race::showPlayerInformation()
 * method to print out information on the race(s) in the game
 * 
 * input parameter: void
 * return type: void
 */
void Race::showPlayerInformation() {
  
  // get information from player calling method and print it out
  cout<<"\nPlayer: "<<this->getName()
      <<"; Attack = "<<this->getAttackValue()
      <<"; Defense = "<<this->getDefenseValue()
      <<"; Health = "<<this->getHealthValue()
      <<"; carrying "<<this->getWeightCarried()<< " of "<<this->getStrengthValue();

}



/*
 * void Race::setCommandCount( int count )
 * mutator methods to set the number of commands the user enters 
 * 
 * input parameter: integer
 * return type: void
 */
void Race::setCommandCount( int count ) {
  
  countOfCommands = count;

}



/*
 * int Race::getCommandCount()
 * accessor method to get the number of commands the player has entered as an integer
 *
 * input parameter: void
 * return type: int
 */
int Race::getCommandCount() {
  
  return countOfCommands;

}



/*
 * void Race::setElementCharacteristics()
 * sets characteristics of game element based on time of the day
 * input parameter: void
 * return type: void
 */
void Race::setElementCharacteristics() {
  
}



/*
 * void Race::setModeOfDay( bool newMode )
 * the method for sets the time of the day
 * newMode sets private variable dayMode to either true or false
 * if dayMode is true, it is day time. Else, it is night time
 * return type: void 
 * input parameter: boolean (newmode)
 */
void Race::setModeOfDay( bool newMode ) {
  
  if(newMode == true) {
    
    dayMode = true;

  } else {

    dayMode = false;

  }
}



/*
 * string Race::getModeOfDay()
 * the accessor method forthe time of the day
 *
 * input parameter: void
 * returns type: string (string is either 'Day' or 'Night')
 * 
 */
string Race::getModeOfDay() {
  
  // string variable to hold time of the day
  string timeOfDay;

  if(dayMode == true) {

    timeOfDay = "Day";

  } else {

    timeOfDay = "Night";

  }
  return timeOfDay;

}



/*
 * string Race::modeOfDay()
 * the method for gets the time of the day
 *
 * input parameter: void
 * returns type: boolean
 * 
 */
bool Race::modeOfDay() {
  
  //boolean variable to hold time of the day
  bool timeOfDay;

  if(dayMode == true) {
    
    timeOfDay = true;

  } else {

    timeOfDay = false;

  }
  return timeOfDay;

}



/* 
 * void Race::switchMode()
 * the method switches between the modes of the day (day and night)
 * 
 * input parameter: void
 * return type: void
 * 
 */
void Race::switchMode() {

  // string variable to hold the mode of the day 
  string checkModeOfDay;

  
  // get the mode of the day and store in string
  checkModeOfDay = getModeOfDay();

  
  if(checkModeOfDay == "Day") {
    
    // if the mode is day time, set mode to night
    setModeOfDay(false);

  } else {
    
    // if the mode is night time, set mode to day
    setModeOfDay(true);

  }
}



/*
 * void Race::setDagger()
 * method is called by Race::pick() method
 * used to assign objects to the null pointers
 * mutator methods to alter the values of races
 * (attack, health, strength and defence parameters - 
 * using the respective values from the dagger item carried)
 *
 * assign dagger object and update all attributes
 *
 * input parameter: void
 * return type: void
 *
 */ 
void Race::setDagger() {
  
  // store dagger object location in pointer
  pdagger= new Dagger;

  
  //add up to attack value
  this->attackValue+= pdagger->getAttackChange();

  
  //add up to defence value
  this->defenseValue+= pdagger->getDefenceChange();

  
  //add up to health value
  this->healthValue+= pdagger->getHealthChange();

  
  //add up to strength
  this->strengthValue+= pdagger->getStrengthChange();

  
  //add to weight carried
  this->weightCarried+= pdagger->getWeight();

}



/*
 * void Race::setSword()
 * method is called by Race::pick() method
 * used to assign objects to the null pointers
 * mutator methods to alter the values of races
 * (attack, health, strength and defence parameters - 
 * using the respective values from the sword item carried)
 *
 * assign sword object and update all attributes
 *
 * input parameter: void
 * return type: void
 *
 */ 
void Race::setSword() {
  
  //store an instance of sword
  psword=new Sword;

  
  //add up to attack value
  this->attackValue+= psword->getAttackChange();

  
  //add up to defence value
  this->defenseValue+= psword->getDefenceChange();

  
  //add up to health value
  this->healthValue+= psword->getHealthChange();

  
  //add up to strength
  this->strengthValue+= psword->getStrengthChange();

  
  //add to weight carried
  this->weightCarried+= psword->getWeight();

}



/*
 * void Race::setRingLife()
 * method is called by Race::pick() method
 * used to assign objects to the null pointers
 * mutator methods to alter the values of races
 * (attack, health, strength and defence parameters - 
 * using the respective values from the ring of life item carried)
 *
 * assign ring of life object and update all attributes
 *
 * input parameter: void
 * return type: void
 *
 */
void Race::setRingLife() {

  //store an instance of ring of life in the ringsCollected vector
  ringsCollected.push_back(RingLife());

  
  //add up to attack value
  this->attackValue+= RingLife().getAttackChange();

  
  //add up to defence value
  this->defenseValue+= RingLife().getDefenceChange();

  
  //add up to health value
  this->healthValue+= RingLife().getHealthChange();

  
  //add up to strength
  this->strengthValue+= RingLife().getStrengthChange();

  
  //add to weight carried
  this->weightCarried+= RingLife().getWeight();

}



/*
 * void Race::setRingStrength()
 * method is called by Race::pick() method
 * used to assign objects to the null pointers
 * mutator methods to alter the values of races
 * (attack, health, strength and defence parameters - 
 * using the respective values from the ring of strength item carried)
 *
 * assign ring of strength object and update all attributes
 *
 * input parameter: void
 * return type: void
 *
 */
void Race::setRingStrength() {

  //store an instance of Ring of strength in the ringsCollected vector
  ringsCollected.push_back(RingStrength());
  
  //pstrength=new RingStrength;

  
  //add up to attack value
  this->attackValue+= RingStrength().getAttackChange();

  
  //add up to defence value
  this->defenseValue+= RingStrength().getDefenceChange();

  
  //add up to health value
  this->healthValue+= RingStrength().getHealthChange();

  
  //add up to strength
  this->strengthValue+= RingStrength().getStrengthChange();

  
  //add to weight carried
  this->weightCarried+= RingStrength().getWeight();

}



/*
 * Race::deleteRing method
 * accesses the ringsCollected vector and deletes the requested ring type
 * receives string parameter containing ring type (strength or life)
 * returns bool to indicate success
 */
bool Race::deleteRing(string item) {
  
  /*
   * traverse through vector to find type of ring requested
   * if found use vector::erase() to delete
   * keep count of indices, using loop control variable i
   */

  //returned to indicate success or failure
  bool done=false;    

  
  cout<<ringsCollected.size()<<endl;

  
  for(unsigned int i=0; i<ringsCollected.size(); i++) {
    
    //if item matched any in the vector
    if(ringsCollected[i].getElementType()==item) {
	
      //erase element at that position
      ringsCollected.erase( ringsCollected.begin()+i );

      cout<<ringsCollected.size()<<endl;

      //set done to true; success
      done=true;

      //only delete one at a time
      break; 
		
    }		
  }

	
  /* now alter the attibutes respective to what 'item' contains
   * if ring of life
   */
  if( item == "Ring of Life" ) {

    //reduce weight	
    setWeightCarried( 0-RingLife().getWeight() );

    //reduce health value
    setHealthValue( 0-RingLife().getHealthChange() );
    
  }
  
  //if ring of strength
  else if( item == "Ring of Strength" ) {

    //reduce weight	
    setWeightCarried( 0-RingStrength().getWeight() );

    //reduce health value
    setHealthValue( 0-RingStrength().getHealthChange() );

    //reduce strength value
    setStrengthValue( 0-RingStrength().getStrengthChange() );

  }
  return done;
  
}



/*
 * void Race::setLeather()
 * method is called by Race::pick() method
 * used to assign objects to the null pointers
 * mutator methods to alter the values of races
 * (attack, health, strength and defence parameters - 
 * using the respective values from the leather armour item carried)
 *
 * assign leather armour object and update all attributes
 *
 * input parameter: void
 * return type: void
 *
 */
void Race::setLeather() {
	
  //new instance of leather armour
  pleather=new Leather;
	
  //add up to attack value
  this->attackValue+= pleather->getAttackChange();
	
  //add up to defence value
  this->defenseValue+= pleather->getDefenceChange();
  
  //add up to health value
  this->healthValue+= pleather->getHealthChange();
  
  //add up to strength
  this->strengthValue+= pleather->getStrengthChange();
  
  //add to weight carried
  this->weightCarried+= pleather->getWeight();

}

 

/*
 * void Race::setPlate()
 * method is called by Race::pick() method
 * used to assign objects to the null pointers
 * mutator methods to alter the values of races
 * (attack, health, strength and defence parameters - 
 * using the respective values from the plate armour item carried)
 *
 * assign plate armour object and update all attributes
 *
 * input parameter: void
 * return type: void
 *
 */
void Race::setPlate() {
	
  //instance of plate armour
  pplate= new Plate;
	
  //add up to attack value
  this->attackValue+= pplate->getAttackChange();
	
  //add up to defence value
  this->defenseValue+= pplate->getDefenceChange();
  
  //add up to health value
  this->healthValue+= pplate->getHealthChange();
  
  //add up to strength
  this->strengthValue+= pplate->getStrengthChange();
  
  //add to weight carried
  this->weightCarried+= pplate->getWeight();

}

 

/*
 * void Race::setLarge()
 * method is called by Race::pick() method
 * used to assign objects to the null pointers
 * mutator methods to alter the values of races
 * (attack, health, strength and defence parameters - 
 * using the respective values from the large shield item carried)
 *
 * assign large shield object and update all attributes
 *
 * input parameter: void
 * return type: void
 *
 */
void Race::setLarge() {
	
  plarge=new LargeShield;
	
  //add up to attack value
  this->attackValue+= plarge->getAttackChange();
	
  //add up to defence value
  this->defenseValue+= plarge->getDefenceChange();
  
  //add up to health value
  this->healthValue+= plarge->getHealthChange();
  
  //add up to strength
  this->strengthValue+= plarge->getStrengthChange();
  
  //add to weight carried
  this->weightCarried+= plarge->getWeight();
  
}


 
/*
 * void Race::setSmall()
 * method is called by Race::pick() method
 * used to assign objects to the null pointers
 * mutator methods to alter the values of races
 * (attack, health, strength and defence parameters - 
 * using the respective values from the small shield item carried)
 *
 * assign small shield object and update all attributes
 *
 * input parameter: void
 * return type: void
 *
 */
void Race::setSmall() {
	
  //pointer to instance of small shield
  psmall=new SmallShield;
	
  //add up to attack value	
  this->attackValue+= psmall->getAttackChange();
	
  //add up to defence value
  this->defenseValue+= psmall->getDefenceChange();
  
  //add up to health value
  this->healthValue+= psmall->getHealthChange();
  
  //add up to strength
  this->strengthValue+= psmall->getStrengthChange();
  
  //add to weight carried
  this->weightCarried+= psmall->getWeight();
  
}


 
/* 
 * void Race::setGold( int newGold )
 * mutator to increase the amount of gold carried by player
 *
 * input parameter: integer (value representing gold)
 * return type: void
 */
void Race::setGold( int newGold ) {
	
  //increase amount of gold present
  gold += newGold;

}

 

/* 
 * void Race::setGold( int newGold )
 * accessor to return the amount of gold carried by player
 *
 * input parameter: void
 * return type: integer (value amount of gold held by player)
 */
int Race::getGold() {
	
  return gold;

}


  
/*
 * bool Race::pick( string item )
 * only called in the main if there is an item to pick
 * allowed to pick if the square the player is on contains an item type
 *
 * return type: boolean 
 * input parameter: string (name of item at location)
 */
bool Race::pick( string item ) {
  
  // boolean variable to hold if item was picked or not, true if item is picked
  bool picked=true;
  
  /*
   * check if player can add on more weight
   * compare weightCarried attribute with strength of race		
   * if the weight carried exceeds the allowed, refuse option
   */
  if( getWeightCarried() >= strengthValue ) {
    
    cout<<"You strength doesn't allow you to carry this item!";

    // assign the value false to picked variable
    picked = false;

  }

  //if weight requirement is met perform the following
  else {
    
    /* allow addition of any number of Rings
     * otherwise check if another type of that item in the same category exists
     * if it is ring, pick up regardless
     * add the ring picked to ringCollected vector by calling the mutator methods
     */
    if( item == "Ring of Life" || item == "Ring of Strength" ) {
	
      //if ring of life, call appropriate mutator
      if( item == "Ring of Life" ) {
	    
	this->setRingLife();

      }

      //if ring of strength, do likewise
      else if( item == "Ring of Strength" ) {

	this->setRingStrength();

      }
    }
    else {
	
      /*
       * if any item apart from Ring
       * check if the object pointer is null
       * check if other pointer of the same type
       * if NULL, create the object, else exit
       */
      if( ( item == "Large Shield" ) && ( ( plarge == NULL ) && ( psmall==NULL ) ) ) {

	/*
	 * if neither shield type exists and request is for a large shield
	 * update large shield attribute
	 */        
	this->setLarge();

	    
	/* 
	 * now check if weight requirement is met
	 * If weight is exceeded, let player know
	 * delete the object
	 */
	if( getWeightCarried() >= strengthValue ) {
	      
	  //if the weight carried exceeds the allowed
	  cout<<"You cannot carry this item!";
								
	  //set the pointer back to NULL
	  plarge=NULL;
								
	  //change return value to false
	  picked=false;

	}						
      }

      else if( ( item == "Small Shield" ) && ( ( plarge == NULL ) && ( psmall==NULL ) ) ) {

	/* 
	 * if neither shield type exists and request is for a small shield
	 * update small shield attribute
	 */
	this->setSmall();

	    
	/* 
	 * now check if weight requirement is met
	 * If weight is exceeded, let player know
	 * delete the object
	 */
	if( getWeightCarried() >= strengthValue ) {
						
	  //if the weight carried exceeds the allowed
	  cout<<"You cannot carry this item!";
								
	  //return pointer to NULL
	  psmall=NULL;
								
	  //set return value to false
	  picked=false;
		
	}	
      }
	
      else if( ( item == "Leather Armour" ) && ( ( pleather == NULL ) && ( pplate == NULL ) ) ) {
	  
	/* 
	 * if neither armour type exists and the request is for a leather armour
	 * update the leather attribute
	 */
	this->setLeather();

	    
	/*
	 * now check if weight requirement is met
	 * If weight is exceeded, let player know
	 * delete the object
	 */
	if( getWeightCarried() >= strengthValue ) {
	      
	  //if the weight carried exceeds the allowed
	  cout<<"You cannot carry this item!";
								
	  // set leather attrib to NULL
	  pleather=NULL;
								
	  // set return value to false
	  picked=false;
		
	}	
      }
	
      else if( ( item == "Plate Armour" ) && ( ( pleather == NULL ) && ( pplate==NULL ) ) ) {
	  
	/*
	 * if neither armour type exists and the request is for a plate armour
	 * update plate attribute
	 */
	this->setPlate();

	    
	/*
	 * now check if weight requirement is met
	 * If weight is exceeded, let player know
	 * delete the object
	 */
	if( getWeightCarried() >= strengthValue ) {
	      
	  // if the weight carried exceeds the allowed
	  cout<<"You cannot carry this item!";
								
	  //set plate attrib to null
	  pplate=NULL;
								
	  //return false
	  picked=false;
		
	}	
      }
	
      else if( ( item == "Dagger" ) && (( pdagger == NULL ) && ( psword == NULL ) ) ) {

	/*
	 * if neither weapon type exists and the request is for a dagger
	 * update dagger attribute
	 */
	this->setDagger();

	    
	/*
	 * now check if weight requirement is met
	 * If weight is exceeded, let player know
	 * delete the object
	 */
	if( weightCarried >= strengthValue ) {
	      
	  //if the weight carried exceeds the allowed
	  cout<<"You cannot carry this item!";
		
	  //set dagger attribute to null
	  pdagger=NULL;
								
	  //retun false
	  picked=false;
		
	}	
      }
	
      else if( ( item == "Sword" ) && ( ( pdagger == NULL ) && ( psword == NULL ) ) ) {
	  
	/*
	 * if neither weapon type exists and the request is for a sword
	 * update sword attribute
	 */
	this->setSword();

	    
	/*
	 * now check if weight requirement is met
	 * If weight is exceeded, let player know
	 * delete the object
	 */
	if( getWeightCarried() >= strengthValue ) {
	      
	  // if the weight carried exceeds the allowed
	  cout<<"You cannot carry this item!";
								
	  //ser sword value to null
	  psword=NULL;
								
	  //set return value to false
	  picked=false;
		
	}	
      }
	
      //if neither requirement is met, alert player
      else {

	cout<<"You cannot carry this item!";

	//set return value to false
	picked=false;
	  
      }
	
    }
			
  }
  
  //return if pick() was succesful or not
  return picked;

}

 
  
/* 
 * string Race::drop()
 * return element type that was dropped
 *
 * input parameter: void
 * return type: string
 */
string Race::drop() {

  //char variable to hold user input
  char A;
	
  // string variable to return string to main
  string item;
	
  //call Race::inventory() to display player stash
  this->inventory();
	
  // print list out to user for item to drop
  cout<<"\nWhich item would you like to drop?: \n";
	
  // provide menu with choices
  cout<<"(D)agger\n(S)word\nRing of li(F)e\nRing of s(T)rength\n(P)late Armour\n(L)eather Armour\ns(M)all Shield \nLar(G)e Shield"<<endl;
	
  //accept user input and store in variable A
  cin>>A; 
	
  /*
   * make decisions about the drop
   * check if player carries that item
   * set object pointer of dropped item to null
   * change item variable to the element type for return
   */
  switch(A) {
    
  case 'D':
    //dagger

    
  case 'd':
    //if player doesnt carry item
    if(pdagger==NULL) {
      //set the item type to return to empty
      cout<<"You do not carry a dagger"<<endl;
      item="Empty";

    }
    else {

      //set the item type to return
      item="Dagger";

      //set object pointer to NULL
      this->pdagger=NULL;

      //reduce weight
      setWeightCarried(0-Dagger().getWeight());

      //reduce the attack value
      setAttackValue(0-Dagger().getAttackChange());

      cout<<"Dagger dropped"<<endl;

    }
    break;


  case 'S':
    //sword


  case 's':
    //if player does not carry item
    if( psword == NULL ) {
      //set the item type to return to empty
      item="Empty";
      cout<<"You do not carry a sword"<<endl;

    }
    else {

      //set the item type to return
      item="Sword";

      //set object pointer to NULL
      this->psword=NULL;

      //reduce weight
      setWeightCarried(0-Sword().getWeight());

      //reduce the attack value
      setAttackValue(0-Sword().getAttackChange());

      cout<<"Sword dropped"<<endl;

    }
    break;


  case 'F':
    //ring of life


  case 'f':
    //if the ring collection is empty
    if( ringsCollected.size() == 0 ) {
      //set the item type to return to empty
      item="Empty";
      cout<<"You do not carry a ring of life"<<endl;

    }
    else {

      //set the item type to return
      item="Ring of Life";

      //call method to delete ring from vector; and if true
      if( deleteRing( item ) == true ) {
	
	cout<<"Ring of life dropped"<<endl;

      }

    }
    break;


  case 'T':
    //ring of strength


  case 't':
    //if the ring collection is empty
    if( ringsCollected.size() == 0 ) {
      //set the item type to return to empty
      item="Empty";
      cout<<"You do not carry a ring of strength"<<endl;

    }
    else {

      //set the item type to return
      item="Ring of Strength";

      //call method to delete ring from vector; and if true
      if( deleteRing( item ) == true ) {
	
	cout<<"Ring of strength dropped"<<endl;

      }
    }
    break;


  case 'P':
    //plate armour


  case 'p':
    //if player doesnt carry item
    if(pplate==NULL) {
      //set the item type to return to empty
      item="Empty";
      cout<<"You do not carry a plate armour"<<endl;

    }
    else {

      //set the item type to return
      item="Plate Armour";

      //set object pointer to NULL
      this->pplate=NULL;

      //reduce weight
      setWeightCarried(0-Plate().getWeight());

      //reduce attack value
      setAttackValue(0-Plate().getAttackChange());

      //reduce defence value
      setDefenseValue(0-Plate().getDefenceChange());

      cout<<"Plate armour dropped"<<endl;

    }
    break;


  case 'L':
    //leather armour


  case 'l':
    //if player doesnt carry item
    if(pleather==NULL) {
      //set the item type to return to empty
      item="Empty";
      cout<<"You do not carry a leather armour"<<endl;

    }
    else {

      //set the item type to return
      item="Leather Armour";

      //set object pointer to NULL
      this->pleather=NULL;

      //reduce weight
      setWeightCarried(0-Leather().getWeight());

      //reduce attack value
      setAttackValue(0-Leather().getAttackChange());

      //reduce defence value
      setDefenseValue(0-Leather().getDefenceChange());

      cout<<"Leather armour dropped"<<endl;

    }
    break;


  case 'M':
    //small shield


  case 'm':
    //if player doesnt carry item
    if(psmall==NULL) {
      //set the item type to return to empty
      item="Empty";
      cout<<"You do not carry a small shield"<<endl;

    }
    else {

      //set the item type to return
      item="Small Shield";

      //set object pointer to NULL
      this->psmall=NULL;

      //reduce weight
      setWeightCarried(0-SmallShield().getWeight());

      //reduce defence value
      setDefenseValue(0-SmallShield().getDefenceChange());

      cout<<"Small shield dropped"<<endl;

    }
    break;

    
  case 'G':
    //large shield


  case 'g':
    //if player doesnt carry item
    if(plarge==NULL) {
      //set the item type to return to empty
      item="Empty";
      cout<<"You do not carry a large shield"<<endl;

    }
    else {

      //set the item type to return
      item=plarge->getElementType();

      //set object pointer to NULL
      this->plarge=NULL;

      setWeightCarried(0-LargeShield().getWeight());

      //reduce attack value
      setAttackValue(0-LargeShield().getAttackChange());

      //reduce defence value
      setDefenseValue(0-LargeShield().getDefenceChange());

      cout<<"Large shield dropped"<<endl;

    }
    break;

    
  default:

    //set the item type to return to empty
    item="Empty";
    
    cout<<"Cannot drop this item"<<endl;

  }

  return item;//return which item was dropped

}

 

/*
 * void Race::inventory()
 * prints out what character holds and amount of gold earned
 *
 * input parameter: void
 * return type: void
 */
void Race::inventory() {

  //number of rings of life
  int lifeCount=0;

  //number of rings of strength
  int strengthCount=0;
		
  cout<<"\nYou are carrying: ";
  
  /*
   * check each Item object contained in the class, 
   * if not NULL print out the respective statement
   */
  if( this->psword != NULL )
    cout<<"A sword\t";

  if( this->pdagger != NULL )
    cout<<"A dagger\t";

  if( this->pleather != NULL )
    cout<<"A leather armour\t";
  
  if( this->pplate != NULL )
    cout<<"A plate armour\t";
  
  if( this->psmall != NULL )
    cout<<"A small shield\t";
  
  if( this->plarge != NULL )
    cout<<"A large shield\t";

  
  /*
   * for the case of rings
   * check if the storage vectors size is 0(empty vector)
   */
  if( ringsCollected.size() > 0 ) {
    
    //if not empty, traverse through the vector with for loop
    for( unsigned int i=0; i<ringsCollected.size(); i++ ) {
	
      //case of ring of life
      if( ringsCollected[i].getElementType() == "Ring of Life" ) {

	//increase count of rings of life present
	lifeCount++;
      }
	  
      //case of ring of strength
      else if( ringsCollected[i].getElementType() == "Ring of Strength" ) {

	//increase count of rings of strength present
	strengthCount++;
	    
      }
    }
    
    //display the respective count
    cout<<strengthCount<<" ring(s) of strength\t";	

    cout<<lifeCount<<" ring(s) of life\t";	
	 	 
  }
	 
}

    

/*
 * void Race::attack()
 * 
 * computes the attack chance of the race element and updates the successfulAttack boolean
 *
 * input parameter: void
 * return type: boolean
 */
bool Race::attack() {

  // compute attack chance - returns true/ false
  if( this->getAttackChance() == true ) {
    
    cout<<"\n"<<getName()<<" attacked successfully";

    // set boolean variable successfulAttack to true
    successfulAttack = true;

  } else {
    
    cout<<"\n"<<getName()<<" failed attack";

    // set boolean variable successfulAttack to false
    successfulAttack = false;
  }
  return successfulAttack;
    
}


 
/*
 * void Race::defense()
 * 
 * computes the defense chance of the race element and updates the successfulDefense boolean
 *
 * input parameter: void
 * return type: boolean
 */
bool Race::defend() {

  // compute defense chance - returns true or false
  if( this->getDefenseChance() == true) {
    
    successfulDefense = true;

  } else {
    
    successfulDefense = false;

  }
  return successfulDefense;

}

  

/*
 * void Race::combatRound( Race * enemy )
 * 
 * method for a combat round:
 * sequence of activities: player attacks, enemy defends, enemy attacks, player defends 
 * (any of them could be successful or not)
 * 
 * input parameter: Race element pointer (Race * enemy)
 * return type: void
 */
void Race::combatRound( Race * enemy ) {

  int damage = 0;
  
  /*
   * player attacks enemy
   * attack method checks for probability of success 
   * stores value (true or false) in successfulAttack variable
   * initialize integer variable to store value of orc's defense
   */
  int orcSpecialDamage = 0;

  
  /*
   * if the attack method returns true, attack is successful and enemy enemy defends
   * else no need to defend
   */
  if( this->attack() == true) {
    
    /*
     * enemy defends against player
     * defend method checks for probability of success and returns true or false 
     */
    if( enemy->defend() == true ) {
      
      /* special race abilities
       * enemy is an orc and it is day
       */
      if( enemy->getSpecialRaceAbility() == 100 ) {
	
        /*
         * perform computations for damage
         * cast value to integer
         */
        orcSpecialDamage = static_cast <int> ( ( this->getAttackValue() - enemy->getDefenseValue())*0.25 );

	enemy->setHealthValue( -orcSpecialDamage );

      } else {

	// enemy is not an orc and/ or it is not day
        enemy->setHealthValue( enemy->getSpecialRaceAbility() );

      }
      
      if( this->getSpecialRaceAbility() == 100 ) {
	
        /*
         * if it is an orc at night, use the damage obtained from it's computation
         * store integer value in damage variable
         */
        damage = orcSpecialDamage;
          
      } else if( enemy->getSpecialRaceAbility() > 0 ) {

	/*
         * if the value obtained is greater than zero
         * the player has increased health and no damage
         */
        damage = 0;
        
      } else {

	// if the value obtained is less than zero, the player has that level of damage
        damage = -( enemy->getSpecialRaceAbility() );
	
      }

      cout<<"\n"<<enemy->getName()<<" defended successfully and takes "<<damage<<" damage";

    } else {

      /*
       * defender's health reduces (negative) by the difference between the
       * attacker's attack value and the enemy's defense value
       */
      enemy->setHealthValue(-( this->getAttackValue() - enemy->getDefenseValue() ) );

      cout<<"\n"<<enemy->getName()<<" failed defense and takes "
          <<(this->getAttackValue() - enemy->getDefenseValue())<<" damage";

    }
  }

  
  // the enemy attacks back nonetheless if its health has not reached 0 or less
  if( enemy->getHealthValue() > 0 ) {
    
    /*
     * enemy attacks player
     * attack method checks for probability of success 
     * returns true or false
     * if the attack is successful, then the player should defend
     */
    if( enemy->attack() == true ) {

      /*
       * player defends against enemy
       * defend method checks for probability of success 
       * stores value (true or false) in successfulDenfense variable
       */
      this->defend();


      // if the defense is successful, the check the special race abilties of the player
      if ( this->defend() == true ) {
	
	/*
         * check the player's special abilities
	 * if the special ability is > 0
	 * then it increases the player's health and there is no damage
	 * attacker is an orc and it is day
         */
        if( this->getSpecialRaceAbility() == 100 ) {
	  
          /*
           * perform computations for damage
           * cast value to integer
           */
          orcSpecialDamage = static_cast<int>( ( enemy->getAttackValue() - this->getDefenseValue())*0.25 );

	  this->setHealthValue( -orcSpecialDamage );

	} else {

	  // attacker is not an orc and/ or it is not day
          this->setHealthValue( this->getSpecialRaceAbility() );
	  
        }
        
        if( this->getSpecialRaceAbility() == 100 ) {
	  
          /*
           * if it is an orc at night, use the damage obtained from it's computation
           * store integer value in damage variable
           */
          damage = orcSpecialDamage;
          
        } else if( this->getSpecialRaceAbility() > 0 ) {
	  
          /*
           * if the value obtained is greater than zero
           * the player has increased health and no damage
           */ 
          damage = 0;
          
        } else {

	  // if the value obtained is less than zero, the player has that level of damage
          damage = -(this->getSpecialRaceAbility());

	}

	cout<<"\n"<<this->getName()<<" defended successfully and takes "<<damage<<" damage\n";
      
      } else{

	// defense was not successful, and the player's health reduces by attacker's value and defence value
	this->setHealthValue( -( enemy->getAttackValue() - this->getDefenseValue() ) );

	// print output to console
	cout<<"\n"<<this->getName()<<" failed defense and takes "
            <<(enemy->getAttackValue() - this->getDefenseValue())<<" damage\n";

      }
	
    } else {

      // attack was not successful and the player loses nothing. Nothing happens
    }
    
  } else {
    
    // the enemy's health has reached 0, the enemy is defeated
    cout<<"\n"<<this->getName()<<" has successfully defeated "<<enemy->getName()<<endl;
  }
    
  // print information to console
  this->showPlayerInformation();

  // show the enemy's information if it's health is still greater than 0 (it is still alive)
  if( enemy->getHealthValue() > 0 ) {
    
    enemy->showPlayerInformation();

  }
}


 
/*
 * void Race::setSpecialRaceAbility( int newDamageLevel )
 * mutator method for the effect of special race ability
 *
 * input parameter: integer (damage level to increase health)
 * return type: void
 */
void Race::setSpecialRaceAbility( int newDamageLevel ) {
  
  damageLevel = newDamageLevel;

}


 
/*
 * int Race::getSpecialRaceAbility()
 * accessor method for the effect of special race ability
 * input parameter: void
 * return type: integer (damage level to increase health)
 */
int Race::getSpecialRaceAbility() {
  
  return damageLevel;

}


 
/*
 * void Race::setGameElement( GameElement * newRace )
 * virtual mutator method to set the game element of a race
 *
 * input parameter: GameElement pointer (GameElement * newRace)
 * return type: void
 */
void Race::setGameElement( GameElement * newRace ) {
  
  race = newRace;

}


 
/*
 * GameElement * Race::getGameElement()
 * virtual accessor method to get the game element of a race
 * input parameter: void
 * return type: GameElement pointer (GameElement * newRace)
 */
GameElement * Race::getGameElement() {
  
  return race;

}
