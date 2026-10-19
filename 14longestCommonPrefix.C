#include <stdlib.h>
#include <stdio.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    
    int Size = 0;
    int brk = 0;

    for (int letra = 0; !brk; letra++){
        
        if (strs[0][letra] == '\0'){
            break;
        }

        for (int i = 1; i < strsSize; i++){
            if (strs[0][letra] != strs[i][letra]){
                brk = 1;
                break;
            }
        }

        if (!brk) Size++;
    }
    
    if (Size == 0){return (char*)"";}

    char* NewString = (char*)malloc(Size + 1);

    for (int i = 0; i < Size; i++){

        NewString[i] = strs[0][i];

    }

    NewString[Size] = '\0';

    return NewString;
}

int main(){

    char* strs[3];
    strs[0] = (char*)"flower"; strs[1] = (char*)"flow"; strs[2] = (char*)"flight";
    // Adicionei (char*) por que o Visual Code tava dando warning
    // warning: ISO C++ forbids converting a string constant to 'char*'

    char* NewString = longestCommonPrefix(strs, 3);
    printf("%s", NewString);

    return 0;
}