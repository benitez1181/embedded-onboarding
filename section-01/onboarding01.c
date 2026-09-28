#include <stdio.h>
#include <stdlib.h>

void FizzBuzz(int n);
int ComparingFunc(const void *A, const void *B);

int main(void){
    printf("Hello World\n");

    int *ptr = malloc(20 * sizeof(int));

    // Populate array from 1-20
    for(int i = 0; i < 20; i++)
        ptr[i] = (i+1);
    
    printf("1 - 20 --------------------------\n");
    for(int i = 0; i < 20; i++)
        FizzBuzz(*(ptr+i));

    printf("\n1 - 30 ---------------------------\n");
    for(int i = 1; i < 31; i++)
        FizzBuzz(i);

    int (*FunctionPtr)(const void*, const void*);
    FunctionPtr = ComparingFunc;

    printf("\nDescending Order-------------------\n");

    qsort(ptr, 20, sizeof(int), FunctionPtr);

    for(int i = 0; i < 20; i++)
        printf("%i\n", ptr[i]);

    return 0;
}

void FizzBuzz(int n){
    if(!(n % 5))
        printf("Buzz\n");
    else if(!(n % 3))
        printf("Fizz\n");
    else if(!((n % 3) & (n % 5)))
        printf("FizzBuzz\n");
}

int ComparingFunc(const void *A, const void *B){
    int a = *(int *)A;
    int b = *(int *)B;

    if(a < b) 
        return 1;
    if(a > b) 
        return -1;
    return 0;
}
