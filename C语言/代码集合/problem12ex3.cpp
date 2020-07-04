#include<iostream>
#include<stdio.h>
#include<inttypes.h>

#define max_range 12375

int64_t prime[max_range + 5] = {0};
int64_t num[max_range + 5] = {0};
int64_t min_num_times[max_range + 5] = {0};

using namespace std;
int64_t triangle(int64_t n)
{
    return n * (n + 1) / 2;
}

int64_t search(int64_t x)
{
    int64_t head = 1, tail = x, mid = (head + tail) >> 1;
    while(head <= tail)
    {
        if(triangle(mid) == x)
        return 1;
        if(triangle(mid) < x)
        head = mid + 1;
        if(triangle(mid) > x)
        tail = mid - 1;
        mid = (head + tail) >> 1;
    }
    return 0;
}

int main()
{
    for(int64_t i = 2; i <= max_range; i++)
    {
        if(!prime[i])
        {
            prime[++prime[0]] = i;
            num[i] = 2;
            min_num_times[i] = 1;
        }
        for(int64_t j = 1; j <= prime[0]; j++)
        {
            if(i * prime[j] > max_range)
            break;
            if(i % prime[j] != 0)
            {
                prime[i * prime[j]] = 1;
                num[i * prime[j]] = num[i] * num[prime[j]];
                min_num_times[i * prime[j]] = min_num_times[prime[j]];
            }
            else
            {
                prime[i * prime[j]] = 1;
                num[i * prime[j]] = num[i] / (min_num_times[i] + 1) * (min_num_times[i] + 2);
                min_num_times[i * prime[j]] = min_num_times[i] + 1;
                break;
            }

        }
        

    }
    int64_t i = 1;
    int64_t sum;
    
    while(1)
    {
         sum = 0;
        if(i % 2 == 0)
        {
            sum = (num[i / 2]) * num[i + 1];
        }
        else
        {
            sum = num[i] * (num[(i + 1) / 2]);
        }
        if(sum > 500)
        break;
        i++;
    }
    printf("%"PRId64"\n""%"PRId64"\n", sum, i);

}
