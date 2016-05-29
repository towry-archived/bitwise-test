
all:
	gcc main.c -o main

.PYONY: clean

clean: 
	rm -rf *.o *.a *.obj
