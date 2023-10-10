#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int counterArray[10] = {0};
    int digit;
    char ch;
    char str[1000];
    
    scanf("%[^\n]%*c", &str);
    int size = strlen(str);
    
    for(int i=0; i<size; i++){
        ch = str[i];
        
        if('0' <= ch && ch <= '9'){
            //digit = atoi(&ch); //For some reason yields errors on Tests cases 7-10
            digit = (int)ch-'0';
            counterArray[digit]++;
        }
    }
    
    for (int i = 0; i<10; i++){
        printf("%d ", counterArray[i]);
    }
    printf("\n");
    
    return 0;
}
