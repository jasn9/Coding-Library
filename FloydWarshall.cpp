
https://cses.fi/problemset/task/1672/

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
typedef long long int ll; 
typedef long double ld; 

ll n,m;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll q;
	cin>>n>>m>>q;
	
	ll dis[n+1][n+1];
	
	for(ll i=1;i<=n;i++)
	{
		
		for(ll j=1;j<=n;j++)
		{
			if(i!=j)
			dis[i][j] = 1e18;
			else
			dis[i][i] = 0;
		}
		
	}
	for(ll i=0;i<m;i++)
	{
		ll a, b, c;
		cin>>a>>b>>c;
		dis[a][b] = min(dis[a][b],c);
		dis[b][a] = min(dis[b][a],c);
	}
	
	
	
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	while(q--)
	{
		ll a,b;
		cin>>a>>b;
		
		if(dis[a][b] == 1e18)cout<<-1<<endl;
		else
		cout<<dis[a][b]<<endl;
		
	}
	
}

