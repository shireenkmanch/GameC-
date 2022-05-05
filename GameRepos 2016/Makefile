# Makefile
#
# Single file to allow compilation of all files involved to create object files
# Invokes link target
# Runs the executable
#
# Authors:
# Sooppiyaragath Shalom Nazir
# Shireen Kudukkil Manchingal
# Dzidzor Adogla-Bessa
# Joseph Nortey
#
# Date: November 15, 2016


#Expanded variable for executable names
exec := main

#Allow target all to invoke compile target (main), the link target
#Run executable
all: $(exec) 
	./$(exec)

#Compile board.cpp to create object file board.o
#Files needed for compilation are board.h and board.cpp
board.o: board.h board.cpp
	g++ -Wall -Wextra -ggdb -c board.cpp

#Compile gameelement.cpp to create object file gameelement.o
#Files needed for compilation are gameelement.h and gameelement.cpp
gameelement.o: gameelement.h gameelement.cpp
	g++ -Wall -Wextra -ggdb -c gameelement.cpp

#Compile empty.cpp to create object file empty.o
#Files needed for compilation are empty.h and empty.cpp
empty.o: empty.h empty.cpp
	g++ -Wall -Wextra -ggdb -c empty.cpp

#Compile race.cpp to create object file race.o
#Files needed for compilation are race.h and race.cpp
race.o: race.h race.cpp
	g++ -Wall -Wextra -ggdb -c race.cpp

#Compile human.cpp to create object file human.o
#Files needed for compilation are human.h and human.cpp
human.o: human.h human.cpp
	g++ -Wall -Wextra -ggdb -c human.cpp

#Compile elf.cpp to create object file elf.o
#Files needed for compilation are elf.h and elf.cpp
elf.o: elf.h elf.cpp
	g++ -Wall -Wextra -ggdb -c elf.cpp

#Compile dwarf.cpp to create object file dwarf.o
#Files needed for compilation are dwarf.h and dwarf.cpp
dwarf.o: dwarf.h dwarf.cpp
	g++ -Wall -Wextra -ggdb -c dwarf.cpp

#Compile hobbit.cpp to create object file hobbit.o
#Files needed for compilation are hobbit.h and hobbit.cpp
hobbit.o: hobbit.h hobbit.cpp
	g++ -Wall -Wextra -ggdb -c hobbit.cpp

#Compile orc.cpp to create object file orc.o
#Files needed for compilation are orc.h and orc.cpp
orc.o: orc.h orc.cpp
	g++ -Wall -Wextra -ggdb -c orc.cpp

#Compile Item.cpp to create object file item.o
#Files needed for compilation are Item.h and Item.cpp
item.o: Item.h Item.cpp
	g++ -Wall -Wextra -ggdb -c Item.cpp

#Compile Weapon.cpp to create object file weapon.o
#Files needed for compilation are Weapon.h and Weapon.cpp
weapon.o: Weapon.h Weapon.cpp
	g++ -Wall -Wextra -ggdb -c Weapon.cpp

#Compile Armour.cpp to create object file armour.o
#Files needed for compilation are Armour.h and Armour.cpp
armour.o: Armour.h Armour.cpp
	g++ -Wall -Wextra -ggdb -c Armour.cpp

#Compile Shield.cpp to create object file shield.o
#Files needed for compilation are Shield.h and Shield.cpp
shield.o: Shield.h Shield.cpp
	g++ -Wall -Wextra -ggdb -c Shield.cpp

#Compile Ring.cpp to create object file ring.o
#Files needed for compilation are Ring.h and Ring.cpp
ring.o: Ring.h Ring.cpp
	g++ -Wall -Wextra -ggdb -c Ring.cpp

#Compile Dagger.cpp to create object file dagger.o
#Files needed for compilation are Dagger.h and Dagger.cpp
dagger.o: Dagger.h Dagger.cpp
	g++ -Wall -Wextra -ggdb -c Dagger.cpp

#Compile Sword.cpp to create object file sword.o
#Files needed for compilation are Sword.h and Sword.cpp
sword.o: Sword.h Sword.cpp
	g++ -Wall -Wextra -ggdb -c Sword.cpp

#Compile Largeshield.cpp to create object file largeshield.o
#Files needed for compilation are LargeShield.h are LargeShield.cpp
largeshield.o: LargeShield.h LargeShield.cpp
	g++ -Wall -Wextra -ggdb -c LargeShield.cpp

#Compile Smallshield.cpp to create object file smallshield.o
#Files needed for compilation are SmallShield.h and SmallShield.cpp
smallshield.o: SmallShield.h SmallShield.cpp
	g++ -Wall -Wextra -ggdb -c SmallShield.cpp

#Compile Plate.cpp to create object file plate.o
#Files needed for compilation are Plate.h and Plate.cpp
plate.o: Plate.h Plate.cpp
	g++ -Wall -Wextra -ggdb -c Plate.cpp

#Compile Leather.cpp to create object file leather.o
#Files needed for compilation are Leather.h and Leather.cpp 
leather.o: Leather.h Leather.cpp
	g++ -Wall -Wextra -ggdb -c Leather.cpp

#Compile Ringlife.cpp to create object file ringlife.o
#Files needed for compilation are RingLife.h and RingLife.cpp
ringlife.o: RingLife.h RingLife.cpp
	g++ -Wall -Wextra -ggdb -c RingLife.cpp

#Compile Ringstrength.cpp to create object file ringstrength.o
#Files needed for compilation are RingStrength.h and RingStrength.cpp
ringstrength.o: RingStrength.h RingStrength.cpp
	g++ -Wall -Wextra -ggdb -c RingStrength.cpp

#Compile main.cpp file to create object file main.o
#The file needed for compilation is main.cpp
main.o: main.cpp
	g++ -Wall -Wextra -ggdb -c main.cpp


#Link object files to create exec file main
main: gameelement.o race.o board.o empty.o human.o elf.o dwarf.o hobbit.o orc.o item.o weapon.o armour.o shield.o ring.o dagger.o sword.o largeshield.o smallshield.o plate.o leather.o ringlife.o ringstrength.o main.o
	g++ -Wall -Wextra -ggdb -o main gameelement.o board.o race.o human.o elf.o dwarf.o orc.o Item.o Weapon.o Armour.o Shield.o Ring.o Dagger.o Sword.o LargeShield.o SmallShield.o Plate.o Leather.o RingLife.o RingStrength.o main.o hobbit.o empty.o

#Clean target removes temporary files(*~), object files(*.o), and executable files ($(exec))
clean:
	rm $(exec) *~ *.o
