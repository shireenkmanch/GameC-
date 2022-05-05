/*
 * elf.h
 *
 * Header file for elf race
 * Derived class from Race class
 * Declares attributes and methods for an elf race
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


#ifndef ELF_H
#define ELF_H

using namespace std;


/*
 * Elf class derives attributes and methods from Race class
 */
class Elf: public Race {
  
 public:
  
  /*
   * generic constructor
   * creates elf object when called and sets attributes of default elf
   */
  Elf();

  
  /*
   * mutator method for setting game element elf
   * derived from Board class
   * return type: nothing ( void )
   * input parameter: Race pointer ( Race * newElf )
   */
  void setGameElement( Race * newElf );


  /*
   * accessor method for getting GameElement of type Race pointer
   * derived from board class
   * return type: Race pointer
   * input parameter: nothing ( void )
   */
  Race * getGameElement();
  

 private:

  // race pointer variable to store address to elf object of type race
  Race * elf;

};


#endif
