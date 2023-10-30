/*
 * File:   client_code.c
 * Author: Ednilson Rossi
 *
 * Created on 02 de outubro de 2023
 */

#include "pilha.h"

void to_empty(Pilha pilha);

int main(int argc, char** argv) {
    Pilha minhaPilha;
    Tipo_Informacao valor;
    init(&minhaPilha);

    printf("digite o valor : ");
    scanf("%d", &valor);

    int resto;
    char resultado[10];
    int i = 0;

    while (valor > 0) {
    resto = valor % 2;
    valor = valor / 2;
    push(minhaPilha, resto);
    }


    while (!is_empty(minhaPilha)) {
        pop(minhaPilha, &valor);
        resultado[i] = valor + '0'; // converte o digito binario para um caractere
        i++;
    }

    resultado[i] = '\0'; // add o terminador de string ao final do array

    printf("binario: %s\n", resultado);
    return 0;
}
