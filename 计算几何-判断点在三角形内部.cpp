//���㷨�������ž��䣨��һ�棩����5.4.3�ڡ���԰�е������е�����
#include<bits/stdc++.h>

using namespace std;
#define ll long long
struct node
{
    ll x,y;
};
node a,b,c,d;

ll area(node a, node b, node c)
{// �������������������������������
    return abs((a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y));
}
bool ok(node a,node b,node c,node p)
{
    ll abc = area(a,b,c);
    ll abp = area(a,b,p);
    ll acp = area(a,c,p);
    ll bcp = area(b,c,p);
// �����֮�͵���ԭ�����������֤��������������
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
