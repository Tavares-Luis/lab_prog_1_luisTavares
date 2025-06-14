#include <string.h>1
#include <stdio.h>
#include "./clientes/clientes.h"
#include "./produtos/produtos.h"
#include "./vendas/vendas.h"

int main () {
    int opcao = 0;
    do {
        printf("Selecione uma opcao: \n"
               "0 = sair\n"
               "1 = Insere cliente\n"
               "2 = Insere produto\n"
               "3 = Inserir venda\n"
               "4 = Listar clientes\n"
               "5 = Listar produtos\n"
               "6 = Excluir cliente\n"
               "7 = Alterar cliente\n");
        scanf("%d", &opcao);
        printf("\n\n");

        switch (opcao) {
            case 1:
                insere_clientes();
                break;
            case 2:
                insere_produtos();
                break;
            case 3:
                gerar_venda();
                break;
            case 4:
                listar_clientes();
                break;
            case 5:
                listar_produtos();
                break;
            case 6:
                excluir_clientes();
                break;
            case 7:
                altera_clientes();
                break;
            case 0:
                printf("Saindo do programa\n");
                break;
            default:
                printf("Opcao inválida!\n");
                break;
        }
    } while (opcao != 0);
    return 0;
}
