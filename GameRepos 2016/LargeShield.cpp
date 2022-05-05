/*
 * LargeShield.cpp
 * Inherits from class Shield
 * Defines methods for a large shield item
 *
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 15, 2016
 */


#include <iostream>
#include "LargeShield.h"


/* 
 * constructor
 * call mutators upon creationg of object
 */
LargeShield::LargeShield() {
  
  //sets the shield type
  setShieldType("Large");

  //sets the element type
  setElementType("Large Shield");

  //increase carriers attack by 5
  setAttackChange(5); 

  //increase carriers defence by 10
  setDefenceChange(10);

  //increase carriers health by 0
  setHealthChange(0);
 
  //increase carriers strength by 0
  setStrengthChange(0);

  //increase carriers inventory weight by 30
  setWeight(30);

}


/* 
 * mutator to change the type of game element
 * returns nothing
 * accepts pointer to object of type Shield
 */
void LargeShield::setGameElement( Shield * newLarge ) {

  large = newLarge;

}


/*
 * accessor to return the type of game element
 * accepts no paramenter
 * returns pointer to object of type GameElement
 */
GameElement * LargeShield::getGameElement() {

  return large;

}


//destructor
LargeShield::~LargeShield() {
}


