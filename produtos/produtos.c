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

// Função para alterar um produto existente
void alterar_produto() {
    int id, encontrado = 0;
    printf("Digite o ID do produto a ser alterado: ");
    scanf("%d", &id);
    for (int i = 0; i < index_produto; i++) {
        if (produtos[i].ID == id) {
            char novo_nome[100];
            double novo_preco;
            printf("Novo nome: ");
            scanf("%s", novo_nome);
            printf("Novo preço: ");
            scanf("%lf", &novo_preco);
            strcpy(produtos[i].nome, novo_nome);
            produtos[i].preco = novo_preco;
            encontrado = 1;
            printf("Produto alterado com sucesso!\n");
            // Atualiza as vendas que usam este produto
            atualizar_vendas_produto(id, novo_nome, novo_preco);
            break;
        }
    }
    if (!encontrado) {
        printf("Produto não encontrado!\n");
    }
}

// Função para excluir um produto
void excluir_produto() {
    int id, encontrado = 0;
    printf("Digite o ID do produto a ser excluído: ");
    scanf("%d", &id);
    // Verifica se existe venda com o produto
    if (existe_venda_com_produto(id)) {
        printf("Não é possível excluir: existe venda cadastrada com este produto!\n");
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
        printf("Produto não encontrado!\n");
    }
}
