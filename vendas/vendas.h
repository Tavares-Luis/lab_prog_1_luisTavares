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
void listar_vendas();    // Lista todas as vendas
void alterar_venda();    // Altera uma venda existente
void excluir_venda();    // Exclui uma venda
// Atualiza vendas quando um produto é alterado
void atualizar_vendas_produto(int id_produto, const char* novo_nome, double novo_preco);
int existe_venda_com_produto(int id_produto);
int existe_venda_com_cliente(int id_cliente);

extern Venda vendas[];
extern int ultima_venda_cadastrada;

#endif
