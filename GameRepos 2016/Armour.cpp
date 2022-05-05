/* 
 * Armour.cpp
 * Class for armour method definitions
 * Defines methods for an armour item
 * Inherits public attributes from the Item class
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
#include "Armour.h"

using namespace std;


/*
 * constructor
 * sets the element type of the class
 * sets item type to 1; indicating an object of Armour class
 */
Armour::Armour () {

   // set item type as 1
   setItemType( 1 );

   // set type of element as Armour
   setElementType( "Armour" );

}


/*
 * mutator for armourType attribute
 * receives string value holding the armourType
 * return type: void 
 */
void Armour::setArmourType( string armourType ) {

  this->armourType=armourType;

}


/* string Armour::getArmourType()
 * accessor method for armourType
 * returns string value of armour type
 * input parameter: void
 */
string Armour::getArmourType() {

  return armourType;

}


//destructor
Armour::~Armour() {
}


/* void Armour::setGameElement( Item * newArmour )
 * accessor function returns nothing
 * accepts a pointer to Item object
 */
void Armour::setGameElement( Item * newArmour ) {

  //initializes new armour to an object of type Item
  armour = newArmour;

}


/* GameElement * Armour::getGameElement()
 * accessor function
 * input parameter: void
 * returns pointer to object of type armour
 */
GameElement * Armour::getGameElement() {
  
  return armour;

}
