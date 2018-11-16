CC=main.cpp
HEADERS=qolife.h
SOURCES=funcs.cpp tools.cpp
OUT=rps

c: $(CC) $(HEADERS) $(SOURCES)
	g++ -Wall $(CC) $(HEADERS) $(SOURCES) -o $(OUT) -std=c++11

r: $(OUT)
	clear
	xterm -hold -T $(OUT) -e ./$(OUT)
