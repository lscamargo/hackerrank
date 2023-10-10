#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char s1[100], s2[100];
    char ch;
    scanf("%c\n", &ch);
    scanf("%[^\n]%*c", &s1);
    scanf("%[^\n]%*c", &s2);
    
    printf("%c", ch);
    printf("\n%s", s1);
    printf("\n%s", s2);
    return 0;
}
