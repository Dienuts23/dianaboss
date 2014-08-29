build:
	gcc server.c -o server -Wall
	gcc client.c -o client -Wall

run:
	./server

clear:
	rm server client