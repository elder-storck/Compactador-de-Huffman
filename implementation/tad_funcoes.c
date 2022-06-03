#include"../include/tad_funcoes.h"
#include"../include/arvore.h"
#include"../include/bitmap.h"
#include<string.h>

#define TAM 128
#define TAM_2 256
#define UM_MEGA 1048576



//************************************************
/* 
 * Função que verifica se ponteiro para arquivo é diferente de NULL  
 * Pré-condição: nenhuma
 * Pós-condição: para o caso do ponteiro para o arquivo ser igual a NULL o programa é fechado
 * Input: string com o nome a ser exibido na mensagem de erro, ponteiro para arquivo a ser comparado
 * Output: nenhum
 */
static void verificaArq(char* nome,FILE *arq){
    if(arq == NULL){
        printf("\nErro 001: Ao Abrir Arquivo %s\n",nome);
        exit(1);
    }
    return ;
}



// **************LISTA DE FREQUENCIA**************
void func_montarListaDeFreq(int vet[],char* nomearq){
    for(int j=0;j<TAM_2;j++){           //atribui zero as posições do vetor
        vet[j] = 0;
    }

    FILE *arq = fopen(nomearq,"r");     //abrindo arquivo de leitura
    verificaArq(nomearq,arq);
    
    int l = 0;
    while(l != EOF){                    //percorre o arquivo de leitura e conta freq das letras
        if(l != EOF){
            l = fgetc(arq);
            vet[l] = vet[l]+1;          //adiciona 1 na frequencia do Byte lido
        }     
    }
    fclose(arq);                        //fecha arquivo de leitura
    return ;
}


void func_exibeListaDeFreq(int vet[]){
    printf("\n\nLista de frequencia\n");

    for(int i=0;i < TAM_2; i++){        //percorre o vetor 
        if(vet[i] != 0)                 //exibe frequência se diferente de zero
        printf("%d: %d\n",i,vet[i]);
    }
    
    printf("\n");
    return;
}


// **************MONTANDO ARVORE**************

void func_montaListaDeArv(Lista *l,int vet[]){
  for(int i=0; i<TAM_2;i++){                        //percorre o vetor 
    if(vet[i] != 0){                                //      se a frequência do Byte é diferente de zero 
      Arv* a1 = arv_cria(i,vet[i],NULL,NULL);       //      monta uma árvore com o Byte e a frequêcia
      lista_insereNoFinal(a1,l);                    //insere a árvore criada ao final da lista
    }
  }
}


Arv* func_montaArvore(Lista *l){
  while(lista_temSoUmaCel(l) == 0){                 
    lista_ordena(l);                                //ordena a lista
    Arv *a1 = lista_retiraPrimeiro(l);              //pega a primeira árvore da lista
    Arv *a2 = lista_retiraPrimeiro(l);              //pega a primeira árvore da lista
    Arv *raiz = arv_cria('+',(arv_retornaFreq(a1)+arv_retornaFreq(a2)),a1,a2);
    lista_insereNoFinal(raiz,l);                    //monta um novo nó da árvore com as duas árvores retiradas como filhos 
  }
  Arv* retorno = lista_retornaPrimArv(l);           //retorna uma árvore só e libera a lista 
  lista_libera(l);
  return retorno;
}


// **************CRIANDO DICIONARIO**************


char** func_alocaDicionario(int coluna){
    char ** c = malloc(sizeof(char*)*TAM_2);
    int i=0;
    for(i=0;i<TAM_2;i++){
        c[i] = calloc(coluna,sizeof(char));
    }
    return c;
}


void func_montaDicionario(char** dic,Arv* a,char *caminho,int coluna){

    if(arv_ehFolha(a)){             //acha nó folha adciona o caminho da árvore até o nó
        strcpy(dic[arv_retornaLetra(a)],caminho);

    }else{
        char camEsq[coluna];        //string para receber caminho percorrido
        char camDir[coluna];

        strcpy(camEsq,caminho);     //copia caminho passado para o caminho criado
        strcpy(camDir,caminho);

        strcat(camDir,"1");         //incrementa caminho
        strcat(camEsq,"0");

        func_montaDicionario(dic,arv_retornaNoDireita(a),camDir,coluna);    //chamada recursiva
        func_montaDicionario(dic,arv_retornaNoEsquerdo(a),camEsq,coluna);   //percorrendo toda árvore
    }
}


void func_ExibeDicionario(char** d){
    int i;
    printf("\n\nDicionario:\n");
    for(i=0;i<TAM_2;i++){                 //percorre vetor 
        if(strlen(d[i]) > 0)            //se string na posição do vetor não for vazia vai exibir na tela
            printf("letra:%c -> caminho:%s\n",i,d[i]);
    }
    printf("\n");
}

void func_liberaDicionario(char **d){
    for(int i=0;i<TAM_2;i++){
        free(d[i]);
    }
    free(d);
}


// **************CRIANDO CODIFICADOR**************


