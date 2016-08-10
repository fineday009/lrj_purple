#include<iostream>
#include<fstream>
#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;

double mass[256];


int main()
{
	//ifstream cin("./zoj2001.txt");
	freopen("zoj.txt","r", stdin);
    //freopen("zoj.out","w", stdout);

    mass['C']=12.01;
    mass['H'] = 1.008;
    mass['O'] = 16.00;
    mass['N'] = 14.01;

	char s[1001];
	int T;


	scanf("%d", &T);
    while(T--){
        scanf("%s", s);
        int len=strlen(s), i=0;
        double res=0.0;
        int alpha_cnt=0;
        s[len]='\0';
        /**
            4
            C
            C6H5OH
            NHC2CH2COOH
            C12H22O11
        */
        while(i<len){
            if(isalpha(s[i])) {
                ++alpha_cnt;
                if(alpha_cnt==2) { res+=mass[s[i-1]]; alpha_cnt=1;}//有累计的原子,累加res
                if(i==len-1) { res+=mass[s[i]];}//若为最后一个字符,累加res, 跳出
                ++i;
            }else{
                alpha_cnt=0;//连续原子数置0
                int sum=0, prev=s[i-1];
                while(!isalpha(s[i]) && i<len) {
                    sum=sum*10+s[i]-'0';
                    ++i;
                }
                res+=sum*mass[prev];
            }
        }
        printf("%.3lf\n", res);
    }

	return 0;
}
