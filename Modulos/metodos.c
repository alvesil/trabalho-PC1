    #include <time.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "metodos.h"    
    
    char entrada[100], tipo[3];
    int contadoraluno, contadorprofessor;
    int contadorpv, auxcontador, padrao;
    int alunoadd;
    int contadorMatriculaAluno = 0;
    
    extern Escola escola;

    

void clr(){
    printf("\ec\e[3J");
}
    
//(Aluno Brasileiro não PcD) - Rafael;Braga;0;013.027.131-40;2375833;15/07/1986;0;72007540;0 >>> Tipo 1 <<<
//(Aluno Estrangeiro não PCD)  - Girolamo;Debastiani;1;Italiano;3039495868;01/05/1925;0;72005674;0 >>> Tipo 2 <<<
//(Aluno Brasileiro PcD) - Tiago;Braga;0;202.304.214-30;3421355;16/02/1984;1;TC3469;20998560;0 >>> Tipo 3 <<<
//(Aluno Estrangeiro PcD) - nome;sobrenome;1;Nacionalidade;Passaporte;DD/MM/AAAA;1;laudo;CEP;0 >>> Tipo 4 <<<
//(Professor Brasileiro não Pcd) - Heloise;Marques;0;339.220.234-39;4920788;21/03/1998;0;230094;1;2222 >>> Tipo 5 <<<
//(Professor Estrangeiro não PCD)  - Sonia Maria;Braga;1;Suica;94883002387;03/05/1950;0;72027620;1;1111 >>> Tipo 6 <<<
//(Professor Brasileiro PcD) - nome;sobrenome;0;CPF;RG;DD/MM/AAAA;1;laudo;CEP;1;PIS >>> Tipo 7 <<<
//(Professor Estrangeiro PcD) - nome;sobrenome;1;Nacionalidade;Passaporte;DD/MM/AAAA;1;laudo;CEP;1;PIS >>> Tipo 8 <<<
void verificarEntrada(){
    contadorpv = 0;
    for(int i = 0; i < strlen(entrada); i++){
        if(entrada[i] == ';'){
            contadorpv++;
        }           
    }
    if(contadorpv < 7 || contadorpv > 10){
            printf("\nPadrao digitada nao esta correto\n");
        }
    else{
        
        padrao = 0;
        for(int i = 0; i < strlen(entrada); i++){
            if(entrada[i] == ';' && entrada[i+1] == '0' && (entrada[i+2] == ';' || entrada[i+2] == '\0')){
                tipo[padrao] = '0';
                padrao++;
                
            }
             if(entrada[i] == ';' && entrada[i+1] == '1' && (entrada[i+2] == ';' || entrada[i+2] == '\0')){
                tipo[padrao] = '1';
                padrao++;
            }
        }
    }



}

