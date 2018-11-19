yahtzee : main.o yahtzee.o
	g++ -o yahtzee main.o yahtzee.o

main.o : main.cpp yahtzee.o
	g++ -c main.cpp
yahtzee.o : yahtzee.cpp
	g++ -c yahtzee.cpp

clean :
	rm yahtzee main.o yahtzee.o
	~/clean.sh
