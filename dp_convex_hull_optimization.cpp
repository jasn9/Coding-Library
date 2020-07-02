#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
typedef long long int ll; 
typedef long double ld; 

#define MAX 1000005
/*
#define mod 1000000007

ll add(ll a,ll b)
{
	return (mod+(a+b)%mod)%mod;
}
ll mul(ll a,ll b)
{
	return (mod+(a*b)%mod)%mod;
}
*/

// dp[i] = min( a[i]*b[j] + dp[j])
// a*x + b = a2*x + b2
// b2-b / a - a2


struct Line{
	ll a, b;
	
	ll value(ll x)
	{
		return a*x+b;
	}
	
	double intersect(Line l)
	{
		ll num = l.b - b;
		ll den = a - l.a;
		if(den < 0)
		{
			den = den * -1;
			num = num * -1;
		}
		if(den == 0)return 1e18;
		return (1.0L * num)/den;
	}
	
};

int main()
{
	
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	  
	ll n;
	cin>>n;
	
	ll a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	
	ll b[n];	
	for(ll i=0;i<n;i++){
		cin>>b[i];
	}

	ll dp[n];
	ll start = 0;
	vector <Line> lines;
	for(ll i=0;i<n;i++)
	{
		//~ cout<<start<<endl;
		//~ for( auto x: lines){
			//~ cout<<x.a<<" "<<x.b<<endl;
		//~ }
		while(start < (ll)lines.size()-1){
			if(lines[start].value(a[i]) >= lines[start+1].value(a[i])){
				start++;
			}
			else{
				break;
			}
		}
		dp[i] = 0;
		if(i!=0)
		{
			dp[i] = lines[start].value(a[i]);
		}
		Line line = {b[i], dp[i]};
		while(start < (ll) lines.size() - 1)
		{
			Line a = lines.end()[-1];
			Line b = lines.end()[-2];
			
			double one = a.intersect(b);
			double two = b.intersect(line);
			
			if(one >= two){
				lines.pop_back();
			}  
			else{
				break;
			}
		}	
		lines.push_back(line);
	}
	cout<<dp[n-1]<<endl;
}
