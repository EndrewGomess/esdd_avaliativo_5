#include "pilha.h"

bool inserir_valores(Pilha p1, int value2);

int main(int argc, char** argv) {
    Pilha minhaPilha;
    Pilha minhaPilha2;
    int menu;
    Tipo_Informacao valor;
    Tipo_Informacao valor2;

    init(&minhaPilha);
    init(&minhaPilha2);

    do{
        printf("\n1 - Empilha");
        printf("\n2 - Desempilha");
        printf("\n3 - Esvaziar");
        printf("\n4 - inserir elementos na pilha para organiza-la em ordem crescente");
        printf("\n5 - Esvaziar segunda pilha");
        printf("\n0 - Sair");
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
                printf("\nEmpilha\n\n\tValor: ");
                scanf("%d", &valor2);
                if (inserir_valores(minhaPilha2, valor2) == true) {
                    printf("\nEmpilhado com sucesso\n");
                } else {
                    printf("\nEstouro de pilha\n");
                }
                break;
            case 5:
                while(!is_empty(minhaPilha2)) {
                    int elemento;
                    pop(minhaPilha2, &valor2);
                    printf("\nValor: %d", valor2);
                }
                printf("\n\n");
                break;
            default:
                break;
        }
    }while(menu != 0);
    return 0;
}

bool inserir_valores(Pilha p1, int value2){
    Pilha pilhaAux;
    init(&pilhaAux);

    bool auxiliar1 = false;
    bool auxiliar2 = false;

    while(!is_empty(p1) || auxiliar2 == true){
        int arg;
        pop(p1, &arg);

        if (arg < value2) {
            push(pilhaAux, arg);
        }else if (arg > value2){
            push(p1, arg);
            
            break;
        }else{
            auxiliar2 = true;
        }
    }

    if(!auxiliar2){
        push(p1, value2);
        auxiliar1 = true;
    }

    while (!is_empty(pilhaAux)){
        int element;
        pop(pilhaAux, &element);
        push(p1, element);
    }

    return auxiliar1;
}