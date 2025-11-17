#include <stdio.h>
#include <string.h>
#include "validarCpfCnpj.h"

//Cria o molde do produto
    typedef struct {
    int code;
    char name[50];
    char type[30];
    float unit_price;
    float quantity;
    char unit[10];
    char manufacturer[50];
    char supplier[50];
    char description[200];
    char manufacture_date[12];
    char expiry_date[12];
    char lot[20];
    char category[50];
} Product; // Product: cada item disponível no catálogo da loja

typedef struct {
    int product_code;
    char name[50];
    int quantity;
    float total_price;
} CartItem; // CartItem: item adicionado ao carrinho do cliente

#define MAX_PRODUCTS 5 //Cria um vetor
#define MAX_CART 5

CartItem cart[MAX_CART];
int cart_count = 0;
float total_purchase = 0;

extern char type[3];
extern char cnpj[20];
extern char cpf[15];
extern char name[20];
float pj_discount = 0.10; 

// Vetor que simula um banco de dados de produtos cadastrados
Product products[MAX_PRODUCTS] = {
    {1, "Cimento CP-II", "Ligante", 39.90, 50, "kg", "Votoran", "Casa do Construtor",
     "Cimento CP-II de alta qualidade, ideal para concreto, argamassa e alvenaria.",
     "01/06/2023", "01/06/2025", "C1234V", "Material de construcao - Cimento"},

    {2, "Tijolo 6 furos", "Alvenaria", 0.90, 1, "un", "Ceramica Alfa", "Distribuidora Rocha",
     "Tijolo 6 furos, ideal para paredes e muros.",
     "10/08/2023", "10/08/2028", "TFA1001", "Materiais de alvenaria"},

    {3, "Tinta Acrilica Branco Neve", "Pintura", 450.00, 18, "litros", "Suvinil", "ConstruMais",
     "Tinta acrilica branca, acabamento fosco, alta cobertura e durabilidade.",
     "05/07/2023", "05/07/2026", "SN-0458", "Tintas e Revestimentos"},

    {4, "Pincel Tigre 3\"", "Ferramenta", 8.50, 10, "un", "Tigre", "Ferragens Ltda",
     "Pincel com cerdas sinteticas e cabo ergonomico, ideal para pintura.",
     "15/06/2023", "15/06/2025", "PT-302", "Ferramentas de pintura"},

    {5, "Arame Recozido 18", "Fixacao", 14.50, 50, "metros", "Belgo Bekaert", "Deposito Central",
     "Arame recozido de 18mm, resistente e ideal para uso em construções.",
     "02/07/2023", "02/07/2028", "AR-1850", "Ferragens e Fixacoes"}
};

//mostra todos os produtos 
void showProducts(){
    printf("\n=== CATALOGO DE PRODUTOS ===\n");
    printf("Codigo | Produto\n");
    printf("---------------------------\n");
    for(int i = 0; i < MAX_PRODUCTS; i++){
        printf("%6d | %s\n" , products[i].code, products[i].name);
    }
}

//Permite selecionar o produto add ao carrinho e pergunta se quer + detalhes
int SelectProduct(){
    int code, found = 0, quantity;
    char option[5];
    char confirm[5];

    printf("\nDigite o codigo do produto desejado: ");
    scanf("%d", &code);

    for(int i = 0; i < MAX_PRODUCTS;i++){
        if(products[i].code == code){
          found = 1;

         printf("\nProduto: %s", products[i].name);
         printf("\nValor unitario: R$ %.2f", products[i].unit_price);

          printf("\nDeseja ver detalhes? Digite '+' para sim ou qualquer outra tecla para continuar: ");
          scanf("%s", option);

          //visualizar detalhes do produto (strcmp compara duas string e = 0 é pq são iguais)
          if(strcmp(option, "+") == 0) {
                printf("\nDescricao: %s\n", products[i].description);
                printf("Fabricante: %s\n", products[i].manufacturer);
                printf("Fornecedor: %s\n", products[i].supplier);
                printf("Validade: %s\n", products[i].expiry_date);
                printf("Lote: %s\n", products[i].lot);
                printf("Classe: %s\n", products[i].category);
          }
          printf("\n Quantidade que deseja do produto:");
          scanf("%d", &quantity);

           printf("Deseja adicionar este produto ao carrinho? (S/N): ");
           scanf("%s", confirm);

        if ((strcmp(confirm, "S") == 0) || (strcmp(confirm, "s") == 0)) {
                float unit_price = products[i].unit_price;

                // Aplica desconto se cliente for PJ
                if((strcmp(type, "PJ") == 0) || (strcmp(type,"pj") == 0)) {
                    if(validarCnpj(cnpj)) {
                        unit_price *= (1 - pj_discount);
                        printf("\nDesconto PJ aplicado! Novo valor unitário: R$ %.2f\n", unit_price);
                    } else {
                        printf("\nCNPJ inválido! Desconto não aplicado.\n");
                    }
                }    


                // Adiciona ao carrinho
                cart[cart_count].product_code = products[i].code;
                strcpy(cart[cart_count].name, products[i].name);
                cart[cart_count].quantity = quantity;
                cart[cart_count].total_price = quantity * unit_price;

                total_purchase += cart[cart_count].total_price;
                cart_count++;

                printf("\nProduto adicionado ao carrinho!\n");
                printf("Subtotal atual: R$ %.2f\n", total_purchase);
            }
          break;   
        }
    }
     if(!found){
        printf("Codigo nao encontrado.\n");
    }
    return 0;
}

