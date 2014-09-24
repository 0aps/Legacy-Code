BIN = automatas
CCFLAGS = -Wall -g

$(BIN): main.o actor.o util.o
	$(CC) -o $(BIN) $^ -lSDL

doc:
	doxygen

clean:
	$(RM) *.o $(BIN)
