#include"arvore.h"


typedef struct lista Lista;




/* 
 * Função que alloca ponteiro para lista 
 * Pré-condição: nenhuma
 * Pós-condição: ponteiro para lista allocado 
 * Input: nenhuma
 * Output: ponteiro para lista
 */
Lista* lista_cria();

/* 
 * Função que insere uma celula no final da lista 
 * Pré-condição: lista existente e árvore existente
 * Pós-condição: celula allocada e árvore atribuida a celula, celula inserida ao final da lista 
 * Input: ponteiro para árvore e ponteiro para lista
 * Output: ponteiro para lista
 */
void lista_insereNoFinal(Arv* a,Lista* lista);

/* 
 * Função que retira uma celula em uma posição especificada da lista 
 * Pré-condição: lista existente e posição válida
 * Pós-condição: celula na posição da lista retirada  
 * Input: ponteiro para lista, posição da celula (int)
 * Output: nenhuma
 */
void lista_retira(Lista* lista, int posicao);

/* 
 * Função que exibe lista  
 * Pré-condição: lista existente
 * Pós-condição: nenhuma 
 * Input: ponteiro para lista
 * Output: nenhuma
 */
void lista_exibe(Lista* lista);

/* 
 * Função que compara se a lista é vazia 
 * Pré-condição: lista existente
 * Pós-condição: nenhuma 
 * Input: ponteiro para lista
 * Output: 1 para celula vazia e 0 para celula não vazia
 */
int lista_ehVazia(Lista* lista);

/* 
 * Função que retira uma celula na primeira posição da lista e retorna árvore
 * Pré-condição: lista existente 
 * Pós-condição: celula desalocada e árvore retornada, lista atualizada, árvore não é desalocada,para arv só com unica celula a lista é liberada 
 * Input: ponteiro para lista
 * Output: ponteiro para árvore ou NULL  em caso de lista vazia
 */
Arv* lista_retiraPrimeiro(Lista* lista);

/* 
 * Função que retira uma celula na ultima posição da lista e retorna árvore
 * Pré-condição: lista existente 
 * Pós-condição: celula desalocada e árvore retornada, lista atualizada, árvore não é desalocada 
 * Input: ponteiro para lista
 * Output: ponteiro para árvore ou NULL  em caso de lista vazia
 */
Arv* lista_retiraUltimo(Lista* lista);

/* 
 * Função que libera lista e não libera árvore
 * Pré-condição: nenhuma
 * Pós-condição: celulas desalocadas, lista desalocada, árvore não é desalocada 
 * Input: ponteiro para lista
 * Output: nenhum
 */
void lista_libera(Lista* lista);

/* 
 * Função que ordena lista
 * Pré-condição: nenhuma
 * Pós-condição: celulas ordenada, lista com posições atualizadas 
 * Input: ponteiro para lista
 * Output: nenhum
 */
void lista_ordena(Lista* lista);

/* 
 * Função auxiliar para função ordena
 * Pré-condição: árvores existentes
 * Pós-condição: nenhuma 
 * Input: ponteiro para duas árvores
 * Output: 1 para frequência da (Arv a) maior que a freq da (Arv b) e 0 para o contrário
 */
int _lista_EhParaTrocar(Arv* a,Arv* b);

/* 
 * Função que retorna ponteiro para a árvore da primeira celula
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma 
 * Input: ponteiro para lista
 * Output: ponteiro para árvore se lista não vazia e ponteiro para NULL caso lista vazia
 */
int lista_temSoUmaCel(Lista* l);

/* 
 * Função compara se a lista tem só uma celula
 * Pré-condição: lista existe
 * Pós-condição: nenhuma 
 * Input: ponteiro para lista
 * Output: 1 para lista tem só uma celula e 0 para o contrário
 */
Arv* lista_retornaPrimArv(Lista *l);


