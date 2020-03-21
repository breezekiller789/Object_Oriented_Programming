CC = g++
CCFLAGS = -Wall -Werror -g -c
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
EXE = hw2.exe

all : main.o func.o
	g++ -o hw2.exe main.o func.o

main.o : main.cpp header.h
	g++ main.cpp -c -g

func.o : func.cpp header.h
	g++ func.cpp -c -g

# .SECONDARY : $(OBJ)
# .PHONY : clean

# $(EXE) : $(OBJ)
# 	$(CC) -o $@ $^

# %.o : %.cpp
# 	$(CC) -o $@ $< $(CCFLAGS)

clean :
	rm *.o hw2.exe
