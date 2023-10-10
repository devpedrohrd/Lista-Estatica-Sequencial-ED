// Arquivo listaSequencial.c
/*Definir:
	-O tipo de dado lista
	-implementatar as funcoes*/

#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

struct li // Tipo de dados "lista"
{
	int qtd;
	struct numeros dados[MAX];
};

// Funçao que cria a lista
Lista *cria_lista()
{
	Lista *li = (Lista *)malloc(sizeof(struct li)); // Aloca posicao na memoria
	if (li != NULL)									// se a lista nao for nula
		li->qtd = 0;								// a quantidade da lista é 0
	return li;										// e a lista é criada
}

// funçao que libera a lista;
void libera_lista(Lista *li)
{
	free(li);
}

// funcao que retorna o tamanho da lista
int tamanho_lista(Lista *li)
{
	if (li == NULL) // se a lista for nula retorna 0;
		return -1;
	else // se nao retorno a quantidade(tamanho);
		return li->qtd;
}
// função que verifica se a lista está cheia
int lista_cheia(Lista *li)
{
	if (li == NULL)
		return -1;
	return (li->qtd == MAX); // retorna se o campo quantida for igual ao tamanho maximo do vetor
}
// funçao que verifica se a lista esta vazia
int lista_vazia(Lista *li)
{
	if (li == NULL)
		return 1;
	return (li->qtd == 0); // se for verdade retorna 1, se não retorna 0;
}

// função que insere no inicio da lista

int insere_lista_inicio(Lista *li, struct numeros n)
{
	if (li == NULL) // verifica se existe
		return 0;
	if (lista_cheia(li)) // verifica se está cheia
		return 0;
	int i;
	for (i = li->qtd - 1; i >= 0; i--)
		li->dados[i + 1] = li->dados[i]; // move todos os elementos para direita e deixa a primeira posicao livre
	li->dados[0] = n;					 // o numero é armazendo na primeira posicao (indice 0)
	li->qtd++;							 // a quantidade do vetor é incrementada
	return 1;
}

// função que insere no final da lista

int insere_lista_final(Lista *li, struct numeros n)
{
	if (li == NULL)
		return 0;
	if (lista_cheia(li))
		return 0;
	li->dados[li->qtd] = n;
	li->qtd++;
	return 1;
}

// funçao que remove no começo da lista

int remove_lista_inicio(Lista *li)
{
	if (li == NULL)
		return 0;
	if (lista_vazia(li))
		return 0;
	int k = 0;
	for (k = 0; k < li->qtd - 1; k++)
		li->dados[k] = li->dados[k + 1]; // move todos os elementos da direita para a esquerda(sobescreve a primeira posicao)
	li->qtd--;
	return 1;
}

// função que remove no final da lista
int remove_lista_final(Lista *li)
{
	if (li == NULL)
		return 0;
	if (li->qtd == 0)
		return 0;
	li->qtd--; // decrementa a quantidade de elemento da lista,ou seja, o ultimo elemento da lista nao faz mais parte
	return 1;
}

// imprimi lista
void imprime_lista(Lista *li)
{
	for (int i = 0; i < li->qtd; i++)
		printf("%d ", li->dados[i].numero);
}

int insere_lista_ordenada(Lista *li, struct numeros n)
{
	// Verifica se a lista é nula (inexistente)
	if (li == NULL)
		return 0; // Retorna 0 para indicar erro

	// Verifica se a lista está cheia
	if (lista_cheia(li))
		return 0; // Retorna 0 para indicar erro

	int i = 0;

	// Percorre a lista até encontrar a posição correta para inserir o elemento
	while (i < li->qtd && li->dados[i].numero < n.numero)
	{
		i++; // Incrementa o índice
	}

	// Move os elementos para abrir espaço para o novo elemento
	for (int k = li->qtd - 1; k >= i; k--)
	{
		li->dados[k + 1] = li->dados[k];
	}

	// Insere o novo elemento na posição correta
	li->dados[i] = n;

	// Incrementa a quantidade de elementos na lista
	li->qtd++;

	// Retorna 1 para indicar sucesso na inserção
	return 1;
}

int remove_lista_qualquer(Lista *li, struct numeros n)
{
	// Verifica se a lista é nula (inexistente)
	if (li == NULL)
		return 0; // Retorna 0 para indicar erro

	// Verifica se a lista está vazia (você deve definir a função lista_vazia)
	if (lista_vazia(li))
		return 0; // Retorna 0 para indicar erro

	int i = 0;

	// Procura o elemento na lista
	while (i < li->qtd && li->dados[i].numero != n.numero)
	{
		i++; // Incrementa o índice
	}

	// Se o elemento não for encontrado, retorna 0 para indicar erro
	if (i == li->qtd)
		return 0;

	int k;

	// Move os elementos para preencher o espaço deixado pelo elemento removido
	for (k = i; k < li->qtd - 1; k++)
	{
		li->dados[k] = li->dados[k + 1];
	}

	// Decrementa a quantidade de elementos na lista
	li->qtd--;

	// Retorna 1 para indicar sucesso na remoção
	return 1;
}

int consulta_lista_posicao(Lista *li, int posicao, struct numeros *n)
{
	if (li == null || posicao <= 0 || posicao > li->qtd)
		return 0;

	*n = li->dados[posicao - 1];
	return 1;
}

int consulta_lista_elemento(Lista *li, int elemento, struct numeros *n)
{
	if (li == NULL || li->dados == NULL)
		return 0;

	int i = 0;

	while (i < li->qtd && li->dados[i].numero != n)
	{
		i++;
	}
	if (i == li->qtd)
		return 0;

	*n = li->dados[i];
	return 1;
}

int remove_lista_posicao(Lista *li, int posicao, struct numeros n)
{
	if (li == NULL || posicao < 0 || posicao >= li->qtd) // verifica se a lista exixte ou está cheia
		return 0;

	int i, k = 0;
	while (i < li->qtd && li->dados[i].numero != n.numero)
	// percorre o array até a ultima posicao ou até encontrar o numero procurado
	{
		i++;
	}

	if (i == li->qtd)
		return 0;

	for (k = i; k < li->qtd - 1; k++)
	{ // move os elementos até a posicao encontrada
		li->dados[k] = li->dados[k + 1];
	}
	li->qtd--; // decrementa a quantidade da lista;
	return 1;
}