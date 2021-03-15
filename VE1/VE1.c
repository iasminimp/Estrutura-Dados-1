#include <stdio.h>
#include <stdlib.h>

#include "VE1.h"

struct ve1 {
    int capacidade; //Tamanho do array F
    int n;          //Posição do útimo elemento (também pode ser usado para determinar o #elementos)
    int *P;         //Array para armazenar os elementos na estrutura
};

VE1 *criaVE1(int capacidade) {
    /*Verifique se o valor em capacidade é válido */
    if (capacidade<1){
        printf("Valor inválido\n");
        return NULL;
    }else{
    /*Se for, inicialize n com -1 (indicando que a estrutura está vazia) */
        VE1 *vetor = malloc(sizeof(VE1));
        if (vetor == NULL){ //verifica se a alocação foi feita fa forma correta
            printf("\n Memória Insuficiente :/ \n");
            exit(1);
        }
        vetor->capacidade = capacidade;
        vetor-> n = -1; // iniciando n com -1 (indicando que a estrutura está vazia)
        vetor-> P = malloc(capacidade*sizeof(int));
    /*Aloque o array 'P' e retorne o ponteiro da estrutura */
        if (vetor->P == NULL){
            free(vetor);
            printf("\n Memória Insuficiente :/ \n");
            exit(1);
        }else{
            for (int i=0;i<capacidade;i++){ //Adicionando todos os campos do vetor como vazio (para nao dar erro na verificação -  de vazio ou cheio)
                vetor->P[i] = -1;
            }
        }
        return vetor;
    }
}

void liberaVE1(VE1 *vetor) {
    /* Faz a desalocação de memória */
    if(vetor == NULL){
        printf("\n Vetor alocado de forma Invalida :/ \n");
        return;
    }
    if (vetor->P != NULL){
        free (vetor->P); //liberando o vetor;
    }
    free(vetor);
    vetor = NULL;
    /* Complexidade: O(1)*/
}

void adicionaVE1(VE1 *vetor, int v) {
    /* Adiciona um elemento no fim do vetor */
    if (vetor == NULL || vetor->P == NULL){
        printf("\n Vetor alocado de forma Invalida :/ \n");
        return;
    }else{
        /* Lembre-se de verificar se há espaço para adicionar o elemento */
        if (vetor->n < vetor->capacidade-1){
            vetor->n++;
            vetor->P [vetor->n] = v;
        }else{
            printf("\n Vetor não possui espaço :/ \n");
        }
    }
    /* Complexidade: O(2)*/
}

void removeVE1(VE1 *vetor) {//n=-1
    /* Retira o ultimo elemento*/
    if(vetor->n < 0){
        return;
    }
    vetor ->P[vetor->n] = -1; //valores menores que ZERO = VAZIO;
    vetor->n --; //Tira uma posição/ diminui o vetor;
    /* Complexidade: O(1)  */

}

int obtemElementoVE1(VE1 *vetor){
    /*Retorna o elemento ultimo*/
    return vetor->P[vetor->n];
     /* Complexidade: O(1)  */
}

int vazioVE1(VE1 *vetor) {
    /* Verifica se a estrutura possui algum elemento ou está vazia */
    //numero negativo == vetor VAZIO
    if (vetor->P[0] >= 0){ //numero valido
        return 0;
    }
    return 1;
    /* Complexidade: O(1)  */
}

int cheioVE1(VE1 *vetor) {
    /* Verifica se a estrutura está cheia */
    if(vetor->capacidade == vetor->n+1){
        printf("ta cheio\n");
        return 1;//retorna um valor maior que ZERO por conta de ser VALIDO
    }
    return 0;//retorna zero caso INVALIDO
    /* Complexidade: O(1)  */
}

int tamanhoVE1(VE1 *vetor) {
    /* Retorna o número de elementos que a estrutura armazena */
    int soma=0;
    //int i=0;
    int tamanho =0;
    tamanho = vetor->capacidade; //Acessando o tamanho do vetor
    for (int i =0; i<tamanho; i++){
        if (vetor->P[i] >= 0){ //numero válido
            soma++;
        }
    }
    return soma;
    /* Complexidade: O(n)  */
}
