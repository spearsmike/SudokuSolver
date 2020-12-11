CFLAGS=-c -lm -D SMART

C++: solver.c solver.h
	g++ $(CFLAGS) solver.c

C: solver.c solver.h
	gcc $(CFLAGS) -D C solver.c

clean:
	rm solver.o