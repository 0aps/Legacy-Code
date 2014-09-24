CC:=g++
BIN_FOLDER:=bin
INCLUDE:=/
CFLAGS:=-c -Wall -Weffc++ -g 
LDFLAGS:=-L/usr/lib -lPocoNet -lPocoUtil -lPocoFoundation

all: bin/encoder.o EchoClient
	g++ $(LDFLAGS) bin/encoder.o bin/connectionHandler.o bin/echoClient.o -o bin/echoExample

bin/encoder.o: encoder/encoder.cpp
	$(CC) $(CFLAGS) encoder/encoder.cpp -o bin/encoder.o

EchoClient: bin/connectionHandler.o bin/echoClient.o
	

bin/connectionHandler.o: echoClient/connectionHandler.cpp
	$(CC) $(CFLAGS) echoClient/connectionHandler.cpp -o bin/connectionHandler.o 

bin/echoClient.o: echoClient/echoClient.cpp
	$(CC) $(CFLAGS) echoClient/echoClient.cpp -o bin/echoClient.o 

.PHONY: clean
clean:
	rm -f bin/*
