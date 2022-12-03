#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float t;
char ch, er;
int n, i, j, k, sort;
void check_char();
int main() {
    do {
        er=0;
        printf("Size of the array:\n");
        scanf("%i%c", &n, &ch);
        check_char ();
    } while (er);
    ch=0;

    float num[n];
    do {
        er=0;
        printf("Enter 0 if random, enter 1 if your number\n");
        scanf("%i%c", &k, &ch);
        check_char();
        if ((k!=1)&&(k!=0)) {
            er=1;
            while ((getchar()) != '\n');
            printf("Enter correct number\n");
        }
    }while(er);
    ch=0;

    if(k==1) {
        do{
            er=0;
            printf("Enter %i elements in the array: \n", n);
            for (i = 0; i < n; i++) {
            scanf("%f%c", &num[i], &ch);
            check_char();
            }
        } while (er);
        ch=0;

    } else {
        for (i = 0; i < n; i++) {
            num[i] = ((int) rand() + (float) rand() / 100000) * pow(-1, i);
        }
    }

    do {
        er=0;
        printf("Enter 1 if sort number in ascending order\n"
               "Enter 0 if sort number in descending order\n");
        scanf("%i%c", &sort, &ch);
        check_char();
        if ((sort!=1)&&(sort!=0)) {
            er=1;
            while ((getchar()) != '\n');
            printf("Enter correct number\n");
        }
    } while (er);

    if(sort==1){
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (num[i] > num[j]) {
                    t = num[i];
                    num[i] = num[j];
                    num[j] = t;
                    }
                }
            }
    } else {
        for (i = 0; i < n - 1; i++)
            for (j = i + 1; j < n; j++) {
                if (num[i] < num[j]) {
                    t = num[i];
                    num[i] = num[j];
                    num[j] = t;
                    }
                }

    }

    printf("\nElements in array are:\n");
    for(i=0;i<n;i++)
    {
        printf("%f\n", num[i]);
    }

    return 0;
}
void check_char (){
    if (ch!='\n')
    { er=1;
        while ((getchar()) != '\n');
        printf("Enter number without symbol\n");
    }
}