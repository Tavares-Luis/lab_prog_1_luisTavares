#include <stdio.h>
#include <stdlib.h> // Usado para system() e para a nova função lerOpcao()

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


int main() {
    while (1) {
        // Removido o clear/cls do menu
        printf("---- SISTEMA DE VENDAS ----\n\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Listar Clientes\n");
        printf("3. Cadastrar Produto\n");
        printf("4. Listar Produtos\n");
        printf("5. Nova Venda\n");
        printf("6. Listar Vendas\n");
        printf("7. Alterar Produto\n");
        printf("8. Excluir Produto\n");
        printf("9. Alterar Venda\n");
        printf("10. Excluir Venda\n");
        printf("0. Sair\n\n");
        printf("Digite sua opcao: ");

        int opcao;
        int c; // Adiciona a declaração da variável c
        scanf("%d", &opcao);
        while ((c = getchar()) != '\n' && c != EOF); // Limpa o buffer após scanf

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
                insere_produtos();
                break;
            case 4:
                listar_produtos();
                break;
            case 5:
                gerar_venda();
                break;
            case 6:
                listar_vendas();
                break;
            case 7:
                alterar_produto();
                break;
            case 8:
                excluir_produto();
                break;
            case 9:
                alterar_venda();
                break;
            case 10:
                excluir_venda();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                return 0;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
        // O laço principal exibe o menu, lê a opção do usuário e executa a função correspondente.
        // Após cada operação, o menu é mostrado novamente até o usuário escolher 0 para sair.
        // O trecho comentado abaixo poderia ser usado para pausar a execução e aguardar o Enter.
        printf("\nPressione Enter para continuar...");
        fflush(stdout);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    return 0;
}