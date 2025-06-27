#include <stdio.h>
#include <stdlib.h> // Usado para system() e para a nova função lerOpcao()

#include "clientes/clientes.h"
#include "produtos/produtos.h"
#include "vendas/vendas.h"


// Função para ler um número inteiro da entrada de forma segura.
// Evita que o programa quebre ou entre em loop infinito se o usuário digitar letras.
int lerOpcao() {
    char buffer[100];
    long opcao;
    char *end;

    // Tenta ler uma linha inteira da entrada padrão (teclado)
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Converte o texto lido para um número longo (strtol)
        opcao = strtol(buffer, &end, 10);

        // A conversão é válida se 'end' for diferente do início do 'buffer'
        // e se o caractere onde a conversão parou for uma quebra de linha ou o fim do texto.
        if (end != buffer && (*end == '\n' || *end == '\0')) {
            return (int)opcao; // Retorna o número convertido
        }
    }

    return -1;
}

// Pequena função para pausar a execução e esperar o usuário pressionar Enter.
void pausar() {
    printf("\nPressione Enter para continuar...");
    // Loop para consumir qualquer caractere restante no buffer até encontrar o Enter ou o fim do arquivo.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    // Se a função lerOpcao() já consumiu o Enter, o getchar() abaixo espera por uma nova entrada.
    if (c != '\n') {
       getchar();
    }
}


int main() {
    int opcao;

    do {
        // --- MELHORIA ---
        // Limpa a tela no início de cada exibição do menu.
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

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


        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                cadastrarCliente();
                pausar();
                break;
            case 2:
                listarClientes();
                pausar();
                break;
            case 3:
                cadastrarProduto();
                pausar();
                break;
            case 4:
                listarProdutos();
                pausar();
                break;
            case 5:
                realizarVenda();
                pausar();
                break;
            case 6:
                listarVendas();
                pausar();
                break;
            case 7:
                alterar_produto();
                pausar();
                break;
            case 8:
                excluir_produto();
                pausar();
                break;
            case 9:
                alterar_venda();
                pausar();
                break;
            case 10:
                excluir_venda();
                pausar();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            case -1: // Caso especial para tratar entrada de texto
                printf("\nOpcao invalida! Voce digitou um texto. Por favor, digite apenas numeros.\n");
                pausar();
                break;
            default: // Caso para números que não são opções válidas
                printf("\nOpcao invalida! Escolha um numero entre 0 e 6.\n");
                pausar();
                break;
        }

    } while (opcao != 0);

    return 0;
}