// https://atcoder.jp/contests/abc164/tasks/abc164_e

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
typedef long long int ll; 
typedef long double ld; 

ll n,m,s;
vector <pair<ll,pair<ll,ll>>> vec[55];
vector <pair<ll,ll>> bank;
ll dp[55][55*55*55];
ll flg[55][55*55*55];
ll ma = 55*55;
void dijkastra()
{
    set < pair<ll,pair<ll,ll>> > pq;
    
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<=ma;j++)
        {
            dp[i][j] = 1e18;
        }
    }
    s = min(s,ma);
    dp[1][s] = 0;
    
    pq.insert({0,{s,1}});
    memset(flg,-1,sizeof(flg));
    while(pq.size()>0)
    {
        auto p = *pq.begin();
        pq.erase(p);
        flg[p.second.second][p.second.first] = 1;
     //   cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
        for(auto v:vec[p.second.second])
        {
         //   cout<<v.first<<endl;
            ll i = 0;
            while(1)
            {
                ll st = p.second.first-v.second.first + i*bank[p.second.second-1].first;
                if(st>(ma))break;
                if(st>=0)
                {
       //             cout<<st<<endl;
                   if(flg[v.first][st]==-1){
                    if(dp[v.first][st] > dp[p.second.second][p.second.first]+v.second.second + i*bank[p.second.second-1].second)
                    {
             //           cout<<v.first<<"*"<<st<<endl;
                        if(pq.find({dp[v.first][st],{st,v.first}})!=pq.end())
                        {
                            pq.erase({dp[v.first][st],{st,v.first}});
                        }
                        dp[v.first][st] = dp[p.second.second][p.second.first]+v.second.second + i*bank[p.second.second-1].second;
                        pq.insert({dp[v.first][st],{st,v.first}});    
                    }
                   }
                }
                i++;
            }
        }
    }

    ll ans[n+1];
    for(ll i=0;i<=n;i++)ans[i] = 1e18;

    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<=ma;j++)
        {
            ans[i] = min(ans[i],dp[i][j]);
        }
    }
    for(ll i=2;i<=n;i++)
    {
        cout<<ans[i]<<endl;
    }

}

int main()
{	
    std::ios_base::sync_with_stdio(0);
	  cin.tie(0);
	  cout.tie(0);
    
    cin>>n>>m>>s;
    
    for(ll i=0;i<m;i++)
    {
        ll u,v,a,b;
        cin>>u>>v>>a>>b;
        
        a = min(ma,a);
        vec[u].push_back({v,{a,b}});
        vec[v].push_back({u,{a,b}});
    }

    for(ll i=0;i<n;i++)
    {
        ll c,d;
        cin>>c>>d;
        bank.push_back({c,d});
    }
    dijkastra();
}
