CC=g++
OBJ=run
SRC=./src

run:$(SRC)/*.cpp
	CC $(SRC)/*.cpp -o $(OBJ)

