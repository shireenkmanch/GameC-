/*
 * Weapon.cpp
 * Class Weapon
 * inherits from the Item class
 * base class to classes Dagger and Sword
 * defines methods and attributes of Weapons
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


#include<iostream>
#include "Weapon.h"

using namespace std;


/*
 * mutator for weaponType attribute
 * receives string value holding the weaponType
 * returns nothing
 */
void Weapon::setWeaponType( string weaponType ) {
  
  this->weaponType=weaponType;

}


/*
 * accessor method for weaponType
 * returns dtring value
 */
string Weapon::getWeaponType() {
  
  return this->weaponType;

}


/*
 * constructor
 * sets the Item type  and element type upon instantiation
 * 0 corresponds to weapon
 * calls mutator methods
 */
Weapon::Weapon() {

  // passes 0 to inicate type Weapon
  setItemType(0);

  //passes Weapon to set element type
  setElementType("Weapon");
  
}


/*
 * mutator methods to define the type of weapon carried
 * returns nothing
 * accepts pointerto object of type Item
 */
void Weapon::setGameElement( Item * newWeapon ) {

  weapon = newWeapon;
 
}


/*
 * accessor method
 * returns pointer to object of type gameelement which contains actuall type Weapon
 */
GameElement * Weapon::getGameElement() {
  
  return weapon;

}


// destructor
Weapon::~Weapon() {
}


