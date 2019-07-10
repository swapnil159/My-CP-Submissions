/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vc vector
#define fs first
#define sec second
#define pq priority_queue
long long fastexp(long long a,long long int n)
{
    int ans=1;
    a%=mod;
    while(n>0)
    {
        if(n&1)
            ans=(ans*a*1LL)%mod;
        n>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
void dfs(vc<ll> v[],bool visited[],ll sor)
{
    visited[sor]=true;
    for(ll a=0;a<v[sor].size();a++)
    {
        if(!visited[v[sor][a]])
        {
            dfs(v,visited,v[sor][a]);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
	ll n=0,count=0;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	vc<ll> v[26];
	vc<char> ans1;
	vc<char> ans2;
	for(ll a=0;a<n;a++)
	{
	    //cout<<a<<endl;
	    ll b=s1[a]-'a';
	    bool visited[26]={false};
	    dfs(v,visited,b);
	    ll c=s2[a]-'a';
	    if(!visited[c])
	    {
	        count++;
	        ans1.pb(s1[a]);
	        ans2.pb(s2[a]);
	        v[b].pb(c);
	        v[c].pb(b);
	    }
	}
	cout<<count<<endl;
	for(ll a=0;a<count;a++)
	{
 
	    cout<<ans1[a]<<" "<<ans2[a]<<endl;
	}
	return 0;
}
