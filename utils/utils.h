#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

// Função genérica de busca
void* utils_busca(const void* array, size_t n_items, size_t item_size, const void* chave, int (*cmp)(const void*, const void*));

// Função genérica de delete
int utils_delete(void* array, size_t* n_items, size_t item_size, const void* chave, int (*cmp)(const void*, const void*));

#endif // UTILS_H

