playgame: game.o check.o gameai.o main.o
	g++ game.o check.o gameai.o main.o -o playgame

game.o: game.cpp game.h
	g++ -c game.cpp

check.o: check.cpp check.h
	g++ -c check.cpp

gameai.o: gameai.cpp gameai.h
	g++ -c map.cpp

main.o: main.cpp check.h gameai.h game.h
	g++ -c main.cpp

clean:
	rm *.o playgame 
