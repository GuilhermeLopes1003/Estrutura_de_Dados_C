#ifndef BIBLIOTECA_PROJETO1_H
#define BIBLIOTECA_PROJETO1_H

typedef struct manutencao
{
    int codigoSolicitacao;
    char codigoEquipamento[7];
    char nomeEquipamento[21];
    int prioridade;
    int periodo;
} Manutencao;

typedef struct no
{
    Manutencao info;
    struct no *prox;
} No;

typedef struct lista
{
    No *inicio;
} Lista;


Lista* InicializaLista()
{
    return NULL;
}


Lista* CriaLista()
{
    Lista *aux;
    aux = (Lista*)malloc(sizeof(Lista));

    aux->inicio = NULL;

    return aux;
}


void inserir(Lista *L, Manutencao d)
{
    int val = 0;

    if (d.prioridade == 1 && d.periodo >= 1 && d.periodo <= 7)
    {
        val = 1;
    }
    else if (d.prioridade == 2 && d.periodo >= 1 && d.periodo <= 15)
    {
        val = 1;
    }
    else if (d.prioridade == 3 && d.periodo >= 1 && d.periodo <= 20)
    {
        val = 1;
    }

    if (val == 1)
    {
        No *novo = (No *) malloc(sizeof(No));

        if (novo == NULL)
        {
            printf("Erro na alocacao de memoria!\n");
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
                printf("Erro: codigo %d ja existe.\n", d.codigoSolicitacao);
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
                printf("Solicitacao Inserida com Sucesso!\n");
            }
        }
    }
    else
    {
        printf("Erro: valores invalidos para prioridade ou periodo. Solicitacao recusada!\n");
    }
}





void consultar(Lista *L, int cod)
{
    if (L == NULL || L->inicio == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }

    No *aux = L->inicio;

    while (aux != NULL && aux->info.codigoSolicitacao < cod)
    {
        aux = aux->prox;
    }

    if (aux != NULL && aux->info.codigoSolicitacao == cod)
    {
        printf("\nCodigo Solicitacao: %d\n", aux->info.codigoSolicitacao);
        printf("Codigo Equipamento: %s\n", aux->info.codigoEquipamento);
        printf("Nome: %s\n", aux->info.nomeEquipamento);
        printf("Prioridade: %d\n", aux->info.prioridade);
        printf("Periodo: %d dias\n", aux->info.periodo);
    }
    else
    {
        printf("Codigo %d nao encontrado.\n", cod);
    }
}


void remover(Lista *L, int cod)
{
    if (L == NULL || L->inicio == NULL)
    {
        printf("Lista vazia!\n");
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
            printf("Codigo %d nao encontrado.\n", cod);
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
            printf("Removido com sucesso!\n");
        }
    }
}


void alterar(Lista *L, int cod)
{
    if (L == NULL || L->inicio == NULL)
    {
        printf("Lista vazia!\n");
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
            int p, per, val = 0;

            printf("\n--- Valores Atuais ---\n");
            printf("Prioridade Atual: %d\n", aux->info.prioridade);
            printf("Periodo Atual: %d dias\n", aux->info.periodo);
            printf("----------------------\n\n");

            printf("Insira a nova prioridade desejada (1-Alta, 2-Media, 3-Baixa): ");
            scanf("%d", &p);

            printf("Insira o novo periodo desejado (dias): ");
            scanf("%d", &per);

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

            if (val == 1)
            {
                aux->info.prioridade = p;
                aux->info.periodo = per;
                printf("Alterado com sucesso!\n");
            }
            else
            {
                printf("Erro: valores invalidos para prioridade ou periodo.\n");
            }
        }
        else
        {
            printf("Codigo %d nao encontrado.\n", cod);
        }
    }
}



void ImprimeLista(Lista *L)
{
    No *aux;
    aux = L->inicio;

    if (aux == NULL) {
        printf("A lista de manutencao esta vazia!!!.\n");
        return;
    }

    while(aux != NULL) {
        printf("Codigo da solicitacao: %d\n", aux->info.codigoSolicitacao);
        printf("Codigo do equipamento: %s\n", aux->info.codigoEquipamento);
        printf("Nome do equipamento:   %s\n", aux->info.nomeEquipamento);
        printf("Prioridade:            %d\n", aux->info.prioridade);
        printf("Periodo (dias):        %d\n", aux->info.periodo);
        printf("---------------------------------------------------------\n");

        aux = aux->prox;
    }
}

#endif