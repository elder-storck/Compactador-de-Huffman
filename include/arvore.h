
#include<stdio.h>

typedef struct arv Arv;



/* 
 * Função que cria uma árvore vazia
 * Pré-condição: Nada
 * Pós-condição: Ponteiro recebendo NULL
 * Input: nada
 * Output: NULL
 */
Arv* arv_criavazia (void);

/* 
 * Função que cria árvore 
 * Pré-condição: nenhuma
 * Pós-condição: Ponteiro para arv alocado
 * Input: letra a ser atribuida(char) , frequencia a ser atribuida(int),arv a esquerda e arv a direita
 * Output: ponteiro para árvore allocada
 */
Arv* arv_cria (unsigned char l,int frequencia, Arv* e, Arv* d);

/* 
 * Função que retorna letra na raiz da árvore 
 * Pré-condição: árvore não vazia
 * Pós-condição: nenhuma
 * Input: árvore
 * Output: letra no campo da arv (char)
 */
unsigned char arv_retornaLetra(Arv* a);

/* 
 * Função que retorna frequencia da letra na raiz da árvore 
 * Pré-condição: árvore não vazia
 * Pós-condição: nenhuma
 * Input: árvore
 * Output: frequencia no campo da arv (int)
 */
int arv_retornaFreq(Arv* a);

/* 
 * Função que libera árvore 
 * Pré-condição: nenhuma
 * Pós-condição: árvore liberada
 * Input: árvore
 * Output: ponteiro NULL
 */
Arv* arv_libera (Arv* a);

/* 
 * Função que compara se árvore é vazia 
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 * Input: árvore
 * Output: 1 para árvore vazia e 0 para árvore não vazia
 */
int arv_vazia (Arv* a);

/* 
 * Função que que compara se uma letra pertence a qualquer nó da árvore 
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 * Input: árvore e letra para comparação
 * Output: 1 para se a letra pertence a árvore e 0 para se a letra não pertence
 */
int arv_pertence (Arv* a,unsigned char l);

/* 
 * Função que exibe na tela a árvore 
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 * Input: árvore
 * Output: nenhum
 */
void arv_exibe (Arv* a);

/* 
 * Função retorna o número de folhas da árvore 
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 * Input: árvore
 * Output: Quantidade de Folhas na árvore
 */
int arv_folhas (Arv* a);

/* 
 * Função retorna a altura da árvore 
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 * Input: árvore
 * Output: altura da árvore(int)
 */
int arv_altura (Arv* a);

/* 
 * Função compara se nó da árvore é folha 
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 * Input: árvore
 * Output: 1 se é folha e 0 para se não é folha(int)
 */
int arv_ehFolha(Arv* a);

/* 
 * Função retorna árvore da direita 
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 * Input: árvore
 * Output: ponteiro para árvore
 */
Arv* arv_retornaNoDireita(Arv* a);

/* 
 * Função retorna árvore da esquerda 
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 * Input: árvore
 * Output: ponteiro para árvore
 */
Arv* arv_retornaNoEsquerdo(Arv* a);