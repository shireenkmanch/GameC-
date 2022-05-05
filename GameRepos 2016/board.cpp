/*
 * board.cpp
 *
 * Class file for board class
 * File contains definitions of methods declared in board.h file
 * Inherits from GameElement class
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 25, 2016
 */


#include "board.h"
#include <vector>
#include <iostream>

using namespace std;


/*
 * Board::Board()
 * generic constructor for Board
 * input parameter: void
 */
Board::Board() {
}


/*
 * Board::~Board()
 * generic destructor for Board
 * input parameter: void
 */
Board::~Board() {
}


/*
 * void Board::setGameElement( GameElement * newGameElement )
 * mutator method for game element in board class
 * sets the address of the game element to the private pointer gameElement
 *
 * return type: void
 * input parameter: GameElement pointer
 */
void Board::setGameElement( GameElement * newGameElement ) {
  
  gameElement = newGameElement;

}


/*
 * GameElement * Board::getGameElement()
 * accessor method for game element in board class
 *
 * return type: GameElement pointer
 * input parameter: void
 */
GameElement * Board::getGameElement() {
  
  return gameElement;

}


/*
 * void Board::setElementCharacteristics()
 * sets characteristics of a game element based on time of the day
 * input parameter: void
 * return type: void
 */
void Board::setElementCharacteristics() {
}
