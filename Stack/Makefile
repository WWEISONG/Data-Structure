objects = matcheragain.o stack.o

matcheragain: $(objects)
	gcc -o matcheragain $(objects)

matcheragain.o: stack.h matcheragain.c
stack.o: stack.h stack.c

.PHONY:clean
clean:
	rm -f matcheragain $(objects)

