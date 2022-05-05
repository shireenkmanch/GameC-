/*
 * Shield.h
 * header for the Shield class
 * declaration of attribute and methods of the Shield class
 * inherits from Item class
 * base class from which classes LargeShield and SmallShield are derived
 * Contains method definitions for shield
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 15, 2016
 */


#ifndef SHIELD_H
#define SHIELD_H
#include "Item.h"

using namespace std;


class Shield : public Item {
 
 public:

  /* 
   * set the type of string; either large or small
   * accepts parameter of type string
   */
  void setShieldType(string);
  

  /* 
   * accessor method to obtain the type of shield
   * accepts no parameter , returns string value
   */
  string getShieldType();
  

  /*
   * mutator to change the type of gmae element
   * returns nothing
   * accepts pointer to object of type Item
   */
  void setGameElement( Item * newShield );


  /*
   * accessor method for game element type
   *
   * returns pointer to GameElemnt object
   */
  GameElement * getGameElement();


  // constructor
  Shield(); 


  // destructor
  ~Shield();
  

  private:

  // hold if shield is large shield or small shield
  string shieldType;


  // pointer to object of type Item
  Item * shield;


};


#endif
