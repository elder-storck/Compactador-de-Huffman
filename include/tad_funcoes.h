#include<stdio.h>
#include<stdlib.h>
#include"lista.h"



/* 
 * Função que monta lista de frequência  
 * Pré-condição: vetor de inteiros existentente e string com o nome do arquivo correto
 * Pós-condição: vetor com as frequências das letras registradas (vetor atualizado)
 * Input: vetor de inteiros com o tamanho definido pela constante TAM, string com o nome para o arquivo que deve ser aberto
 * Output: nenhum
 */
void func_montarListaDeFreq(int vet[],char* nomearq);

/* 
 * Função que exibe na tela a lista de frequência  
 * Pré-condição: vetor de inteiros existentente
 * Pós-condição: nenhuma
 * Input: vetor de inteiros com o tamanho definido pela constante TAM
 * Output: nenhum
 */
void func_exibeListaDeFreq(int vet[]);

/* 
 * Função que monta lista de árvores   
 * Pré-condição: vetor de inteiros existentente,lista existente
 * Pós-condição: cada letra com uma árvore criada e adcionada a lista
 * Input: ponteiro para lista, vetor de inteiros com o tamanho definido pela constante TAM
 * Output: nenhum
 */
void func_montaListaDeArv(Lista *l,int vet[]);

/* 
 * Função que pega lista de árvores para montar única árvore e libera lista usada
 * Pré-condição: lista de árvores existente
 * Pós-condição: única árvore criada com base na frequencia da letra ,lista liberada
 * Input: ponteiro para lista de árvores
 * Output: ponteiro para árvore montada
 */
Arv* func_montaArvore(Lista *l);

/* 
 * Função que que aloca memória para um vetor de string
 * Pré-condição: nenhuma
 * Pós-condição: vetor de string alocado com tamanho do vetor especificado pela constante TAM e string de tamanho da variável coluna
 * Input: numero de colunas do vetor (int)
 * Output: ponteiro para o vetor de strings
 */
char** func_alocaDicionario(int coluna);

/* 
 * Função que percorre árvore e monta um vetor de string com o caminho em binário até a letra
 * Pré-condição: vetor de string alocado,árvore existente
 * Pós-condição: vetor de string com as informações do caminho em binário para cada letra montado
 * Input: vetor de string (char**), ponteiro para árvore (Arv*), caminho até aquele nó da árvore (char*),tamanho do caminho até a folha (int) 
 * Output: nenhum
 */
void func_montaDicionario(char** dic,Arv* a,char *caminho,int coluna);

/* 
 * Função que percorre vetor de string e exibe as strings na tela
 * Pré-condição: vetor de string existente
 * Pós-condição: nenhum
 * Input: vetor de string (char**) 
 * Output: nenhum
 */
void func_ExibeDicionario(char** d);

/* 
 * Função que libera vetor de string
 * Pré-condição: vetor de string existente
 * Pós-condição: vetor e strings liberados 
 * Input: vetor de string (char**) 
 * Output: nenhum
 */
void func_liberaDicionario(char **d);

/* 
 * Função que le as letras em um arquivo e escreve o valor binário referente a letra lida em outro arquivo
 * Pré-condição: vetor de string existente,nome do arquivo para leitura correto e ponteiro para arquivo destino válido
 * Pós-condição: arquivo destino modificado 
 * Input: vetor de string (char**), nome do arquivo para leitura(char*), ponteiro para arquivo destino (FILE*), número de bits para a strutura
 * Output: nenhum
 */
void func_escreveCodificado(char** dic,char *arqOrig,FILE *arqDest,int tamanho,long int numBit);

/* 
 * Função que le os caracteres em um arquivo codificado e escreve as letras referentes aos binários lido em outro arquivo
 * Pré-condição: ponteiro para arquivo destino válido, árvore de decodificação válida
 * Pós-condição: arquivo destino modificado 
 * Input: nome do arquivo para escrita(char*), ponteiro para arquivo de leitura (FILE*), ponteiro para árvore (Arv*),número de bits para a strutura
 * Output: nenhum
 */
void func_escreveDecodificado(char *arqDest,FILE *arqOrig,Arv *a,long int numBit);

/* 
 * Função que recebe arquivo de texto e cria outro arquivo com os dados do primeiro codificado
 * Pré-condição: nome dos arquivos válidos
 * Pós-condição: arquivo codificado gerado e com os dados escritos 
 * Input: nome do arquivo para leitura(char*), nome do arquivo para escrita(char*)
 * Output: nenhum
 */
void func_criaArquivoCodificado(char *arqOrig,char *arqDest);

/* 
 * Função que recebe arquivo de texto e cria outro arquivo com os dados do primeiro decoficado
 * Pré-condição: nome dos arquivos válidos
 * Pós-condição: arquivo decodificado gerado e com os dados escritos 
 * Input: nome do arquivo para leitura(char*), nome do arquivo para escrita(char*)
 * Output: nenhum
 */
void func_criaArquivoDecodificado(char *arqOrig,char *arqDest);