Eduardo Alves
Rafael Debastiani do Carmo Braga

makefile

all:
    gcc -c Modulos\diciplina.c
	gcc -c Modulos\metodos.c
	gcc -c Modulos\menu.c
	gcc main.c metodos.o diciplina.o  menu.o -o sistemaescola
	rm ./*.o
	.\sistemaescola.exe


Sobre os modulos

    modulo menu, ele faz todo o controle do meu principal

    modulo pessoa, é o modulo mais extenço, ele possui todas as funções que se relaciona com uma pessoa
    cadastrar pessoa( chama a função verificar pessoa e realiza o cadastro ) - alterar dados - excluir pessoa
     - exibir pessoa - verificar entrada(verifica a trata a string recebica para ser usada no modulo cadastrar
     pessoa).

     metodos.h, nele estão alem das chamdas das funções de metodos.c estão os tipos pessoa, diciplina e escola

     medulo diciplina, tem as funções criar diciplina - mudar professor da diciplina - addAluno - Exibir diciplina
     - excluir aluno