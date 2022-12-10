all: thread
thread: thread.c
	gcc -o thread thread.c
clean:
	rm -f thread process
