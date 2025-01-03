# A simple Makefile for compiling small SDL projects

# set the compiler
CC := g++

# set the compiler flags
CFLAGS := -LSDL2/bin -lSDL2 -ISDL2/include -ggdb3 -O0 --std=c++17 -Wall -w
# add header files here
HDRS := ../.././src/*.h

# add source files here
SRCS := ../.././src/*.cpp

# generate names of object files
OBJS := $(SRCS:.c=.o)

# name of executable
EXEC := main#name your executable file

# default recipe
all: $(EXEC)
 
showfont: showfont.c Makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

glfont: glfont.c Makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

# recipe for building the final executable
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

# recipe for building object files
#$(OBJS): $(@:.o=.c) $(HDRS) Makefile
#    $(CC) -o $@ $(@:.o=.c) -c $(CFLAGS)

# recipe to clean the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean