#include <stdio.h>
#include <stdlib.h>

int Convert(char c){
    switch(c){
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

int romanToInt(char* s) {
    int Total = 0;

    for (int i = 0; s[i] != '\0';i++){
        int Soma = 0;
        int Valor = Convert(s[i]);
        Soma += Valor;

        if (s[i+1] == s[i]){
            Soma += Valor;
            i++;
            if (s[i+1] == s[i]){
                Soma += Valor;
                i++;
            }
        }

        if (Convert(s[i+1]) > Valor){
            Total -= Soma;
        } else {
            Total += Soma;
        }

    }

    return Total;
}

int main(){

    char Case1[] = "III";
    char Case2[] = "LVIII";
    char Case3[] = "MCMXCIV";

    printf("Case1 = %d\nCase2 = %d\nCase3 = %d", romanToInt(&Case1[0]), romanToInt(&Case2[0]), romanToInt(&Case3[0]));

    return 0;
}