
// https://atcoder.jp/contests/abc133/tasks/abc133_f

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n;
vector <ll> vec[100005];
map < pair <ll,ll> , ll > col,wei;

ll parent[100005][30];
ll level[100005];

ll solve(ll u,ll par,ll lev)
{
    level[u] = lev;
    parent[u][0] = par;
    for(ll i=0;i<vec[u].size();++i)
    {
        ll v = vec[u][i];
        if(v!=par)
        {
            solve(v,u,lev+1);
        }
    }
}

ll precompute()
{
    for(ll i=1;i<=20;i++){

        for(ll j=1;j<=n;j++){
            if(parent[j][i-1]!=0)
            parent[j][i] = parent[parent[j][i-1]][i-1];
            //cout<<parent[j][i]<<" "<<j<<" "<<i<<endl;
        }

    }
}

ll query(ll u,ll v)
{

    if(level[u]<level[v])
        swap(u,v);

    for(ll i=20;i>=0;i--)
    {
        if((level[u]-(1LL<<i))>=level[v]){
            u = parent[u][i];
            cout<<u<<" "<<i<<endl;
        }
    }
    //cout<<u<<" "<<v<<endl;
    if(u==v){
        return v;
    }
    for(ll i=20;i>=0;i--)
    {
        if(parent[u][i]>0 and parent[v][i]!=parent[u][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];




}

int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll q;
    cin>>n>>q;

    for(ll i=0;i<n-1;i++){
        ll a,b;
        ll c,d;
        cin>>a>>b>>c>>d;
        vec[a].push_back(b);
        vec[b].push_back(a);
        col[{a,b}] = c;
        col[{b,a}] = c;
        wei[{a,b}] = d;
        wei[{b,a}] = d;
    }
    level[1] = 0;
    memset(parent,0,sizeof(parent));
    solve(1,0,0);
    precompute();

    while(q--)
    {

        ll u,v;
        cin>>u>>v;

        cout<<query(u,v)<<endl;

    }



}
