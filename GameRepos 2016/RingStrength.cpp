/*
 * RingStrength.cpp
 * RingStrength class
 * inherits from Ring class
 * Contains method definitions for ring of life
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
#include "RingStrength.h"


// default constructor
RingStrength::RingStrength() {

  //set type of ring 
  setRingType( "RingStrength" );

  //set type of element
  setElementType( "Ring of Strength" );

  //increase carriers attack by 0
  setAttackChange( 0 );

  //increase carriers defence by 0
  setDefenceChange( 0 );

  //increase carriers health by 10
  setHealthChange( 10 );

  //increase carriers strength by 50
  setStrengthChange( 50 );

  //increase carriers inventory weight by 1
  setWeight( 1 );

}


/*
 * mutator to change the type of game element
 * returns nothing
 * accepts pointer to object of type Item
 */
void RingStrength::setGameElement( Ring * newStrength ) {
  
  strength = newStrength;

}


/*
 * accessor to change the type of game element
 * aceepts no parameter
 * returns pointer to object of type Item
 */
GameElement * RingStrength::getGameElement() {

  return strength;

}


// destructor
RingStrength::~RingStrength() {
};
