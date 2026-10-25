#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigoSolicitacao;
    char codigoEquipamento[10];
    char nomeEquipamento[21];
    int prioridade;
    int periodo;
} Manutencao;

typedef struct No
{
    Manutencao info;
    struct No *prox;
} No;

typedef struct
{
    No *inicio;
} Lista;

Lista* InicializaLista()
{
    return NULL;
}

Lista* CriaLista()
{
    Lista *L = (Lista *) malloc(sizeof(Lista));
    L->inicio = NULL;
    return L;
}

void inserir(Lista *L, Manutencao d)
{
    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Erro de memória.\n");
    }
    else
    {
        novo->info = d;
        novo->prox = NULL;

        No *aux = L->inicio;
        No *ant = NULL;
        int dup = 0;

        while (aux != NULL && aux->info.codigoSolicitacao < d.codigoSolicitacao)
        {
            ant = aux;
            aux = aux->prox;
        }

        if (aux != NULL && aux->info.codigoSolicitacao == d.codigoSolicitacao)
        {
            dup = 1;
        }

        if (dup == 1)
        {
            printf("Erro: código %d já cadastrado.\n", d.codigoSolicitacao);
            free(novo);
        }
        else
        {
            if (ant == NULL)
            {
                novo->prox = L->inicio;
                L->inicio = novo;
            }
            else
            {
                novo->prox = aux;
                ant->prox = novo;
            }
            printf("Solicitação inserida com sucesso.\n");
        }
    }
}

void remover(Lista *L, int cod)
{
    if (L->inicio == NULL)
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        No *aux = L->inicio;
        No *ant = NULL;

        while (aux != NULL && aux->info.codigoSolicitacao != cod)
        {
            ant = aux;
            aux = aux->prox;
        }

        if (aux == NULL)
        {
            printf("Código %d não encontrado.\n", cod);
        }
        else
        {
            if (ant == NULL)
            {
                L->inicio = aux->prox;
            }
            else
            {
                ant->prox = aux->prox;
            }

            free(aux);
            printf("Removido com sucesso.\n");
        }
    }
}

void consultar(Lista *L, int cod)
{
    if (L->inicio == NULL)
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        No *aux = L->inicio;

        while (aux != NULL && aux->info.codigoSolicitacao < cod)
        {
            aux = aux->prox;
        }

        if (aux != NULL && aux->info.codigoSolicitacao == cod)
        {
            printf("\nCód. Solicitação: %d\n", aux->info.codigoSolicitacao);
            printf("Cód. Equipamento: %s\n", aux->info.codigoEquipamento);
            printf("Nome: %s\n", aux->info.nomeEquipamento);
            printf("Prioridade: %d\n", aux->info.prioridade);
            printf("Período: %d dias\n", aux->info.periodo);
        }
        else
        {
            printf("Código %d não encontrado.\n", cod);
        }
    }
}

void alterar(Lista *L, int cod)
{
    if (L->inicio == NULL)
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        No *aux = L->inicio;

        while (aux != NULL && aux->info.codigoSolicitacao < cod)
        {
            aux = aux->prox;
        }

        if (aux != NULL && aux->info.codigoSolicitacao == cod)
        {
            int p = 0, per = 0, val = 0, c;

            do
            {
                printf("Nova Prioridade (1-Alta, 2-Média, 3-Baixa): ");
                if (scanf("%d", &p) != 1)
                {
                    while ((c = getchar()) != '\n' && c != EOF);
                    p = 0;
                }

                printf("Novo Período (dias): ");
                if (scanf("%d", &per) != 1)
                {
                    while ((c = getchar()) != '\n' && c != EOF);
                    per = 0;
                }

                if (p == 1 && per >= 1 && per <= 7)
                {
                    val = 1;
                }
                else if (p == 2 && per >= 1 && per <= 15)
                {
                    val = 1;
                }
                else if (p == 3 && per >= 1 && per <= 20)
                {
                    val = 1;
                }
                else
                {
                    printf("Valores inválidos para prioridade ou limite de dias. Tente novamente.\n");
                }
            } while (val == 0);

            aux->info.prioridade = p;
            aux->info.periodo = per;
            printf("Dados atualizados com sucesso.\n");
        }
        else
        {
            printf("Código %d não encontrado.\n", cod);
        }
    }
}

void ImprimeLista(Lista *L)
{
    if (L->inicio == NULL)
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        No *aux = L->inicio;

        while (aux != NULL)
        {
            printf("\nCód. Solicitação: %d | Cód. Equip: %s | Nome: %s | Prioridade: %d | Período: %d dias",
                   aux->info.codigoSolicitacao, aux->info.codigoEquipamento,
                   aux->info.nomeEquipamento, aux->info.prioridade, aux->info.periodo);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void LiberaLista(Lista *L)
{
    No *aux = L->inicio;
    No *temp;

    while (aux != NULL)
    {
        temp = aux;
        aux = aux->prox;
        free(temp);
    }
    free(L);
}

void inserirOrdemUrgencia(Lista *L_urgencia, Manutencao d)
{
    No *novo = (No *) malloc(sizeof(No));

    if (novo != NULL)
    {
        novo->info = d;
        novo->prox = NULL;

        No *aux = L_urgencia->inicio;
        No *ant = NULL;
        int avanca = 1;

        while (aux != NULL && avanca == 1)
        {
            avanca = 0;

            if (aux->info.prioridade < d.prioridade)
            {
                avanca = 1;
            }
            else if (aux->info.prioridade == d.prioridade)
            {
                if (aux->info.periodo < d.periodo)
                {
                    avanca = 1;
                }
                else if (aux->info.periodo == d.periodo)
                {
                    if (aux->info.codigoSolicitacao < d.codigoSolicitacao)
                    {
                        avanca = 1;
                    }
                }
            }

            if (avanca == 1)
            {
                ant = aux;
                aux = aux->prox;
            }
        }

        if (ant == NULL)
        {
            novo->prox = L_urgencia->inicio;
            L_urgencia->inicio = novo;
        }
        else
        {
            novo->prox = aux;
            ant->prox = novo;
        }
    }
}

void exibirOrdemManutencao(Lista *L)
{
    if (L->inicio == NULL)
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        Lista *L_urgencia = CriaLista();
        No *aux = L->inicio;

        while (aux != NULL)
        {
            inserirOrdemUrgencia(L_urgencia, aux->info);
            aux = aux->prox;
        }

        printf("\n--- Ordem de Realização da Manutenção ---\n");
        ImprimeLista(L_urgencia);

        LiberaLista(L_urgencia);
    }
}
