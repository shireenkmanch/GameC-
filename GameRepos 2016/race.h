/*
 * race.h
 *
 * Base class header file from which all other races will be derived
 * Shared attributes and methods for all other derived classes are declared
 * Declares attributes and methods for races
 * Inherits from the Board class
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 15, 2016
 */


#ifndef RACE_H
#define RACE_H

#include "gameelement.h"
#include "board.h"
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
#include <string>

using namespace std;


class Race: public Board {

 // Methods for race class are declared in public section
 public:

  /*
   * general constructor
   * initializes the value of health, weight and other attributes of type Race
   */
  Race();
  
  /*
   * destructor 
   * deletes pointers created for Item classes
   */
  ~Race();
  
  /*
   * mutator method for name
   * input parameter: string
   * return type: void (nothing)
   */
  void setName( string newName );

  /*
   * accessor method for name
   * input parameter: void (nothing)
   * return type: string (name of race)
   */
  string getName();

  /*
   * mutator method for race type
   * input parameter: integer
   * return type: void (nothing)
   */
  void setRaceType( int newRaceType );

  /*
   * accessor method for race type
   * return type: integer (type of race (0 - 4))
   * input parameter: void (nothing)
   */
  int getRaceType();
  
  /*
   * mutator method for attack
   * input parameter: integer (attack value of race)
   * return type: void
   */
  void setAttackValue( int newAttackValue );
  
  /*
   * accessor method for attack
   * input parameter: void (nothing)
   * return type: integer (attack value of race)
   */
  int getAttackValue();

  /*
   * mutator method for attack chance
   * input parameters: integers (2)
   * attackSuccess - the number of success(es)
   * totalProbability - the total number of events (success or failure)
   * return type: void (nothing)
   */
  void setAttackChance( int attackSuccess, int totalProbability );
  
  /*
   * accessor method for attack chance
   * return type: boolean (the attack chance value as true or false)
   * a true value denotes the attack is successful
   * a false value denotes the attack is unsuccessful
   * input parameter: void (nothing)
   */
  bool getAttackChance();

  /*
   * mutator method for defense
   * input parameter: integer (defense value of race)
   * return type: void (nothing)
   */
  void setDefenseValue( int newDefenseValue );
  
  /*
   * accessor method for defense
   * input parameter: void (nothing)
   * return type: integer (defense value of race)
   */
  int getDefenseValue();
  
  /*
   * mutator method for attack chance
   * input parameters: integers (2)
   * defenseSuccess - the number of success(es)
   * totalProbability - the total number of events (success or failure)
   * return type: void (nothing)
   */
  void setDefenseChance( int defenseSuccess, int totalProbability );
  
  /*
   * accessor method for defense chance
   * return type: boolean (true or false denoting success or failure)
   * a true value denotes the defense is successful
   * a false value denotes the defense is unsuccessful
   * input parameter: void (nothing)
   */
  bool getDefenseChance();

  /*
   * mutator method for health
   * input parameter: integer (health value of race)
   * return type: void (nothing)
   */
  void setHealthValue( int newHealthValue );
  
  /*
   * accessor method for health
   * input parameter: void (nothing)
   * return type: integer (value of health of race)
   */
  int getHealthValue();

  /*
   * mutator method for strength
   * input parameter: integer
   * return type: void
   */
  void setStrengthValue( int newStrengthValue );
  
  /*
   * accessor method for strength
   * input parameter: void (nothing)
   * return type: integer (strength value of race)
   */
  int getStrengthValue();

  /*
   * prints out the information of the player location and time of day
   * input parameter: void 
   * return type: void
   */ 
  void showGameEnvironmentInformation();
  
  /*
   * function to print out the race information
   * input parameter: void 
   * return type: void 
   */
  void showPlayerInformation();
  
  /*
   * sets characteristics of a game element based on time of the day
   * input parameter: void
   * return type: void
   */
  virtual void setElementCharacteristics();

  /*
   * mutator method to set the number of times the player issues a command
   * input parameter: integer (value of number of times player has chosen an option)
   * return type: void
   */
  void setCommandCount( int count );

  /*
   * accessor method for strength
   * input parameter: void
   * return type: integer (the number of commands the player has entered so far)
   */
  int getCommandCount();

  /*
   * mutator method to set the mode of the day (day or night)
   * input parameter: boolean (true for day, false for night)
   * return type: void
   */
  void setModeOfDay( bool newMode );

  /*
   * accessor method for the mode of the day (day or night)
   * input parameter: void
   * return type: string (Day or Night)
   */
  string getModeOfDay();
  
  /*
   * accessor method for the mode of the day (day or night)
   * input parameter: void
   * return type: boolean (Day -true or Night - false)
   */
  bool modeOfDay();

  /*
   * method to switch mode of the day between day and night
   * input parameter: void
   * return type: void
   */
  void switchMode();

  /*
   * method to attack an enemy
   * calculate the probabililty of success or failure in attack
   * input parameter: void
   * return type: boolean
   */
  bool attack();
  
  /*
   * method to defend against an enemy
   * calculate the probabililty of success or failure in defense
   * input parameter: void
   * return type: bool
   */
  bool defend();

  /*
   * void combatRound( Race * enemy )
   * method to initiate and maintain a combat round
   * combat round: a->attacks, b->defends, then b->attacks, a->defends
   * input parameter: Race pointer (Race * enemy)
   * return type: void
   */
  void combatRound( Race * enemy );
  
  /*
   * method to pick up item from board
   * input parameter: string (of type board)
   * return type: boolean
   */
  bool pick( string );

