/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#pragma GCC optimize ("-O3")
#define mod 1000000007
#define inf 1000000000000000000
#define rk 256
#define pb push_back
#define mp make_pair
#define vc vector
#define fs first
#define sec second
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define all(v) v.begin(),v.end()
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define T ll t=0;cin>>t;for(ll test=0;test<t;test++)
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n;
    cin>>n;
    map<char,ll> m;
    m['a']=1;
    m['e']=2;
    m['i']=3;
    m['o']=4;
    m['u']=5;
    vc<pll> v[6];
    string s[n];
    for(ll a=0;a<n;a++)
    {
        cin>>s[a];
        ll last=0,cnt=0;
        for(ll b=0;b<(ll)s[a].length();b++)
        {
            char y=s[a][b];
            if(y=='a' or y=='e' or y=='i' or y=='o' or y=='u')
                cnt++,last=m[y];
        }
        v[last].pb({cnt,a});
    }
    for(ll a=0;a<6;a++)
        sort(all(v[a]));
    ll flag[n];
    for(ll a=0;a<n;a++)
        flag[a]=0;
    vc<pll> seco,fis;
    for(ll a=1;a<6;a++)
    {
        if((ll)v[a].size()==0)
            continue;
        for(ll b=0;b<(ll)v[a].size()-1;b++)
        {
            if(v[a][b].fs==v[a][b+1].fs)
            {
                ll ind1=v[a][b].sec,ind2=v[a][b+1].sec;
                flag[ind1]=2;
                flag[ind2]=2;
                seco.pb({ind1,ind2});
                b++;
            }
        }
    }
    vc<pll> left;
    for(ll a=1;a<6;a++)
    {
        if(v[a].size()==0)
            continue;
        for(ll b=0;b<(ll)v[a].size();b++)
        {
            ll ind=v[a][b].sec;
            if(flag[ind]==0)
            {
                left.pb(v[a][b]);
            }
        }
    }
    sort(all(left));
    for(ll a=0;a<(ll)left.size()-1;a++)
    {
        if(left[a].fs==left[a+1].fs)
        {
            ll ind1=left[a].sec;
            ll ind2=left[a+1].sec;
            flag[ind1]=1;
            flag[ind2]=1;
            fis.pb({ind1,ind2});
            a++;
        }
    }
    ll i=0,j=0;
    vc<pll> ans; 
    while(i<(ll)seco.size() and j<(ll)fis.size())
    {
        ans.pb({fis[j].fs,seco[i].fs,});
        ans.pb({fis[j].sec,seco[i].sec,});
        i++,j++;
    }
    while(i<(ll)seco.size()-1LL)
    {
        ans.pb({seco[i].fs,seco[i+1].fs});
        ans.pb({seco[i].sec,seco[i+1].sec});
        i+=2;
    }
    cout<<ans.size()/2<<endl;
    for(auto y:ans)
    {
        cout<<s[y.fs]<<" "<<s[y.sec]<<endl;
    }
	return 0;
}
