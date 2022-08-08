all:
	gcc -c Modulos\diciplina.c
	gcc -c Modulos\metodos.c
	gcc -c Modulos\menu.c
	gcc main.c metodos.o diciplina.o  menu.o -o sistemaescola
	rm ./*.o
	.\sistemaescola.exe
