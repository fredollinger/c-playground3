#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int count_distinct_characters(const char* s) {
    int count[256] = {0}; // Assuming ASCII characters
    int distinct = 0;
    while (*s) {
        if (!count[(unsigned char)*s]) {
            distinct++;
            count[(unsigned char)*s] = 1;
        }
        s++;
    }
    return distinct;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int countA = count_distinct_characters(a);
    int countB = count_distinct_characters(b);
    if (countA == countB) return strcmp(a, b);
    return countA - countB;
}

int sort_by_length(const char* a, const char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    if (lenA == lenB) return strcmp(a, b);
    return lenA - lenB;
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    qsort(arr, len, sizeof(char*), (int (*)(const void*, const void*))cmp_func);
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