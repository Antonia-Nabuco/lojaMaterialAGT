# 🏗️ CONSTRUCOM — Sistema de Orçamento e Compra de Materiais de Construção

Este repositório contém o código-fonte do projeto **CONSTRUCOM**, uma aplicação desenvolvida para **facilitar o processo de orçamento e compra de materiais de construção**.  
O projeto foi criado como parte da disciplina **Algoritmos (AGT)** do **Departamento de Ciências da Computação (DCC)** da **UDESC**.

**Professora:** Everlin Costa Marques

---

## 🧩 Sobre o Projeto

O **CONSTRUCOM** tem como objetivo **automatizar e simplificar o processo de cotação e compra de materiais de construção**, oferecendo ao usuário uma experiência prática e intuitiva.  

A aplicação permite:
- Consultar um **catálogo de produtos**;
- Ver **preços e detalhes técnicos** de cada item;
- Realizar **orçamentos personalizados**;
- Finalizar a compra com **emissão automática de recibo ou nota fiscal**.

## ⚙️ Como Usar o Sistema

O fluxo de utilização do sistema é dividido em **5 etapas principais**:

### 1️⃣ Menu Inicial
Ao iniciar, o sistema apresenta as seguintes opções:
- `A` — Ver os horários de funcionamento;
- `B` — Fazer um orçamento / iniciar compra.

---

### 2️⃣ Coleta de Dados do Cliente
Ao escolher a opção `B`, o sistema solicita a identificação do cliente:
1. O usuário informa se é **Pessoa Física (PF)** ou **Pessoa Jurídica (PJ)**;
2. São solicitados os dados correspondentes (Nome, CPF/CNPJ, etc.);
3. Os dados são exibidos para confirmação — em caso de erro, o processo é refeito.

---

### 3️⃣ Catálogo e Seleção de Produtos
Após a confirmação dos dados:
1. O sistema exibe a lista de produtos disponíveis;
2. O usuário digita o **código do produto** desejado;
3. São mostrados **preço unitário, quantidade em estoque e unidade de medida**;
4. Para ver mais detalhes, o usuário pode digitar `+`;
5. Para confirmar, digite `ok` e informe a **quantidade** desejada.

---

### 4️⃣ Continuação ou Encerramento da Compra
O sistema pergunta se o usuário deseja adicionar mais itens:
- `S` — Retorna à lista de produtos;
- `N` — Finaliza o orçamento.

---

### 5️⃣ Emissão do Recibo / Nota Fiscal
Ao finalizar a compra:
1. Um **desconto de 5%** é aplicado automaticamente para **Pessoa Jurídica (PJ)**;
2. É exibido um **resumo final** com:
   - Itens comprados;
   - Quantidades;
   - Preços unitários;
   - Total final com desconto (se aplicável);
   - Dados do cliente.

---

## 💡 Tecnologias Utilizadas
- **Linguagem:** C  
- **Ambiente de desenvolvimento:** Code::Blocks / GCC  
- **Paradigma:** Programação estruturada  
- **Entrada e saída:** Terminal (CLI)

---

## 👥 Equipe de Desenvolvimento
- **Integrantes:** [Adicione aqui os nomes dos autores do projeto]
- **Disciplina:** Algoritmos (AGT)  
- **Curso:** Ciência da Computação — UDESC

---

## 📄 Licença
Este projeto foi desenvolvido para fins **educacionais** e **não possui fins comerciais**.

---
