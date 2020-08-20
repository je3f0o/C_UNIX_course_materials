
all:
	make array_stack
	make node_stack

array_stack:
	gcc main.c -Wall -g -o array_stack

node_stack:
	gcc node_stack.c -Wall -g -o node_stack

clear:
	rm -f node_stack array_stack
