#include <stdio.h>
#include <stdlib.h>

int* search(int A[4][3],int x)
{
    int* X = (int*) calloc(2 , sizeof(int));
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(A[i][j] == x)
            {
                X[0] = i;
                X[1] = j;
                return X;
                
            }
        }
    } 
    free(X);
    return NULL; 
}

int  main()
{
    int* X;
    int x;
    int A[4][3]={{79, 9, 55}, {11, 14, 1456}, {5, 89, 65}, {3, 8, 7}};
    printf("Digite o numero que deseja achar na matriz: ");
    scanf("%d", &x);
    X=search(A,x);
    if(X == NULL)
    {
        printf("A matriz nao possui o elemento pesquisado");
        return 0;
    }else{    
            printf("O elemento [%d][%d] da matriz possui %d. ",X[0],X[1],x); 
    }
    getchar();
    return 0;
    

}