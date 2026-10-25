#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "Biblioteca_Projeto1.h"

void limpaBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int lerCodigoSolicitacao()
{
    int cod = 0;
    int val = 0;

    printf("Código da solicitação (4 dígitos, 1000 a 9999): ");
    do
    {
        if (scanf("%d", &cod) != 1)
        {
            limpaBuffer();
            cod = 0;
        }
        else
        {
            limpaBuffer();
        }

        if (cod >= 1000 && cod <= 9999)
        {
            val = 1;
        }
        else
        {
            printf("Código inválido. Digite novamente (1000 a 9999): ");
        }
    } while (val == 0);

    return cod;
}

void lerCodigoEquipamento(char *codEq)
{
    int val = 0;

    printf("Código do equipamento (3 letras e 3 números, ex: OSC023): ");
    do
    {
        scanf("%9s", codEq);
        limpaBuffer();

        if (strlen(codEq) == 6 &&
            isalpha(codEq[0]) && isalpha(codEq[1]) && isalpha(codEq[2]) &&
            isdigit(codEq[3]) && isdigit(codEq[4]) && isdigit(codEq[5]))
        {
            codEq[0] = toupper(codEq[0]);
            codEq[1] = toupper(codEq[1]);
            codEq[2] = toupper(codEq[2]);
            val = 1;
        }
        else
        {
            printf("Formato inválido. Digite 3 letras e 3 dígitos (ex: OSC023): ");
        }
    } while (val == 0);
}

void lerNomeEquipamento(char *nome)
{
    int val = 0;

    printf("Nome do equipamento (máximo 20 caracteres): ");
    do
    {
        nome[0] = '\0';
        scanf(" %20[^\n]", nome);
        limpaBuffer();

        if (strlen(nome) > 0)
        {
            val = 1;
        }
        else
        {
            printf("Nome inválido. Digite novamente: ");
        }
    } while (val == 0);
}

int lerPrioridade()
{
    int p = 0;
    int val = 0;

    printf("Prioridade (1-Alta, 2-Média, 3-Baixa): ");
    do
    {
        if (scanf("%d", &p) != 1)
        {
            limpaBuffer();
            p = 0;
        }
        else
        {
            limpaBuffer();
        }

        if (p >= 1 && p <= 3)
        {
            val = 1;
        }
        else
        {
            printf("Prioridade inválida. Escolha 1, 2 ou 3: ");
        }
    } while (val == 0);

    return p;
}

int lerPeriodo(int p)
{
    int per = 0;
    int max = 20;
    int val = 0;

    if (p == 1)
    {
        max = 7;
    }
    else if (p == 2)
    {
        max = 15;
    }

    printf("Período em dias (1 a %d): ", max);
    do
    {
        if (scanf("%d", &per) != 1)
        {
            limpaBuffer();
            per = 0;
        }
        else
        {
            limpaBuffer();
        }

        if (per >= 1 && per <= max)
        {
            val = 1;
        }
        else
        {
            printf("Período inválido para prioridade %d. Digite entre 1 e %d dias: ", p, max);
        }
    } while (val == 0);

    return per;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Lista *L;
    L = InicializaLista();
    L = CriaLista();

    int op, cod;
    Manutencao d;

    do
    {
        system("cls");
        printf("\n Sistema de Gerenciamento de Manutenção de Equipamentos de Laboratório \n");
        printf("\n------------------------ MENU ---------------------------\n");
        printf("1 - Inserir uma Solicitação\n");
        printf("2 - Remover uma Solicitação\n");
        printf("3 - Consultar uma Solicitação\n");
        printf("4 - Alterar prioridade/período\n");
        printf("5 - Exibir ordem de realização da manutenção\n");
        printf("6 - Exibir todas as solicitações\n");
        printf("0 - Sair\n");
        printf("---------------------------------------------------------\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &op) != 1)
        {
            limpaBuffer();
            op = -1;
        }
        else
        {
            limpaBuffer();
        }

        switch (op)
        {
            case 1:
                printf("\n--- Nova Solicitação ---\n");
                d.codigoSolicitacao = lerCodigoSolicitacao();
                lerCodigoEquipamento(d.codigoEquipamento);
                lerNomeEquipamento(d.nomeEquipamento);
                d.prioridade = lerPrioridade();
                d.periodo = lerPeriodo(d.prioridade);

                inserir(L, d);
                break;

            case 2:
                printf("\n--- Remover Solicitação ---\n");
                cod = lerCodigoSolicitacao();
                remover(L, cod);
                break;

            case 3:
                printf("\n--- Consultar Solicitação ---\n");
                cod = lerCodigoSolicitacao();
                consultar(L, cod);
                break;

            case 4:
                printf("\n--- Alterar Solicitação ---\n");
                cod = lerCodigoSolicitacao();
                alterar(L, cod);
                break;

            case 5:
                exibirOrdemManutencao(L);
                break;

            case 6:
                printf("\n--- Lista de Solicitações ---\n");
                ImprimeLista(L);
                break;

            case 0:
                printf("Encerrando o sistema...\n");
                LiberaLista(L);
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }

        if (op != 0)
        {
            printf("\n");
            system("pause");
        }

    } while (op != 0);

    return 0;
}
