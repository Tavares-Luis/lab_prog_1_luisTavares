cmake_minimum_required(VERSION 3.31)
project(lab_prog_1_luisTavares C)

set(CMAKE_C_STANDARD 11)

include_directories(clientes)
include_directories(produtos)
include_directories(vendas)

add_executable(lab_prog_1_luisTavares
        clientes/clientes.c
        clientes/clientes.h
        produtos/produtos.c
        produtos/produtos.h
        vendas/vendas.c
        vendas/vendas.h
        main.c)
