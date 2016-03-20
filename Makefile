CC=cc

CFLAGS=-Wall -g

OUTPUT=ACQUEST

SOURCES=$(wildcard *.c src/**/*.c src/*.c)
HEADERS=$(wildcard *.h src/**/*.h src/*.h)

# mac specific stuff...
FRAMEWORKS=-framework OpenGL -framework GLUT -framework Cocoa

all: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) $(FRAMEWORKS) -o $(OUTPUT)

clean:
	rm -f *.o
	rm -f src/*.o
	rm -f src/environment/*.o
	rm -f src/system/*.o
	rm -f src/environment/*.gch
	rm -f src/system/*.gch
	rm -rf $(OUTPUT)*
