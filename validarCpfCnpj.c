#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "validarCpfCnpj.h"

void validarCpf(char *cpf){
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
        return;
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
        return;
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
    } else {
        printf("CPF inválido: dígitos verificadores incorretos.\n");
    }

}


void validarCpnj(char *cnpj){




}

