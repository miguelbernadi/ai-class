CPP  := g++
ARGS := 

DBG_ARGS := -Wall -Wextra -pedantic $(ARGS)
REL_ARGS := $(ARGS)

all: debug

release:
	$(CPP) $(REL_ARGS) src/example.cpp

debug:
	$(CPP) $(DBG_ARGS) src/example.cpp

test:
	echo 'Stub'
