# 🛒 Sistema de Vendas em C

Um projeto simples desenvolvido em **linguagem C** para simular o gerenciamento de clientes, produtos e vendas de uma pequena loja.

O código é organizado de forma **modular**, com responsabilidades bem divididas em pastas, facilitando a manutenção, escalabilidade e compreensão do sistema.

---

## 🆕 Novidades e Melhorias Recentes

- Submenu de busca/pesquisa: agora é possível buscar clientes, produtos ou vendas por ID, além de buscas por nome para clientes e produtos, tudo separado para evitar confusão de IDs.
- Persistência de dados: todos os dados de clientes, produtos e vendas são salvos automaticamente em arquivos texto na pasta `DB/`, garantindo que nada se perca ao fechar o programa.
- Listagem de vendas reformatada: cada venda aparece agrupada, mostrando nota, cliente, total e todos os produtos daquela venda de forma clara e separada.
- Antes de alterar ou excluir qualquer cliente, produto ou venda, o sistema exibe automaticamente a listagem correspondente para facilitar a escolha do ID.
- Ao alterar qualquer campo (nome, email, preço, estoque, etc.), o valor atual é exibido entre parênteses para facilitar a edição.
- Prevenção de conflitos de ID: cada entidade (cliente, produto, venda) tem seu próprio espaço de IDs, e as buscas são sempre feitas no contexto correto.
- Mensagens de debug e feedback melhoradas para facilitar o uso e a depuração.
- Caminhos dos arquivos ajustados para garantir funcionamento mesmo rodando em subpastas de build (ex: cmake-build-debug).
- Unificação de código: as funções de busca e exclusão foram centralizadas para evitar repetição de código, tornando o sistema mais limpo e fácil de manter.
- Operações de busca e exclusão sempre atuam em apenas uma entidade por vez, evitando qualquer ambiguidade ou conflito de IDs.

---

## 📦 Funcionalidades

O sistema oferece as seguintes operações básicas de um CRUD (Create, Read, Update, Delete) para cada módulo:

### 👤 Gerenciamento de Clientes
- ➕ Cadastrar novo cliente (nome, e-mail)
- 📋 Listar todos os clientes cadastrados
- ✏️ Alterar informações de um cliente existente (com exibição do valor atual)
- ❌ Excluir um cliente do sistema (se não houver vendas associadas, com listagem automática antes)
- 🔎 Buscar cliente por ID ou por nome

### 📦 Gerenciamento de Produtos
- ➕ Cadastrar novo produto (nome, preço)
- 📋 Listar todos os produtos disponíveis
- ✏️ Alterar informações de um produto existente (com exibição do valor atual)
- ❌ Excluir um produto do sistema (se não houver vendas associadas, com listagem automática antes)
- 🔎 Buscar produto por ID ou por nome

### 🧾 Registro e Gerenciamento de Vendas
- ➕ Realizar uma nova venda associando um cliente e múltiplos produtos
- 📋 Listar todas as vendas realizadas (agrupadas por nota fiscal, mostrando todos os produtos)
- ✏️ Alterar uma venda existente (com exibição do valor atual e listagem automática antes)
- ❌ Excluir uma venda (com listagem automática antes)
- 🔎 Buscar venda por número da nota fiscal
- 💰 Cálculo automático do valor total da venda

### 🗂️ Interface e Usabilidade
- Menus interativos no terminal
- Listagem automática antes de alterar ou excluir registros
- Exibição do valor atual ao alterar dados
- Mensagens de erro e confirmação amigáveis

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

---

## 📋 Observações

- O sistema é totalmente modularizado, com arquivos separados para clientes, produtos e vendas.
- As listagens exibem os dados em tabelas organizadas, facilitando a visualização.
- Caso encontre algum erro de símbolo não encontrado, verifique se todos os arquivos `.h` possuem as declarações corretas das funções utilizadas entre os módulos.
> ⚠️ **Caso encontre algum erro durante a compilação ou execução, anote a mensagem exibida e informe para que eu possa ajudar a corrigir!**

---

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

Desenvolvido por Luis Tavares
