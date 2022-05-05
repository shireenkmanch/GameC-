/* Armour.h
 *
 * Header for the Armour class
 * Inherits public attributes from the Item class
 * Base class for plate and leather armour
 * Declares attributes and methods for armour item
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


#ifndef ARMOUR_H
#define ARMOUR_H

#include "Item.h"

using namespace std;


class Armour : public Item {
  
 public:

  /*
   * mutator method to define armour type
   * accepts a string
   */
  void setArmourType(string);

  
  /*
   * accessor type to obtain armour type
   * returns string
   */
  string getArmourType();


  // default constructor
  Armour();

  
  //destructor
  ~Armour();


  /*
   * mutator for to set the exact type of game element to armour
   * accepts pointer to object of type Item
   * returns nothing
   */
  void setGameElement( Item * newArmour );

  
  /*
   * accessor to return the type of game element
   * accepts no paramenter
   * returns pointer to object of type GameElement
   */
  GameElement * getGameElement();

  
 private:

  //holds if armour is plate or leather
  string armourType;

  //creates an pointer to object of type Item
  Item * armour;


};


#endif