  /*
   * method to show the inventory of a player
   * input parameter: void
   * return type: void
   */
  void inventory();

  /*
   * method to drop an item a player is carrying
   * input parameter: void
   * return type: string
   */
  string drop();
  
  /*
   * mutator method to set the weight carried by a player
   * input parameter: integer (weight of item)
   * return type: void
   */
  void setWeightCarried( int );
  
  /*
   * accessor method to get weight carried by player
   * input parameter: void
   * return type: integer (total weight carried by player)
   */
  int getWeightCarried();
  
  /*
   * mutator to set the amount of gold carried by player
   * input parameter: integer (amount of gold)
   * return type: void
   */
  void setGold(int);
  
  /*
   * accessor to obtain amount of gold carried by player
   * input parameter: void
   * return type: integer (amount of gold)
   */
  int getGold();
  
  /*
   * mutator method for the effect of special race ability
   * input parameter: integer (damage level to increase health)
   * return type: void
   */
  void setSpecialRaceAbility( int newDamageLevel );
  
  /*
   * accessor method for the effect of special race ability
   * input parameter: void
   * return type: integer (damage level to increase health)
   */
  int getSpecialRaceAbility();
  
  /*
   * virtual mutator method to set the game element of a race
   * input parameter: GameElement pointer (GameElement * newRace)
   * return type: void
   */
  virtual void setGameElement( GameElement * newRace );
  
  /*
   * virtual accessor method to get the game element of a race
   * input parameter: void
   * return type: GameElement pointer (GameElement * newRace)
   */
  virtual GameElement * getGameElement();
  
  /*
   * mutator method to set the dagger weapon item a race carries
   * input parameter: void
   * return type: void
   */
  void setDagger();
  
  /*
   * mutator method to set the sword weapon item a race carries
   * input parameter: void
   * return type: void
   */
  void setSword();
  
  /*
   * mutator method to set the ring of life item a race carries
   * input parameter: void
   * return type: void
   */
  void setRingLife();
  
  /*
   * mutator method to set the ring of strength item a race carries
   * input parameter: void
   * return type: void
   */
  void setRingStrength();
  
  /*
   * mutator method to set the leather sword item a race carries
   * input parameter: void
   * return type: void
   */
  void setLeather();
  
  /*
   * mutator method to set the plate sword item a race carries
   * input parameter: void
   * return type: void
   */
  void setPlate();
  
  /*
   * mutator method to set the large shield item a race carries
   * input parameter: void
   * return type: void
   */
  void setLarge();
  
  /*
   * mutator method to set the small shield item a race carries
   * input parameter: void
   * return type: void
   */
  void setSmall();
  
  /* Race::deleteRing method
   * accesses the ringsCollected vector and deletes the requested ring type
   * receives string parameter containing ring type (strength or life)
   * returns void
   */
  bool deleteRing(string item);
  

 // All attributes are declared in the private section to provide encapsulation
 private:

  // string variable to hold name of race
  string name;
  
  // integer variable to hold the attack value of the race
  int attackValue;
  
  // boolean variable to hold the attack chance of the race
  bool attackChance;
  
  // integer variable to hold the defense value of the race
  int defenseValue;
  
  // boolean variable to hold the defense chance of the race
  bool defenseChance;
  
  // integer variable to hold the health value of the race
  int healthValue;
  
  // integer variable to hold the strength value of the race
  int strengthValue;
  
  // integer variable to hold the value of the attack success of the race
  int attackSuccess;
  
  // integer variable to hold the value of the defense success of the race
  int defenseSuccess;
  
  // integer variable to hold the value of the total probability of defense of the race
  int totalDefenseProbability;
  
  // integer variable to hold the value of the total probability of attack of the race
  int totalAttackProbability;
  
  // boolean array to hold the true and false values of success and failure of attack
  bool attackProbability[];
  
  // boolean array to hold the true and false values of success and failure of defense
  bool defenseProbability[];
  
  // integer variable to keep count of number of commands entered by player
  int countOfCommands;
  
  // integer variable to hold total weight carried on by race (used in inventory)
  int weightCarried;
  
  // integer variable to hold amount of gold acquired by player from defeating an enemy
  int gold;
  
  // pointers of derived class items
  // these objects can be picked up by a player (implemented by Race::pick() method)
  // pointers initialized to NULL
  
  //pointer to object of class Weapon
  Sword *psword=NULL;
  
  //pointer to object of class Dagger 
  Dagger *pdagger=NULL;
  
  //pointer to object of class RingLife
  RingLife *plife=NULL;
  
  //pointer to object of class RingStrength
  RingStrength *pstrength=NULL;
  
  //pointer to object of class Leather
  Leather *pleather=NULL;
  
  //pointer to object of class Plate
  Plate *pplate=NULL;
  
  //pointer to object of class SmallShield
  SmallShield *psmall=NULL;
  
  //pointer to object of class LargeShield
  LargeShield *plarge=NULL;
  
  vector<Ring> ringsCollected;
  
  // integer variable to hold type of race
  int raceType;
  
  // boolean variable to hold time of day (day or night)
  // true means it is day time, false means it is night time
  bool dayMode;
  
  // boolean variable to hold state of an attack (successful or failed)
  bool successfulAttack;
  
  // boolean variable to hold state of an successful (successful or failed)
  bool successfulDefense;
  
  // damage level based on special race ability (affects health value of race)
  int damageLevel; 
  
  // GameElement pointer to point to address of race
  GameElement * race;
  
};

#endif
