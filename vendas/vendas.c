#include <stdio.h>
#include "vendas.h"
#include "../clientes/clientes.h"
#include "../produtos/produtos.h"

#define MAX_VENDAS 100
Venda vendas[MAX_VENDAS];
int ultima_venda_cadastrada = 0;

void gerar_venda() {
    listar_clientes();
    int id_cliente;
    printf("Informe o ID do cliente: ");
    scanf("%d", &id_cliente);

    listar_produtos();
    int id_produto, quantidade;
    printf("Informe o ID do produto: ");
    scanf("%d", &id_produto);
    printf("Informe a quantidade: ");
    scanf("%d", &quantidade);

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


