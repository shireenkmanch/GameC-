/*
 * Ring.cpp
 * inherits from the Item class
 * Defines methods for rings
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


#include<iostream>
#include "Ring.h"

using namespace std;


/* constructor
 * calls mutator methods
 */ 
Ring::Ring () {

  //sets the item type; 2-Ring
  setItemType( 2 );

  //sets the element type
  setElementType( "Ring" );
  
}


/*
 * mutator for ringType attribute
 * receives string value holding the ringType
 */
void Ring::setRingType( string ringType ) {

  this->ringType=ringType;

}


/*
 * accessor method for ringType
 * returns string value with ring type
 */
string Ring::getRingType() {
  
  return ringType;

}


/* mutator to change the type of game element
 * returns nothing
 * accepts pointer to object of type Ring
 */
void Ring::setGameElement( Item * newRing ) {

  ring = newRing;

}


/*
 * accessor to return the type of game element
 * accepts no paramenter
 * returns pointer to object of type GameElement
 */
GameElement * Ring::getGameElement() {
  
  return ring;

}

// destructor
Ring::~Ring() {
}


