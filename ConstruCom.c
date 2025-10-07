#include <stdio.h>
    int main(){
        char opcao;
        printf("\nOlá seja bem vindo ! \nO sistema CONSTRUCOM é uma aplicação de orçamento e compra de materiais de construção");
        printf("\ndigite : \na) Ver Horarios \nb) Fazer Horcamento de materiais\n");
        scanf(" %c",&opcao);
        if(opcao=='A' || opcao=='a'){
            printf("segue o hoarios(blablanla terminar\n)");
        } 
        
        if (opcao=='B' || opcao=='b'){
            char name[20], email[40], phone[12],cpf[15],cnpj[20],type[02];
            printf("\nSe Pessoa Fisica(digite PF)\nSe Pessoa Juridica(digite PJ)");
            scanf("%c",&type);
            if (type == "PF" || type == "pf" ){
                printf("\nDigite o seu nome :\n");
                scanf("%c",&name);
                printf("\nDigite o seu email :\n");
                scanf("%c",&email);
                printf("\nDigite o seu telefone :\n");
                scanf("%c",&phone);
                printf("\nDigite o seu cpf :\n");
                scanf("%c",&cpf);
            }
            if (type == "PJ" || type == "pj" ){
                printf("\nDigite o nome da sua empresa :\n");
                scanf("%c",&name);
                printf("\nDigite o email da sua empres :\n");
                scanf("%c",&email);
                printf("\nDigite o seu telefone :\n");
                scanf("%c",&phone);
                printf("\nDigite o seu CNPJ da sua empres :\n");
                scanf("%c",&cnpj);
            }
            else {printf("Desculpa, esta opção não exite");}

        }
        
        else{
            printf("Desculpa, esta opção não exite");
        }
        
    }

