CFLAGS = -Wall -Wextra -pedantic -O3 
DIR = $(HOME)/.local/bin/

cprec: src/cprec.c
	cc src/cprec.c -o cprec $(CFLAGS) 


install-linux: cprec
	mkdir -p $(DIR)
	mv cprec $(DIR)