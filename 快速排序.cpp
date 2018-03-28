#include <bits/stdc++.h>

using namespace std;

int a[500000];
void QuickSort(int a[], int s, int e)
{
    if(s>=e) return ;
    int k = a[s];
    int i = s, j = e;
    while(i != j){
        while(j > i && a[j] >= k)
            --j;
        swap(a[i],a[j]);
        while(i < j && a[i] <= k)
            ++i;
        swap(a[i],a[j]);
    }  //最后a[i] = k
    QuickSort(a,s,i-1);
    QuickSort(a,i+1,e);
}

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    QuickSort(a,0,n-1);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
