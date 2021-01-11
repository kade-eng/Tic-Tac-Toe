CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

all: ttt1.o ttt2.o show_node count_nodes alphatoe

ttt1.o: ttt1.c
	$(CC) $(CFLAGS) -c ttt1.c -o ttt1.o

ttt2.o: ttt2.c
	$(CC) $(CFLAGS) -c ttt2.c -o ttt2.o

show_node.o: show_node.c
	$(CC) $(CFLAGS) -c show_node.c -o show_node.o

show_node: show_node.o ttt1.o ttt2.o ttt.h
	$(CC) $(CFLAGS) show_node.o ttt1.o ttt2.o -o show_node

count_nodes.o: count_nodes.c
	$(CC) $(CFLAGS) -c count_nodes.c -o count_nodes.o

count_nodes: count_nodes.o ttt1.o ttt2.o ttt.h
	$(CC) $(CFLAGS) count_nodes.o ttt1.o ttt2.o -o count_nodes

alphatoe.o: alphatoe.c
	$(CC) $(CFLAGS) -c alphatoe.c -o alphatoe.o

alphatoe: alphatoe.o ttt1.o ttt2.o ttt.h
	$(CC) $(CFLAGS) alphatoe.o ttt1.o ttt2.o -o alphatoe

clean:
	rm *.o ttt1.o ttt2.o show_node count_nodes alphatoe
