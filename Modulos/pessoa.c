    char entrada[100];
    int contador, auxcontador;
    int tipo;
//(Aluno Brasileiro não PcD) - nome;sobrenome;0;CPF;RG;DD/MM/AAAA;0;CEP;0 >>> Tipo 1 <<<
//(Aluno Estrangeiro não PCD)  - nome;sobrenome;1;Nacionalidade;Passaporte;DD/MM/AAAA;0;CEP;0 >>> Tipo 2 <<<
//(Aluno Brasileiro PcD) - nome;sobrenome;0;CPF;RG;DD/MM/AAAA;1;laudo;CEP;0 >>> Tipo 3 <<<
//(Aluno Estrangeiro PcD) - nome;sobrenome;1;Nacionalidade;Passaporte;DD/MM/AAAA;1;laudo;CEP;0 >>> Tipo 4 <<<
//(Professor Brasileiro não Pcd) - nome;sobrenome;0;CPF;RG;DD/MM/AAAA;0;CEP;1;PIS >>> Tipo 5 <<<
//(Professor Estrangeiro não PCD)  - nome;sobrenome;1;Nacionalidade;Passaporte;DD/MM/AAAA;0;CEP;1;PIS >>> Tipo 6 <<<
//(Professor Brasileiro PcD) - nome;sobrenome;0;CPF;RG;DD/MM/AAAA;1;laudo;CEP;0 >>> Tipo 7 <<<
//(Professor Estrangeiro PcD) - nome;sobrenome;1;Nacionalidade;Passaporte;DD/MM/AAAA;1;laudo;CEP;0 >>> Tipo 8 <<<
int verificarEntrada(){
    for(int i = 0; i < strlen(entrada); i++){
        if(entrada[i] == ';'){
            contador++;
        }
    
    if(contador < 7 || contador)
    }

return tipo;
}

void cadastrarPessoa(Escola *escola, int contador){

    printf("\nDigite o cadastro da pessoa: ");
    scanf("%[^\n]s", entrada);
    getchar();

    if(contador == 8){
        for(int i = 0; i < strlen(entrada); i++){
            if(entrada[i] == ';'){
                auxcontador++;
            }
            if()
        }
    }

}