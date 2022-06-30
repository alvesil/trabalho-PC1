#include <time.h>

long int matricula = 000;
int i;

void matricula_incremento(long int matricula) {
    matricula = matricula + i;


    int anoAtual;
    time_t data_ano;
    time(&data_ano);

    struct tm* data = localtime(&data_ano);

    anoAtual = (data->tm_year - 100);
    anoAtual = (anoAtual * 1000) + matricula;

    printf("%d\n", anoAtual);
    i++;



}