#include <bits/stdc++.h>

using namespace std;

char str[1005];
int a[1005][1005];
int tile=1;
void chess(int tr,int tc,int dr,int dc,int size)
{
    if(size==1) return;
    int t=tile++,s=size/2;

    if(dr<tr+s && dc<tc+s)//���Ͻ�
        chess(tr,tc,dr,dc,s);//�����������ⷽ�񣬽����ٷֳ��ĸ������̣�����ʹ��ͬ���ķ������������̽��еݹ顣
    else
    {
        a[tr+s-1][tc+s-1]=t;
        chess(tr,tc,tr+s-1,tc+s-1,s);//���������ⷽ��������̣��ٶ�������������������ӵ�Ϊ���ⷽ���������ⷽ��֮�󣬶���������̽��еݹ�
    }

    if(dr<tr+s && dc>=tc+s)//���Ͻ�
        chess(tr,tc+s,dr,dc,s);
    else
    {
        a[tr+s-1][tc+s]=t;
        chess(tr,tc+s,tr+s-1,tc+s,s);
    }

    if(dr>=tr+s && dc<tc+s)//���½�
    {
        chess(tr+s,tc,dr,dc,s);
    }
    else
    {
        a[tr+s][tc+s-1]=t;
        chess(tr+s,tc,tr+s,tc+s-1,s);
    }

    if(dr>=tr+s && dc>=tc+s)//���½�
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
