/* 
 * Item.cpp
 * Class name Item
 * This class inherits from the Board class
 * Defines methods for items the player can carry during the game
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 15, 2016
 */


#include "Item.h"


/*
 * constructor
 * calls setElementType method to set item type to Item
 */
Item::Item() {

  setElementType( "Item" );

}

  
/*
 * mutator method that receives integer values and assign them to the 
 * attribute weight
 * return - nothing ( void )
 */
void Item::setWeight( int w ) {

  // sets the weight 
  weight=w;

}


/*
 * mutator method that receives integer values and assign them to the 
 * attribute attackChange
 * return - nothing ( void )
 */
void Item::setAttackChange( int a ) {

  // sets the attackChange
  attackChange=a;

}


/*
 * mutator method that receives integer values and assign them to the 
 * attribute defenceChange
 * return - nothing ( void )
 */
void Item::setDefenceChange( int d ) {

  // sets the defenceChange
  defenceChange=d;

}


/*
 * mutator method that receives integer values and assign them to the 
 * attribute healthChange
 * return - nothing ( void )
 */
void Item::setHealthChange( int h ) {

  // sets the healthChange
  healthChange=h;

}


/*
 * mutator method that receives integer values and assign them to the 
 * attribute strengthChange
 * return - nothing ( void )
 */
void Item::setStrengthChange( int s ) {

  // sets the strengthChange
  strengthChange=s;

}


/*
 * accessor method that returns the value of attributes weight
 * accept no parameters
 * returns integer value
 */
int Item::getWeight() {

  // returns the weight of the item
  return weight;

}


/*
 * accessor method that returns the value of attributes attackChange
 * accept no parameters
 * returns integer value
 */
int Item::getAttackChange() {

  // returns the attachChange
  return attackChange;

}


/*
 * accessor method that returns the value of attributes defenceChange
 * accept no parameters
 * returns integer value
 */
int Item::getDefenceChange() {

  // returns the defenceChange
  return defenceChange;

}


/*
 * accessor method that returns the value of attributes healthChange
 * accept no parameters
 * returns integer value 
 */
int Item::getHealthChange() {

  // returns the healthChange
  return healthChange;

}


/*
 * accessor method that returns the value of attributes strengthChange
 * accept no parameters
 * returns integer value
 */
int Item::getStrengthChange() {

  // returns the strengthChange
  return strengthChange;

}


/* 
 * mutator method to set the type of game element
 * returns nothing
 * accepts pointer to object of type GameElement
 */
void Item::setGameElement( GameElement * newItem ) {

  //set item to received parameter
  item = newItem;

}


/*
 * accessor method to retrieve pointer to object of type GameElement
 * receives no parameter
 */ 
GameElement * Item::getGameElement() {

  // returns the item
  return item;

}


/*
 * mutator method to update the type of element
 * used by the derived classes
 * accept an integer parameter
 * returns nothing
 */
void Item::setItemType( int newItemType ) {
 
  // sets the type of item
  itemType = newItemType;

}


/* 
 * accessor method
 * returns an integer value indicating item type
 */
int Item::getItemType() {

  // returns the type of item
  return itemType;

}


/*
 * destructor
 */
Item::~Item() {
}
