// Arquivo listaSequencial.c
/*Definir:
	-O tipo de dado lista
	-implementatar as funcoes*/

#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

struct li
{
	int qtd;
	struct numeros dados[MAX];
};

// Funçao que cria a lista
Lista *cria_lista()
{
	Lista *li;
	li = (Lista *)malloc(sizeof(struct li));
	if (li != NULL)
		li->qtd = 0;
	return li;
}

// funçao que libera a lista;
void libera_lista(Lista *li)
{
	free(li);
}

// funcao que retorna o tamanho da lista
int tamanho_lista(Lista *li)
{
	if (li == NULL)
		return -1;
	else
		return li->qtd;
}
// função que verifica se a lista está cheia
int lista_cheia(Lista *li)
{
	if (li == NULL)
		return -1;
	return (li->qtd == MAX);
}
// funçao que verifica se a lista esta vazia
int lista_vazia(Lista *li)
{
	if (li == NULL)
		return -1;
	return (li->qtd == 0);
}

// função que insere no inicio da lista

int insere_lista_inicio(Lista *li, struct numeros n)
{
	if (li == NULL)
		return 0;
	if (lista_cheia(li))
		return 0;
	int i;
	for (i = li->qtd - 1; i >= 0; i--)
		li->dados[i + 1] = li->dados[i];
	li->dados[0] = n;
	li->qtd++;
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
	if (li->qtd == 0)
		return 0;
	int k = 0;
	for (k = 0; k < li->qtd - 1; k++)
		li->dados[k] = li->dados[k + 1];
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
	li->qtd--;
	return 1;
}

// imprimi lista
void imprime_lista(Lista *li)
{
	for (int i = 0; i < li->qtd; i++)
		printf("%d ", li->dados[i].numero);
}
