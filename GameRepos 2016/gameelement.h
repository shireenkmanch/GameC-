/*
 * gameelement.h
 *
 * Base class header file from which all other game elements will be derived
 * Game elements include races and items
 * Declares attributes and methods for all other derived classes
 *
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 25, 2016
 */ 


#ifndef GAMEELEMENT_H
#define GAMEELEMENT_H
#include <string>

using namespace std;


class GameElement {
 public:

  // constructor
  GameElement();

  
  // destructor
  ~GameElement();

  
  void setLocation(int newRowCoordinate, int newColumnCoordinate);

  
  /* 
   * accessor method for location
   * accepts no input parameter
   * returns the row coordinate value as an integer
   */
  int getRowCoordinate();

  
  /* 
   * accessor method for location
   * accepts no input parameter
   * returns the row coordinate value as an integer  
   */
  int getColumnCoordinate();

  
  /* 
   * mutator method for type of element
   * accepts an integer parameter:
   * newElementType - the type of game element (race, item, empty)
   */
  void setElementType(string newElementType);

  
  /*
   * accessor method for type
   * accepts no input parameter
   * returns the type of an element as an integer
   */
  string getElementType();

  
 private:

  // declaration integer variable to hold row coordinates of elements
  int rowCoordinate;

  
  // declaration integer variable to hold column coordinates of elements
  int columnCoordinate;

  
  /*
   * declaration of integer variable to hold the type of element
   * (0 = empty, 1 = race, 2 = item)
   */
  string elementType;

};


#endif
