
# Mike Pierce
# Makefile (C++)



EXE = nclife
COMPILER = g++
CPPFLAGS = -g -std=c++11 -Wall -W -Werror -pedantic
LDFLAGS = -lrt
SOURCES = $(wildcard *.*pp)
HEADERS = $(wildcard *.hpp)
OBJECTS = $(SOURCES:.cpp=.o)
DENTFLAGS = -bli0 -brf -br -ts4 -nut -i4 -npsl -nsaf -nsai -nsaw -npcs -nsob



all: $(EXE)

$(EXE): $(OBJECTS) $(HEADERS)
	$(COMPILER) $(LDFLAGS) *.o -lncurses -o $(EXE)

%.o: %.cpp
	$(COMPILER) $(CPPFLAGS) -c $< -o $@

.PHONY: clean indent 

clean:
	rm -f $(EXE)
	rm -f *.o
	rm -f *.h.gch

indent:
	indent $(DENTFLAGS) $(SOURCES)
	indent $(DENTFLAGS) $(HEADERS)



