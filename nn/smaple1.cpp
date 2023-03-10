#include<iostream>
#include<sys/time.h>
using namespace std;

int N=250;

int b1[250][250];
int a1[250];
int sum1[250];

int b2[250][250];
int a2[250];
int sum2[250];

int re=100;

void common(int N)
{

int i,j;
    for(i = 0; i < N; i++){
 sum1[i] = 0.0;
 for(j = 0; j < N; j++)
 sum1[i] += b1[j][i]*a1[j];
 }
 
}

void cache(int N)
{
    int i,j;
for(i = 0; i < N; i++)
sum2[i] = 0.0;
 for(j = 0; j < N; j++)
 for(i = 0; i < N; i++)
 sum2[i] += b2[j][i]*a2[j];

}


int main()
{

   int i=0;


    float time_use=0;
    struct timeval start;
    struct timeval end;
    gettimeofday(&start,NULL);
    
    while(i<re)
    {
        common(N);
        i++;
    }
    gettimeofday(&end,NULL);
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒

    cout<<"time use is:"<<time_use<<"微秒"<<endl;
    int j=0;

     gettimeofday(&start,NULL);
    
   while(j<re)
   {
    cache(N);
    j++;
   }
     gettimeofday(&end,NULL);
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
     cout<<"time use is:"<<time_use<<"微秒"<<endl;

    return 0;
}