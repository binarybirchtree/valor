CXX = clang++
CXXFLAGS = -std=c++14 -g -Wall -pedantic -Igtest -I..
LDFLAGS = -lcpprest -lglog -Lgtest -lgtest -lpthread -lstdc++ -lm

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
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS) $(TESTS) gtest

test:
	./$(TESTS)
