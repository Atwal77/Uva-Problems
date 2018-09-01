/*
"IF U BELIEVE WHY NOT!!"
                       --Cristiano Ronaldo
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define M 1000000007
#define INF 1000000007
typedef pair<lli,lli> ll;
#define mem(a,x) memset(a,x,sizeof(a))
lli n,k,m;
lli dist[507][507];
lli path1[207][207];
vector<int> v2(1005,1);
vector<double> v;
lli x,y,c,z,t,q,u,d,a1,b;
struct edge
{
    lli a,b,cost;
};
/*void djkstra(int x,vector<ll> v[])
{
    mem(vis,0);
    dist[x]=0;
    s2.insert({0,x});
    while(!s2.empty())
    {
        ll p=*s2.begin();
        s2.erase(s2.begin());
        x=p.second;
        if(vis[x])
        continue;
        vis[x]=1;
        for(int j=0;j<v[x].size();j++)
        {
            if(dist[v[x][j].second]>dist[x]+v[x][j].first)
            {
                dist[v[x][j].second]=dist[x]+v[x][j].first;
                s2.insert({dist[v[x][j].second],v[x][j].second});
                a[v[x][j].second]=x;
            }
        }
    }
}*/
lli parent[100007];
lli find(lli a)
{
    return a==parent[a]?a:parent[a]=find(parent[a]);
}
void dset(lli n)
{
    for(int j=0;j<=n;j++)
    parent[j]=j;
}
void unio(lli a,lli b,lli rank[])
{
    if(rank[find(a)]>rank[find(b)])
    parent[find(b)]=find(a);
    else if(rank[find(b)]>rank[find(a)])
    parent[find(a)]=find(b);
    else
    {
        parent[find(a)]=find(b);
        rank[find(b)]++;
    }
}
bool check(lli a)
{
    if((a1*a*m+b*(a-1)+d)>=x)
    return true;
    return false;
}
/*bool valid(int i,int x)
{
    for(int j=1;j<x;j++)
    {
        if((abs(b[j-1]-i)==abs(j-x))||(i==b[j-1])||(j==x))
        return false;
    }
    return true;
}*/
lli p[10007];
lli dp[30001][12];
map<ll,ll> pat;
map<ll,lli> p2;
lli pr[200007],we[200007];
lli a[100005];
map<lli,vector<int>> m4;
vector<int> v4;
int f=0;
lli tot=1;
lli vis[1001][1001];
lli p1;
lli s[10001];
lli solve(lli n,lli i)
{
//cout<<n<<" "<<i<<" "<<a[i]<<" "<<dp[n][i]<<endl;
if(n<0||i>11)
return 0;
//cout<<n<<" "<<i<<" "<<a[i]<<" "<<dp[n][i]<<endl;
if(n==0)
return 1;
if(dp[n][i]!=-1)
return dp[n][i];
dp[n][i]=solve(n-a[i],i);
dp[n][i]+=solve(n,i+1);
return dp[n][i];
}
int main()
{
double i;
while(1)
{
    cin>>i;
    n=floor(100.00*i+0.5);
    double y=n/100.0;
    if(n==0)
    return 0;
    a[1]=5;
    a[2]=10;
    a[3]=20;
    a[4]=50;
    a[5]=100;
    a[6]=200;
    a[7]=500;
    a[8]=1000;
    a[9]=2000;
    a[10]=5000;
    a[11]=10000;
    for(int i=0;i<=30000;i++)
    {
        for(int j=1;j<=11;j++)
        dp[i][j]=-1;
    }
    int c=0;
    lli n1=n;
    while(n>0)
    {
        n/=10;
        c++;
    }
    if(c<=3)
    c=3;
    for(int i=5-c;i>=1;i--)
    cout<<" ";
    printf("%0.2f ",y);
    lli d=solve(n1,1);
    lli d1=d;
    c=0;
    while(d1>0)
    {
        d1/=10;
        c++;
    }
    for(int i=16-c;i>=1;i--)
    cout<<" ";
    cout<<d<<endl;
}
}
