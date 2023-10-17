#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

  
char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n][m][k];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m][k];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k];
}

int countSeparator (char* str, char ch){
    int i=0, counter=0;
    while(str[i] != '\0'){
        if (str[i] == ch) counter++;
        i++;
    }
    return counter;
}

int countSeparatorStop (char* str, char separator, char stopChar){
    int i=0, counter=0;
    while(str[i] != '\0' && str[i] != stopChar){
        if (str[i] == separator) counter++;
        i++;
    }
    return counter;
}

int countWordLetters(char* str){
    int i=0;
    while(str[i] != '\0' && str[i] != ' ' && str[i] != '.' && str[i] != '\n'){
        i++;
    }
    return i;
}

void updateCursor (char** str){
    int i=0;
    while(str[0][i] != ' ' && str[0][i] != '.' && str[0][i] != '\n'){
        if(str[0][i] == '\0') {
            str[0] += i;
            return;
        }
        i++;
    }
    while(str[0][i] == ' ' || str[0][i] == '.' || str[0][i] == '\n' || str[0][i] == '\0'){
        if(str[0][i] == '\0'){
            str[0] += i;
            return;
        }
        i++;
    }
    str[0] += i;
    return;
}

void copyWord(char* dest, char* src){
    int i=0;
    while(src[i] != ' ' && src[i] != '.' && src[i] != '\n'){
        dest[i] = src[i];
        i++;
    }
}

char**** get_document(char* text) {
    int i=0;
    int paragraphCount, sentenceCount, wordCount, letterCount;
    
    paragraphCount = text? (countSeparator(text, '\n')) + 1: 0;
    printf("Paragraph count = %d\n", paragraphCount);

    char**** document = (char****) calloc(paragraphCount, sizeof(char***));
    
    for(i=0;i<paragraphCount; i++){
        sentenceCount = countSeparatorStop(text, '.', '\n');
        printf("    sentenceCount = %d\n", sentenceCount);
        
        document[i] = (char***) calloc(sentenceCount, sizeof(char**));
        for(int j=0; j<sentenceCount; j++){
            wordCount = countSeparatorStop(text, ' ', '.') + 1;
            printf("       wordCount = %d\n", wordCount);
            
            document[i][j] = (char**) calloc(wordCount, sizeof(char*));
            for(int k=0; k<wordCount; k++){
                letterCount = countWordLetters(text);
                printf("            letterCount = %d\n", letterCount);
                
                document[i][j][k] = (char*) calloc(letterCount, sizeof(char));
                copyWord(document[i][j][k], text);
                updateCursor(&text);
            }
        }
    }
    return document;
}
