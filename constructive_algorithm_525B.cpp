// https://codeforces.com/problemset/problem/525/B


#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){

    string s;
    cin>>s;

    ll m;
    cin>>m;

    ll sum[s.size()+1+2];
    memset(sum,0,sizeof(sum));

    for(ll i=0;i<m;i++)
    {
        ll l,r;cin>>l;
        r = s.size()-l+1;
        sum[l]+=1;
        sum[r+1]-=1;
    }

    for(ll i=1;i<=s.size()+1;i++)
    {
        sum[i]+=sum[i-1];
    }

    for(ll i=0;i<(s.size()/2);i++)
    {
        if(sum[i+1]%2==1){
            swap(s[i],s[s.size()-i-1]);
        }
    }
    cout<<s<<endl;


}
