 
new_getpass : main.o new_getpass.o
	clang -o new_getpass main.o new_getpass.o 
	 
main.o: main.c
	clang -c main.c

new_getpass.o: new_getpass.c
	clang -c new_getpass.c

clean:
	rm -f new_getpass main.o new_getpass.o
