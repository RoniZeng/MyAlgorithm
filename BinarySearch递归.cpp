/**
    算法:递归版二分查找
    作者:曾荣丽
    时间:2018/3/20
*/
#include<bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define maxn 100000+50
#define INF 0x3f3f3f3f
#define N 5000
#define M 150
int a[N];
int BinarySearch(int *a,int n,int low,int high) //a为给定有序数组,n为待搜索数字,low为上界,high为下界
{
    int mid=(low+high)/2;
    if(low>high) return -1;
	if(a[mid]==n) return mid;
    else if(n<a[mid]) return BinarySearch(a,n,low,mid-1);
	else if(n>a[mid]) return BinarySearch(a,n,mid+1,high);
    
}

int main()
{
    int n,x;
    printf("输入数组大小,待查数字和数组: ");
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    printf("该数字下标(从1开始记起)为: %d\n",BinarySearch(a,x,1,n));
}


