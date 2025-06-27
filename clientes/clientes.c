#include <stdio.h>
#include <string.h>
#include "clientes.h"
#include "../vendas/vendas.h"

#define QTD_CLIENTE 100
int index_cliente = 0;
Cliente clientes[QTD_CLIENTE];

void insere_clientes() {
    while (index_cliente < QTD_CLIENTE) {
        printf("Insira o nome do cliente: ");
        scanf(" %[^\n]", clientes[index_cliente].nome);
        printf("Insira o e-mail do cliente: ");
        scanf(" %[^\n]", clientes[index_cliente].email);

        clientes[index_cliente].ID = index_cliente + 1;
        index_cliente++;

        int opcao = 0;
        printf("Deseja inserir mais clientes?\n1 - SIM\n2 - NAO\n");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // Limpa o buffer
        if (opcao != 1) break;
    }
}

void listar_clientes() {
    printf("\n==== LISTA DE CLIENTES ====");
    if (index_cliente == 0) {
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }
    printf("\n%-5s | %-30s | %-30s\n", "ID", "Nome", "Email");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < index_cliente; i++) {
        printf("%-5d | %-30s | %-30s\n",
               clientes[i].ID, clientes[i].nome, clientes[i].email);
    }
    printf("--------------------------------------------------------------------------\n");
}

void altera_clientes() {
    int id;
    printf("\n==== ALTERAÇÃO DE CLIENTE ====");
    printf("\nInforme o ID do cliente a alterar: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    if (id < 1 || id > index_cliente) {
        printf("\nID invalido!\n");
        return;
    }
    printf("Novo nome: ");
    scanf(" %[^\n]", clientes[id - 1].nome);
    printf("Novo email: ");
    scanf(" %[^\n]", clientes[id - 1].email);
    printf("Cliente atualizado com sucesso!\n");
    // Atualização automática das vendas não é necessária para clientes,
    // pois vendas só guardam o ID do cliente, não nome/email.
}

void excluir_clientes() {
    int id;
    char buffer[100];
    printf("\n==== EXCLUSÃO DE CLIENTE ====");
    printf("\nInforme o ID do cliente a excluir: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    if (id < 1 || id > index_cliente) {
        printf("\nID invalido!\n");
        return;
    }
    if (existe_venda_com_cliente(id)) {
        printf("\nNão é possível excluir: existe venda cadastrada com este cliente!\n");
        return;
    }

    for (int i = id - 1; i < index_cliente - 1; i++) {
        clientes[i] = clientes[i + 1];
        clientes[i].ID = i + 1;
    }
    index_cliente--;
    printf("Cliente removido com sucesso!\n");
}
