// https://atcoder.jp/contests/dp/tasks/dp_q

// Educational DP round Q - Flowers

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

//#define endl '\n'

ll n;
ll arr[200005];
ll hrr[200005];
ll dp[200005];

ll bit[200005];

ll compute(ll idx){
    ll ans = 0;
    while(idx>=0){
        //cout<<idx<<" "<<bit[idx]<<endl;
        ans = max(ans,bit[idx]);
        idx = (idx&(idx+1))-1;
    }
    return ans;
}

void update(ll idx,ll delta)
{
    while(idx<n){
        //cout<<idx<<endl;
        bit[idx]=max(bit[idx],delta);
        idx = (idx|(idx+1));
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    memset(bit,0,sizeof(bit));
    cin>>n;
    for(ll i=0;i<n;i++)cin>>arr[i];
    for(ll i=0;i<n;i++)cin>>hrr[i];

    map <ll,ll> mp;
    ll ans = 0;
    for(ll i=0;i<n;i++){

        ll val = arr[i];
        ll maxval = compute(val-1);
        //cout<<maxval<<"-"<<endl;
        ans = max(ans,maxval+hrr[i]);

        update(val-1,maxval+hrr[i]);


    }

    cout<<ans<<endl;

}
