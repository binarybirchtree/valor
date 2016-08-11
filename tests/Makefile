CXX = clang++
CXXFLAGS = -std=c++14 -g -Wall -pedantic -Igtest -I..
LDFLAGS = -lcpprest -lssl -lcrypto -lboost_system -lglog -Lgtest -lgtest -lpthread -lstdc++ -lm

SOURCES = $(wildcard *.cc)
OBJECTS = $(subst .cc,.o,$(SOURCES)) $(filter-out ../valor.o, $(wildcard ../*.o))

TESTS = valor_tests

.PHONY: all clean test

all: gtest_libraries $(TESTS)

gtest:
	cp -r /usr/src/gtest $@

gtest_libraries: gtest
	cd $^ && cmake . && make

valor_tests: $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS) $(TESTS) gtest

test:
	./$(TESTS)
