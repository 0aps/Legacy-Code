CFLAGS:=-c -Wall -Weffc++ -g
LDFLAGS:=-lboost_system -lboost_locale

all: bin/encoder.o EchoClient
	g++ -o bin/echoExample bin/encoder.o bin/connectionHandler.o bin/echoClient.o $(LDFLAGS) 

EchoClient: bin/connectionHandler.o bin/echoClient.o
	
bin/connectionHandler.o: echoClient/connectionHandler.cpp
	g++ $(CFLAGS) -o bin/connectionHandler.o echoClient/connectionHandler.cpp

bin/echoClient.o: echoClient/echoClient.cpp
	g++ $(CFLAGS) -o bin/echoClient.o echoClient/echoClient.cpp
	
bin/encoder.o: encoder/encoder.cpp
	g++ $(CFLAGS) -o bin/encoder.o encoder/encoder.cpp
	
.PHONY: clean
clean:
	rm -f bin/*
