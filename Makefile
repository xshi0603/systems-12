all:
	gcc -o forkin fork.c

run: all
	./forkin

clean:
	rm forkin
