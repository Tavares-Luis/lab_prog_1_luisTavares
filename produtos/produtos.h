#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct {
    char nome[100];
    double preco;
    int ID;
    int estoque; // Quantidade disponível em estoque
} Produto;

void insere_produtos();
void listar_produtos();
void alterar_produto(); // Altera um produto existente
void excluir_produto(); // Exclui um produto

extern Produto produtos[];
extern int index_produto;

#endif