void func_escreveCodificado(char** dic,char *arqOrig,FILE *arqDest,int tamanho,long int numBit){
    FILE *arq = fopen(arqOrig,"r");                             //abrindo arquivo para leitura
    verificaArq(arqOrig,arq);
    rewind(arq);                                                //volta ponteiro de leitura para inicio do arquivo

    bitmap* bm = bitmapInit(numBit);                            //cria bitmap
    
    int l = 0;    
    while(l != EOF){                                            //percorrendo arquivo até o final
        l = fgetc(arq);                                         //lendo byte
        if( l != EOF && l < TAM_2){
            int cont = strlen(dic[l]);                          //cria contador para copiar as strings
            for(int i=0; i < cont; i++){
              bitmapAppendLeastSignificantBit(bm,dic[l][i]);    //adiciona bit ao bitmap 
            }
        }
    }

    fwrite(bitmapGetContents(bm),sizeof(unsigned char),((numBit+7)/8),arqDest); //escreve no arquivo binario o bitmap
    bitmapLibera(bm);
    fclose(arq);                                                //fecha arquivo de leitura
    return ;
}


void func_escreveDecodificado(char *arqDest,FILE *arqOrig,Arv *a,long int numBit){

    FILE *arq = fopen(arqDest,"w");                     //abrindo arquivo para escrita
    verificaArq(arqDest,arq);
    
    Arv* aux = a;                                       //criando árvore auxiliar
    bitmap* bm2 = bitmapInit(numBit+1);                 //criando bitmap

    fread(bitmapGetContents(bm2),sizeof(unsigned char),(numBit+7)/8,arqOrig);   //lendo bit e adicionando ao bitmap
  
    for (int i=0; i<numBit; i++) {                      //percorrendo bitmap
        u_int32_t teste;
        teste = bitmapGetBit(bm2,i);                    //obtendo bit na posição i
        
        if((0x01 & teste) != 0){                        //comparando bit
            aux = arv_retornaNoDireita(aux);            //anda na árvore se bit comparado for 1
        
        }else if((0x01 & teste) == 0){                  //comparando bit
            aux = arv_retornaNoEsquerdo(aux);           //anda na árvore se bit comparado for 0
        }
        
        if(arv_ehFolha(aux)){                           //compara se o nó da árvore é folha
            char letra = arv_retornaLetra(aux);     
            fprintf(arq,"%c",letra);                    //escreve no arquivo destino a letra byte daquele nó
            aux = a;                                    //retorna ponteiro da árvore para raiz
        }
    }

    bitmapLibera(bm2);
    fclose(arq);                                        //fecha arquivo de escrita e libera bitmap
    return ;
}


// **************MANIPULANDO ARQUIVO**************


void func_criaArquivoCodificado(char *arqOrig,char *arqDest){

    int vet[TAM_2];
    func_montarListaDeFreq(vet,arqOrig);                        //criando vetor com as frequências

    Lista *l = lista_cria();                                    //criando lista com os no folha
    func_montaListaDeArv(l,vet);

    Arv* a = func_montaArvore(l);                               //liberando a lista e montando uma única árvore

    char** dicionario = func_alocaDicionario(arv_altura(a)+1);  //Criando o dicionário de letra e valor em binário
    func_montaDicionario(dicionario,a,"",arv_altura(a)+1);

    long int numBit=0;
    for(int i=0;i<TAM_2;i++){                                   //contando quantidade de bits a serem usados
        numBit = numBit + (strlen(dicionario[i]) * vet[i]);
    }

    FILE *arqEsc = fopen(arqDest,"wb");                          //abrindo arquivo que vai ser escrito
    verificaArq(arqDest,arqEsc);
    
    fwrite(vet,sizeof(int),TAM_2,arqEsc);                       //escrevendo lista de frequência no arquivo

    func_escreveCodificado(dicionario,arqOrig,arqEsc,arv_altura(a),numBit);//escrevendo letras em binário em arquivo

    func_liberaDicionario(dicionario);                          //libera estruturas usadas
    arv_libera(a);
    fclose(arqEsc);
}


void func_criaArquivoDecodificado(char *arqOrig,char *arqDest){
    FILE *arqLeitura = fopen(arqOrig,"rb");                     //abrindo arq para leitura
    verificaArq(arqOrig,arqLeitura);

    int vet[TAM_2];                                             //criando vetor de frequência
    fread(vet,sizeof(int),TAM_2,arqLeitura); 

    Lista *l = lista_cria();                                    //criando lista com os nós folhas
    func_montaListaDeArv(l,vet);                                
    
    Arv* a = func_montaArvore(l);                               //liberando a lista e montando uma única árvore

    char** dicionario = func_alocaDicionario(arv_altura(a)+1);  //Criando o dicionário de letra e valor em binário
    func_montaDicionario(dicionario,a,"",arv_altura(a)+1);

    long int numBit=0;
    for(int i=0;i<TAM_2;i++){                                   //contando quantidade de bits a serem usados
        numBit = numBit + (strlen(dicionario[i]) * vet[i]);
    }

    func_escreveDecodificado(arqDest,arqLeitura,a,numBit);      //cria o arquivo destino e escreve o texto decodificado nele

    func_liberaDicionario(dicionario);
    arv_libera(a);                                              //libera árvore e dicionário
    fclose(arqLeitura);                                         //fecha arquivo de leitura
    return ;
}