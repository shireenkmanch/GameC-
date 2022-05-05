/*
 * Shield.cpp
 * class Shield
 * definition of class methods
 * inherits from the Item class
 * base class from which LargeShield and SmallShield inherit
 * Contains attributes and method declarations for ring of life
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 15, 2016
 */


#include<iostream> 
#include "Shield.h"

using namespace std;


/*
 * constructor
 * call mutator methods to set values
 */
Shield::Shield () {

  // set item type to 3, corresponding with the value of a shield item
  setItemType( 3 );


  // set item type to string
  setElementType("Shield");
	
}


/*
 * mutator for shieldType attribute
 * parameter - string value holding the shieldType
 * return - nothing
 */
void Shield::setShieldType( string shieldType ) {

  this->shieldType=shieldType;

}


/*
 * accessor method for shieldType
 * returns string value
 */
string Shield::getShieldType() {

  return shieldType;

}


// destructor
Shield::~Shield() {
}


/* mutator to change the type of gmae element
 * returns nothing
 * accepts pointer to object of type Item
 */
void Shield::setGameElement( Item * newShield ) {

  shield = newShield;

}


/*
 * accessor method for game element type
 * returns pointer to GameElemnt object
 */
GameElement * Shield::getGameElement() {

  return shield;

}

