#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    printf("From Bin to Dec\n");
    printf("Enter num of elements: ");
    int a;
    scanf("%d", &a);
    
    long int *variety1, *variety2, *variety3, *variety4;
    variety1 = calloc(a, sizeof(long int));
    variety2 = calloc(a, sizeof(long int));
    variety3 = calloc(a, sizeof(long int));
    variety4 = calloc(a, sizeof(long int));
    
    for(int i=0;i<a;i++)
    {
        printf("Enter %d element: ",i+1);
        scanf("%lu", &variety1[i]);
        variety2[i] = variety1[i];
    }
    
    for(int i=0;i<a;i++)
    {
        while(variety2[i] != 0)
        {
            if(variety2[i]%10 == 0 || variety2[i]%10 == 1 || variety2[i]%10 == -1){
                variety3[i]*=10;
                variety3[i] += variety2[i]%10;
                
            }
            
            
            variety2[i]/=10;
        }
    }
    
    for(int i=0; i<a; i++)
    {
        variety2[i] = variety3[i];
    }
    
    for(int i=0;i<a;i++)
    {
        int j = 0, k = 0, flag_uns = 1;
        if(variety3[i] < 0)
        {
            flag_uns = 0;
            variety3[i]*=-1;
        }
        while(variety3[i] != 0)
        {
            if(variety3[i]%10 == 1)
            {
                variety4[i]+= pow(2,k);
                k++;
            }
            else if(variety3[i]%10 == 0)
            {
                k++;
            }
            variety3[i] /= 10;
            j++;
            
        }
        if(flag_uns == 0)
        {
            variety4[i]*=-1;
        }
    }
    
    for(int i=0;i<a;i++)
    {
        printf("%ld : %ld\n",variety2[i], variety4[i]);
    }
    
    return 0;
}

