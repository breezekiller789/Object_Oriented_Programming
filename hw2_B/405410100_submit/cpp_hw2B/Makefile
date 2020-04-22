CC = g++
CCFLAGS = -Wall -Werror -g -c -O3
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
EXE = hw2_B

all : main.o func.o
	g++ -o hw2_B.exe main.o func.o -O3

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
	rm *.o hw2_B.exe
