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


void inserir(Lista *L, Manutencao dados)
{
    No *novo = (No *) malloc(sizeof(No));

    novo->info = dados;
    novo->prox = NULL;

    No *atual = L->inicio;
    No *anterior = NULL;
    int duplicado = 0;

    while (atual != NULL && atual->info.codigoSolicitacao < dados.codigoSolicitacao) // enquanto é menor, anda até ser falso
        {
            anterior = atual;
            atual = atual->prox;
        }

    if (atual != NULL && atual->info.codigoSolicitacao == dados.codigoSolicitacao) // checagem inserçao duplicada
        {
            duplicado = 1;
        }

    if (duplicado == 1)
        {
            printf("Erro: codigo de solicitacao %d ja existe.\n", dados.codigoSolicitacao);
            free(novo);
        }
    else
    {
        if (anterior == NULL)  // condição inserir no inicio da lista
            {
                novo->prox = L->inicio;
                L->inicio = novo;
            }
        else                          // condição inserir no meio ou no fim da lista
        {
                novo->prox = atual;
                anterior->prox = novo;
        }
    }

    printf("\n-----------------------------------------------------------------\n");
    printf("      Manuntencao do Equipamento Adicionado com Sucesso!");
    printf("\n-----------------------------------------------------------------\n");
}


void remover(Lista *L, int codigo)
{
    No *atual = L->inicio;
    No *anterior = NULL;
    int encontrado = 0;

    while (atual != NULL && atual->info.codigoSolicitacao != codigo) // anda enquanto nao achar o codigo
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL)
    {
        encontrado = 1;
    }

    if (encontrado == 0)
    {
        printf("Erro: codigo de solicitacao %d nao encontrado.\n", codigo);
    }
    else
    {
        if (anterior == NULL)          // remover o primeiro no da lista
        {
            L->inicio = atual->prox;
        }
        else                            // remover do meio ou do fim
        {
            anterior->prox = atual->prox;
        }

        free(atual);

        printf("\n-----------------------------------------------------------------\n");
        printf("      Solicitacao removida com sucesso!");
        printf("\n-----------------------------------------------------------------\n");
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