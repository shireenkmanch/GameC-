/* 
 * empty.h
 *
 * The class for the dagger item
 * Declares attributes and methods for an empty square
 * Derives attributes and methods from base class board.h
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 15, 2016
 */


#ifndef EMPTY_H
#define EMPTY_H
#include "gameelement.h"
#include "board.h"

class Empty: public Board {

 public:
  
  /*
   * constructor that sets the game element type as empty
   */
  Empty();


  /* 
  * mutator method setGameElement
  * parameter - pointer to object of GameElement
  * return - nothing
  */
  void setGameElement( GameElement * newEmpty );


  /* accessor method getGameElement
   * return the empty object
   * parameter - nothing
   * return - object of class GameElement
   */
  GameElement * getGameElement();
  
 private:

  // declaring pointer to object of type GameElement 
  GameElement * empty;

};

#endif
