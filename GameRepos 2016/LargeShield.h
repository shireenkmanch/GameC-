/*
 * LargeShield.h
 * Inherits from Shield class
 * Declares attributes and methods for a large shield item
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


#ifndef LARGESHIELD_H
#define LARGESHIELD_H

#include <iostream>
#include "Shield.h"


class LargeShield : public Shield {

 public:

  //constructor
  LargeShield();


  //destructor
  ~LargeShield();

		
  /*
   * mutator to change the type of game element
   * returns nothing
   * accepts pointer to object of type Shield
   */  
  void setGameElement( Shield * newLarge );

		
  /*
   * accessor to return the type of game element
   * accepts no paramenter
   * returns pointer to object of type GameElement
   */
  GameElement * getGameElement();
  

 private:

  //pointer to object of type Shield
  Shield * large;
  
};


#endif
