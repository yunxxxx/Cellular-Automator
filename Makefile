OBJS= project.o
DEBUG=-g
CC=g++
CFLAGS=-Wall -c $(DEBUG)
LFLAGS=-Wall $(DEBUG)
EXE=run

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

project.o: project.cpp
		$(CC) $(CFLAGS) project.cpp

clean:
	rm *~ *.o $(EXE) -v
