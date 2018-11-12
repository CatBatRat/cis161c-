CC=main.cpp
OUT=guessnum

c: $(CC) $(HEADERS)
	g++ -Wall $(CC) $(HEADERS) -o $(OUT) -std=c++11

r: $(OUT)
	clear
	xterm -T $(OUT) -e ./$(OUT)
