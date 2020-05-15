CC = g++
CCFLAGS = -Wall -Werror -g -c -O3
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
EXE = hw4

all : main.o func.o
	g++ -o hw4.exe main.o func.o -O3

main.o : main.cpp header.h
	g++ main.cpp -c -g -O3

func.o : func.cpp header.h
	g++ func.cpp -c -g -O3

# .SECONDARY : $(OBJ)
# .PHONY : clean

# $(EXE) : $(OBJ)
# 	$(CC) -o $@ $^

# %.o : %.cpp
# 	$(CC) -o $@ $< $(CCFLAGS)

clean :
	rm *.o hw4.exe
