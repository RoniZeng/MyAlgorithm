#include<bits/stdc++.h>

using namespace std;

#define N 505
#define inf 99999999

int e[N][N], dis[N], v[N];

int main()
{
    int n, m, Min, t1, t2, t3, j, pos;


    //�������������
    while(scanf("%d%d", &n, &m)) {
    memset(v,0,sizeof(v));
    memset(dis,0,sizeof(dis));
    int cnt = 0, sum = 0; //������·��Ȩֵ��
    //m = n * (n-1) / 2;
    //��ʼ��ͼ
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) e[i][j] = 0;
            else e[i][j] = inf;
        }
    }

    //����ͼ����
    for(int i=1; i<=m; i++){
        scanf("%d %d %d",&t1, &t2, &t3);
        e[t1][t2] = t3;
        e[t2][t1] = t3;
    }

    //��ʼ��dis���飬1�Ŷ��㵽���������ʼ����
    for(int i=1; i<=n; i++)
        dis[i] = e[1][i];

    v[1] = 1; //��һ����������

    for(int i=1; i<n; i++){ //�����˵�һ���Ժ�ʣ��n-1�����
        Min = inf;
        for(int j=1; j<=n; j++){
            if(v[j]==0 && dis[j] < Min){ //�ҳ���С����Ľڵ�
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
    printf("%d\n",sum); //ѡ��n-1���ߣ�ʹ�ñߵ��ܳ���֮�����
    }
    return 0;
}
