/*
 * RingLife.h
 * Ring of life class- RingLife
 * Inherits from class Ring
 * Declares attributes and method declarations for ring of life
 * 
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


#ifndef	 RINGLIFE_H
#define RINGLIFE_H

#include <iostream>
#include "Ring.h"


class RingLife: public Ring {
	
 public:

  //default constructor
  RingLife();


  //destructor
  ~RingLife();

  
  /* 
   * mutator to change the type of game element
   * returns nothing
   * accepts pointer to object of type Item
   */
  void setGameElement( Ring * newLife );

  
  /* 
   * accessor to return the type of game element
   * accepts no paramenter
   * returns pointer to object of type Item
   */
  GameElement * getGameElement();

  
 private:

  // pointer to object of type Ring
  Ring * life;

  
};

#endif
