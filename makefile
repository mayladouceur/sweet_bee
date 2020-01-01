final: Main.o Menus.o Space.o Hive.o Backpack.o Bee.o Board.o Flower.o Normal.o Swatter.o
	g++ -std=c++11 -g Main.o Menus.o Hive.o Space.o Backpack.o Bee.o Board.o Flower.o Normal.o Swatter.o -o final

Main.o: Main.cpp
	g++ -std=c++11 -g -c Main.cpp

Menus.o: Menus.cpp Menus.hpp
	g++ -std=c++11 -g -c Menus.cpp

Hive.o: Hive.cpp Hive.hpp
	g++ -std=c++11 -g -c Hive.cpp

Space.o: Space.cpp Space.hpp
	g++ -std=c++11 -g -c Space.cpp

Backpack.o: Backpack.cpp Backpack.hpp
	g++ -std=c++11 -g -c Backpack.cpp

Bee.o: Bee.cpp Bee.hpp
	g++ -std=c++11 -g -c Bee.cpp

Board.o: Board.cpp Board.hpp 
	g++ -std=c++11 -g -c Board.cpp

Flower.o: Flower.cpp Flower.hpp 
	g++ -std=c++11 -g -c Flower.cpp

Normal.o: Normal.cpp Normal.hpp
	g++ -std=c++11 -g -c Normal.cpp


Swatter.o: Swatter.cpp Swatter.hpp
	g++ -std=c++11 -g -c Swatter.cpp

zip:
	zip -D FinalProject_LaDouceur_May.zip *.cpp *.hpp *.pdf makefile

clean:
	rm *.o final


