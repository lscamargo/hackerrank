#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
	//Better to use strcmp
    int i = 0;
    int ret = 0;
    while(a[i] != '\0' && b[i]!='\0'){
        if(a[i] > b[i]){
            ret=1;
            break;
        } else if (a[i] < b[i]){
            ret = -1;
            break;
        }
        i++;
    }
    if     (ret == 0 && a[i] == '\0' && b[i] != '\0') {ret = -1;} //a ends before b
    else if(ret == 0 && a[i] != '\0' && b[i] == '\0') {ret = 1;}  //b ends before a
    return ret;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return lexicographic_sort(a, b) * (-1);
}

int distinct_charc_count (const char * s){
	//Better to use strlen
    int i=0, count = 0, isFirstOccurrence;
    while(s[i] != '\0'){
        isFirstOccurrence = 1;
        for (int j = 0; j < i; j++) {
            if (s[j] == s[i]) {
                isFirstOccurrence = 0;
            }            
        }
        count += isFirstOccurrence;
        i++;
    }
    return count;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int ret = 0;

    int counta = distinct_charc_count(a);
    int countb = distinct_charc_count(b);

    if (counta > countb){ ret = 1;}
    else if (counta < countb) {ret = -1;}
    else {ret = lexicographic_sort(a, b);}
    
    return ret;
}

int sort_by_length(const char* a, const char* b) {
    int i=-1, ret=0;
    
    do {
        i++;
        if     (a[i] == '\0' &&b[i] != '\0'){ret = -1;}
        else if(a[i] != '\0' &&b[i] == '\0'){ret = 1;}
    } while(a[i] != '\0' && b[i] != '\0');
    
    if(ret == 0){
        ret = lexicographic_sort(a, b);
    }
    return ret;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char* aux;
    int cmp;
    for(int i=len; i>0; i--){
            for(int j=0; j<i-1; j++){
            cmp = cmp_func(arr[j], arr[j+1]);
            if(cmp > 0){
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}