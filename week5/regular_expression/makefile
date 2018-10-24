main=regular.cpp
out=regular

c:$(main)
	clear
	g++ $(main) -o $(out)

r:$(out)
	xterm -T $(out) -e ./$(out) &
	disown
