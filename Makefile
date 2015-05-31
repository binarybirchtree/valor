CC = clang++
CCFLAGS = -g -Wall --std=c++14 -I.
LDFLAGS = -lcpprest -lglog

SOURCES = $(wildcard *.cc)
OBJECTS = $(subst .cc,.o,$(SOURCES))

TARGET = vindicator
TESTS = tests

.PHONY: all clean test

all: $(TARGET) $(TESTS)

$(TESTS):
	$(MAKE) -C $@

vindicator: $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cc
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(TARGET) && \
	cd $(TESTS) && make clean

test:
	cd $(TESTS) && make && make test
