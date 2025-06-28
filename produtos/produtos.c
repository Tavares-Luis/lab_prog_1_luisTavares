#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "produtos.h"
#include "../vendas/vendas.h"

#define QTD_PRODUTOS 100
#define PRODUTOS_FILE "../DB/produtos.txt"

Produto produtos[QTD_PRODUTOS];
int index_produto = 0;

void salvar_produtos() {
    FILE *f = fopen(PRODUTOS_FILE, "w");
    if (!f) return;
    for (int i = 0; i < index_produto; i++) {
        fprintf(f, "%d;%s;%.2lf;%d\n", produtos[i].ID, produtos[i].nome, produtos[i].preco, produtos[i].estoque);
    }
    fclose(f);
}

void carregar_produtos() {
    FILE *f = fopen(PRODUTOS_FILE, "r");
    if (!f) return;
    index_produto = 0;
    while (!feof(f)) {
        Produto p;
        if (fscanf(f, "%d;%99[^;];%lf;%d\n", &p.ID, p.nome, &p.preco, &p.estoque) == 4) {
            produtos[index_produto++] = p;
        }
    }
    fclose(f);
}

void insere_produtos() {
    while (index_produto < QTD_PRODUTOS) {
        printf("Insira o nome do produto: ");
        scanf(" %[^\n]", produtos[index_produto].nome);
        printf("Insira o preco do produto: ");
        scanf("%lf", &produtos[index_produto].preco);
        printf("Insira a quantidade em estoque: ");
        scanf("%d", &produtos[index_produto].estoque);
        while (getchar() != '\n');
        produtos[index_produto].ID = index_produto + 1;
        index_produto++;
        salvar_produtos();
        int opcao = 0;
        printf("Deseja inserir mais produtos?\n1 - SIM\n2 - NAO\n");
        scanf("%d", &opcao);
        while (getchar() != '\n');
        if (opcao != 1) break;
    }
}

void listar_produtos() {
    printf("\n==================== LISTA DE PRODUTOS ====================\n");
    if (index_produto == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    printf("%-5s | %-30s | %-10s | %-10s\n", "ID", "Nome do Produto", "Preco (R$)", "Estoque");
    printf("--------------------------------------------------------------------------\n");
    for (int j = 0; j < index_produto; j++) {
        printf("%-5d | %-30s | %10.2lf | %-10d\n",
               produtos[j].ID, produtos[j].nome, produtos[j].preco, produtos[j].estoque);
    }
    printf("--------------------------------------------------------------------------\n");
}

// Função para alterar um produto existente
void alterar_produto() {
    listar_produtos(); // Mostra a lista antes de pedir o ID
    int id, encontrado = 0;
    printf("Digite o ID do produto a ser alterado: ");
    scanf("%d", &id);
    while (getchar() != '\n');
    printf("\n==== ALTERACAO DE PRODUTO ====\n");
    for (int i = 0; i < index_produto; i++) {
        if (produtos[i].ID == id) {
            char novo_nome[100];
            double novo_preco;
            int novo_estoque;
            printf("Novo nome (Nome atual: %s): ", produtos[i].nome);
            scanf(" %[^\n]", novo_nome);
            printf("Novo preco (Preco atual: %.2lf): ", produtos[i].preco);
            scanf("%lf", &novo_preco);
            printf("Novo estoque (Estoque atual: %d): ", produtos[i].estoque);
            scanf("%d", &novo_estoque);
            while (getchar() != '\n');
            strcpy(produtos[i].nome, novo_nome);
            produtos[i].preco = novo_preco;
            produtos[i].estoque = novo_estoque;
            encontrado = 1;
            salvar_produtos();
            printf("\nProduto alterado com sucesso!\n");
            // Atualiza as vendas que usam este produto
            atualizar_vendas_produto(id, novo_nome, novo_preco);
            break;
        }
    }
    if (!encontrado) {
        printf("\nProduto nao encontrado!\n");
    }
}

// Função para excluir um produto
void excluir_produto() {
    listar_produtos(); // Mostra a lista antes de pedir o ID
    int id, encontrado = 0;
    printf("Digite o ID do produto a ser excluido: ");
    scanf("%d", &id);
    while (getchar() != '\n');
    printf("\n==== EXCLUSAO DE PRODUTO ====\n");
    // Verifica se existe venda com o produto
    if (existe_venda_com_produto(id)) {
        printf("\nNao e possivel excluir: existe venda cadastrada com este produto!\n");
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
            salvar_produtos();
            printf("Produto removido com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("\nProduto nao encontrado!\n");
    }
}
