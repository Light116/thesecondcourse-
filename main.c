#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    printf("From Bin to Dec\n");
    printf("Enter num of elements: ");	//Число элементов
    int a;
    scanf("%d", &a);
    
    long int *variety1, *variety2, *variety3, *variety4;
    variety1 = calloc(a, sizeof(long int));	//просто служит для первоначального забора элементов
    variety2 = calloc(a, sizeof(long int));	//1 множество
    variety3 = calloc(a, sizeof(long int));	//служит для перевода в десятичную систему
    variety4 = calloc(a, sizeof(long int));	//2 множество
    
	
	//Ввод пользователем элементов множества
    for(int i=0;i<a;i++)
    {
        printf("Enter %d element: ",i+1);
        scanf("%lu", &variety1[i]);
        variety2[i] = variety1[i];
    }
    
	// Защита системы от недопустимых значений
    for(int i=0;i<a;i++)
    {
	int k=0;  
      while(variety2[i] != 0)
        {
            if(variety2[i]%10 == 0 || variety2[i]%10 == 1 || variety2[i]%10 == -1){
                variety3[i] += variety2[i]%10 *pow(10,k);
            k++;
       	}
            variety2[i]/=10;
        }
    }
    
	//Задание первого множества
    for(int i=0; i<a; i++)
    {
        variety2[i] = variety3[i];
    }
    
	// Перевод значений из 2-ной в 10-ную СС
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
    
	//Вывод элементов двух множеств
    for(int i=0;i<a;i++)
    {
        printf("%ld : %ld\n",variety2[i], variety4[i]);
    }
    
    return 0;
}

