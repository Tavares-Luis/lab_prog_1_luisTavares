#include <stdio.h>
#include <stdlib.h>

#define MAX_CLIENTES 10
#define MAX_PRODUTOS 10

typedef struct {
    char nome[50];
    char email[50];
} Cliente;
a
typedef struct {
    char nome[50];
    float preco;
} Produto;

void InsereCliente(Cliente clientes[], int *iClient) {
    int op = 0;

    if (*iClient >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    printf("Insira o nome do cliente:\n");
    scanf(" %[^\n]", clientes[*iClient].nome); // permite espaços
    printf("Insira o email do cliente:\n");
    scanf(" %[^\n]", clientes[*iClient].email);

    printf("Cliente inserido com sucesso!\n\n");
    (*iClient)++;

    printf("Deseja inserir mais clientes?\n");
    printf("1 - Sim\n");
    printf("0 - Nao\n");
    scanf("%d", &op);

    if (op == 1) {
        InsereCliente(clientes, iClient);
    }
}

void ListaClientes(Cliente clientes[], int iClient) {
    if (iClient == 0) {
        printf("Nenhum cliente cadastrado.\n\n");
        return;
    }

    printf("Lista de Clientes:\n");
    for (int i = 0; i < iClient; i++) {
        printf("%d - Nome: %s | Email: %s\n", i + 1, clientes[i].nome, clientes[i].email);
    }
    printf("\n");
}

void InsereProduto(Produto produtos[], int *iProduto) {
    if (*iProduto >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    printf("Insira o nome do produto:\n");
    scanf(" %[^\n]", produtos[*iProduto].nome);
    printf("Insira o preco do produto:\n");
    scanf("%f", &produtos[*iProduto].preco);

    printf("Produto inserido com sucesso!\n\n");
    (*iProduto)++;
}

void ListaProdutos(Produto produtos[], int iProduto) {
    if (iProduto == 0) {
        printf("Nenhum produto cadastrado.\n\n");
        return;
    }

    printf("Lista de Produtos:\n");
    for (int i = 0; i < iProduto; i++) {
        printf("%d - Nome: %s | Preco: R$ %.2f\n", i + 1, produtos[i].nome, produtos[i].preco);
    }
    printf("\n");
}

void InsereVenda() {
    printf("Venda inserida com sucesso!\n\n");
}

int main() {
    Cliente clientes[MAX_CLIENTES];
    Produto produtos[MAX_PRODUTOS];
    int iClients = 0;
    int iProdutos = 0;
    int op = 1;

    do {
        printf("---------------------\n");
        printf("Menu de Selecao:\n");
        printf("0 - Sair do Programa\n");
        printf("1 - Inserir Cliente\n");
        printf("2 - Inserir Produto\n");
        printf("3 - Inserir Venda\n");
        printf("4 - Listar Clientes\n");
        printf("5 - Listar Produtos\n");
        printf("---------------------\n");
        scanf("%d", &op);
        printf("---------------------\n\n");

        if (op == 1) {
            InsereCliente(clientes, &iClients);
        } else if (op == 2) {
            InsereProduto(produtos, &iProdutos);
        } else if (op == 3) {
            InsereVenda();
        } else if (op == 4) {
            ListaClientes(clientes, iClients);
        } else if (op == 5) {
            ListaProdutos(produtos, iProdutos);
        }

    } while (op != 0);

    printf("Programa encerrado.\n");
    return 0;
}