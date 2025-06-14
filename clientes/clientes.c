#include <stdio.h>
#include <string.h>
#include "clientes.h"

#define QTD_CLIENTE 100
int index_cliente = 0;
Cliente clientes[QTD_CLIENTE];

void insere_clientes() {
    while (index_cliente < QTD_CLIENTE) {
        printf("Insira o nome do cliente: ");
        scanf("%s", clientes[index_cliente].nome);
        printf("Insira o e-mail do cliente: ");
        scanf("%s", clientes[index_cliente].email);

        clientes[index_cliente].ID = index_cliente + 1;
        index_cliente++;

        int opcao;
        printf("Deseja inserir mais clientes?\n1 - SIM\n2 - NAO\n");
        scanf("%d", &opcao);
        if (opcao != 1) break;
    }
}

void listar_clientes() {
    for (int i = 0; i < index_cliente; i++) {
        printf("Cliente %d - Nome: %s | Email: %s\n",
               clientes[i].ID, clientes[i].nome, clientes[i].email);
    }
}

void excluir_clientes() {
    int id;
    printf("Informe o ID do cliente a excluir: ");
    scanf("%d", &id);

    if (id < 1 || id > index_cliente) {
        printf("ID invalido!\n");
        return;
    }

    for (int i = id - 1; i < index_cliente - 1; i++) {
        clientes[i] = clientes[i + 1];
        clientes[i].ID = i + 1;
    }
    index_cliente--;
    printf("Cliente removido com sucesso!\n");
}

void altera_clientes() {
    int id;
    printf("Informe o ID do cliente a alterar: ");
    scanf("%d", &id);

    if (id < 1 || id > index_cliente) {
        printf("ID invalido!\n");
        return;
    }

    printf("Novo nome: ");
    scanf("%s", clientes[id - 1].nome);
    printf("Novo email: ");
    scanf("%s", clientes[id - 1].email);
    printf("Cliente atualizado com sucesso!\n");
}
