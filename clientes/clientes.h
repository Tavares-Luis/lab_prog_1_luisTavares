#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct {
    char nome[100];
    char email[100];
    int ID;
} Cliente;

void insere_clientes();
void listar_clientes();
void excluir_clientes();
void altera_clientes();

extern Cliente clientes[];
extern int index_cliente;

#endif



