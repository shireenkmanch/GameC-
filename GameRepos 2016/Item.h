/* 
 * Item.h
 * Header file for class Item
 * This class inherits from the Board class
 * Declares methods and attributes for the Item objects
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 15, 2016
 */


#ifndef ITEM_H
#define ITEM_H

#include "gameelement.h"
#include "board.h"


/*
 * derives public methods from GameElement class
 */
class Item: public Board {

 public: 

  //constructor
  Item();

  // setter functions that receive integer values and assign them to the attributes

  // sets the weight
  void setWeight( int w );

  // sets the attackChange  
  void setAttackChange( int a );

  // sets the defenceChange
  void setDefenceChange( int d );

  // sets the healthChange
  void setHealthChange( int h );

  // sets the strengthChange
  void setStrengthChange( int s );

  // sets the item type eg. Weapon=0
  void setItemType( int newItemType );

  // sets type of game element
  void setGameElement( GameElement * newItem );


  //accessor functions that return the values of respective attributes

  // returns the weight
  int getWeight(); 

  // returns the attachChange
  int getAttackChange();

  // returns the defenceChange
  int getDefenceChange();

  // returns the healthChange
  int getHealthChange();

  // returns the strengthChange 
  int getStrengthChange();

  // returns item type eg Weapon=0
  int getItemType();


  /* accessor method to return the type of game element
   * gets type of game element
   * accepts no paramenter
   * returns pointer to object of type GameElement
   */
  GameElement * getGameElement();
  

  //destructor
  ~Item();

  
 private:

  //private attributes

  // variable that stores the weight of the item
  int weight; 

  // variable that stores the value by which the attack of the race increases
  int attackChange;

  // variable that stores the value by which the defence value of the race increaes
  int defenceChange; 

  // variable that stores the value by which health of a race is increased 
  int healthChange;

  // variable that stores the increase in strength a race gains
  int strengthChange;

  // pointer to object of type GameElement
  GameElement * item;

  // variable that stores respective item types from derived classes
  int itemType;

};

#endif
