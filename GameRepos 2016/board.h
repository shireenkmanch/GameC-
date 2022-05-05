/* 
 * board.h
 * 
 * Header file for board class
 * File contains declaration of variables and methods to be used in board.cpp class
 * Inherits from GameElement class
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 25, 2016
 *
 */


#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "gameelement.h"

using std::vector;


class Board: public GameElement {

 public:
 
  // generic constructor
  Board();
 
 
  // destructor
  ~Board();

  
  Board( string type );


  /*
   * void Board::setGameElement( GameElement * newGameElement )
   * mutator method for game element in board class
   *
   * input parameter: GameElement pointer
   * sets the address of the game element to the private pointer gameElement
   *
   * return type: void
   */ 
  virtual void setGameElement( GameElement * newGameElement );


  /* virtual GameElement * getGameElement()
   * accessor method to get gameElement from the board
   *
   * return type: GameElement pointer
   * input parameter: void
   */
  virtual GameElement * getGameElement();
  

  /* void Board::setElementCharacteristics()
   * sets characteristics of a game element based on time of the day
   * input parameter: void
   * return type: void
   */
  void setElementCharacteristics();
 
 
 private:
  
  // GameElement type to be stored on the board
  GameElement * gameElement;
  
};


#endif
