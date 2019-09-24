https://codeforces.com/contest/913/problem/C

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
typedef long long int ll; 
typedef long double ld; 

ll cost[35];
	
int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n,l;
	cin>>n>>l;
	memset(cost,0,sizeof(cost));
	ll arr[n+1];
	
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cost[0] = arr[0];
	
	for(ll i=1;i<32;i++)
	{
		if(i<n)
		{
			cost[i] = min(2*cost[i-1],arr[i]);
		}
		else {
			cost[i] = 2*cost[i-1];
		}
		//cout<<i<<"*"<<cost[i]<<endl;
	}
	
	string s = "";
	ll k = l;
	while(k>0)
	{
		s = char((k%2)+'0') + s;
		k = k/2;
	}
	
	
	
	while(s.size()<32)s = '0'+s;
	//cout<<s<<endl;
	ll ans = -1;
  
  // i = 33 here i was lazy hence actually it takes case where no one is inserted in mask
  
	for(ll i=0;i<33;i++)
	{
		if(i==32 || s[i]=='0')
		{
			string p = s;
			p[i] = '1';
			for(ll j=i+1;j<32;j++){
				p[j] = '0';
			}
			
			ll val = 0;
			for(ll j=0;j<32;j++)
			{
				if(p[j]=='1')val += cost[31-j];
			}
			//cout<<p<<" "<<val<<endl;
			if(ans==-1)ans = val;
			ans = min(ans,val);
		}
	}
	cout<<ans<<endl;
}

