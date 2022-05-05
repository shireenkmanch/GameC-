/* 
 * Leather.h
 * Leather shield class
 * Inherits from the armour class
 * Declares attributes and methods for a Leather armour
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


#ifndef	 LEATHER_H
#define LEATHER_H

#include <iostream>
#include "Armour.h"


class Leather : public Armour {

 public:

  //constructor
  Leather();

  
  //destructor
  ~Leather();

  
  /*
   * mutator to change the type of game element
   * returns nothing
   * accepts pointer to object of type Armour
   */
  void setGameElement( Armour * newLeather );
  
  
  /*
   * accessor to return the type of game element
   * accepts no paramenter
   * returns pointer to object of type GameElement
   */
  GameElement * getGameElement();

  
 private:

  //pointer to object of type Armour
  Armour * leather;

  
};


#endif
