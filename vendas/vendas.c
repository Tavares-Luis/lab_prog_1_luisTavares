#include <stdio.h>
#include "vendas.h"
#include "../clientes/clientes.h"
#include "../produtos/produtos.h"

#define MAX_VENDAS 100
Venda vendas[MAX_VENDAS];
int ultima_venda_cadastrada = 0;

void gerar_venda() {
    int id_cliente, id_produto, quantidade;
    printf("Informe o ID do cliente: ");
    scanf("%d", &id_cliente);
    while (getchar() != '\n');

    printf("Informe o ID do produto: ");
    scanf("%d", &id_produto);
    while (getchar() != '\n');

    printf("Informe a quantidade: ");
    scanf("%d", &quantidade);
    while (getchar() != '\n');

    if (id_cliente < 1 || id_cliente > index_cliente ||
        id_produto < 1 || id_produto > index_produto) {
        printf("ID de cliente ou produto invalido!\n");
        return;
    }

    ProdutoVenda prod_venda;
    prod_venda.id_produto = id_produto;
    prod_venda.quantidade = quantidade;

    double preco_unit = produtos[id_produto - 1].preco;
    double valor_total = preco_unit * quantidade;

    Venda nova_venda;
    nova_venda.id_nota_fiscal = ++ultima_venda_cadastrada;
    nova_venda.id_cliente = id_cliente;
    nova_venda.produtos[0] = prod_venda;
    nova_venda.valor_total = valor_total;

    vendas[ultima_venda_cadastrada - 1] = nova_venda;

    printf("Venda registrada com sucesso! Total: R$%.2lf\n", valor_total);
}

// Lista todas as vendas
void listar_vendas() {
    printf("\n==================== LISTA DE VENDAS ====================\n");
    if (ultima_venda_cadastrada == 0) {
        printf("Nenhuma venda cadastrada.\n");
        return;
    }
    printf("%-8s | %-30s | %-30s | %-10s | %-10s\n", "Nota", "Cliente", "Produto", "Qtd", "Total (R$)");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < ultima_venda_cadastrada; i++) {
        int id_cliente = vendas[i].id_cliente;
        int id_produto = vendas[i].produtos[0].id_produto;
        char* nome_cliente = clientes[id_cliente-1].nome;
        char* nome_produto = produtos[id_produto-1].nome;
        printf("%-8d | %-30s | %-30s | %-10d | %10.2lf\n",
            vendas[i].id_nota_fiscal,
            nome_cliente,
            nome_produto,
            vendas[i].produtos[0].quantidade,
            vendas[i].valor_total);
    }
    printf("-------------------------------------------------------------------------------------------------------------\n");
}

// Altera uma venda existente
void alterar_venda() {
    int id, encontrado = 0;
    printf("Digite o ID da venda a ser alterada: ");
    scanf("%d", &id);
    while (getchar() != '\n');
    printf("\n==== ALTERAÇÃO DE VENDA ====");
    for (int i = 0; i < ultima_venda_cadastrada; i++) {
        if (vendas[i].id_nota_fiscal == id) {
            printf("Novo ID do cliente: ");
            scanf("%d", &vendas[i].id_cliente);
            while (getchar() != '\n');
            printf("Novo ID do produto: ");
            scanf("%d", &vendas[i].produtos[0].id_produto);
            while (getchar() != '\n');
            printf("Nova quantidade: ");
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
        printf("\nVenda não encontrada!\n");
    }
}

// Exclui uma venda
void excluir_venda() {
    int id, encontrado = 0;
    printf("Digite o ID da venda a ser excluída: ");
    scanf("%d", &id);
    while (getchar() != '\n');
    printf("\n==== EXCLUSÃO DE VENDA ====");
    for (int i = 0; i < ultima_venda_cadastrada; i++) {
        if (vendas[i].id_nota_fiscal == id) {
            for (int j = i; j < ultima_venda_cadastrada - 1; j++) {
                vendas[j] = vendas[j + 1];
                vendas[j].id_nota_fiscal = j + 1;
            }
            ultima_venda_cadastrada--;
            encontrado = 1;
            printf("Venda excluída com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("\nVenda não encontrada!\n");
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
