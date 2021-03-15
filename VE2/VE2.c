#include <stdio.h>
#include <stdlib.h>

#include "VE2.h"

struct ve2 {
    int capacidade; //Tamanho do array F
    int ini;        //Posicao do "primeiro" elemento
    int fim;        //Posição livre onde um elemento deve ser inserido
    int n;          //Número de elementos na estrutura
    int *F;         //Array para armazenar os elementos
};

VE2 *criaVE2(int capacidade) {
    /*Verifique se o valor em capacidade é válido */
    if (capacidade<1){
        printf("Valor inválido\n");
        return NULL;
    }else{
    /*Se for, inicialize n, ini e fim com 0 (indicando que a estrutura está vazia) */

        VE2 *vetor = malloc(sizeof(VE2));
        if (vetor == NULL){ //verifica se a alocação foi feita fa forma correta
            printf("\n Memória Insuficiente :/ \n");
            exit(1);
        }
        vetor->capacidade = capacidade;
        vetor-> n = 0; // iniciando n com 0;
        vetor-> ini = 0; // iniciando ini com 0;
        vetor-> fim = 0; // iniciando fim com 0;

        /*Aloque o array 'F' e retorne o ponteiro da estrutura */
        vetor-> F = malloc(capacidade*sizeof(int));
        if (vetor->F == NULL){
            free(vetor);
            printf("\n Memória Insuficiente :/ \n");
            exit(1);
        }else{
            for (int i=0;i<capacidade;i++){ //Adicionando todos os campos do vetor como vazio (para nao dar erro na verificação -  de vazio ou cheio)
                vetor->F[i] = -1;
            }
        }
        return vetor;
    }
    return NULL;
}

void liberaVE2(VE2 *vetor) {
    /* Faz a desalocação de memória */
    if(vetor == NULL){
        printf("\n Vetor alocado de forma Invalida :/ \n");
        return;
    }
    free(vetor->F);
    free(vetor);
    //vetor = NULL;
}

void adicionaVE2(VE2 *vetor, int v) {
    /* Adiciona um elemento no FIM do vetor */
    if (vetor->n==vetor->capacidade){
        printf("\n Vetor alocado de forma Invalida :/ \n");
        return;
    }else{
        /* Lembre-se de verificar se há espaço para adicionar o elemento */
        vetor->F [vetor->fim % vetor->capacidade] = v;
        vetor->fim++;
        vetor->n++;
    }
}

void removeVE2(VE2 *vetor) {
    vetor-> ini=(vetor->ini + 1)%vetor->capacidade;
    vetor->n --; //Tira uma posição/ diminui o vetor;
    /* Complexidade: O(1)  */
}

int obtemElementoVE2(VE2 *vetor){
    /*Retorna o elemento ultimo */
    return vetor->F[vetor->ini];
    /* Complexidade: O(1)  */
}

int vazioVE2(VE2 *vetor) { //ok
    /* Verifica se a estrutura está vazia */
    if (vetor->n == 0){ //numero valido
        return 1;
    }
    return 0;
    /* Complexidade: O(1)  */
}

int cheioVE2(VE2 *vetor) {
    /* Verifica se a estrutura está cheia */
    if(vetor->n == vetor->capacidade){
        printf("ta cheio\n");
        return 1;//retorna um valor maior que ZERO por conta de ser VALIDO
    }
    return 0;//retorna zero caso INVALIDO
    /* Complexidade: O(1)  */
}

int tamanhoVE2(VE2 *vetor) {
    return vetor->n;
    /* Complexidade: O(1)  */
}

/*
>>> O que mudaria se optarmos por não usar esse campo e sempre manter o primeiro elemento na posição 0?
Irei sobrepor os elementos do vetor;

>>> A complexidade para inserir e remover um elemento seriam as mesmas?
Nesta caso não.
*/

