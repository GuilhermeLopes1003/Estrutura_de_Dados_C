#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca_Projeto1.h"

int main()
{
    Lista *L;
    L = CriaLista();

    int op, cod;
    Manutencao d;

    do
    {
        system("cls");

        printf("\n Bem Vindo ao Sistema de Gerenciamento de Manuntencao de Equipamentos de um Laboratorio \n");
        printf("\n------------------------ MENU ---------------------------\n");
        printf("1 - Inserir uma Solicitacao de Manutencao no Sistema\n");
        printf("2 - Remover uma Solicitacao no Sistema\n");
        printf("3 - Consultar uma Solicitacao no Sistema\n");
        printf("4 - Alterar prioridade e/ou periodo no Sistema\n");
        printf("5 - Exibir ordem de realizacao da manutencao no Sistema\n");
        printf("6 - Exibir todas as solicitacoes no Sistema\n");
        printf("0 - Finalizar/Sair\n");
        printf("\n---------------------------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        system("cls"); 

        switch (op)
        {
            case 1:
                printf("Codigo da solicitacao: ");
                scanf("%d", &d.codigoSolicitacao);

                printf("Codigo do equipamento: ");
                scanf(" %s", d.codigoEquipamento);

                printf("Nome do equipamento: ");
                scanf(" %20[^\n]", d.nomeEquipamento); 

                printf("Prioridade (1-Alta, 2-Media, 3-Baixa): ");
                scanf("%d", &d.prioridade);

                printf("Periodo (dias): ");
                scanf("%d", &d.periodo);
                printf("\n---------------------------------------------------------\n");
                
                inserir(L, d);
                printf("\n");
                system("pause");
                break;

            case 2:
                printf("Digite o codigo para remover: ");
                scanf("%d", &cod);
                remover(L, cod);
                printf("\n");
                system("pause");
                break;

            case 3:
                printf("Digite o codigo para consultar: ");
                scanf("%d", &cod);
                consultar(L, cod);
                printf("\n");
                system("pause");
                break;

            case 4:
                printf("Digite o codigo para alterar: ");
                scanf("%d", &cod);
                alterar(L, cod);
                printf("\n");
                system("pause");
                break;

            case 5:
                printf("Opcao exibir Ordem ainda nao implementada.\n");
                printf("\n");
                system("pause");
                break;

            case 6:
                printf("\n----------Lista de Solicitacoes Ativas no Sistema------------\n\n");
                ImprimeLista(L);
                printf("\n");
                system("pause");
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                printf("\n");
                system("pause");
                break;
        }

    } while (op != 0);

    return 0;
}
