/** 
    算法:给图涂色问题：相邻的顶点颜色互不相同 
    作者:曾荣丽
    时间:2018/3/20
*/
/*
涂的时候从颜色1开始到m，每当涂上一个色，
要用ok（cur）判断第cur个点是否可以涂这个色，
不可以的话就不再往下涂了，改试另一个颜色，可以的话就继续。
*/
#include<bits/stdc++.h>

using namespace std;
#define N 500
int n,m;
int a=1,b=1;
int sum=0;
int G[N][N]={0};
int color[N];
// 判断对顶点k着色以后是否合法着色
bool ok(int c)
{
    for(int k=1; k<=n; k++){
        if(G[c][k] && color[c]==color[k]){ // 第k个顶点与某个相邻的顶点有颜色冲突
            return false;
        }
    }
    return true;// 合法
}

void dfs(int cur)
{
    if(cur>n){ // 所有的顶点都已经染完色，程序退出
        for(int i=1; i<=n; i++){
            printf("%d ",color[i]);
        }
        sum++;
        printf("\n");
    } 
    else{ 
        for(int i=1; i<=m; i++){ //枚举m种颜色  
            color[cur]=i; //如果这个点周围没有i这种颜色，就说明这个点可以涂成颜色i  
            if(ok(cur)){
                dfs(cur+1); 
            }
            color[cur]=0; // 第k个顶点的染色不合法，回溯
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m); // 输入n为顶点个数，颜色数m，图的邻接矩阵G[][]
    while(~scanf("%d%d",&a,&b),a&&b){
        G[a][b]=G[b][a]=1; //相连的关系记录一下  
    }
    dfs(1);
    printf("%d\n",sum);
}