void cadastraPessoa(Escola *escola, int contadoraluno, int contadorprofessor){

    int i, j;

    printf("\nDigite o cadastro da pessoa: ");
    scanf("%[^\n]s", entrada);
    getchar();

    verificarEntrada();
if(contadoraluno < 30){
    if(tipo[0] == '0' && tipo[1] == '0' && tipo[2] == '0' ){
        //aluno brasileiro não PcD
        /* Incrementa a Matrícula se Aluno */

        int anoAtual;
        time_t data_ano;
        time(&data_ano);

        struct tm *data = localtime(&data_ano);

        anoAtual = (data->tm_year - 100);
        anoAtual = (anoAtual * 1000) + contadorMatriculaAluno;

        escola->alunos[contadoraluno].matricula = anoAtual;
        contadorMatriculaAluno++;

        escola->alunos[contadoraluno].nacionalidade = 0;
        escola->alunos[contadoraluno].pcd = 0;
        alunoadd = 1;

        j = 0;
        i = 0;
        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].nome[i] = entrada[j];
            j++;
            i++;
        }
            
        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].sobrenome[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;
            
        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].cpf[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].rg[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].dt_nasc[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].cep[i] = entrada[j];
            j++;
            i++;
        }
    }

    if(tipo[0] == '1' && tipo[1] == '0' && tipo[2] == '0' ){
        //aluno estrangeiro não PcD
         /* Incrementa a Matrícula se Aluno */

        int anoAtual;
        time_t data_ano;
        time(&data_ano);

        struct tm *data = localtime(&data_ano);

        anoAtual = (data->tm_year - 100);
        anoAtual = (anoAtual * 1000) + contadorMatriculaAluno;

        escola->alunos[contadoraluno].matricula = anoAtual;
        contadorMatriculaAluno++;

        escola->alunos[contadoraluno].nacionalidade = 1;
        escola->alunos[contadoraluno].pcd = 0;
        alunoadd = 1;

        j = 0;
        i = 0;
        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].nome[i] = entrada[j];
            j++;
            i++;
        }
            
        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].sobrenome[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;
            
        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].paisOrigem[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].passaporte[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].dt_nasc[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].cep[i] = entrada[j];
            j++;
            i++;
        }
    }

    if(tipo[0] == '0' && tipo[1] == '1' && tipo[2] == '0' ){
        //aluno Brasileiro PcD
         /* Incrementa a Matrícula se Aluno */

        int anoAtual;
        time_t data_ano;
        time(&data_ano);

        struct tm *data = localtime(&data_ano);

        anoAtual = (data->tm_year - 100);
        anoAtual = (anoAtual * 1000) + contadorMatriculaAluno;

        escola->alunos[contadoraluno].matricula = anoAtual;
        contadorMatriculaAluno++;

        escola->alunos[contadoraluno].nacionalidade = 0;
        escola->alunos[contadoraluno].pcd = 1;
        alunoadd = 1;

        j = 0;
        i = 0;
        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].nome[i] = entrada[j];
            j++;
            i++;
        }
            
        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].sobrenome[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;
            
        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].cpf[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].rg[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].dt_nasc[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].laudo[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].cep[i] = entrada[j];
            j++;
            i++;
        }
    }

    if(tipo[0] == '1' && tipo[1] == '1' && tipo[2] == '0' ){
        //Aluno Estrangeiro Pcd
        /* Incrementa a Matrícula se Aluno */

        int anoAtual;
        time_t data_ano;
        time(&data_ano);

        struct tm *data = localtime(&data_ano);

        anoAtual = (data->tm_year - 100);
        anoAtual = (anoAtual * 1000) + contadorMatriculaAluno;

        escola->alunos[contadoraluno].matricula = anoAtual;
        contadorMatriculaAluno++;

        j = 0;
        i = 0;

        escola->alunos[contadoraluno].nacionalidade = 1;
        escola->alunos[contadoraluno].pcd = 1;
        alunoadd = 1;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].nome[i] = entrada[j];
            j++;
            i++;
        }
            
        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].sobrenome[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;
            
        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].paisOrigem[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].passaporte[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].dt_nasc[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].laudo[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->alunos[contadoraluno].cep[i] = entrada[j];
            j++;
            i++;
        }
    }
}

else{
    printf("\nNumero maximo de alunos atingido\n");
}

