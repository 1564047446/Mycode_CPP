/*************************************************************************
	> File Name: contestB.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 18时17分31秒
 *************************************************************************/



#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int64_t a[1000] = {0};
int64_t b[1000] = {0};

int main()
{
    a[0] = 1;
    a[1] = 1;
    for(int i = 1; i <= 100; i++)
    {
        for(int j = 1; j <= a[0]; j++)
        {
            a[j] *= i;
        }
        for(int j = 1; j <= a[0]; j++)
        {
            if(a[j] < 10)  continue;
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
            if(j == a[0])
            ++a[0];
        }
    }


    int num = 1;
    b[1] = 1;
    int k = 0;
    int a1[1000] = {0};
    a1[0] = 1;
    
    for(int i = 1; i <= a[0]; i++)
    {
        while(a[i])
        {
            if(a[i] % 10 != 0)
                a1[++k] = a[i] % 10;
            a[i] /= 10;
        }
    }
    int numb = 1;
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= numb; j++)
        {
            b[j] *= a1[i];
        }
        for(int j = 1; j <= numb; j++)
        {
            if(b[j] < 10) continue;
            b[j + 1] += b[j] / 10;
            b[j] %= 10;
            if(j == numb)
            ++numb;
        }
    }



    for(int i = numb; i >= 1; i--)
    {
        printf("%"PRId64, b[i]);
    }
    printf("\n");
  /*  for(int64_t i = 1; i <= a[0]; i++)
    {
        if(a[i] != 0)
        {
            while(a[i])
            {
                num *= a[i] % 10;
                a[i] /= 10;
            }
            printf("%"PRId64"\n", num);
        }
    }*/
  //  printf("%"PRId64"\n", num);
}

