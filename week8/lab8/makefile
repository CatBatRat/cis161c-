CC=main.cpp
HEADERS=scoring.h
INCLUDES=scoring.cpp
OUT=yahtzee

c: $(CC) $(HEADERS) $(INCLUDES)
	g++ -Wall $(CC) $(HEADERS) $(INCLUDES) -o $(OUT) -std=c++11

r: $(OUT)
	clear
	xterm -T $(OUT) -e ./$(OUT)
