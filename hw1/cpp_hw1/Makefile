CC = g++
CCFLAGS = -Wall -Werror -c
CCFLAGS += -g
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
EXE = hw1

$(EXE) : $(OBJ)
	$(CC) $^ -o $@

%.o : %.cpp
	$(CC) -c -o $@ $< $(CCFLAGS)

.PHONY: clean
clean :
	@echo "Clean..."
	-rm $(OBJ) $(EXE)
