/*
 * human. h
 *
 * Header file for human race
 * Declares attributes and methods for a human race
 * Derives attributes and methods from race class
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 15, 2016
 */


#ifndef HUMAN_H
#define HUMAH_H

#include <cstdlib>
#include <iostream>
#include "race.h"

using namespace std;


/* 
 * Human class derives attributes and methods from Race class
 */
class Human: public Race {

 public:

  /* 
   * generic constructor
   * creates human object when called and sets attributes of default human
   */  
  Human();
  

  /* 
   * mutator method for setting game element human
   * derived from Board class
   * return type: nothing ( void )
   * input parameter: Race pointer ( Race * newHuman )
   */
  void setGameElement( Race * newHuman );


  /* 
   * accessor method for getting GameElement of type Race pointer
   * derived from board class
   * return type: Race pointer
   * input parameter: nothing ( void )
   */
  Race * getGameElement();

  
 private:

  // race pointer variable to store address to human object of type race
  Race * human;

};


#endif
