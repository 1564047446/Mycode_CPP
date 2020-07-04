/*************************************************************************
	> File Name: p187-20.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月20日 星期三 11时51分59秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


char s[11001];

int q,n,a[100001];
int main()
{
	cin>>q;
	for(int p=1;p<=q;p++)
	   {
	      long long ans=-0x7fffffff;
	      int x,y;
	   	  cin>>n;
	   	  for(int i=1;i<=n;i++)
	   	     {cin>>a[i];a[n+i]=a[i];}
 	      for(int i=1;i<=n;i++)
 	      {
 	         long long sum=0;
 	         for(int j=i;j<n+i;j++)
 	         {
 	            sum+=a[j];
 	            if(sum>ans)
 	            {
 	            	x=i;
 	            	y=j;
 	            	ans=sum;
 	            }
 	        }
 	        }
 	        cout<<ans<<' '<<x<<' ';
 			if(y>n)cout<<y-n<<endl;
            else cout<<y<<endl;
	   }
	return 0;
}
