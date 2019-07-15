objects = base.o quack.o

base: $(objects)
	gcc -o base $(objects)

base.o: quack.h base.c
quack.o: quack.c quack.h

.PHONY:clean
clean:
	rm -f base $(objects)

