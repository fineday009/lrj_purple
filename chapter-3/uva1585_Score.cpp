#include<iostream>
#include<fstream>
#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;

int main()
{
	//ifstream cin("./zoj2001.txt");
	//freopen("zoj.txt","r", stdin);
//    freopen("zoj.out","w", stdout);

	char s[85];
	int n;

	scanf("%d", &n);
    while(n--){
        scanf("%s", s);
        int os=0, len=strlen(s), res=0, i=0;
        while(i<len){
            if(s[i]=='O'){ ++os; res+=os;}
            else { os=0;}
            ++i;
        }
        printf("%d\n", res);
    }

	return 0;
}