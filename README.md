# 🛒 Sistema de Vendas em C

Um projeto simples desenvolvido em **linguagem C** para simular o gerenciamento de clientes, produtos e vendas de uma pequena loja.

O código é organizado de forma **modular**, com responsabilidades bem divididas em pastas, facilitando a manutenção, escalabilidade e compreensão do sistema.

---

## 📦 Funcionalidades

O sistema oferece as seguintes operações básicas de um CRUD (Create, Read, Update, Delete) para cada módulo:

### 👤 Gerenciamento de Clientes
- ➕ Cadastrar novo cliente (nome, e-mail)
- 📋 Listar todos os clientes cadastrados
- ✏️ Alterar informações de um cliente existente
- ❌ Excluir um cliente do sistema (se não houver vendas associadas)

### 📦 Gerenciamento de Produtos
- ➕ Cadastrar novo produto (nome, preço)
- 📋 Listar todos os produtos disponíveis
- ✏️ Alterar informações de um produto existente
- ❌ Excluir um produto do sistema (se não houver vendas associadas)

### 🧾 Registro e Gerenciamento de Vendas
- ➕ Realizar uma nova venda associando um cliente e um produto
- 📋 Listar todas as vendas realizadas
- ✏️ Alterar uma venda existente
- ❌ Excluir uma venda
- 💰 Cálculo automático do valor total da venda

---

## 🛠️ Como Compilar e Executar

Para compilar e executar o projeto, você precisará ter um compilador C (como o **GCC**) e o **CMake** instalados em sua máquina.

### ✅ Usando o CLion (IDE)

1.  **Abra o Projeto:** Clone ou baixe o repositório e abra a pasta do projeto no CLion.
2.  **Aguarde o Carregamento:** O CLion identificará automaticamente o arquivo `CMakeLists.txt` e preparará o ambiente.
3.  **Compile e Execute:** Clique no botão **Run (▶️)**. A IDE cuidará de todo o processo de compilação e execução.

### ⚙️ Como corrigir problemas com o CMake no CLion

Se você já possui um projeto com CMake e está enfrentando problemas de build, siga este passo a passo para reconfigurar o ambiente:

1. Abra o projeto normalmente no CLion.
2. Clique nas **três barrinhas** no canto superior esquerdo da IDE para abrir o menu lateral.
3. Vá até a seção **Tools**.
4. Desça até encontrar **CMake** e clique em **Unload CMake Project**.
5. No explorador de arquivos do projeto, **delete** os arquivos/pastas `CMakeLists.txt` e `cmake-build-debug`.
6. Abra novamente o menu das três barrinhas, vá em **File** e selecione **Create CMake Project**.
7. Selecione **todos os arquivos que contêm código-fonte** (normalmente arquivos `.c` e `.h`).
8. O CLion irá gerar um novo `CMakeLists.txt` e reconfigurar o ambiente.
9. Compile e execute normalmente pelo botão **Run (▶️)**.

> **Dica:** Sempre que houver problemas de build ou mudanças grandes na estrutura do projeto, refaça esse processo para garantir que o CMake reconheça todos os arquivos corretamente.

---

### 💻 Compilação manual via terminal

Se preferir compilar manualmente, siga os passos abaixo:

```sh
mkdir build
cd build
cmake ..
cmake --build .
./lab_prog_1_luisTavares
```

---

## 📋 Observações

- O sistema é totalmente modularizado, com arquivos separados para clientes, produtos e vendas.
- As listagens exibem os dados em tabelas organizadas, facilitando a visualização.
- Caso encontre algum erro de símbolo não encontrado, verifique se todos os arquivos `.h` possuem as declarações corretas das funções utilizadas entre os módulos.
> ⚠️ **Caso encontre algum erro durante a compilação ou execução, anote a mensagem exibida e informe para que eu possa ajudar a corrigir!**

---

Desenvolvido por Luis Tavares
