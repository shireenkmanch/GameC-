/*
 * Plate.cpp
 * Plate armour class- Plate
 * Inherits from the Armour class
 * Defines methods for a plate armour item
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
#include "Plate.h"


/* 
 * constructor
 *  call mutator methods to set values upon creating of object
 */
Plate::Plate() {

   //set armour type
   setArmourType("Plate");

   //set element type
   setElementType("Plate");

   //increase carriers attack by 5
   setAttackChange(5);

   //increase carriers defence by 10
   setDefenceChange(10);

   //increase carriers health by 0
   setHealthChange(0);

   //increase carriers strength by 0
   setStrengthChange(0);

   //increase carriers inventory weight by 40
   setWeight(40);
   
}


/*
 * mutator to change the type of game element
 * returns nothing
 * accepts pointer to object of type Armour
 */
void Plate::setGameElement( Armour * newPlate ) {
  
  plate = newPlate;

}


/* 
 * accessor to return the type of game element
 * accepts no paramenter
 * returns pointer to object of type GameElement
 */
GameElement * Plate::getGameElement() {
  
  return plate;

}


//destructor
Plate::~Plate() {
}
