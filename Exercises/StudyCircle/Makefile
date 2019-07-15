objects = linkedList.o linkedListUser.o

linkedListUser: $(objects)
	gcc -o linkedListUser $(objects)

linkedList.o: linkedList.h linkedList.c
linkedListUser.o: linkedList.h linkedListUser.c

.PHONY:clean
clean:
	rm -f linkedListUser $(objects)