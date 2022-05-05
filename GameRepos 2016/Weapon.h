/*
 * Weapon.h
 * Header for the Weapons class
 * declares methods and attributes of Weapon
 * inherits from the Item class
 * base class to classes Dagger and Sword
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


#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include <iostream>


class Weapon : public Item {
  
 public:
  
  /* 
   * mutator method
   * accepts string to update type of weapon
   */
  void setWeaponType( std::string );

  
  // accessor method to retrieve the type of weapon 
  std::string getWeaponType();


  // default constructor
  Weapon();


  // destructor
  ~Weapon();

  
  /*
   * mutator method
   * accepts pointer to object of type GameElement
   * returns nothing
   */
  void setGameElement( Item * newWeapon );

  
  /*
   * accessor to obtain the type of elemtn held
   * returns pointer to object
   */
  GameElement * getGameElement();

  
 private:

  // variable to hold if weapon is a sword or dagger
  std::string weaponType;


  // pointer to oject of type Item
  Item * weapon;
  
};


#endif
