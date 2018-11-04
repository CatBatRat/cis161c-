kalafus : main.o commissionCalculator.o extrema.o factor.o hackenbush.o randomTime.o reversePolishNotationCalculator.o tool.o user.o
	g++ -o kalafus commissionCalculator.o extrema.o factor.o hackenbush.o main.o randomTime.o reversePolishNotationCalculator.o tool.o user.o

main.o : main.cpp commissionCalculator.o extrema.o factor.o hackenbush.o randomTime.o reversePolishNotationCalculator.o tool.o user.o
	g++ -c main.cpp
commissionCalculator.o : commissionCalculator.cpp tool.h
	g++ -c commissionCalculator.cpp
extrema.o : extrema.cpp tool.h
	g++ -c extrema.cpp
factor.o : factor.cpp tool.h
	g++ -c factor.cpp
hackenbush.o : hackenbush.cpp tool.h
	g++ -c hackenbush.cpp
randomTime.o : randomTime.cpp tool.h
	g++ -c randomTime.cpp
reversePolishNotationCalculator.o : reversePolishNotationCalculator.cpp tool.h
	g++ -c reversePolishNotationCalculator.cpp
tool.o : tool.cpp
	g++ -c tool.cpp
user.o : user.cpp
	g++ -c user.cpp

clean :
	rm kalafus *.o
