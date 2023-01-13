#include <stdio.h>
#include <stdlib.h>

#define n_a 21
#define n_b 21
#define m_b 15

void print_B (int **B);
void print_A (int **A);
void print_B_t(int **B);
void print_C (int **C);

void max (int **A);
void min (int **A);
void product (int **A, int **B, int **C);
void sort (int **A);
void sum_cols (int **B);
void sum_rows (int **A);

int main()
{
    /////////////////////////////////////// ARRAY A
  int **A = 0;
  A = malloc(sizeof(*A) * n_a);
  for (int i = 0; i<n_a; i++)
    A[i] = malloc(sizeof(**A) * n_a);

  for (int i = 0; i<n_a; i++)
    for(int j = 0; j<n_a; j++)
        A[i][j] =  rand() % 8;
    /////////////////////////////////////// ARRAY A

    /////////////////////////////////////// ARRAY B
  int **B = 0;
  B = malloc(sizeof(*B) * n_a);
  for (int i = 0; i<n_a; i++)
    B[i] = malloc(sizeof(**B) * n_a);

  for (int i = 0; i<n_a; i++)
    for(int j = 0; j<n_a; j++)
        B[i][j] =  rand() % 10;
    /////////////////////////////////////// ARRAY B

    /////////////////////////////////////// ARRAY C
  int **C = 0;
  C = malloc(sizeof(*C) * n_a);
  for (int i = 0; i<n_a; i++)
    C[i] = malloc(sizeof(**C) * n_a);
    //////////////////////////////////////// ARRAY C

    print_A(&*A);
    print_B(&*B);

    int choice;


    int exit;

    do {
    printf("1. Max elements of matrix A\n2. Min elements of matrix A\n3. To transpose matrix B\n4. Product AxB\n5. To sort the row of matrix A\n6. Sum rows of matrix A\n7. Sum colomns\n\nYour choice: ");
    scanf("\n\n%d", &choice);

    if (choice == 1)
        max(&*A);
    else if(choice == 2)
        min(&*A);
    else if(choice == 3)
        print_B_t(&*B);
    else if(choice == 4)
        product(&*A, &*B, &*C);
    else if(choice == 5)
        sort(&*A);
    else if(choice == 6)
        sum_rows(&*A);
    else if(choice == 7)
        sum_cols(&*B);
    choice = 0;

    printf("\n\n\tContinue?   1 - YES, 2 - EXIT\n\t\t    ");
    scanf(" %d", &exit);



    } while (exit == 1);

}

void print_A (int **A) {
    printf("\t\tMatrix A\n");
    for (int i = 0; i<n_a; i++)
        {
    for(int j = 0; j<n_a; j++)
        printf("%d ", A[i][j]);
    printf("\n");
        }
    printf("\n");
}

void print_B (int **B) {
    printf("\tMatrix B\n");
    for (int i = 0; i<n_b; i++)
        {
    for(int j = 0; j<m_b; j++)
        printf("%d ", B[i][j]);
        printf("\n");
        }
    printf("\n\n");
}

void print_B_t(int **B) {

    printf("\n\tTranspose matrix B\n");
    for (int i = 0; i<m_b; i++) {
    for(int j = 0; j<n_b; j++)
        printf("%d ", B[j][i]);
    printf("\n");
  }

}

void print_C (int **C) {

    for (int i = 0; i<3; i++) {
    for(int j = 0; j<3; j++)
        printf("%d ", C[i][j]);
    printf("\n");
  }

}

void max (int **A) {

    int max = A[0][0];

    for (int i = 0; i < n_a; i++)
        for (int j = 0; j < n_a; j++)
            if (A[i][j] > max)

                max = A[i][j];

    printf("\nMax element is %d", max);
}

void min (int **A) {

    int min = A[0][0];

    for (int i = 0; i < n_a; i++)
        for (int j = 0; j < n_a; j++)
            if (i != j)
                if (A[i][j] < min)

                    min = A[i][j];

    printf("\nMin element is %d", min);
}

void product (int **A, int **B, int **C) {

    for(int i = 0; i < n_a; i++)
        for(int j = 0; j < n_a; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n_a; k++)
               C[i][j] += A[i][k] * B[k][j];
        }

    printf("\nProduct A x B\n");
    print_C(&*C);
}

void sort (int **A) {

    int M, temp;

    do {
        printf("\nChoose the row to sort\n");
        scanf("%u", &M);
            if (M < 0 && M >= n_a){printf("\nThat`s not right, try again"); }
    }while (M < 0 && M >= n_a - 1);

    --M;

    for(int i = 0 ; i < n_a - 1; i++)
       for(int j = 0 ; j < n_a - i - 1 ; j++)
           if(A[M][j] > A[M][j+1]) {
              temp = A[M][j];
              A[M][j] = A[M][j+1];
              A[M][j+1] = temp;
           }

    printf("\nResult of sorting is:\n");
    for (int i = 0; i < n_a; i++) {
        printf("%d ", A[M][i]);
        printf("");
        };

}

void sum_rows (int **A) {

    int i, j, sum = 0;

    for (i = 0; i < n_a; i++)
    {
        for (j = 0; j < n_a; j++)
        {
            sum += A[i][j];
        }
    printf("\nSum of A-matrix row %d is %d ", i, sum);
    sum = 0;
    }
}

void sum_cols (int **B) {

    int i, j, sum = 0;

    for (j = 0; j < n_a; j++)
    {
        for (i = 0; i < n_a; i++)
        {
            sum += B[i][j];
        }
    printf("\nSum of B-matrix column %d is %d ", j, sum);
    sum = 0;
    }
}