if(contadorprofessor < 5){
    
    if(tipo[0] == '0' && tipo[1] == '0' && tipo[2] == '1' ){
        //Professor Brasileiro não PcD

        j = 0;
        i = 0;

        escola->professores[contadorprofessor].nacionalidade = 0;
        escola->professores[contadorprofessor].pcd = 0;
        alunoadd = 2;
        
        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].nome[i] = entrada[j];
            j++;
            i++;
            
        }
            
        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].sobrenome[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;
            
        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].cpf[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].rg[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].dt_nasc[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].cep[i] = entrada[j];
            j++;
            i++;
        }
        j = j + 3;
        i = 0;

        while (entrada[j] != '\0'){
            escola->professores[contadorprofessor].pis[i] = entrada[j];
            j++;
            i++;
        }
    }

     if(tipo[0] == '1' && tipo[1] == '0' && tipo[2] == '1' ){
        //Professor Estrangeiro não PcD

        j = 0;
        i = 0;

        escola->professores[contadorprofessor].nacionalidade = 1;
        escola->professores[contadorprofessor].pcd = 0;
        alunoadd = 2;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].nome[i] = entrada[j];
            j++;
            i++;
        }
            
        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].sobrenome[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;
            
        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].paisOrigem[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].passaporte[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].dt_nasc[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].cep[i] = entrada[j];
            j++;
            i++;
        }
        j = j + 3;
        i = 0;

        while (entrada[j] != '\0'){
            escola->professores[contadorprofessor].pis[i] = entrada[j];
            j++;
            i++;
        }
    }

     if(tipo[0] == '0' && tipo[1] == '1' && tipo[2] == '1' ){
        //Professor Brasileiro PcD

        j = 0;
        i = 0;

        escola->professores[contadorprofessor].nacionalidade = 0;
        escola->professores[contadorprofessor].pcd = 1;
        alunoadd = 2;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].nome[i] = entrada[j];
            j++;
            i++;
        }
            
        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].sobrenome[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;
            
        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].cpf[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].rg[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].dt_nasc[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].laudo[i] = entrada[j];
            j++;
            i++;
        }
        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].cep[i] = entrada[j];
            j++;
            i++;
        }
        j = j + 3;
        i = 0;

        while (entrada[j] != '\0'){
            escola->professores[contadorprofessor].pis[i] = entrada[j];
            j++;
            i++;
        }
    }

     if(tipo[0] == '1' && tipo[1] == '1' && tipo[2] == '1' ){
        //Professor Estrangeiro PcD

        j = 0;
        i = 0;

        escola->professores[contadorprofessor].nacionalidade = 1;
        escola->professores[contadorprofessor].pcd = 1;
        alunoadd = 2;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].nome[i] = entrada[j];
            j++;
            i++;
        }
            
        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].sobrenome[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;
            
        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].paisOrigem[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].passaporte[i] = entrada[j];
            j++;
            i++;
        }

        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].dt_nasc[i] = entrada[j];
            j++;
            i++;
        }

        j = j+3;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].laudo[i] = entrada[j];
            j++;
            i++;
        }
        j++;
        i = 0;

        while (entrada[j] != ';'){
            escola->professores[contadorprofessor].cep[i] = entrada[j];
            j++;
            i++;
        }
        j = j + 3;
        i = 0;

        while (entrada[j] != '\0'){
            escola->professores[contadorprofessor].pis[i] = entrada[j];
            j++;
            i++;
        }
    }
}
else{
    printf("\nNumero maximo de professores atingido\n");
}
}


void mostraPessoa(Escola *escola, int contadoraluno, int contadorprofessor)
{
    int menu1 = 0;
    int matricula = 0;
    char pis[12];
    printf("1-Aluno \n2-Professor \n3-Voltar \n");
    scanf("%i", &menu1);

    switch (menu1)
    {
    case 1:
        printf("Digite a matricula: ");
        scanf("%d", &matricula);

        int aux = 0;
        for (int i = 0; i < contadoraluno; i++)
        {
            if (matricula == escola->alunos[i].matricula)
            {
                printf("\nMatricula: %i\n", escola->alunos[i].matricula);
                printf("Nome: %s\n", escola->alunos[i].nome);
                printf("Sobrenome: %s\n", escola->alunos[i].sobrenome);
                if (escola->alunos[i].nacionalidade == 0)
                {
                    printf("CPF: %s\n", escola->alunos[i].cpf);
                    printf("RG: %s\n", escola->alunos[i].rg);
                }
                else
                {
                    printf("Passaporte: %s\n", escola->alunos[i].passaporte);
                    printf("País de Origem: %s\n", escola->alunos[i].paisOrigem);
                }
                printf("Data de Nascimento: %s\n", escola->alunos[i].dt_nasc);
                if (escola->alunos[i].pcd == 1)
                {
                    printf("Laudo: %s\n", escola->alunos[i].laudo);
                }
                printf("\n");
                aux = 1;
            }
        }
        if (aux == 0)
        {
            printf("Pessoa nao encontrada\n");
        }

        break;
    case 2:
        printf("Digite o PIS: ");
        scanf("%s", pis);
        getchar();
        
        for (int i = 0; i < contadorprofessor; i++)
        {
            
            int comparapis = strcmp(pis, escola->professores[i].pis);
            if (comparapis == 0){

                printf("\nPis: %s\n", escola->professores[i].pis);
                printf("Nome: %s\n", escola->professores[i].nome);
                printf("Sobrenome: %s\n", escola->professores[i].sobrenome);
                if (escola->professores[i].nacionalidade == 0)
                {
                    printf("CPF: %s\n", escola->professores[i].cpf);
                    printf("RG: %s\n", escola->professores[i].rg);
                }
                else
                {
                    printf("Passaporte: %s\n", escola->professores[i].passaporte);
                    printf("País de Origem: %s\n", escola->professores[i].paisOrigem);
                }
                printf("Data de Nascimento: %s\n", escola->professores[i].dt_nasc);
                if (escola->professores[i].pcd == 1)
                {
                    printf("Loaudo: %s\n", escola->professores[i].laudo);
                }
                printf("\n");
                aux = 1;
            }
        }
        if (aux == 0)
        {
            printf("Pessoa nao encontrada\n");
        }
        break;
    case 3:
        break;
    default:
        break;
    }
}

