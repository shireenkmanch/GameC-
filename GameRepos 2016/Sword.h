/*
 * Sword.h
 * Sword class
 * Defines attibutes and methods of a sword
 * Inherits from Weapon class
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


#include <iostream>
#include "Weapon.h"

#ifndef	 SWORD_H
#define SWORD_H


class Sword:public Weapon {
	
 public:

  // default constructor
  Sword();


  //destructor
  ~Sword();

  
  /* 
   * mutator function that returns nothing
   * accepts pointer to object of type weapon
   */
  void setGameElement( Weapon * newSword );

  
  // accessor value that returns pointer to object of type gameelement
  GameElement * getGameElement();

  
 private:

  //pointer of type Weapon
  Weapon * sword; 


};


#endif
