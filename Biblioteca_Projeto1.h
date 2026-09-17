#ifndef Biblioteca_Projeto1_H
#define Biblioteca_Projeto1_H


typedef struct Manuntencaoo
{
    int codigoSolicitacao;
    char codigoEquipamento[7];
    char nomeEquipamento[21];
    int prioridade;
    int periodo;
} Manuntencao;

typedef struct no
{
    manuntencao info;
    struct no *prox;
} No;

typedef struct lista
{
    No *inicio;
} Lista;