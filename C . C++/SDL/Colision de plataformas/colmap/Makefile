CXX = g++
OBJS = main.o nivel.o tortuga.o juego.o
CXXFLAGS = -g -Wall
BIN = colmap

all: $(BIN)

$(BIN): $(OBJS)
	g++ -o colmap $(OBJS) -lSDL

documentacion:
	doxygen doc/Doxyfile

clean:
	$(RM) *.o $(BIN) doc/html -f -r
