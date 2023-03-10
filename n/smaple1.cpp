#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include<sys/time.h>
using namespace std;



int sum1=0;

int sum2=0;

int a[4096];
int b[4096];
int c[4096];


void common()
{
    
    int temp=0;
    for (int i = 0; i < 4096; i++)
     temp+= a[i];
    sum1=temp;

}

void o1()
{

int sum_1 = 0; int sum_2 = 0;
for (int i = 0;i < 4096; i += 2) {
 sum_1 += a[i];
 sum_2 += a[i + 1];
 }
 sum2 = sum_1 + sum_2;
}

void o2(int n)
{
if (n == 1)
 return;
 else
 {
 for (int i = 0; i < n / 2; i++)
 {
     b[i] += b[n - i - 1];
 }
 n = n / 2;
 o2(n);
 }

}

void o3(int n)
{
for (int m = n; m > 1; m /= 2) // log(n)个步骤
 for (int i = 0; i < m / 2; i++)
 c[i ] = c[i * 2] + c[i * 2 + 1];
}


int re=1;






int main() 
{

for(int i=0;i<4096;i++)
{
    a[i]=b[i]=c[i]=i;
}
    int i=0;
 
    float time_use=0;
    struct timeval start;
    struct timeval end;
    gettimeofday(&start,NULL);
    while(i<re)
    {
        
        common();
        i++;
    }
    gettimeofday(&end,NULL);
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    cout<<"common求和结果"<<sum1<<endl;
    cout<<"time use is:"<<time_use<<"微秒"<<endl;
    i=0;


    gettimeofday(&start,NULL);
    while(i<re)
    {
        
        o1();
        i++;
    }
    gettimeofday(&end,NULL);
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    cout<<"多链路式求和结果"<<sum2<<endl;
    cout<<"time use is:"<<time_use<<"微秒"<<endl;
    i=0;

    gettimeofday(&start,NULL);
     for(int i=0;i<4096;i++)
     a[i]=i;
    gettimeofday(&end,NULL);
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    float temp=time_use;
    i=0;
    




    gettimeofday(&start,NULL);
    while(i<re)
    {
        
        o2(4096);
        i++;
    }
    gettimeofday(&end,NULL);
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    cout<<"递归求和结果"<<b[0]<<endl;
    cout<<"time use is:"<<time_use<<"微秒"<<endl;
    i=0;

    gettimeofday(&start,NULL);
    while(i<re)
    {
        o3(4096);
        i++;
    }
    gettimeofday(&end,NULL);
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    cout<<"二重循环求和结果"<<c[0]<<endl;
    cout<<"time use is:"<<time_use<<"微秒"<<endl;
    i=0;



}