void alterardadopessoa(Escola *escola, int contadoraluno, int contadorprofessor){

    int menu1 = 0;
    int matricula = 0;
    char pis[12];
    char laudomedico[30];
    char novocep[12];
    int opcao;

    printf("1-Aluno \n2-Professor \n3-Voltar \n");
    scanf("%i", &menu1);

    switch (menu1)
    {
    case 1:
        printf("Digite a matricula: ");
        scanf("%d", &matricula);

        int aux = 0;
        for (int i = 0; i < contadoraluno; i++)
        {
            if (matricula == escola->alunos[i].matricula){

                printf("\n1 - Pessoa com Deficiencia(PcD)?");
                printf("\n2 - Codigo do Laudo Medico");
                printf("\n3 - CEP");
                scanf("%d", &opcao);
                getchar();

                if(opcao == 1){
                    if(escola->alunos[i].pcd == 0){
                        escola->alunos[i].pcd = 1;
                        printf("Digite o codigo do laudo medico: ");
                        scanf("%s", laudomedico);
                        getchar();
                        strcpy(escola->alunos[i].laudo, laudomedico);
                    }
                    else{
                        escola->alunos[i].pcd = 0;
                        strcpy(escola->alunos[i].laudo, "");
                        printf("\n\nItem deficiencia removida\n\n");
                    }
                    aux = 1;
                }

                if(opcao == 2){
                    if(escola->professores[i] == 1){
                    printf("\nDigite o novo codigo do laudo medico: ");
                    scanf("%s", laudomedico);
                    getchar();
                    strcpy(escola->alunos[i].laudo, laudomedico);

                    aux = 1;
                    }
                    else{
                        aux = 0;
                    }
                }

                if(opcao == 3){
                    printf("\nDigite o novo CEP: ");
                    scanf("%s", novocep);
                    getchar();
                    strcpy(escola->alunos[i].cep, novocep);

                    aux = 1;
                }               
            }
        }
        if (aux == 0)
        {
            printf("\nOpcao invalida\n");
        }

        break;
    case 2:
        printf("Digite o PIS: ");
        scanf("%s", pis);
        getchar();
        
        for (int i = 0; i < contadorprofessor; i++)
        {
            
            int comparapis = strcmp(pis, escola->professores[i].pis);
            if (comparapis == 0){
                printf("\n1 - Pessoa com Deficiencia(PcD)?");
                printf("\n2 - Codigo do Laudo Medico");
                printf("\n3 - CEP");
                scanf("%d", &opcao);
                getchar();

                if(opcao == 1){
                    if(escola->alunos[i].pcd == 0){
                        escola->professores[i].pcd = 1;
                        printf("Digite o codigo do laudo medico: ");
                        scanf("%s", laudomedico);
                        getchar();
                        strcpy(escola->professores[i].laudo, laudomedico);
                    }
                    else{
                        escola->professores[i].pcd = 0;
                        strcpy(escola->professores[i].laudo, "");
                        printf("\n\nItem deficiencia removida\n\n");
                    }
                    aux = 1;
                }

                if(opcao == 2){
                    if(escola->professores[i] == 1){
                    printf("\nDigite o novo codigo do laudo medico: ");
                    scanf("%s", laudomedico);
                    getchar();
                    strcpy(escola->professores[i].laudo, laudomedico);

                    aux = 1;
                    }
                    else{
                        aux = 0;
                    }
                }

                if(opcao == 3){

                    printf("\nDigite o novo CEP: ");
                    scanf("%s", novocep);
                    getchar();
                    strcpy(escola->professores[i].cep, novocep);

                    aux = 1;
                }        
                
            }
        }
        if (aux == 0)
        {
            printf("Pessoa nao encontrada ou nao possui o item\n");
        }
        break;
    case 3:
        break;
    default:
        break;
    }
}
