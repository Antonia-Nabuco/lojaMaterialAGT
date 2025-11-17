#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "validarCpfCnpj.h"

int validarCpf(char *cpf){
    int i, j, soma, digito1, digito2;

    // Remover caracteres não numéricos
    char cpf_numerico[12];
    j = 0;
    for(i = 0; cpf[i] != '\0'; i++){
        if(isdigit(cpf[i])){
            cpf_numerico[j++] = cpf[i];
        }
    }
    cpf_numerico[j] = '\0';

    // Verificar se o CPF tem 11 dígitos
    if(strlen(cpf_numerico) != 11){
        printf("CPF inválido: deve conter 11 dígitos.\n");
        return 0;
    }

    // Verificar se todos os dígitos são iguais
    int todos_iguais = 1;
    for(i = 1; i < 11; i++){
        if(cpf_numerico[i] != cpf_numerico[0]){
            todos_iguais = 0;
            break;
        }
    }
    if(todos_iguais){
        printf("CPF inválido: todos os dígitos são iguais.\n");
        return 0;
    }

    // Calcular o primeiro dígito verificador
    soma = 0;
    for(i = 0; i < 9; i++){
        soma += (cpf_numerico[i] - '0') * (10 - i);
    }
    digito1 = (soma * 10) % 11;
    if(digito1 == 10) digito1 = 0;

    // Calcular o segundo dígito verificador
    soma = 0;
    for(i = 0; i < 10; i++){
        soma += (cpf_numerico[i] - '0') * (11 - i);
    }
    digito2 = (soma * 10) % 11;
    if(digito2 == 10) digito2 = 0;

    // Verificar se os dígitos verificadores estão corretos
    if(digito1 == (cpf_numerico[9] - '0') && digito2 == (cpf_numerico[10] - '0')){
        printf("CPF válido.\n");
        return 1;
    } else {
        printf("CPF inválido: dígitos verificadores incorretos.\n");
        return 0;
    }
}


int validarCnpj(char *cnpj) {
    int numeros[14];
    int i, j = 0;
    int soma, resto, dig1, dig2;
    int peso1[12] = {5,4,3,2,9,8,7,6,5,4,3,2};
    int peso2[13] = {6,5,4,3,2,9,8,7,6,5,4,3,2};

    // Pega só os números do CNPJ digitado
    for (i = 0; cnpj[i] != '\0'; i++) {
        if (isdigit(cnpj[i]) && j < 14) {
            numeros[j++] = cnpj[i] - '0';
        }
    }

    // Se não tiver 14 números, já está errado
    if (j != 14) {
        return 0;
    }

    // Calcula o primeiro dígito verificador
    soma = 0;
    for (i = 0; i < 12; i++) {
        soma += numeros[i] * peso1[i];
    }

    resto = soma % 11;
    if (resto < 2) {
        dig1 = 0;
    } else {
        dig1 = 11 - resto;
    }

    // Calcula o segundo dígito verificador
    soma = 0;
    for (i = 0; i < 13; i++) {
        if (i < 12) {
            soma += numeros[i] * peso2[i];
        } else {
            soma += dig1 * peso2[i];
        }
    }

    resto = soma % 11;
    if (resto < 2) {
        dig2 = 0;
    } else {
        dig2 = 11 - resto;
    }

    // Compara os dígitos calculados com os digitados
    if (dig1 == numeros[12] && dig2 == numeros[13]) {
        return 1;
    } else {
        return 0;
    }
}

