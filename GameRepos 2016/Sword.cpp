/*
 * Sword.cpp
 * Sword class, inherits from Weapon class
 * Definition of class methods
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
#include "Sword.h"


/* 
 * default constructor
 * calls mutator functions to set the values of attributes upon object instantiation
 */
Sword::Sword() {

  //set weapon type to sword
  setWeaponType("Sword");

  //set element type to sword
  setElementType("Sword");

  //increase carriers attack by 10
  setAttackChange(10);

  //increase carriers defence by 0
  setDefenceChange(0);

  //increase carriers health by 0
  setHealthChange(0);

  //increase carriers strength by 0
  setStrengthChange(0);

  //increase carriers inventory weight by 10
  setWeight(10);
  
}


/*
 * mutator method
 * returns nothings
 * received a pointer to object of type Weapon
 */
void Sword::setGameElement( Weapon * newSword ) {

  sword = newSword;

}


/*
 * mutator method
 * returns pointer to object of type GameElement
 * accepts no parameter
 */
GameElement * Sword::getGameElement() {
  
  return sword;

}


// destructor
Sword::~Sword() {
}
