#include <iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
using namespace std;

char dp[5][6];
const char inst[]="ABLR";
const int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

bool constains(const char a[], int ch)
{
    for(int i=0; i<4; ++i) if(a[i] == ch) return true;
    return false;
}

bool __move(char (*dp)[6], char ch, int *bi, int *bj){
    int k;
    for(k=0; k<5; ++k) if(inst[k]==ch) break;
    int ni=*bi+dir[k][0], nj=*bj+dir[k][1];
    if((ni>=0&&ni<5) && (nj>=0&&nj<5)){
        swap(dp[ni][nj], dp[*bi][*bj]);
        *bi=ni, *bj=nj;
        return true;
    }

    return false;
}

int main()
{
    //freopen("./zoj.txt","r", stdin);
	//freopen("./zoj.out","w", stdout);
    char move[256];
    int t=0;

    while(cin.getline(dp[0],6)){
        if(dp[0][0]=='Z') break;
        int bi, bj;
        for(int i=1; i<5; ++i) cin.getline(dp[i], 6);
        for(int i=0; i<5; ++i){
            for(int j=0; j<5; ++j){
                if(dp[i][j]==' ') { bi=i; bj=j;}
            }
            if(strlen(dp[i]) == 4){ dp[i][4]=' '; bi=i; bj=4;}
        }

        bool legal=true;
        while(1){
            cin.getline(move, 256);
            int end=strlen(move)-1;
            for(int i=0; i <= ((move[end]=='0')?(end-1):end); ++i){
                if(constains(inst, move[i]) && __move(dp, move[i], &bi, &bj)){
                    legal=true;
                }else{
                    legal=false;//·Ç·¨
                    break;
                }
            }
            if(move[end]=='0') break;
        }

        if(++t>1) puts("");
        printf("Puzzle #%d:\n", t);

        if(legal==false){
            printf("This puzzle has no final configuration.\n");
        }else{
            for(int i=0; i<5; ++i)
                for(int j=0; j<5; ++j){
                    printf("%c%c", dp[i][j], j==4?'\n':' ');
                }
        }
    }

    return 0;
}
