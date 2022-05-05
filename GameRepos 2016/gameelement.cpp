/*
 * gameelement.cpp
 *
 * Class GameElement
 * Defines methods for a game element
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


#include <iostream>
#include <string>
#include "gameelement.h"


// generic constructor
GameElement::GameElement() {
}


// destructor
GameElement::~GameElement() {
}


/*
 * void setLocation( int newRowCoordinate, int newColumnCoordinate )
 *
 * mutator method for setting the position of a game element
 * accepts two integer:
 * newRowCoordinate - the integer variable to set the row coordinate
 * newColumnCoordinate - the integer variable to set the column coordinate
 */
void GameElement::setLocation( int newRowCoordinate, int newColumnCoordinate ) {
  
  rowCoordinate = newRowCoordinate;
  columnCoordinate = newColumnCoordinate;

}


/*
 * int getRowCoordinate() 
 *
 * returns the row coordinate of the game element as an integer
 * accepts no input parameter
 */
int GameElement::getRowCoordinate() {
  
  return rowCoordinate;

}


/*
 * int getColumnCoordinate() 
 *
 * returns the column coordinate of the game element as an integer
 * accepts no input parameter
 */
int GameElement::getColumnCoordinate() {
  
  return columnCoordinate;

}


/*
 * void setElementType( int newElementType ) 
 *
 * returns void
 * accepts an integer parameter:
 * 0 = empty
 * 1 = race
 * 2 = item
 * sets the parameter to the private variable elementType
 */
void GameElement::setElementType( string newElementType ) {
  
  this->elementType = newElementType;

}


/*
 * int getElementType() 
 *
 * returns an integer (elementType) which refers to the type of game element
 * accepts no input parameter
 * 0 = empty
 * 1 = race
 * 2 = item
 */
string GameElement::getElementType() {
  
  return this->elementType;

}
