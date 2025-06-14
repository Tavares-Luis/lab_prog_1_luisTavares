#include <stdio.h>
#include <string.h>
#include "produtos.h"

#define QTD_PRODUTOS 100
Produto produtos[QTD_PRODUTOS];
int index_produto = 0;

void insere_produtos() {
    while (index_produto < QTD_PRODUTOS) {
        printf("Insira o nome do produto: ");
        scanf("%s", produtos[index_produto].nome);
        printf("Insira o preco do produto: ");
        scanf("%lf", &produtos[index_produto].preco);

        produtos[index_produto].ID = index_produto + 1;
        index_produto++;

        int opcao;
        printf("Deseja inserir mais produtos?\n1 - SIM\n2 - NAO\n");
        scanf("%d", &opcao);
        if (opcao != 1) break;
    }
}

void listar_produtos() {
    for (int j = 0; j < index_produto; j++) {
        printf("Produto %d - Nome: %s | Preco: %.2lf\n",
               produtos[j].ID, produtos[j].nome, produtos[j].preco);
    }
}