CC=main.cpp
HEADERS=tools9.h
INCLUDES=shapes.cpp parse.cpp
OUT=shapeway

c: $(CC) $(HEADERS) $(INCLUDES)
	g++ -Wall $(CC) $(HEADERS) $(INCLUDES) -o $(OUT) -std=c++11

r: $(OUT)
	clear
	xterm -e ./$(OUT)
