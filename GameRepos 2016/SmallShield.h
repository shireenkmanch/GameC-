/*
 * SmallShield.h
 * SmallShield header file
 * Contains Declaration of attributes and class methods
 * Inherits from Shield class
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 15, 2016
 */


#ifndef	 SMALLSHIELD_H
#define SMALLSHIELD_H

#include <iostream>
#include "Shield.h"


class SmallShield : public Shield {
	
 public:

  //constructor
  SmallShield();

  //destructor
  ~SmallShield();


  /* 
   * mutator method, returns nothing
   * accepts pointer to object of type Shield as parameter
   */
  void setGameElement( Shield * newSmall );


  /*
   * accessor method to get GameElement
   * returns pointer of type GameElement
   * accepts no parameter
   */
  GameElement * getGameElement();
  

 private:

 //pointer to object of type Shield
  Shield * small;

};


#endif
