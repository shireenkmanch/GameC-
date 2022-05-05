/*
 * RingStrength.h
 * Ring of strength class- RingStrength
 * inherits from Ring class
 * Contains attributes and method declarations for ring of strength
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


#ifndef	 RINGSTRENGTH_H
#define RINGSTRENGTH_H

#include <iostream>
#include "Ring.h"


class RingStrength: public Ring {
	
 public:

  // constructor
  RingStrength();


  // destructor
  ~RingStrength();

  
  /* 
   * mutator to change the type of game element
   * returns nothing
   * accepts pointer to object of type Ring
   */
  void setGameElement( Ring * newStrength );
  

  /*
   * accessor to return the type of game element
   * accepts no paramenter
   * returns pointer to object of type GameElement
   */
  GameElement * getGameElement();

  
 private:

  // pointer to object of type Ring
  Ring * strength;

};


#endif
