
CC = g++
CFLAGS = -g -Wall -std=c++11
SRCS = main.cpp chaining.cpp quadratic.cpp
SRCS = ${wildcard *.cpp}
OBJS = ${SRCS:.cpp=.o}
INCLS = ${SRCS:.cpp=.h}

p2: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o p2

$(OBJS):
	$(CC) $(CFLAGS) -c $*.cpp

depend: Makefile.dep
	$(CC) -MM $(SRCS) > Makefile.dep

Makefile.dep:
	touch Makefile.dep

.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip $(SRCS) $(INCLS) Makefile Makefile.dep

clean:
	rm -f *.o a.out core

include Makefile.dep


