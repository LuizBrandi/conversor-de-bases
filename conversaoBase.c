#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void hexadecimal(int num);
void binario(int num);
int binarioDec(char bin[]);
int hexadecimalDec(char hex[]);
int charInt(char vetor[]);

int main(void){
    int num, quantidade, i;
    char numero[10];
    char tipo[4];
    scanf("%d", &quantidade);
    for(i = 0; i < quantidade; i++){
        scanf("%s %s", numero, tipo);
        printf("Case %d: \n", i+1);
        if(strcmp(tipo, "dec") == 0){
            num = charInt(numero);
            hexadecimal(num);
            binario(num);   
        }
        if(strcmp(tipo, "bin") == 0){
            int auxBin = binarioDec(numero);
            printf("%d dec\n", auxBin);
            hexadecimal(auxBin);
        }
        if(strcmp(tipo, "hex") == 0){
            int auxHex = hexadecimalDec(numero);
            printf("%d dec\n", auxHex);
            binario(auxHex);
        }
        printf("\n");
    }

}

void hexadecimal(int num){
    char hex[10];
    int divisao = 100, resto, i = 0, j;

    while(num > 0){
        divisao = num/16;
        resto = num%16;
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
        num = divisao;
        i++;
    }
    hex[i] = '\0';

    int tamanho = strlen(hex);
    //printf("%d", tamanho);
    for(j = tamanho - 1; j >= 0; j--){
        printf("%c", hex[j]);
    }
    printf(" hex\n");
}

void binario(int num){
    int i = 0, j, divisao = 100, resto;
    char bin[10];

    while(divisao > 0){
        divisao = num/2;
        resto = num%2;
        if(resto == 1){
            bin[i] = '1';
        } else if(resto == 0){
            bin[i] =  '0';
        }
        num = divisao;
        i++;
    }
    bin[i] = '\0';

    int tamanho = strlen(bin);
    for(j = tamanho - 1; j >= 0; j--){
        printf("%c", bin[j]);
    }
    printf(" bin\n");
}

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

int hexadecimalDec(char hex[]){
    int i, j = 0;
    int numero = 0, decimal = 0;
    int tamanho = strlen(hex);
    for(i = tamanho - 1; i >= 0; i--){
        if(hex[i] == 'a'){
            numero = 10;
            decimal += numero * pow(16, j);
            j++;
        } else if(hex[i] == 'b'){
            numero = 11;
            decimal += numero * pow(16, j);
        } else if(hex[i] == 'c'){
            numero = 12;
            decimal += numero * pow(16, j);
        } else if(hex[i] == 'd'){
            numero = 13;
            decimal += numero * pow(16, j);
        } else if(hex[i] == 'e'){
            numero = 14;
            decimal += numero * pow(16, j);
        } else if(hex[i] == 'f'){
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

int charInt(char vetor[]){
    int num = atoi(vetor);
    return num;
}

