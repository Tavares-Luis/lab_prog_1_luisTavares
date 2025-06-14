#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct {
    char nome[100];
    double preco;
    int ID;
} Produto;

void insere_produtos();
void listar_produtos();

extern Produto produtos[];
extern int index_produto;

#endif



