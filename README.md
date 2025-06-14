# 🛒 Sistema de Vendas em C

Um projeto simples desenvolvido em **linguagem C** para simular o gerenciamento de clientes, produtos e vendas de uma pequena loja.

O código é organizado de forma **modular**, com responsabilidades bem divididas em pastas, facilitando a manutenção, escalabilidade e compreensão do sistema.

---

## 📦 Funcionalidades

O sistema oferece as seguintes operações básicas de um CRUD (Create, Read, Update, Delete) para cada módulo:

* **Gerenciamento de Clientes:**
    * [✔️] Cadastrar novo cliente (Nome, CPF, contato, etc.).
    * [✔️] Listar todos os clientes cadastrados.
    * [✔️] Alterar informações de um cliente existente.
    * [✔️] Excluir um cliente do sistema.

* **Gerenciamento de Produtos:**
    * [✔️] Cadastrar novo produto (Nome, código, preço, estoque).
    * [✔️] Listar todos os produtos disponíveis.

* **Registro de Vendas:**
    * [✔️] Realizar uma nova venda associando um cliente e um ou mais produtos.
    * [✔️] Calcular o valor total da venda automaticamente.

---

## 🛠️ Como Compilar e Executar

Para compilar e executar o projeto, você precisará ter um compilador C (como o **GCC**) e o **CMake** instalados em sua máquina.

### ✅ Usando o CLion (IDE)

1.  **Abra o Projeto:** Clone ou baixe o repositório e abra a pasta do projeto no CLion.
2.  **Aguarde o Carregamento:** O CLion identificará automaticamente o arquivo `CMakeLists.txt` e preparará o ambiente.
3.  **Compile e Execute:** Clique no botão **Run (▶️)**. A IDE cuidará de todo o processo de compilação e execução.

### 💻 Usando o Terminal (Linha de Comando)

Se preferir compilar manualmente, siga os passos abaixo:

```bash
# 1. Clone o repositório (se ainda não o fez)
git clone [https://sua-url-do-repositorio.git](https://sua-url-do-repositorio.git)
cd nome-da-pasta-do-projeto

# 2. Crie um diretório para os arquivos de compilação (build) para manter o projeto limpo
mkdir build

# 3. Acesse o diretório criado
cd build

# 4. Use o CMake para gerar os arquivos de compilação (Makefiles)
# O '..' aponta para o diretório anterior, onde o CMakeLists.txt está localizado.
cmake ..

# 5. Compile o código-fonte usando o make
make

# 6. Execute o programa gerado
./sistema
