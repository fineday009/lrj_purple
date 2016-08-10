#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 1000000005
char s[MAXN], t[MAXN];

int main()
{
    while(~scanf("%s %s", s, t)){
        int lens=strlen(s), lent=strlen(t), i, j;
        for( i=0, j=0; i<lent && j<lens; ++i){
            if(t[i]==s[j])
                ++j;
        }
        if(j==lens) puts("Yes");
        else puts("No");
    }

    return 0;
}
/*
Sample Input
sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter
Sample Output
Yes
No
Yes
No
*/
