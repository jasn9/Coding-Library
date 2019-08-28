
https://codeforces.com/problemset/problem/113/B

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
typedef int ll; 
typedef long double ld; 

ll trie[2000005][27];

ll flt[2000005];

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s,p,q;
	
	cin>>s>>p>>q;
	
	ll st[2005];
	
	ll ed[2005];
	memset(flt,0,sizeof(flt));
	for(ll i=0;i<s.size();++i)
	{
		ll j = 0;
		
		while(j<s.size() and j<p.size() and s[i+j]==p[j])j++;
		
		if(j == p.size())
		{
			st[i] = 1;
		}
		else
		{
			st[i] = 0;
		}
		
	}
	
	for(ll i=-1+s.size();i>=0;i--)
	{
		ll j = -1+q.size();
		ll k = 0;
		while(j>=0 and s[i-k]==q[j])j--,k++;
		if(j<0)
		{
			ed[i] = 1;
		}
		else
		{
			ed[i] = 0;
		}
		
	}
	
	memset(trie,0,sizeof(trie));
	
	ll numberOfTrieNode = 0;

	ll ans = 0;
	for(ll i=0;i<s.size();i++)
	{
		if(st[i]==1)
		{
			//cout<<i<<endl;
			ll node = 0;
			for(ll j=i;j<s.size();++j)
			{
				
				if(trie[node][s[j]-'a'] == 0)
				{
					numberOfTrieNode++;
					trie[node][s[j]-'a'] = numberOfTrieNode;
				}
				node = trie[node][s[j]-'a'];
				
				if(ed[j]==1)
				{
					//cout<<"#"<<j<<endl;
					if((j-i+1>=p.size()) and (j-i+1>=q.size()))
					{
						//cout<<i<<"*"<<j<<" "<<node<<endl;
						flt[node]++;
						if(flt[node]==1)ans++;
					}
				}
				
			}
		}
	}
	cout<<ans<<endl;
	
	
}

