/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vc vector
#define pb push_back
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    ll n;
    cin>>n;
    ll arr[200005]={0},freq[200005]={0},pref[200005]={0};
    for(ll a=0;a<n;a++)
    {
        ll b;
        cin>>b;
        arr[b]++;
    }
    ll ans=0;
    for(ll a=1;a<200005;a++)
    {
        pref[a]=arr[a]+pref[a-1];
        if(arr[a]>1 and arr[a-1]>1)
            freq[a]=freq[a-1]+1;
        else if(arr[a]>0)
            if(arr[a-1]>1)
                freq[a]=freq[a-1]+1;
            else if(freq[a-1]>0)
                freq[a]=2;
            else
                freq[a]=1;
    }
    ll pos=0,sum=0;
    for(ll a=1;a<200005;a++)
    {
        ll pre=a-freq[a];
        ll sum1=pref[a]-pref[pre];
        if(sum1>sum)
        {
            sum=sum1;
            pos=a;
        }
    }
    ll pre=pos-freq[pos];
    vc<ll> v;
    for(ll a=pre+1;a<=pos;a++)
    {
        if(arr[a]>0)
        {
            v.pb(a);
            arr[a]--;
        }
    }
    cout<<sum<<endl;
    for(ll a=pos-1;a>pre;a--)
    {
        if(arr[a]>0)
        {
            v.pb(a);
            arr[a]--;
        }
    }
    for(auto y:v)
    {
        cout<<y<<" ";
        while(arr[y]>0)
        {
            cout<<y<<" ";
            arr[y]--;
        }
    }
	return 0;
}
