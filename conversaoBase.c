#include <stdio.h>
#include <string.h>
#include <math.h>

void decHexadecimal(int num);
void decBinario(int num);
int binarioDec(char bin[]);
int hexadecimalDec(char hex[]);
int charToInt(char num[]);

int main(void){
    char numero[10], base[10];
    int auxDec, auxBin, auxHex;
    scanf("%s %s", numero, base);

    if(strcmp(base, "dec") == 0){
        auxDec = charToInt(numero);
        decBinario(auxDec);
        printf(" bin\n");
        decHexadecimal(auxDec);
        printf(" hex\n");
    } else if(strcmp(base, "bin") == 0){
        auxBin = binarioDec(numero);
        printf("%d bin\n", auxBin);
        decHexadecimal(auxBin);
        printf(" hex\n");
    } else if(strcmp(base, "hex") == 0){
        auxHex = hexadecimalDec(numero);
        printf("%d dec\n", auxHex);
        decBinario(auxHex);
        printf(" bin\n");
    }
}

//Funcao que converte um char na base decimal para um char na base hexadecimal
void decHexadecimal(int num){
    char hex[10];
    int divisao = 100, resto, i = 0, j, numero = num;

    while(numero > 0){
        divisao = numero/16;
        resto = numero%16;
        if(resto <= 9){
            hex[i] = resto + '0';
        } else if(resto == 10){
            hex[i] = 'A';
        } else if(resto == 11){
            hex[i] = 'B';
        } else if(resto == 12){
            hex[i] = 'C';
        } else if(resto == 13){
            hex[i] = 'D';
        } else if(resto == 14){
            hex[i] = 'E';
        } else if(resto == 15){
            hex[i] = 'F';
        }
        numero = divisao;
        i++;
    }
    hex[i] = '\0';

    int tamanho = strlen(hex);
    for(j = tamanho - 1; j >= 0; j--){
        printf("%c", hex[j]);
    }
}

//Funcao que converte um char na base decimal para um char na base hexadecimal
void decBinario(int num){
    int i = 0, j, quociente = 100, resto;
    char bin[10];

    while(quociente > 0){
        quociente = num/2;
        resto = num%2;
        if(resto == 1){
            bin[i] = '1';
        } else if(resto == 0){
            bin[i] =  '0';
        }
        num = quociente;
        i++;
    }
    bin[i] = '\0';

    int tamanho = strlen(bin);
    for(j = tamanho - 1; j >= 0; j--){
        printf("%c", bin[j]);
    }
}

//Funcao que converte um char na base binaria em um inteiro na base decimal
int binarioDec(char bin[]){
    int i, j = 0;
    int decimal = 0, numero = 0;
    int tamanho = strlen(bin);
    for(i = tamanho - 1; i >= 0; i--){
        numero = bin[i] - '0'; 
        decimal += numero * pow(2, j);
        j++;
    }
    return decimal;
}

//Funcao que converte um char na base hexadecimal para um inteiro na base decimal 
int hexadecimalDec(char hex[]){
    int i, j = 0;
    int numero = 0, decimal = 0;
    int tamanho = strlen(hex);
    for(i = tamanho - 1; i >= 0; i--){
        if(hex[i] == 'A'){
            numero = 10;
            decimal += numero * pow(16, j);
            j++;
        } else if(hex[i] == 'B'){
            numero = 11;
            decimal += numero * pow(16, j);
        } else if(hex[i] == 'C'){
            numero = 12;
            decimal += numero * pow(16, j);
        } else if(hex[i] == 'D'){
            numero = 13;
            decimal += numero * pow(16, j);
        } else if(hex[i] == 'E'){
            numero = 14;
            decimal += numero * pow(16, j);
        } else if(hex[i] == 'F'){
            numero = 15;
            decimal += numero * pow(16, j);
        } else {
            numero = hex[i] - '0';
            decimal += numero * pow(16, j);
        }
        j++;
    }

    return decimal;
}

//Funcao que converte um char em um numero inteiro
int charToInt(char num[]){
    int numero = 0, mult = 1, i;
    for(i = strlen(num) - 1; i >= 0; i--){
        numero += (num[i] - '0') * mult;
        mult = mult * 10;
    }
    return numero;
}