#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

int main(void)
{

    Lista *li;

    int continuar = 1;

    do
    {
        printf("\nMenu de Opcao\n");
        printf("1. Cria Lista \n");
        printf("2. Libera lista\n");
        printf("3. Inserindo um elemento no comeco\n");
        printf("4. Inserindo um elemento no fim\n");
        printf("5. Inserindo um elemento de forma ordenada\n");
        printf("6. Removendo um elemento no comeco\n");
        printf("7. Removendo um elemento no final\n");
        printf("8. Removendo um elemento no qualquer\n");
        printf("9. Imprimindo a lista\n");
        printf("10. verificar se lista esta cheia\n");
        printf("0. Sair\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch (continuar)
        {
        case 1:
            li = cria_lista();
            printf("Lista criada com sucesso!");
            break;

        case 2:
            if (lista_vazia(li))
            {
                printf("Lista vazia\n");
                break;
            }
            else
            {
                libera_lista(li);
                printf("Lista destruida!");
            }
            break;
        case 3:
            if (lista_cheia(li))
                printf("Lista cheia!\n");
            else
            {
                struct numeros num;
                printf("Digite um numero a ser inserido na lista:");
                scanf("%d", &num.numero);
                insere_lista_inicio(li, num);
                printf("Numero inserido com sucesso!\n");
            }
            break;

        case 4:
            if (lista_cheia(li))
                printf("Lista cheia!\n");
            else
            {
                struct numeros num;
                printf("Digite um numero a ser inserido na lista:");
                scanf("%d", &num.numero);
                insere_lista_final(li, num);
                printf("Número inserido com sucesso!\n");
            }
            break;
        case 5:
            if (lista_cheia(li))
                printf("Lista cheia!\n");
            else
            {
                struct numeros num;
                printf("Digite um numero a ser inserido na lista:");
                scanf("%d", &num.numero);
                insere_lista_ordenada(li, num);
                printf("Número inserido com sucesso!\n");
            }
            break;
        case 6:
            if (remove_lista_inicio(li))
                printf("Elemento excluido com sucesso!\n");
            else
            {
                printf("Lista vazia!\n");
            }
            break;

        case 7:
            if (remove_lista_final(li))
                printf("Elemento excluido com sucesso!\n");
            else
            {
                printf("Lista vazia!\n");
            }
            break;
        case 8:
            if (lista_vazia(li) || li == NULL)
            {
                printf("\nA Lista esta Vazia\n");
            }
            else
            {
                struct numeros num;
                printf("Digite o numero que deseja remover:");
                scanf("%d", &num);
                remove_lista_qualquer(li, num);
            }
            break;
        case 9:
            // sair();
            imprime_lista(li);
            break;

        case 10:
            if (lista_cheia(li))
                printf("Lista cheia!");
            else
                printf("Lista nao cheia!");
            break;

        case 0:
            libera_lista(li);
            break;

        default:
            printf("Digite uma opcao valida\n");
        }
    } while (continuar);
}
