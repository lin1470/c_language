#include<iostream>
#include<string.h>
#include<cctype>
using namespace std;

int main()
{
    int t;
    char a[200];
    cin>>t;
    getchar();
    for (int j=0;j<t;j++)
    {
        fgets(a,199,stdin);
        int n = strlen(a)-1; //字符串的个数
        if(a[0]!=' ')
            printf("%c\n",toupper(a[0]));
        for(int i=1;i<n;i++)
            if(a[i-1]==' '&&a[i]!=' ')
                printf("%c",toupper(a[i]));
        printf("\n");
        memset(a,0,sizeof(a));
    }
    return 0;
}
