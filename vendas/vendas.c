#include <stdio.h>
#include <stdlib.h>
#include "vendas.h"
#include "../clientes/clientes.h"
#include "../produtos/produtos.h"

#define MAX_VENDAS 100
#define VENDAS_FILE "../DB/vendas.txt"

Venda vendas[MAX_VENDAS];
int ultima_venda_cadastrada = 0;

void salvar_vendas() {
    FILE *f = fopen(VENDAS_FILE, "w");
    if (!f) return;
    for (int i = 0; i < ultima_venda_cadastrada; i++) {
        fprintf(f, "%d;%d;%.2f", vendas[i].id_nota_fiscal, vendas[i].id_cliente, vendas[i].valor_total);
        for (int j = 0; j < 10; j++) {
            fprintf(f, ";%d,%d", vendas[i].produtos[j].id_produto, vendas[i].produtos[j].quantidade);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void carregar_vendas() {
    FILE *f = fopen(VENDAS_FILE, "r");
    if (!f) return;
    ultima_venda_cadastrada = 0;
    while (!feof(f)) {
        Venda v;
        int campos = fscanf(f, "%d;%d;%f", &v.id_nota_fiscal, &v.id_cliente, &v.valor_total);
        if (campos != 3) break;
        for (int j = 0; j < 10; j++) {
            fscanf(f, ";%d,%d", &v.produtos[j].id_produto, &v.produtos[j].quantidade);
        }
        fscanf(f, "\n");
        vendas[ultima_venda_cadastrada++] = v;
    }
    fclose(f);
}

void gerar_venda() {
    int id_cliente;
    printf("Informe o ID do cliente: ");
    scanf("%d", &id_cliente);
    while (getchar() != '\n');

    if (id_cliente < 1 || id_cliente > index_cliente) {
        printf("ID de cliente invalido!\n");
        return;
    }

    Venda nova_venda;
    nova_venda.id_nota_fiscal = ++ultima_venda_cadastrada;
    nova_venda.id_cliente = id_cliente;
    nova_venda.valor_total = 0;
    int num_produtos = 0;
    char opcao;
    do {
        if (num_produtos >= 10) {
            printf("Limite de produtos por venda atingido.\n");
            break;
        }
        int id_produto, quantidade;
        printf("Informe o ID do produto: ");
        scanf("%d", &id_produto);
        while (getchar() != '\n');
        printf("Informe a quantidade: ");
        scanf("%d", &quantidade);
        while (getchar() != '\n');
        if (id_produto < 1 || id_produto > index_produto) {
            printf("ID de produto invalido!\n");
            continue;
        }
        if (produtos[id_produto - 1].estoque < quantidade) {
            printf("Estoque insuficiente para o produto '%s'. Disponivel: %d\n",
                   produtos[id_produto - 1].nome, produtos[id_produto - 1].estoque);
            continue;
        }
        ProdutoVenda prod_venda;
        prod_venda.id_produto = id_produto;
        prod_venda.quantidade = quantidade;
        nova_venda.produtos[num_produtos++] = prod_venda;
        double preco_unit = produtos[id_produto - 1].preco;
        nova_venda.valor_total += preco_unit * quantidade;
        // Desconta do estoque
        produtos[id_produto - 1].estoque -= quantidade;
        printf("Adicionar mais um produto? (s/n): ");
        scanf(" %c", &opcao);
        while (getchar() != '\n');
    } while (opcao == 's' || opcao == 'S');

    if (num_produtos == 0) {
        printf("Nenhum produto foi adicionado a venda. Venda cancelada.\n");
        ultima_venda_cadastrada--;
        return;
    }

    // Preencher o restante do array com valores padrão
    for (int i = num_produtos; i < 10; i++) {
        nova_venda.produtos[i].id_produto = 0;
        nova_venda.produtos[i].quantidade = 0;
    }

    vendas[ultima_venda_cadastrada - 1] = nova_venda;
    salvar_vendas();
    printf("Venda registrada com sucesso! Total: R$%.2lf\n", nova_venda.valor_total);
}

// Lista todas as vendas
void listar_vendas() {
    printf("\n==================== LISTA DE VENDAS ====================\n");
    if (ultima_venda_cadastrada == 0) {
        printf("Nenhuma venda cadastrada.\n");
        return;
    }
    for (int i = 0; i < ultima_venda_cadastrada; i++) {
        int id_cliente = vendas[i].id_cliente;
        char* nome_cliente = clientes[id_cliente-1].nome;
        printf("Nota: %d | Cliente: %s | Total: R$%.2lf\n", vendas[i].id_nota_fiscal, nome_cliente, vendas[i].valor_total);
        for (int j = 0; j < 10; j++) {
            if (vendas[i].produtos[j].quantidade > 0) {
                int id_produto = vendas[i].produtos[j].id_produto;
                char* nome_produto = produtos[id_produto-1].nome;
                printf("  Produto: %-20s | Qtd: %d\n", nome_produto, vendas[i].produtos[j].quantidade);
            }
        }
        printf("------------------------------------------------------------\n");
    }
}

// Altera uma venda existente
void alterar_venda() {
    listar_vendas(); // Mostra a lista antes de pedir o ID
    int id, encontrado = 0;
    printf("Digite o ID da venda a ser alterada: ");
    scanf("%d", &id);
    while (getchar() != '\n');
    printf("\n==== ALTERACAO DE VENDA ====");
    for (int i = 0; i < ultima_venda_cadastrada; i++) {
        if (vendas[i].id_nota_fiscal == id) {
            printf("Novo ID do cliente (ID atual: %d): ", vendas[i].id_cliente);
            scanf("%d", &vendas[i].id_cliente);
            while (getchar() != '\n');
            printf("Novo ID do produto (ID atual: %d): ", vendas[i].produtos[0].id_produto);
            scanf("%d", &vendas[i].produtos[0].id_produto);
            while (getchar() != '\n');
            printf("Nova quantidade (Qtd atual: %d): ", vendas[i].produtos[0].quantidade);
            scanf("%d", &vendas[i].produtos[0].quantidade);
            while (getchar() != '\n');
            double preco_unit = produtos[vendas[i].produtos[0].id_produto - 1].preco;
            vendas[i].valor_total = preco_unit * vendas[i].produtos[0].quantidade;
            encontrado = 1;
            printf("\nVenda alterada com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("\nVenda nao encontrada!\n");
    }
}

// Exclui uma venda
void excluir_venda() {
    listar_vendas(); // Mostra a lista antes de pedir o ID
    int id, encontrado = 0;
    printf("Digite o ID da venda a ser excluida: ");
    scanf("%d", &id);
    while (getchar() != '\n');
    printf("\n==== EXCLUSAO DE VENDA ====\n");
    for (int i = 0; i < ultima_venda_cadastrada; i++) {
        if (vendas[i].id_nota_fiscal == id) {
            for (int j = i; j < ultima_venda_cadastrada - 1; j++) {
                vendas[j] = vendas[j + 1];
                vendas[j].id_nota_fiscal = j + 1;
            }
            ultima_venda_cadastrada--;
            encontrado = 1;
            printf("Venda excluida com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("\nVenda nao encontrada!\n");
    }
}

// Atualiza vendas quando um produto é alterado
void atualizar_vendas_produto(int id_produto, const char* novo_nome, double novo_preco) {
    for (int i = 0; i < ultima_venda_cadastrada; i++) {
        for (int j = 0; j < 10; j++) {
            if (vendas[i].produtos[j].id_produto == id_produto && vendas[i].produtos[j].quantidade > 0) {
                // Atualiza o valor total da venda com o novo preço
                vendas[i].valor_total = 0;
                for (int k = 0; k < 10; k++) {
                    if (vendas[i].produtos[k].quantidade > 0) {
                        int pid = vendas[i].produtos[k].id_produto;
                        double preco = (pid == id_produto) ? novo_preco : produtos[pid-1].preco;
                        vendas[i].valor_total += preco * vendas[i].produtos[k].quantidade;
                    }
                }
            }
        }
    }
}

// Verifica se existe venda com o cliente
int existe_venda_com_cliente(int id_cliente) {
    for (int i = 0; i < ultima_venda_cadastrada; i++) {
        if (vendas[i].id_cliente == id_cliente) {
            return 1;
        }
    }
    return 0;
}

// Verifica se existe venda com o produto
int existe_venda_com_produto(int id_produto) {
    for (int i = 0; i < ultima_venda_cadastrada; i++) {
        for (int j = 0; j < 10; j++) {
            if (vendas[i].produtos[j].id_produto == id_produto && vendas[i].produtos[j].quantidade > 0) {
                return 1;
            }
        }
    }
    return 0;
}

// Removidas chamadas de carregar_vendas() das funções abaixo, pois os dados agora são carregados apenas uma vez no início do programa (main).
// Nenhuma chamada a carregar_vendas() encontrada nas funções de cadastro, alteração, exclusão ou listagem de vendas.
// Certifique-se de chamar carregar_vendas() apenas no início do programa (main.c).
