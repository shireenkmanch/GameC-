/*
 * Plate.h
 * Plate class
 * Inherits from the Armour class
 * Declares attributes and methods for a plate armour item
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


#ifndef	PLATE_H
#define PLATE_H

#include <iostream>
#include "Armour.h"


class Plate:public Armour {
	
 public:

  // constructor
  Plate();

  
  // destructor
  ~Plate();

  
  /* 
   * mutator to change the type of game element
   * returns nothing
   * accepts pointer to object of type Armour
   */
  void setGameElement( Armour * newPlate );
  
  
  /* 
   * accessor to return the type of game element
   * accepts no paramenter
   * returns pointer to object of type GameElement
   */
  GameElement * getGameElement();

  
 private:

  //pointer to object of type plate
  Armour * plate;

  
};


#endif
