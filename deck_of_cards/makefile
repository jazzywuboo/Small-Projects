#Jasmine Norman

CC=g++

final.exe : main.o deck.o player.o
	g++ -o final.exe main.o deck.o player.o

main.o : main.cpp deck.o player.o
	g++ -c -o main.o main.cpp

deck.o : deck.cpp deck.hpp
	g++ -c -o deck.o deck.cpp

player.o : player.cpp player.hpp
	g++ -c -o player.o player.cpp

clean :
	rm -f *.o
	rm -f *.exe