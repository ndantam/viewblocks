
CC := gcc --std=gnu99
CXX := g++ --std=gnu++11

PKG_CONFIG_MODULES := amino amino_gl amino_collision sdl2 glew
CFLAGS_ALL := $(CFLAGS) -g `pkg-config --cflags $(PKG_CONFIG_MODULES)`
LDFLAGS_ALL := $(LDLAGS) -g `pkg-config --libs $(PKG_CONFIG_MODULES)`

all: test scene1

test: test.c viewblocks.c viewblocks.h
	$(CC) test.c viewblocks.c $(CFLAGS_ALL) $(LDFLAGS_ALL) -o test


scene1: scene1.c viewblocks.c viewblocks.h
	$(CC) scene1.c viewblocks.c $(CFLAGS_ALL) $(LDFLAGS_ALL) -o scene1

clean:
	rm -f *.o test
