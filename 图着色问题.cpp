/** 
    �㷨:��ͼͿɫ���⣺���ڵĶ�����ɫ������ͬ 
    ����:������
    ʱ��:2018/3/20
*/
/*
Ϳ��ʱ�����ɫ1��ʼ��m��ÿ��Ϳ��һ��ɫ��
Ҫ��ok��cur���жϵ�cur�����Ƿ����Ϳ���ɫ��
�����ԵĻ��Ͳ�������Ϳ�ˣ�������һ����ɫ�����ԵĻ��ͼ�����
*/
#include<bits/stdc++.h>

using namespace std;
#define N 500
int n,m;
int a=1,b=1;
int sum=0;
int G[N][N]={0};
int color[N];
// �ж϶Զ���k��ɫ�Ժ��Ƿ�Ϸ���ɫ
bool ok(int c)
{
    for(int k=1; k<=n; k++){
        if(G[c][k] && color[c]==color[k]){ // ��k��������ĳ�����ڵĶ�������ɫ��ͻ
            return false;
        }
    }
    return true;// �Ϸ�
}

void dfs(int cur)
{
    if(cur>n){ // ���еĶ��㶼�Ѿ�Ⱦ��ɫ�������˳�
        for(int i=1; i<=n; i++){
            printf("%d ",color[i]);
        }
        sum++;
        printf("\n");
    } 
    else{ 
        for(int i=1; i<=m; i++){ //ö��m����ɫ  
            color[cur]=i; //����������Χû��i������ɫ����˵����������Ϳ����ɫi  
            if(ok(cur)){
                dfs(cur+1); 
            }
            color[cur]=0; // ��k�������Ⱦɫ���Ϸ�������
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m); // ����nΪ�����������ɫ��m��ͼ���ڽӾ���G[][]
    while(~scanf("%d%d",&a,&b),a&&b){
        G[a][b]=G[b][a]=1; //�����Ĺ�ϵ��¼һ��  
    }
    dfs(1);
    printf("%d\n",sum);
}
