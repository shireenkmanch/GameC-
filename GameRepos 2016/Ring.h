/*
 * Ring.h
 * Header for the Ring class
 * Inherits from the Item class
 * base class from which RingLife and RingStrength inherit
 * Declares attributes and methods for rings
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 15, 2016
 */


#ifndef RING_H
#define RING_H

#include "Item.h"


class Ring : public Item {
 
 public:
  
  /* 
   * mutator to set ring type
   * accepts string value
   * returns nothing
   */
  void setRingType( std::string );

  /*
   * accessor that returns the ring type as string value
   * accepts no paramenter
   */
  std::string getRingType();

  
  /*
   * mutator to change the type of game element
   * returns nothing
   * accepts pointer to object of type Item
   */
  void setGameElement( Item * newRing );

  
  /*
   * accessor to return the type of game element
   * accepts no paramenter
   * returns pointer to object of type GameElement
   */
  GameElement * getGameElement();


  // contructor; takes in no parameter
  Ring();


  //destructor
  ~Ring();
  

 private:

  // hold if ring of life or ring of strength
  std::string ringType;

  
  //pointer to object of type Item
  Item * ring;
 

};


#endif
