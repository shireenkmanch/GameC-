/* 
 * hobbit.h
 *
 * Header file for horbit race
 * Declares attributes and methods for a hobbit race
 * Derived from Race class
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


#ifndef HOBBIT_H
#define HOBBIT_H

using namespace std;


/* 
 * Hobbit class derives attributes and methods from Race class
 */
class Hobbit: public Race {
 
 public:
 
  /* 
   * generic constructor
   * creates hobbit object when called and sets attributes of default hobbit
   */
  Hobbit();

  
  /* 
   * mutator method for setting game element hobbit
   * derived from Board class
   * return type: nothing ( void )
   * input parameter: Race pointer ( Race * newHobbit ) 
   */
  void setGameElement( Race * newHobbit );


  /*
   * accessor method for getting GameElement of type Race pointer
   * derived from board class
   * return type: Race pointer
   * input parameter: nothing ( void )
   */
  Race * getGameElement();

  
 private:

  // race pointer variable to store address to hobbit object of type race
  Race * hobbit;
  
};

#endif
