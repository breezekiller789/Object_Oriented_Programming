CC = g++
CCFLAGS = -g -c
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
EXE = hw4
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
NC = \033[1;0m

.SECONDARY : $(OBJ)
.PHONY : clean

$(EXE) : $(OBJ)
	$(CC) -o $@ $^
	@echo "$(GREEN)Done!$(NC)"

%.o : %.cpp
	@echo "$(RED)Compiling...$(NC)"
	$(CC) -o $@ $< $(CCFLAGS)

clean :
	@echo "$(BLUE)Cleaning...$(NC)"
	rm $(OBJ) $(EXE)
	@echo "$(YELLOW)Done!$(NC)"
