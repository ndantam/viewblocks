
CC := gcc --std=gnu99
CXX := g++ --std=gnu++11

PKG_CONFIG_MODULES := amino amino_gl amino_collision sdl2 glew
CFLAGS_ALL := $(CFLAGS) -g `pkg-config --cflags $(PKG_CONFIG_MODULES)`
LDFLAGS_ALL := $(LDLAGS) -g `pkg-config --libs $(PKG_CONFIG_MODULES)`

test: test.c viewblocks.c viewblocks.h
	$(CC) test.c viewblocks.c $(CFLAGS_ALL) $(LDFLAGS_ALL) -o test

clean:
	rm -f *.o test
