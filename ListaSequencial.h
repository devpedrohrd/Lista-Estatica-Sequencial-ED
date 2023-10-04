// arquivo ListaSequencial.h
/*Definir:
	- Prototipos das funcoes ;
	- O tipo de dado armazendo na lista
	- o pomteiro "lista"
	- tamanho do vetor utilizado na lista*/

#define MAX 30
struct numeros
{
	int numero;
};
typedef struct li Lista;

Lista *cria_lista();
void libera_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);
void imprime_lista(Lista *li);
int insere_lista_inicio(Lista *li, struct numeros n);
int insere_lista_final(Lista *li, struct numeros n);
int remove_lista_final(Lista *li);
int remove_lista_inicio(Lista *li);