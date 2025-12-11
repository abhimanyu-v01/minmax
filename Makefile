
output: main.o game.o
	g++ main.o game.o -o tictactoe

main.o: main.cpp
	g++ -c main.cpp

game.o: game.cpp
	g++ -c game.cpp

clean:
	rm -rf output
