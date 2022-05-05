/* 
 * empty.cpp
 *
 * The class for an empty square ( no game element)
 * Defines methods for an empty square
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


#include "empty.h"
#include "gameelement.h"
#include "board.h"

using namespace std;


/*
 * constructor that sets the game element type as empty
 */
Empty::Empty() {

  setElementType( "Empty" );
}


/* 
 * mutator method setGameElement
 * assigns the parameter value to empty
 * parameter - pointer to object of GameElement
 * return - nothing
 */
void Empty::setGameElement( GameElement * newEmpty ) {

  empty = newEmpty;

}


/* accessor method getGameElement
 * return the empty object
 * parameter - nothing
 * return - object of class GameElement
 */
GameElement * Empty::getGameElement() {

  return empty;

}
