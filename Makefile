CC=cc

CFLAGS=-Wall -g

LDFLAGS=$(shell pkg-config --libs allegro_color-5.0 allegro_acodec-5 allegro_font-5 allegro_physfs-5.0 allegro_dialog-5.0 allegro_dialog-5 allegro_acodec-5.0 allegro_main-5 allegro_image-5 allegro-5 allegro_ttf-5.0 allegro-5.0 allegro_primitives-5.0 allegro_primitives-5 allegro_physfs-5 allegro_main-5.0 allegro_audio-5 allegro_image-5.0 allegro_font-5.0 allegro_audio-5.0 allegro_memfile-5 allegro_memfile-5.0 allegro_ttf-5 allegro_color-5)

OUTPUT=ACQUEST

SOURCES=$(wildcard *.c src/**/*.c src/*.c)
HEADERS=$(wildcard *.h src/**/*.h src/*.h)

all: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) $(LDFLAGS) -o $(OUTPUT)

clean:
	rm -f *.o
	rm -f src/*.o
	rm -f src/environment/*.o
	rm -f src/system/*.o
	rm -f src/environment/*.gch
	rm -f src/system/*.gch
	rm -f $(OUTPUT)
