#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca_Projeto1.h"

int main()
{
    printf("\n\n Bem Vindo ao Sistema de Gerenciamento de Manuntencao de Equipamentos de um Laboratorio \n");
    Lista *lista_manuntencao;
    lista_manuntencao = InicializaLista();
    lista_manuntencao = CriaLista();

    int opcao;
    Manutencao dados;

    do
    {
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
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:

                printf("Codigo da solicitacao: ");
                scanf("%d", &dados.codigoSolicitacao);

                printf("Codigo do equipamento: ");
                scanf("%s", dados.codigoEquipamento);

                printf("Nome do equipamento: ");
                scanf(" %s", dados.nomeEquipamento);

                printf("Prioridade (1-Alta, 2-Media, 3-Baixa): ");
                scanf("%d", &dados.prioridade);

                printf("Periodo (dias): ");
                scanf("%d", &dados.periodo);
                printf("\n---------------------------------------------------------\n");
                inserir(lista_manuntencao, dados);
                break;

            case 2:

                int codigoRemover;
                printf("Digite o codigo da solicitacao que deseja remover: ");
                scanf("%d", &codigoRemover);
                remover(lista_manuntencao, codigoRemover);
                break;

            case 3:

                printf("Opcao Consultar ainda nao implementada.\n");
                break;

            case 4:

                printf("Opcao Alterar ainda nao implementada.\n");
                break;

            case 5:

                printf("Opcao Exibir Ordem ainda nao implementada.\n");
                break;

            case 6:
                printf("\n---------------------------------------------------------\n");
                printf("\n----------Lista de Solicitacoes Ativas no Sistema------------\n");
                ImprimeLista(lista_manuntencao);
                break;

            case 0:
                printf("Encerrando o programa...\n");

                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
