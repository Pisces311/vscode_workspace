#include<bits/stdc++.h>

inline long long read(){
    long long x=0,f=1;
    char c=getchar();
    for(;c>'9'||c<'0';c=getchar()){
        if(c=='-')f=-1;
    }
    for(;c>='0'&&c<='9';c=getchar()){
        x=x*10+c-'0';
    }
    return x*f;
}

int size[10],deg[10],tmp[10];
std::vector<int> vec[10];

void dfs(int now,int fa){
    size[now]=1;
    for(auto i:vec[now]){
        if(i==fa)continue;
        dfs(i,now);
        size[now]+=size[i];
    }
}

inline void work(){
    for(int t=read();t;t--){
        int n=6;
        for(int i=1;i<=n;i++)size[i]=0,vec[i].clear(),deg[i]=0,tmp[i]=i;
        for(int i=1;i<n;i++){
            int a=read(),b=read();
            vec[a].emplace_back(b);
            vec[b].emplace_back(a);
            deg[a]++,deg[b]++;
        }
        std::sort(tmp+1,tmp+n+1,[=](int a,int b){return deg[a]<deg[b];});
        if(deg[tmp[6]]==4)puts("2,2-dimethylbutane");
        else if(deg[tmp[6]]==2)puts("n-hexane");
        else if(deg[tmp[6]]==deg[tmp[5]])puts("2,3-dimethylbutane");
        else {
            dfs(tmp[6],0);
            int cnt=0;
            for(auto i:vec[tmp[6]]){
                if(size[i]>=2)cnt++;
            }
            if(cnt==1)puts("2-methylpentane");
            else puts("3-methylpentane");
        }
    }
}

int main(){
    work();
    return 0;
}