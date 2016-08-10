#include <iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
using namespace std;

bool isCycle(const char* s, int cycle)
{
    int len=strlen(s), i=0;
    if(cycle==len) return true;
    for( ; (i+cycle)<len; ++i){
        if(s[i]!=s[i+cycle]) return false;
    }
    return (i+cycle)==len;
}

int main()
{
    //freopen("./zoj.txt","r", stdin);
    //freopen("./zoj.out","w", stdout);
    int T,n;
    char s[100];

    while(~scanf("%d", &T)){
        while(T--){
            scanf("%s", s);
            int len=strlen(s);
            //brute-force with len
            for(int i=1; i<=len; ++i){
                //detect
                if((len%i==0) && isCycle(s, i)){
                    printf("%d\n", i);
                    break;
                }
            }
            if(T!=0) puts("");
        }
    }

    return 0;
}