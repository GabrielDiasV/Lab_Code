#include<stdlib.h>
#include<stdio.h>
#include<time.h>


void q1(int n){

    for (int i=0; i<n; i+=2){
        printf("%d", n);
    }

    return;
}


void q2(int n){

    if (n>=1){
        if (n%2==0){
            printf("%d", n);
            q2(n-2);
        }
        else {
            q2(n-1);
        }
    }
    else{
        return;
    }
}


int q3(){

    FILE *fileptr;
    int prod = 1;
    int sum = 0;
    int curr_int;

    fileptr = fopen("archieve_III.txt", "r");

    if(fileptr==NULL){
        printf("unable to open txt file");
        return 1;
    }

    while (fscanf(fileptr, "%d", &curr_int) == 1){
        if ((curr_int % 2) == 0){
            prod *= curr_int;
        }
        else{
            sum += curr_int;
        }
    }

    printf("even sum: %d \n odd product: %d \n", sum, prod);

    return 0;
}


int q4(){

    FILE *fileptr;
    float grade;
    char gender;
    float fem_grade = 0, male_grade = 0;
    int fem_total = 0, male_total = 0;
    float fem_med, male_med;

    fileptr = fopen("archieve_IV", "r");

    if(fileptr==NULL){
        printf("unable to open txt file");
        return 1;
    }

    while(fscanf(fileptr, "%c %f\n", &gender, &grade) != EOF){
        if (gender == 'M'){
            male_grade += grade;
            male_total++;
        }
        else{
            fem_grade += grade;
            fem_total++;
        }
    }

    fclose(fileptr);

    fem_med = fem_grade / fem_total;
    male_med = male_grade / male_total;

    if(male_med > fem_med){
        printf("%f", male_med);
    }
    else{
        printf("%f", fem_med);
    }

    return 0;
}


int q5(int n){

    if (n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }

    return (q5(n-1) + q5(n-2));
}


int q6(int n){

    int fib_n = 1;
    int fib_n1 = 0;
    int temp;

    if (n==0){
        printf("%d", fib_n1);
        return 0;
    }
    else if (n==1){
        printf("%d", fib_n);
        return 0;
    }

    for (int i=2; i<=n; i++){
        temp = fib_n;
        fib_n = fib_n + fib_n1;
        fib_n1 = temp;
    }

    printf("%d", fib_n);

    return 0;
}


int q7(int n){

    int *vector;

    int temp;

    vector = (int *)malloc(sizeof(int) * n);

    srand((unsigned)time(NULL));

    for (int i=0; i<n; i++){
        vector[i] = rand() % 100;
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (vector[j + 1] < vector[j]){
                temp = vector[j + 1];
                vector[j + 1] = vector[j];
                vector[j] = temp;
            }
        }
    }

    for (int i=0; i<n; i++){
        printf("%d", vector[i]);
    }

    free(vector);

    return 0;
}


int main(){  
    
}