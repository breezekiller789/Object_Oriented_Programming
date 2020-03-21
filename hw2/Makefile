CC = g++
CCFLAGS = -Wall -Werror -g -c
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
EXE = hw2

.SECONDARY : $(OBJ)
.PHONY : clean

$(EXE) : $(OBJ)
	$(CC) -o $@ $^

%.o : %.cpp
	$(CC) -o $@ $< $(CCFLAGS)

clean :
	rm *.o hw2
