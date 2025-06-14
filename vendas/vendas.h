#ifndef VENDA_H
#define VENDA_H

typedef struct produto_venda {
    int id_produto;
    int quantidade;
} ProdutoVenda;

typedef struct venda {
    int id_nota_fiscal;
    int id_cliente;
    ProdutoVenda produtos[10];
    float valor_total;
} Venda;

void gerar_venda();

#endif


