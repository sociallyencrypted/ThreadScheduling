all: thread process
thread: thread.c
	gcc -o thread thread.c
process: process.c kernelCompile.sh
	gcc -o process process.c
clean:
	rm -f thread process