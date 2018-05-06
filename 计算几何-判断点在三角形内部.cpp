//《算法竞赛入门经典（第一版）》中5.4.3节“果园中的树”中的问题
#include<bits/stdc++.h>

using namespace std;
#define ll long long
struct node
{
    ll x,y;
};
node a,b,c,d;

ll area(node a, node b, node c)
{// 由三个点计算这三个点组成三角形面积
    return abs((a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y));
}
bool ok(node a,node b,node c,node p)
{
    ll abc = area(a,b,c);
    ll abp = area(a,b,p);
    ll acp = area(a,c,p);
    ll bcp = area(b,c,p);
// 若面积之和等于原三角形面积，证明点在三角形内
    if(abc == abp + acp + bcp) return true;
    return false;
}
int main()
{
    ll n;
    while(cin>>d.x>>d.y)
    {
        cin>>a.x>>a.y;
        cin>>b.x>>b.y;
        cin>>c.x>>c.y;
        cout<<(ok(a,b,c,d)?"Yes":"No")<<endl;
    }
}
