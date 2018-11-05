CC=main.cpp
HEADERS=qolife.h
OUT=geometry

c: $(CC) $(HEADERS)
	xterm -T compiling -hold -e g++ -Wall $(CC) $(HEADERS) -o $(OUT) -std=c++11

r: geometry
	clear
	xterm -T $(OUT) -hold -e ./$(OUT)
