#include <stdio.h>
#include <string.h>
#include "produtos.h"
#include "../vendas/vendas.h"

#define QTD_PRODUTOS 100
Produto produtos[QTD_PRODUTOS];
int index_produto = 0;

void insere_produtos() {
    while (index_produto < QTD_PRODUTOS) {
        printf("Insira o nome do produto: ");
        scanf(" %[^\n]", produtos[index_produto].nome);
        printf("Insira o preco do produto: ");
        scanf("%lf", &produtos[index_produto].preco);
        while (getchar() != '\n'); // Limpa o buffer

        produtos[index_produto].ID = index_produto + 1;
        index_produto++;

        int opcao = 0;
        printf("Deseja inserir mais produtos?\n1 - SIM\n2 - NAO\n");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // Limpa o buffer
        if (opcao != 1) break;
    }
}

void listar_produtos() {
    printf("\n==================== LISTA DE PRODUTOS ====================\n");
    if (index_produto == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    printf("%-5s | %-30s | %-10s\n", "ID", "Nome do Produto", "Preço (R$)");
    printf("---------------------------------------------------------------\n");
    for (int j = 0; j < index_produto; j++) {
        printf("%-5d | %-30s | %10.2lf\n",
               produtos[j].ID, produtos[j].nome, produtos[j].preco);
    }
    printf("---------------------------------------------------------------\n");
}

// Função para alterar um produto existente
void alterar_produto() {
    int id, encontrado = 0;
    printf("Digite o ID do produto a ser alterado: ");
    scanf("%d", &id);
    while (getchar() != '\n');
    printf("\n==== ALTERAÇÃO DE PRODUTO ====");
    for (int i = 0; i < index_produto; i++) {
        if (produtos[i].ID == id) {
            char novo_nome[100];
            double novo_preco;
            printf("Novo nome: ");
            scanf(" %[^\n]", novo_nome);
            printf("Novo preço: ");
            scanf("%lf", &novo_preco);
            while (getchar() != '\n');
            strcpy(produtos[i].nome, novo_nome);
            produtos[i].preco = novo_preco;
            encontrado = 1;
            printf("\nProduto alterado com sucesso!\n");
            // Atualiza as vendas que usam este produto
            atualizar_vendas_produto(id, novo_nome, novo_preco);
            break;
        }
    }
    if (!encontrado) {
        printf("\nProduto não encontrado!\n");
    }
}

// Função para excluir um produto
void excluir_produto() {
    int id, encontrado = 0;
    printf("Digite o ID do produto a ser excluído: ");
    scanf("%d", &id);
    while (getchar() != '\n');
    printf("\n==== EXCLUSÃO DE PRODUTO ====");
    // Verifica se existe venda com o produto
    if (existe_venda_com_produto(id)) {
        printf("\nNão é possível excluir: existe venda cadastrada com este produto!\n");
        return;
    }
    for (int i = 0; i < index_produto; i++) {
        if (produtos[i].ID == id) {
            // Move os produtos seguintes para "tapar o buraco"
            for (int j = i; j < index_produto - 1; j++) {
                produtos[j] = produtos[j + 1];
                produtos[j].ID = j + 1;
            }
            index_produto--;
            encontrado = 1;
            printf("Produto excluído com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("\nProduto não encontrado!\n");
    }
}
