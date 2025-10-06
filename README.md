# CONSTRUCOM - Sistema de Orçamento e Compra de Materiais de Construção

[cite_start]Este repositório contém o código-fonte do projeto **CONSTRUCOM**, uma aplicação de orçamento e compra de materiais de construção desenvolvida para a disciplina de Algoritmos (AGT) do Departamento de Ciências da Computação (DCC) da UDESC. [cite: 1, 2, 3, 6]

[cite_start]**Professora:** Everlin Costa Marques [cite: 4]

## Sobre o Projeto

[cite_start]O sistema CONSTRUCOM é uma aplicação desenvolvida para facilitar o processo de orçamento e compra de materiais de construção. [cite: 6] [cite_start]A plataforma permite que o usuário visualize um catálogo de produtos, consulte preços, acesse informações detalhadas e finalize a compra com a emissão de um recibo ou nota fiscal. [cite: 7]

## Catálogo de Produtos

O sistema conta com uma variedade de produtos essenciais para construção e reforma:

### Cimento
* [cite_start]**Nome Comercial:** Cimento CP-II [cite: 9]
* [cite_start]**Tipo:** Ligante [cite: 9]
* [cite_start]**Fabricante:** Votoran [cite: 12]
* [cite_start]**Fornecedor:** Casa do Construtor [cite: 17]
* [cite_start]**Descrição:** Cimento de alta qualidade, ideal para concreto, argamassa e obras de alvenaria, proporcionando resistência e durabilidade. [cite: 14, 15]
* [cite_start]**Embalagem:** Sacos de 50 kg. [cite: 10, 11]

### Tijolo
* [cite_start]**Nome Comercial:** Tijolo 6 furos [cite: 24]
* [cite_start]**Tipo:** Alvenaria [cite: 25]
* [cite_start]**Fabricante:** Cerâmica Alfa [cite: 28]
* [cite_start]**Fornecedor:** Distribuidora Rocha [cite: 28]
* [cite_start]**Descrição:** Adequado para a construção de paredes e muros, oferecendo boa resistência e eficiência. [cite: 35, 36]
* [cite_start]**Embalagem:** Pallet com 1000 unidades. [cite: 26, 27, 30]

### Tinta
* [cite_start]**Nome Comercial:** Tinta Acrílica Branco Neve [cite: 40, 41]
* [cite_start]**Tipo:** Pintura [cite: 42]
* [cite_start]**Fabricante:** Suvinil [cite: 45]
* [cite_start]**Fornecedor:** ConstruMais [cite: 46]
* [cite_start]**Descrição:** Tinta acrílica de acabamento fosco para ambientes internos e externos, com alta cobertura e resistência às intempéries. [cite: 51, 52, 53, 54]
* [cite_start]**Embalagem:** Galão de 18 litros. [cite: 43, 44]

### Pincel
* [cite_start]**Nome Comercial:** Pincel Tigre 3" [cite: 66]
* [cite_start]**Tipo:** Ferramenta [cite: 67]
* [cite_start]**Fabricante:** Tigre [cite: 70]
* [cite_start]**Fornecedor:** Ferragens Ltda [cite: 71]
* [cite_start]**Descrição:** Pincel com cerdas sintéticas e cabo ergonômico, ideal para pintura e aplicação de revestimentos. [cite: 74]
* [cite_start]**Embalagem:** Caixa com 10 unidades. [cite: 68, 69]

### Arame
* [cite_start]**Nome Comercial:** Arame recozido 18 [cite: 78]
* [cite_start]**Tipo:** Fixação [cite: 79]
* [cite_start]**Fabricante:** Belgo Bekaert [cite: 82]
* [cite_start]**Fornecedor:** Depósito Central [cite: 82]
* [cite_start]**Descrição:** Arame de alta resistência utilizado para amarrações e fixações em estruturas metálicas e uso geral na construção civil. [cite: 86, 87]
* [cite_start]**Embalagem:** Bobina de 50 metros. [cite: 80, 81]

## Como Usar o Sistemaknow how to fix an issue, consider opening a pull request for it.

Learn more about pull requests 

O fluxo de utilização do sistema é dividido em 5 etapas principais:

### Etapa 1: Menu Inicial
Ao iniciar, o sistema apresenta as seguintes opções:
* [cite_start]`A` - Para ver os horários. [cite: 94]
* [cite_start]`B` - Para fazer um orçamento / iniciar compra. [cite: 95]

### Etapa 2: Coleta de Dados do Cliente
Ao escolher a opção `B`, o sistema solicita a identificação do cliente:
1.  [cite_start]O usuário informa se é **Pessoa Física (PF)** ou **Pessoa Jurídica (PJ)**. [cite: 100]
2.  [cite_start]Com base na escolha, são solicitados os dados correspondentes (Nome, CPF/CNPJ, etc.). [cite: 101]
3.  Os dados são exibidos para confirmação. [cite_start]Em caso de erro, o processo é refeito. [cite: 102, 103]

### Etapa 3: Catálogo e Seleção de Produtos
[cite_start]Após a confirmação dos dados, o sistema exibe a lista de produtos disponíveis: [cite: 104, 106]
1.  [cite_start]O usuário digita o código do produto que deseja. [cite: 113]
2.  [cite_start]O sistema exibe o preço unitário, a quantidade em estoque e a unidade de medida. [cite: 114, 115, 116, 117]
3.  [cite_start]Para ver mais detalhes (descrição, fabricante, validade), o usuário pode digitar `+`. [cite: 118]
4.  [cite_start]Para confirmar a seleção, o usuário digita `ok` e informa a quantidade desejada. [cite: 119]

### Etapa 4: Continuação ou Encerramento da Compra
[cite_start]O sistema pergunta se o usuário deseja adicionar mais algum item. [cite: 121, 122]
* [cite_start]Se `S`, o processo retorna à lista de produtos. [cite: 123]
* [cite_start]Se `N`, o orçamento é finalizado. [cite: 124]

### Etapa 5: Emissão do Recibo / Nota Fiscal
Ao finalizar a compra:
1.  [cite_start]Um **desconto de 5%** é aplicado automaticamente para clientes **Pessoa Jurídica (PJ)**. [cite: 126]
2.  [cite_start]É gerado um resumo final contendo os itens, quantidades, preços, o total final com desconto (se aplicável) e os dados do cliente. [cite: 127, 128, 129, 130, 131]
