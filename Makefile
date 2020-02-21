all: compile-tree compile-beep run
compile-tree:
	gcc christmas_tree.c -o christmas_tree
compile-beep:
	gcc beep.c -o beep
run:
	sudo ./christmas_tree
