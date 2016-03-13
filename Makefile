CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard lib/environment/*.c lib/system/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))


TARGET=build/acquest.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

all: $(TARGET) $(SO_TARGET)

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
       ar rcs $@ $(OBJECTS)
       ranlib $@

$(SO_TARGET): $(TARGET) $(OBJECTS)
       $(CC) -shared -o $@ $(OBJECTS)

build:
       @mkdir -p build
       @mkdir -p bin

clean:
       rm -rf build $(OBJECTS) $(TESTS)
       rm -f tests/tests.log
       find . -name "*.gc*" -exec rm {} \;
       rm -rf `find . -name "*.dSYM" -print`
