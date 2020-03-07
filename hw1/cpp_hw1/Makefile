CC = g++
CCFLAGS = -Wall -Werror -c
CCFLAGS += -g
OBJ = good.o main.o func.o
EXE = hw1

$(EXE) : $(OBJ)
	$(CC) $^ -o $@

%.o : %.cpp
	$(CC) -c -o $@ $< $(CCFLAGS)

# main.o : main.cpp
# 	$(CC) $(CCFLAGS) main.cpp

# func.o : func.cpp
# 	$(CC) $(CCFLAGS) func.cpp

.PHONY: clean
clean :
	@echo "Clean..."
	-rm $(OBJ) hw1
