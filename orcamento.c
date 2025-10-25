#include <stdio.h>
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

Product products[MAX_PRODUCTS] = {
    {1, "Cimento CP-II", "Ligante", 39.90, 50, "kg", "Votoran", "Casa do Construtor",
     "Cimento CP-II de alta qualidade, ideal para concreto, argamassa e alvenaria.",
     "01/06/2023", "01/06/2025", "C1234V", "Material de construção - Cimento"},

    {2, "Tijolo 6 furos", "Alvenaria", 0.90, 1, "un", "Cerâmica Alfa", "Distribuidora Rocha",
     "Tijolo 6 furos, ideal para paredes e muros.",
     "10/08/2023", "10/08/2028", "TFA1001", "Materiais de alvenaria"},

    {3, "Tinta Acrílica Branco Neve", "Pintura", 450.00, 18, "litros", "Suvinil", "ConstruMais",
     "Tinta acrílica branca, acabamento fosco, alta cobertura e durabilidade.",
     "05/07/2023", "05/07/2026", "SN-0458", "Tintas e Revestimentos"},

    {4, "Pincel Tigre 3\"", "Ferramenta", 8.50, 10, "un", "Tigre", "Ferragens Ltda",
     "Pincel com cerdas sintéticas e cabo ergonômico, ideal para pintura.",
     "15/06/2023", "15/06/2025", "PT-302", "Ferramentas de pintura"},

    {5, "Arame Recozido 18", "Fixação", 14.50, 50, "metros", "Belgo Bekaert", "Depósito Central",
     "Arame recozido de 18mm, resistente e ideal para uso em construções.",
     "02/07/2023", "02/07/2028", "AR-1850", "Ferragens e Fixações"}
};

//mostra todos os produtos 
void showProducts(){
    printf("\n=== CATÁLOGO DE PRODUTOS ===\n");
    printf("Código | Produto\n");
    printf("---------------------------\n");
    for(int i = 0; i < MAX_PRODUCTS; i++){
        printf("%6d | %s\n" , products[i].code, products[i].name);
    }
}

//Permite selecionar o produto add ao carrinho e pergunta se quer + detaalhes
int SelecProduct(){
    int code, found = 0, quantity;
    char option[5];
    char confirm[5];

    printf("\nDigite o código do produto desejado: ");
    scanf("%d", &code);

    for(int i = 0; i < MAX_PRODUCTS;i++){
        if(products[i].code == code){
          found = 1;

         printf("\nProduto: %s", products[i].name);
         printf("\nValor unitário: R$ %.2f", products[i].unit_price);

          printf("Deseja ver detalhes? Digite '+' para sim ou qualquer outra tecla para continuar: ");
          scanf("%s", option);

          //visualizar detalhes do produto (strcmp compara duas string e = 0 é pq são iguais)
          if(strcmp(option, "+") == 0) {
                printf("\nDescrição: %s\n", products[i].description);
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

         if (strcmp(confirm, "S") == 0 || strcmp(confirm, "s") == 0) {
        // Adiciona ao carrinho
          cart[cart_count].product_code = products[i].code;
          strcpy(cart[cart_count].name, products[i].name);
          cart[cart_count].quantity = quantity;
          cart[cart_count].total_price = quantity * products[i].unit_price;

         total_purchase += cart[cart_count].total_price;
         cart_count++;

        printf("\nProduto adicionado ao carrinho!\n");

        }
       printf("Subtotal atual: R$ %.2f\n", total_purchase);
       return;
    }
     if(!found){
        printf("Código não encontrado.\n");
    }
    
}