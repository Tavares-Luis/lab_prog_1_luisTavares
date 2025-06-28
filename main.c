#include <stdio.h>
#include <stdlib.h> // Usado para system() e para a nova função lerOpcao()
#include <string.h>

#include "clientes/clientes.h"
#include "produtos/produtos.h"
#include "vendas/vendas.h"


// Pequena função para pausar a execução e esperar o usuário pressionar Enter.
void pausar() {
    printf("\nPressione Enter para continuar...");
    fflush(stdout); // Garante que a mensagem aparece antes de esperar o Enter
    int c;
    // Consome todos os caracteres até o Enter
    while ((c = getchar()) != '\n' && c != EOF);
}

void buscar_menu() {
    int op;
    while (1) {
        printf("\n==================== MENU DE BUSCA ====================\n");
        printf("1. Buscar Cliente por ID\n");
        printf("2. Buscar Produto por ID\n");
        printf("3. Buscar Venda por Nota Fiscal\n");
        printf("4. Buscar Cliente por Nome\n");
        printf("5. Buscar Produto por Nome\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
        while (getchar() != '\n');
        if (op == 0) return;
        if (op == 1) {
            int id, achou = 0;
            printf("Digite o ID do cliente: ");
            scanf("%d", &id);
            while (getchar() != '\n');
            for (int i = 0; i < index_cliente; i++) {
                if (clientes[i].ID == id) {
                    printf("ID: %d | Nome: %s | Email: %s\n", clientes[i].ID, clientes[i].nome, clientes[i].email);
                    achou = 1;
                    break;
                }
            }
            if (!achou) printf("Nenhum cliente encontrado com esse ID!\n");
        } else if (op == 2) {
            int id, achou = 0;
            printf("Digite o ID do produto: ");
            scanf("%d", &id);
            while (getchar() != '\n');
            for (int i = 0; i < index_produto; i++) {
                if (produtos[i].ID == id) {
                    printf("ID: %d | Nome: %s | Preco: R$%.2lf | Estoque: %d\n", produtos[i].ID, produtos[i].nome, produtos[i].preco, produtos[i].estoque);
                    achou = 1;
                    break;
                }
            }
            if (!achou) printf("Nenhum produto encontrado com esse ID!\n");
        } else if (op == 3) {
            int nota, achou = 0;
            printf("Digite o numero da nota fiscal: ");
            scanf("%d", &nota);
            while (getchar() != '\n');
            for (int i = 0; i < ultima_venda_cadastrada; i++) {
                if (vendas[i].id_nota_fiscal == nota) {
                    printf("Nota: %d | Cliente: %s | Total: R$%.2lf\n", vendas[i].id_nota_fiscal, clientes[vendas[i].id_cliente-1].nome, vendas[i].valor_total);
                    printf("Produtos:\n");
                    for (int j = 0; j < 10; j++) {
                        if (vendas[i].produtos[j].quantidade > 0) {
                            printf("  - %s (Qtd: %d)\n", produtos[vendas[i].produtos[j].id_produto-1].nome, vendas[i].produtos[j].quantidade);
                        }
                    }
                    achou = 1;
                    break;
                }
            }
            if (!achou) printf("Nenhuma venda encontrada com essa nota fiscal!\n");
        } else if (op == 4) {
            char termo[100];
            int achou = 0;
            printf("Digite o nome do cliente: ");
            scanf(" %[^\n]", termo);
            for (int i = 0; i < index_cliente; i++) {
                if (strstr(clientes[i].nome, termo)) {
                    printf("ID: %d | Nome: %s | Email: %s\n", clientes[i].ID, clientes[i].nome, clientes[i].email);
                    achou = 1;
                }
            }
            if (!achou) printf("Nenhum cliente encontrado!\n");
        } else if (op == 5) {
            char termo[100];
            int achou = 0;
            printf("Digite o nome do produto: ");
            scanf(" %[^\n]", termo);
            for (int i = 0; i < index_produto; i++) {
                if (strstr(produtos[i].nome, termo)) {
                    printf("ID: %d | Nome: %s | Preco: R$%.2lf | Estoque: %d\n", produtos[i].ID, produtos[i].nome, produtos[i].preco, produtos[i].estoque);
                    achou = 1;
                }
            }
            if (!achou) printf("Nenhum produto encontrado!\n");
        } else {
            printf("Opcao invalida!\n");
        }
        printf("\n========================================================\n");
        printf("Pressione Enter para continuar...");
        while (getchar() != '\n');
    }
}

int main() {
    carregar_clientes();
    carregar_produtos();
    carregar_vendas();
    int c;
    while (1) {
        printf("\n========================================================\n");
        printf("                 SISTEMA DE VENDAS                     \n");
        printf("========================================================\n");
        printf("CLIENTES\n");
        printf(" 1. Cadastrar Cliente\n");
        printf(" 2. Listar Clientes\n");
        printf(" 3. Alterar Cliente\n");
        printf(" 4. Excluir Cliente\n");
        printf("PRODUTOS\n");
        printf(" 5. Cadastrar Produto\n");
        printf(" 6. Listar Produtos\n");
        printf(" 7. Alterar Produto\n");
        printf(" 8. Excluir Produto\n");
        printf("VENDAS\n");
        printf(" 9. Nova Venda\n");
        printf("10. Listar Vendas\n");
        printf("11. Alterar Venda\n");
        printf("12. Excluir Venda\n");
        printf("OUTROS\n");
        printf("13. Buscar/Pesquisar\n");
        printf(" 0. Sair\n");
        printf("========================================================\n");
        printf("Digite sua opcao: ");
        int opcao;
        scanf("%d", &opcao);
        while ((c = getchar()) != '\n' && c != EOF);
        if (opcao == 0) {
            printf("Saindo do sistema...\n");
            break;
        }
        switch (opcao) {
            case 1:
                insere_clientes();
                break;
            case 2:
                listar_clientes();
                break;
            case 3:
                altera_clientes();
                break;
            case 4:
                excluir_clientes();
                break;
            case 5:
                insere_produtos();
                break;
            case 6:
                listar_produtos();
                break;
            case 7:
                alterar_produto();
                break;
            case 8:
                excluir_produto();
                break;
            case 9:
                gerar_venda();
                break;
            case 10:
                listar_vendas();
                break;
            case 11:
                alterar_venda();
                break;
            case 12:
                excluir_venda();
                break;
            case 13:
                buscar_menu();
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
        printf("\nPressione Enter para continuar...");
        fflush(stdout);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    return 0;
}