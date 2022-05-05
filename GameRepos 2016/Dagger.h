/* 
 * Dagger.h
 *
 * Header file for class Dagger
 * Derives attributes and methods from base class Weapon.h
 * Declares attributes and methods of a dagger item
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 15, 2016
 */


#ifndef	 DAGGER_H
#define DAGGER_H

#include <iostream>
#include "Weapon.h"


class Dagger:public Weapon {
	
 public:

  //default constructor
  Dagger();

  //destructor
  ~Dagger();
  
  /*
   * mutator method
   * receives pointer to object of type Weapon
   * returns nothing
   */
  void setGameElement( Weapon * newDagger );


  /*
   * accessor method
   * returns pointer of type GameElement
   */
  GameElement * getGameElement();
  

  private:

  //pointer of type Weapon
  Weapon * dagger;

};

#endif
