#include<bits/stdc++.h>

using namespace std;

#define N 505
#define inf 99999999

int e[N][N], dis[N], v[N];

int main()
{
    int n, m, Min, t1, t2, t3, j, pos;


    //输入点数、边数
    while(scanf("%d%d", &n, &m)) {
    memset(v,0,sizeof(v));
    memset(dis,0,sizeof(dis));
    int cnt = 0, sum = 0; //点数、路径权值和
    //m = n * (n-1) / 2;
    //初始化图
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) e[i][j] = 0;
            else e[i][j] = inf;
        }
    }

    //无向图建边
    for(int i=1; i<=m; i++){
        scanf("%d %d %d",&t1, &t2, &t3);
        e[t1][t2] = t3;
        e[t2][t1] = t3;
    }

    //初始化dis数组，1号顶点到各个顶点初始距离
    for(int i=1; i<=n; i++)
        dis[i] = e[1][i];

    v[1] = 1; //第一个结点访问了

    for(int i=1; i<n; i++){ //访问了第一个以后，剩下n-1个结点
        Min = inf;
        for(int j=1; j<=n; j++){
            if(v[j]==0 && dis[j] < Min){ //找出最小距离的节点
                Min = dis[pos = j];
            }
        }

        v[pos] = 1;
        sum += Min;

        for(int j=1 ;j<=n; j++){
            if(v[j]==0)
                dis[j] = min(dis[j],e[pos][j]);
        }
    }
    printf("%d\n",sum); //选出n-1条边，使得边的总长度之和最短
    }
    return 0;
}
