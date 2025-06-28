#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "clientes.h"
#include "../vendas/vendas.h"

#define CLIENTES_FILE "../DB/clientes.txt"
#define QTD_CLIENTE 100
int index_cliente = 0;
Cliente clientes[QTD_CLIENTE];

void salvar_clientes() {
    FILE *f = fopen(CLIENTES_FILE, "w");
    if (!f) return;
    for (int i = 0; i < index_cliente; i++) {
        fprintf(f, "%d;%s;%s\n", clientes[i].ID, clientes[i].nome, clientes[i].email);
    }
    fclose(f);
}

void carregar_clientes() {
    FILE *f = fopen(CLIENTES_FILE, "r");
    if (!f) {
        printf("[DEBUG] Nao foi possivel abrir o arquivo de clientes!\n");
        return;
    }
    index_cliente = 0;
    while (!feof(f)) {
        Cliente c;
        if (fscanf(f, "%d;%99[^;];%99[^\n]\n", &c.ID, c.nome, c.email) == 3) {
            clientes[index_cliente++] = c;
        }
    }
    fclose(f);
    printf("[DEBUG] Clientes carregados: %d\n", index_cliente);
}

void insere_clientes() {
    while (index_cliente < QTD_CLIENTE) {
        printf("Insira o nome do cliente: ");
        scanf(" %[^\n]", clientes[index_cliente].nome);
        printf("Insira o email do cliente: ");
        scanf(" %[^\n]", clientes[index_cliente].email);
        clientes[index_cliente].ID = index_cliente + 1;
        index_cliente++;
        salvar_clientes();
        int opcao = 0;
        printf("Deseja inserir mais clientes?\n1 - SIM\n2 - NAO\n");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // Limpa o buffer
        if (opcao != 1) break;
    }
}

void listar_clientes() {
    printf("\n==== LISTA DE CLIENTES ====\n");
    if (index_cliente == 0) {
        printf("Nenhum cliente cadastrado.\n");
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
    listar_clientes(); // Mostra a lista antes de pedir o ID
    int id;
    printf("\n==== ALTERACAO DE CLIENTE ====\n");
    printf("\nInforme o ID do cliente a alterar: ");
    scanf("%d", &id);
    while (getchar() != '\n'); // Limpa o buffer

    if (id < 1 || id > index_cliente) {
        printf("\nID invalido!\n");
        return;
    }
    printf("Novo nome (Nome atual: %s): ", clientes[id - 1].nome);
    scanf(" %[^\n]", clientes[id - 1].nome);
    printf("Novo email (Email atual: %s): ", clientes[id - 1].email);
    scanf(" %[^\n]", clientes[id - 1].email);
    salvar_clientes();
    printf("Cliente atualizado com sucesso!\n");
}

void excluir_clientes() {
    listar_clientes(); // Mostra a lista antes de pedir o ID
    int id;
    char buffer[100];
    printf("\n==== EXCLUSAO DE CLIENTE ====\n");
    printf("\nInforme o ID do cliente a excluir: ");
    scanf("%d", &id);
    while (getchar() != '\n'); // Limpa o buffer

    if (id < 1 || id > index_cliente) {
        printf("\nID invalido!\n");
        return;
    }
    if (existe_venda_com_cliente(id)) {
        printf("\nNao e possivel excluir: existe venda cadastrada com este cliente!\n");
        return;
    }

    for (int i = id - 1; i < index_cliente - 1; i++) {
        clientes[i] = clientes[i + 1];
        clientes[i].ID = i + 1;
    }
    index_cliente--;
    salvar_clientes();
    printf("Cliente removido com sucesso!\n");
}
