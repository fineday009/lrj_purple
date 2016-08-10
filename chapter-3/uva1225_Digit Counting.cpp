#include <iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
#define MAXN 10005
int t[MAXN][10];

void init()
{
    for(int i=1; i<=MAXN; ++i){
        //init.
        for(int j=0; j<=9; ++j)
            t[i][j]=t[i-1][j];
        //traverse number i`s bit.
        int temp=i;
        while(temp){
            t[i][temp%10]++;
            temp/=10;
        }
    }
}

int main()
{
    int T,n;
    init();

    while(~scanf("%d", &T)){
        while(T--){
            scanf("%d", &n);
            for(int i=0; i<=9; ++i)
                printf("%d%c", t[n][i], i==9?'\n':' ');
        }
    }

    return 0;
}