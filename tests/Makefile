CC = clang++
CCFLAGS = -g -Wall --std=c++14 -Igtest -I..
LDFLAGS = -lcpprest -lglog -Lgtest -lgtest -lpthread

SOURCES = $(wildcard *.cc)
OBJECTS = $(subst .cc,.o,$(SOURCES)) $(filter-out ../vindicator.o, $(wildcard ../*.o))

TESTS = vindicator_tests

.PHONY: all clean test

all: gtest_libraries $(TESTS)

gtest:
	cp -r /usr/src/gtest $@

gtest_libraries: gtest
	cd $^ && cmake . && make

vindicator_tests: $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cc
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS) $(TESTS) gtest

test:
	./$(TESTS)