void gerarNotaFiscal(void) {
    printf("\n=====================================\n");
    printf("              NOTA FISCAL            \n");
    printf("=====================================\n");
    printf("Nome: %s\n", name);
    printf("Tipo de cliente: %s\n", type);
    if ((strcmp(type, "PJ") == 0) || (strcmp(type, "pj") == 0)) {
        printf("CNPJ: %s\n", cnpj);
    } else {
        printf("CPF: %s\n", cpf);
    }
    printf("\nItens:\n");

    for (int i = 0; i < cart_count; i++) {
        int code = cart[i].product_code;
        Product *p = NULL;
        for (int j = 0; j < MAX_PRODUCTS; j++) {
            if (products[j].code == code) { p = &products[j]; break; }
        }

        if (p != NULL) {
            float unit_price = p->unit_price;
            if ((strcmp(type, "PJ") == 0) || (strcmp(type, "pj") == 0)) {
                unit_price *= (1.0f - pj_discount); // mostra preço já com desconto PJ
            }

            printf("\n-------------------------------------\n");
            printf("Produto: %s\n", p->name);
            printf("Codigo: %d\n", p->code);
            printf("Categoria: %s\n", p->category);
            printf("Tipo: %s\n", p->type);
            printf("Fabricante: %s\n", p->manufacturer);
            printf("Fornecedor: %s\n", p->supplier);
            printf("Descricao: %s\n", p->description);
            printf("Lote: %s\n", p->lot);
            printf("Data de fabr.: %s\n", p->manufacture_date);
            printf("Validade: %s\n", p->expiry_date);
            printf("Unidade: %s\n", p->unit);
            printf("Quantidade: %d\n", cart[i].quantity);
            printf("Preco unitario (aplicado): R$ %.2f\n", unit_price);
            printf("Total do item: R$ %.2f\n", cart[i].quantity * unit_price);
        } else {
            printf("\nProduto codigo %d - detalhes nao encontrados.\n", code);
        }
    }

    printf("\n-------------------------------------\n");
    if ((strcmp(type, "PJ") == 0) || (strcmp(type, "pj") == 0)) {
        float subtotal = total_purchase;
        float desconto = subtotal * pj_discount;
        float total_com_desconto = subtotal - desconto;
        printf("Subtotal (sem desconto): R$ %.2f\n", subtotal);
        printf("Desconto PJ (%.0f%%): R$ %.2f\n", pj_discount * 100.0f, desconto);
        printf("Total a pagar: R$ %.2f\n", total_com_desconto);
    } else {
        printf("Total a pagar: R$ %.2f\n", total_purchase);
    }
    printf("=====================================\n\n");

    printf("\nOrcamento finalizado!\n");
    printf("Total da compra: R$ %.2f\n", total_purchase);
    return;
}
void orcamento(void){
    char continuar = 'S';
    while(continuar == 'S' || continuar == 's'){
        showProducts();
        SelectProduct();

        printf("\nDeseja adicionar outro produto? (S/N): ");
        scanf(" %c", &continuar);
    }
    gerarNotaFiscal();
} 