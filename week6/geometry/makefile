CC=main.cpp
HEADERS=qolife.h
OUT=geometry

c: $(CC) $(HEADERS)
	g++ -Wall $(CC) $(HEADERS) -o $(OUT) -std=c++11

r: geometry
	clear
	xterm -T $(OUT) -e ./$(OUT)
