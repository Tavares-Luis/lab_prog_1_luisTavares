#include "utils.h"
#include <string.h>

void* utils_busca(const void* array, size_t n_items, size_t item_size, const void* chave, int (*cmp)(const void*, const void*)) {
    for (size_t i = 0; i < n_items; i++) {
        const void* item = (const char*)array + i * item_size;
        if (cmp(item, chave) == 0) {
            return (void*)item;
        }
    }
    return NULL;
}

int utils_delete(void* array, size_t* n_items, size_t item_size, const void* chave, int (*cmp)(const void*, const void*)) {
    for (size_t i = 0; i < *n_items; i++) {
        void* item = (char*)array + i * item_size;
        if (cmp(item, chave) == 0) {
            // Move os itens seguintes para trás
            memmove(item, (char*)item + item_size, (*n_items - i - 1) * item_size);
            (*n_items)--;
            return 1; // Sucesso
        }
    }
    return 0; // Não encontrado
}

