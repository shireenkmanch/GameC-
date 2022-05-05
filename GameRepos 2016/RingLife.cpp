/*
 * RingLife.cpp 
 * Ring of life class - RingLife
 * Inherits from Ring class
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
#include "RingLife.h"


/* 
 * constructor
 * calls mutator mehtods to initialize the values upon creation of object
 */
RingLife::RingLife() {

  //set ring type to life
  setRingType( "Life" );

  //set element type to ring of life
  setElementType( "Ring of Life" );

  //increase carriers attack by 0
  setAttackChange( 0 );

  //increase carriers defence by 0
  setDefenceChange( 0 );

  //increase carriers health by 10
  setHealthChange( 10 );

  //increase carriers strength by 0
  setStrengthChange( 0 );

  //increase carriers inventory weight by 1 
  setWeight( 1 );

}


/* 
 * mutator to change the type of game element
 * returns nothing
 * accepts pointer to object of type Ring
 */
void RingLife::setGameElement( Ring * newLife ) {
  
  life = newLife;

}


/*
 * accessor to return the type of game element
 * accepts nothing
 * returns pointer to object of type gameelement
 */
GameElement * RingLife::getGameElement() {
  
  return life;

}


// destructor
RingLife::~RingLife() {
}
