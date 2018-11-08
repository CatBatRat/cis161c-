CC=main.cpp
HEADERS=qolife.h
OUT=temperature

c: $(CC) $(HEADERS)
	g++ -Wall $(CC) $(HEADERS) -o $(OUT) -std=c++11

r: temperature
	clear
	xterm -T $(OUT) -e ./$(OUT)
