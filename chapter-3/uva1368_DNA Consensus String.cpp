#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 1005

char s[55][MAXN]={};
int count[128]={};

int main()
{
    //freopen("./zoj.txt","r", stdin);
//    freopen("./zoj.out","w", stdout);

    int T;
    int m,n;
    while(~scanf("%d", &T)){
        while(T--){
            memset(s, 0, sizeof(s));
            string res="";
            int total_error=0;

            scanf("%d%d", &m, &n);

            for(int i=0; i<m; ++i) scanf("%s", s[i]);

            for(int c=0; c<n; ++c){
                memset(count, 0, sizeof(count));
                for(int r=0; r<m; ++r) count[s[r][c]]++;
                char maxIndex=0, max=-1;
                for(int i=0; i<128; ++i){
                    if(count[i]>max){
                        max=count[i];
                        maxIndex=i;
                    }
                }
                total_error+=(m-max);
                res+=maxIndex;
            }

            cout<<res<<'\n'<<total_error<<endl;
        }
    }

    return 0;
}
