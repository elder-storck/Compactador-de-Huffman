#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "../include/lista.h"
#include "../include/tad_funcoes.h"

#define TAM_ 255
#define ARQ_LE "./arquivos/musica_marechal.txt"
//"imagen.jpg" musica_marechal.txt
//"arquivo.txt"
#define ARQ_ESCREVE "./arquivos/ARQGERADO_COMPACTADO.comp"
#define ARQ_DEC "./arquivos/ARQGERADODESCOMPACTADO"

int main(int argc,char *argv[]){
    if(argv[1] == NULL){
        puts("\nNumeros de argumrntos da funcão:%d\nPoucos argumentos na chamada da Função\n\n");
    }else{
        char nomeArqDestino[50] = "";
        for(int i=0; i<strlen(argv[1])-5;i++){
            nomeArqDestino[i] = argv[1][i];
        }
        func_criaArquivoDecodificado(argv[1],nomeArqDestino);
    }

    return 0;
}
