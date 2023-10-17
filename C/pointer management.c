#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int i;
    int total_number_of_shelves = 5;
    //scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries = 5;
    //scanf("%d", &total_number_of_queries);
    
    total_number_of_books = (int *) calloc (total_number_of_shelves, sizeof(int));
    for(i=0; i<total_number_of_shelves; i++){
        total_number_of_books[i] = 0;
    }
    
    total_number_of_pages = (int**) calloc(total_number_of_shelves, sizeof(int));
    /*for(i=0; i<total_number_of_shelves; i++){
        total_number_of_pages[i] = NULL;
    }*/
        
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);
            
            total_number_of_books[x]++;
            
            /*printf("Total number of books\n");
            for(i=0; i<total_number_of_shelves; i++){
                printf("%d, ", total_number_of_books[i]);
            } */
            
            int book_index = total_number_of_books[x];
            if(total_number_of_pages[x]){
                total_number_of_pages[x] = (int*) realloc(total_number_of_pages[x], book_index * sizeof(int));
            } else {
                total_number_of_pages[x] = (int*) malloc(sizeof(int));
            }
            total_number_of_pages[x][book_index-1] = y;
            
            /*printf("total Numver of pages\n");
            for(i=0; i<total_number_of_shelves; i++){
                int n = total_number_of_books[i];
                for(int j=0; j<n; j++){
                    printf("%d, ", total_number_of_pages[i][j]);
                }
                printf(";\n");
            }*/

        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}