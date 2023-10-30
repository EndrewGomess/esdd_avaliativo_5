/*
 * File:   client_code.c
 * Author: Ednilson Rossi
 *
 * Created on 02 de outubro de 2023
 */

#include "pilha.h"

int verifica_pilha(char valor[]);

int main(int argc, char** argv) {
    Pilha minhaPilha;
    int menu;
    Tipo_Informacao valor;
    char palavra[50];

    init(&minhaPilha);

    do{
        printf("\n1 - Empilha");
        printf("\n2 - Desempilha");
        printf("\n3 - Esvaziar");
        printf("\n4 - String");
        printf("\n5 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("\nEmpilha\n\n\tValor: ");
                scanf("%d", &valor);
                if(push(minhaPilha, valor)){
                    printf("\nEmpilhado com sucesso\n");
                }else{
                    printf("\nEstouro de pilha\n");
                }
                break;
            case 2:
                if(pop(minhaPilha, &valor)){
                    printf("\nDesempilha\n\n\tValor: %d", valor);
                }else{
                    printf("\nPilha vazia\n");
                }
                break;
            case 3:
                while(!is_empty(minhaPilha)){
                    pop(minhaPilha, &valor);
                    printf("\nValor: %d", valor);
                }
                break;
            case 4:
                scanf("%s",palavra);
                if(verifica_pilha(palavra) == 1){
                    printf("BEM FORMADA\n");
                }else{
                    printf("MAL FORMADA\n");
                }
                break;
        }
    }while(menu != 5);
    return 0;
}



int verifica_pilha(char v[]) {
    int tamanho = strlen(v);
    Pilha verificacao;
    init(&verificacao);

    for (int i = 0; i < tamanho; i++) {
        char letra = v[i];
        if (letra == '{' || letra == '[' || letra == '(') {
            push(verificacao, letra);
        } else if (letra == '}' || letra == ']' || letra == ')') {
            if (is_empty(verificacao)) {
                return 0; // a pilha esta vazia antes de encontrar o caractere de abertura correto
            }
            char expressao;
            if (pop(verificacao, &expressao) != 1) {
                return 0; // o caractere de fechamento não corresponde ao caractere de abertura
            }
        }
    }
    
    int vazio = is_empty(verificacao);

    return vazio; // retorna 1 se a expressão estiver bem formada, caso não, retorna 0
}
