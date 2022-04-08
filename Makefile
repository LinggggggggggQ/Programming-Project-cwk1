library_manager:main.c
	@gcc -c main.c User.c book_management.c interface.c Login_and_register.c -DPARAM_SUP
	@gcc -o library_manager main.o User.o book_management.o interface.o Login_and_register.o

all:library_manager

clean:
	@rm -f library_manager *.o

