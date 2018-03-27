#include <bits/stdc++.h>

using namespace std;

char str[1005];
int a[1005][1005];
int tile=1;
void chess(int tr,int tc,int dr,int dc,int size)
{
    if(size==1) return;
    int t=tile++,s=size/2;

    if(dr<tr+s && dc<tc+s)//左上角
        chess(tr,tc,dr,dc,s);//如果其存在特殊方格，将它再分成四个子棋盘，并且使用同样的方法，对子棋盘进行递归。
    else
    {
        a[tr+s-1][tc+s-1]=t;
        chess(tr,tc,tr+s-1,tc+s-1,s);//不存在特殊方格的子棋盘，假定与另外三个子棋盘相接的为特殊方格，有了特殊方格之后，对这个子棋盘进行递归
    }

    if(dr<tr+s && dc>=tc+s)//右上角
        chess(tr,tc+s,dr,dc,s);
    else
    {
        a[tr+s-1][tc+s]=t;
        chess(tr,tc+s,tr+s-1,tc+s,s);
    }

    if(dr>=tr+s && dc<tc+s)//左下角
    {
        chess(tr+s,tc,dr,dc,s);
    }
    else
    {
        a[tr+s][tc+s-1]=t;
        chess(tr+s,tc,tr+s,tc+s-1,s);
    }

    if(dr>=tr+s && dc>=tc+s)//右下角
    {
        chess(tr+s,tc+s,dr,dc,s);
    }
    else
    {
        a[tr+s][tc+s]=t;
        chess(tr+s,tc+s,tr+s,tc+s,s);
    }
}

int main()
{

    int n,sx,sy;
    cin>>n>>sx>>sy;
    chess(1,1,sx,sy,n);
    for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
            printf("%2d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
