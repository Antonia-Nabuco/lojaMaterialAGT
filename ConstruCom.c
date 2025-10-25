#include <stdio.h>
#include <string.h>
#include "validarCpfCpnj.h"
#include "orcamento.h"

void cadastrar(void);
void orcamento(void);

int main(){
    char opcion;  
    printf("\nOlá seja bem vindo ! \nO sistema CONSTRUCOM é uma aplicação de orçamento e compra de materiais de construção");
    printf("\nDigite : \na) Ver Horarios \nb) Fazer orcamento de materiais\n");
    scanf(" %c",&opcion);
    if(opcion=='A' || opcion=='a'){
        printf("Segue os horarios: Segunda a Sexta, das 8h às 18h\n");
    }
    else if(opcion=='B' || opcion=='b'){
        cadastrar();
        orcamento();
    }
    else{
        printf("Desculpa, esta opção não existe\n");
    }
    return 0;
}

void cadastrar(void) {
    char name[20], email[40], phone[12], cpf[15], cnpj[20], type[3];
    printf("\nSe Pessoa Fisica(digite PF)\nSe Pessoa Juridica(digite PJ): ");
    scanf("%2s", type);
    printf("\nDigite o seu nome :\n");
    scanf("%19s", name);
    printf("\nDigite o seu email :\n");
    scanf("%39s", email);
    printf("\nDigite o seu telefone :\n");
    scanf("%11s", phone);

    if (strcmp(type, "PF") == 0 || strcmp(type, "pf") == 0) {
        printf("\nDigite o seu cpf :\n");
        scanf("%11s", cpf);
        if (!validarCpf(cpf)){
            printf("CPF inválido. Cadastro não realizado.\n");
            return;
        }
    }
    else if (strcmp(type, "PJ") == 0 || strcmp(type, "pj") == 0) {
        printf("\nDigite o nome da sua empresa :\n");
        scanf("%19s", name);
        printf("\nDigite o email da sua empresa :\n");
        scanf("%39s", email);
        printf("\nDigite o seu CNPJ da sua empresa (somente o numero):\n");
        scanf("%19s", cnpj);
        if (!validarCnpj(cnpj)){
            printf("CNPJ inválido. Cadastro não realizado.\n");
            return;
        }

    }
    else {
        printf("Desculpa, esta opção não existe\n");
        return;
    }
}

void orcamento(void) {
    printf("\nFunção de orçamento chamada!\n");
}


