/*
 * SmallShield.cpp
 * SmallShield class 
 * Definition of class methods
 * Derives from Shield class
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
#include "SmallShield.h"


/*
 * constructor
 * calls mutators to initialize these values
 */ 
SmallShield::SmallShield() {

   //set the shield type to small
   setShieldType( "Small" );

   //set the element type
   setElementType( "Small Shield" );

   //increase carriers attack by 0
   setAttackChange( 0 ); 

   //increase carriers defence by 5
   setDefenceChange( 5 );

   //increase carriers health by 0 
   setHealthChange( 0 );

   //increase carriers strength by 0
   setStrengthChange( 0 );

   //increase carriers inventory weight by 10
   setWeight( 10 );

}


/* 
 * mutator to change the type of game element
 * returns nothing
 * accepts pointer to object of type Item
 */
void SmallShield::setGameElement( Shield * newSmall ) {

  small = newSmall;

}


/* 
 * accessor to return the type of game element
 * accepts no paramenter
 * returns pointer to object of type Item
 */
GameElement * SmallShield::getGameElement() {

  return small;

}


//destructor
SmallShield::~SmallShield() {
}


