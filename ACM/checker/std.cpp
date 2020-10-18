#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define MK make_pair
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
#define all(v) v.begin(),v.end()
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=2e5+10;
vector<pii> pn;
int acnt[N], bcnt[N];
int cnt[N];
int n,p;
int ans;
void add(int x){
    int s=pn[x].se/2;
    if(pn[x].se%2){
        bcnt[s]++;
        if(!acnt[s])ans++;
    }else{
        acnt[s]++;
        if(!bcnt[s])ans++;
    }
}
bool del(int x){
    int s=pn[x].se/2;
    if(pn[x].se%2){
        bcnt[s]--;
        if(!acnt[s])ans--;
    }else{
        acnt[s]--;
        if(!bcnt[s])ans--;
    }
    cnt[s]++;
    return cnt[s]==2;
}
int main()
{
    int T; rd(T); int cs=0;
    while(T--){
        rd(n); rd(p); int t; ans=0;pn.clear();
        For(i,0,n)acnt[i]=bcnt[i]=cnt[i]=0;
        For(i,1,n)rd(t), pn.PB(MK(t,2*i)), rd(t), pn.PB(MK(t,2*i+1));
        sort(pn.begin(), pn.end());
        int l=pn.size()-1;
        int res=0;
        Rep(i,pn.size()-1,0){

            //printf("%f\n",s);
            while(l>=0 && 1ll*pn[l].fi*100>=1ll*p*pn[i].fi){
                add(l); l--;
            }
            res=max(res,ans);
            if(del(i))break;
        }
        printf("Case #%d: %d\n",++cs,res);
    }
    return 0;
}