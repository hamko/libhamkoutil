CC = g++

HAMKOUTILHEAD = hamkoutil.hpp
CSRCS = $(shell ls *.c 2> /dev/null)
CXXSRCS = $(shell ls *.cpp 2> /dev/null)
OBJS = $(CSRCS:.c=.o) $(CXXSRCS:.cpp=.o)
HEADS = $(shell ls *.h 2> /dev/null) $(shell ls *.hpp 2> /dev/null)

CFLAGS = -fPIC -g -Wall
LFLAGS = -lm

PROD = libhamkoutil.so.1.0
PROD_VER = libhamkoutil.so.1
PROD_LINK = libhamkoutil.so
SHARECFLAGS = -shared -Wl,-soname,$(PROD_VER) 

all: $(PROD)

$(PROD): $(OBJS)
	$(CC) $(SHARECFLAGS) -o $@ $^

.SUFFIXES: .c .cpp .o
.c.o:
	$(CC) $(CFLAGS) -c $< $(LFLAGS)
.cpp.o:
	$(CC) $(CFLAGS) -c $< $(LFLAGS)

$(OBJS): $(HEADS)

.PHONY: clean install
clean:
	rm -f $(PROD) $(PROD_VER) $(OBJS)
install: 
	cp -f $(PROD) /usr/lib
	ldconfig /usr/lib
	rm -f /usr/lib/$(PROD_LINK)
	ln -s /usr/lib/$(PROD_VER) /usr/lib/$(PROD_LINK)
	cp -f hamkoutil.hpp /usr/include/
	mkdir -p /usr/include/hamkoutil
	cp -p *.hpp /usr/include/hamkoutil 2> /dev/null
	cp -p *.h /usr/include/hamkoutil 2> /dev/null
