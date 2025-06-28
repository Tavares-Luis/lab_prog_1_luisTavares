cmake_minimum_required(VERSION 3.31)
project(lab_prog_1_luisTavares)

set(CMAKE_CXX_STANDARD 14)

include_directories(clientes)
include_directories(DB)
include_directories(produtos)
include_directories(utils)
include_directories(vendas)

add_executable(lab_prog_1_luisTavares
        clientes/clientes.c
        clientes/clientes.h
        DB/clientes.txt
        DB/produtos.txt
        DB/vendas.txt
        produtos/produtos.c
        produtos/produtos.h
        utils/utils.c
        utils/utils.h
        vendas/vendas.c
        vendas/vendas.h
        main.c)
