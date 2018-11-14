CC=main.cpp
HEADERS=qolife.h
INCLUDES=funcs.cpp
OUT=guessnum

c: $(CC) $(HEADERS) $(INCLUDES)
	g++ -Wall $(CC) $(HEADERS) $(INCLUDES) -o $(OUT) -std=c++11

r: $(OUT)
	clear
	xterm -T $(OUT) -e ./$(OUT)
