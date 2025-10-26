#include <stdio.h>
#include <string.h>
#include "validarCpfCpnj.h"

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
} Product;

typedef struct {
    int product_code;
    char name[50];
    int quantity;
    float total_price;
} CartItem;

#define MAX_PRODUCTS 5 //Cria um vetor
#define MAX_CART 5

CartItem cart[MAX_CART];
int cart_count = 0;
float total_purchase = 0;

extern char type[3];
extern char cnpj[20];
float pj_discount = 0.10; 


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

//Permite selecionar o produto add ao carrinho e pergunta se quer + detaalhes
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

          printf("Deseja ver detalhes? Digite '+' para sim ou qualquer outra tecla para continuar: ");
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
            if((strcmp(type, "PJ") == 0)||(strcmp(type,"pj") == 0)) {
            //    if(validarCnpj(cnpj)) {   // usar cnpj_cliente
            //    unit_price *= (1 - pj_discount);
            //     }   printf("\nDesconto PJ aplicado! Novo valor unitário: R$ %.2f\n", unit_price);
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
    
}

void orcamento(void){
    char continuar = 'S';
    while(continuar == 'S' || continuar == 's'){
        showProducts();
        SelectProduct();

        printf("\nDeseja adicionar outro produto? (S/N): ");
        scanf(" %c", &continuar);
    }

    printf("\nOrcamento finalizado!\n");
    printf("Total da compra: R$ %.2f\n", total_purchase);
}