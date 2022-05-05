/*
 * Leather.cpp
 * Class Leather for leather armour
 * Inherits from the Armour class
 * Defines methods for a Leather armour
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
#include "Leather.h"


//default constructor
Leather::Leather() {

  //sets armour type to leather
  setArmourType( "Leather" );

  //sets element type to leather
  setElementType( "Leather" );

  //increase carriers attack by 0
  setAttackChange( 0 );

  //increase carriers defence by 5
  setDefenceChange( 5 );

  //increase carriers health by 0
  setHealthChange( 0 );

  //increase carriers strength by 0
  setStrengthChange( 0 );

  //increase carriers inventory weight by 20
  setWeight( 20 );
  
}


/* mutator to change the type of game element
 * returns nothing
 * accepts pointer to object of type Armour
 */
void Leather::setGameElement( Armour * newLeather ) {
  
  leather = newLeather;

}


/* accessor to return the type of game element
 * accepts no paramenter
 * returns pointer to object of type GameElement
 */
GameElement * Leather::getGameElement() {
  
  return leather;

}


//destructor
Leather::~Leather() {
}

