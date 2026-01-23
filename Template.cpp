#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// -------------------- Types --------------------
using ll = long long;
using i128 = __int128_t;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

template <class T> bool chmin(T &a, const T &b){ if(b < a){ a=b; return true; } return false; }
template <class T> bool chmax(T &a, const T &b){ if(b > a){ a=b; return true; } return false; }

const ll INFLL = (ll)4e18;
const int INF = (int)2e9;

// -------------------- PBDS --------------------
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// -------------------- ModInt --------------------
template<ll MOD>
struct ModInt{
    ll v;
    ModInt(ll _v=0){ v=_v%MOD; if(v<0) v+=MOD; }
    ModInt& operator+=(const ModInt& o){ v+=o.v; if(v>=MOD) v-=MOD; return *this; }
    ModInt& operator-=(const ModInt& o){ v-=o.v; if(v<0) v+=MOD; return *this; }
    ModInt& operator*=(const ModInt& o){ v=(i128)v*o.v%MOD; return *this; }
    friend ModInt operator+(ModInt a,const ModInt& b){ return a+=b; }
    friend ModInt operator-(ModInt a,const ModInt& b){ return a-=b; }
    friend ModInt operator*(ModInt a,const ModInt& b){ return a*=b; }
    static ModInt pow(ModInt a, ll e){
        ModInt r=1;
        while(e){
            if(e&1) r*=a;
            a*=a;
            e>>=1;
        }
        return r;
    }
    static ModInt inv(ModInt a){ return pow(a, MOD-2); }
};

// -------------------- Combinatorics --------------------
template<ll MOD>
struct Comb {
    using mint = ModInt<MOD>;
    vector<mint> fact, invFact;
    void init(int n){
        fact.assign(n+1,1);
        invFact.assign(n+1,1);
        for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i;
        invFact[n]=mint::inv(fact[n]);
        for(int i=n-1;i>=0;i--) invFact[i]=invFact[i+1]*(i+1);
    }
    mint nCr(int n,int r){
        if(r<0 || r>n) return 0;
        return fact[n]*invFact[r]*invFact[n-r];
    }
};

// -------------------- DSU --------------------
struct DSU{
    int n;
    vector<int> p, s;
    DSU(int n=0){ init(n); }
    void init(int n_){
        n=n_;
        p.resize(n+1);
        s.assign(n+1,1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        while(x!=p[x]) x=p[x]=p[p[x]];
        return x;
    }
    bool unite(int a,int b){
        a=find(a), b=find(b);
        if(a==b) return false;
        if(s[a]<s[b]) swap(a,b);
        p[b]=a; s[a]+=s[b];
        return true;
    }
};

// -------------------- Fenwick --------------------
struct Fenwick{
    int n;
    vector<ll> bit;
    Fenwick(int n=0){ init(n); }
    void init(int n_){
        n=n_;
        bit.assign(n+1,0);
    }
    void add(int i,ll v){
        for(;i<=n;i+=i&-i) bit[i]+=v;
    }
    ll sumPrefix(int i){
        ll s=0;
        for(;i>0;i-=i&-i) s+=bit[i];
        return s;
    }
    ll sumRange(int l,int r){
        if(l>r) return 0;
        return sumPrefix(r)-sumPrefix(l-1);
    }
};

// -------------------- Lazy SegTree (Range Add / Range Sum) --------------------
struct SegTreeLazySum {
    int n;
    vector<ll> st, lazy;
    SegTreeLazySum(int n=0){ init(n); }
    void init(int n_){
        n=1;
        while(n<n_) n<<=1;
        st.assign(2*n,0);
        lazy.assign(2*n,0);
    }
    void build(const vector<ll>& a){
        int m=sz(a);
        init(m);
        for(int i=0;i<m;i++) st[n+i]=a[i];
        for(int i=n-1;i>=1;i--) st[i]=st[2*i]+st[2*i+1];
    }
    void apply(int p,int l,int r,ll v){
        st[p] += (r-l+1)*v;
        lazy[p] += v;
    }
    void push(int p,int l,int r){
        if(lazy[p]==0) return;
        int m=(l+r)>>1;
        apply(2*p,l,m,lazy[p]);
        apply(2*p+1,m+1,r,lazy[p]);
        lazy[p]=0;
    }
    void rangeAdd(int p,int l,int r,int ql,int qr,ll v){
        if(qr<l || r<ql) return;
        if(ql<=l && r<=qr){ apply(p,l,r,v); return; }
        push(p,l,r);
        int m=(l+r)>>1;
        rangeAdd(2*p,l,m,ql,qr,v);
        rangeAdd(2*p+1,m+1,r,ql,qr,v);
        st[p]=st[2*p]+st[2*p+1];
    }
    ll rangeSum(int p,int l,int r,int ql,int qr){
        if(qr<l || r<ql) return 0;
        if(ql<=l && r<=qr) return st[p];
        push(p,l,r);
        int m=(l+r)>>1;
        return rangeSum(2*p,l,m,ql,qr) + rangeSum(2*p+1,m+1,r,ql,qr);
    }
};

// -------------------- LCA (Binary Lifting) --------------------
struct LCA {
    int n, LOG;
    vector<vector<int>> up, g;
    vector<int> depth;
    LCA(int n=0){ init(n); }
    void init(int n_){
        n=n_;
        LOG=1;
        while((1<<LOG)<=n) LOG++;
        g.assign(n+1,{});
        up.assign(LOG, vector<int>(n+1,0));
        depth.assign(n+1,0);
    }
    void addEdge(int u,int v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void dfs(int u,int p){
        up[0][u]=p;
        for(int i=1;i<LOG;i++) up[i][u]=up[i-1][ up[i-1][u] ];
        for(int v: g[u]){
            if(v==p) continue;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
    }
    void build(int root=1){ dfs(root,root); }
    int lift(int u,int k){
        for(int i=0;i<LOG;i++) if(k&(1<<i)) u=up[i][u];
        return u;
    }
    int lca(int a,int b){
        if(depth[a]<depth[b]) swap(a,b);
        a=lift(a, depth[a]-depth[b]);
        if(a==b) return a;
        for(int i=LOG-1;i>=0;i--){
            if(up[i][a]!=up[i][b]){
                a=up[i][a]; b=up[i][b];
            }
        }
        return up[0][a];
    }
};

// -------------------- HLD (Path Query via SegTree indices) --------------------
struct HLD {
    int n;
    vector<vector<int>> g;
    vector<int> parent, depth, heavy, head, pos, sub;
    int curPos;

    HLD(int n=0){ init(n); }
    void init(int n_){
        n=n_;
        g.assign(n+1,{});
        parent.assign(n+1,0);
        depth.assign(n+1,0);
        heavy.assign(n+1,-1);
        head.assign(n+1,0);
        pos.assign(n+1,0);
        sub.assign(n+1,0);
        curPos=0;
    }
    void addEdge(int u,int v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int dfs1(int u,int p){
        parent[u]=p;
        sub[u]=1;
        int mx=0;
        for(int v: g[u]){
            if(v==p) continue;
            depth[v]=depth[u]+1;
            int szv=dfs1(v,u);
            sub[u]+=szv;
            if(szv>mx){
                mx=szv;
                heavy[u]=v;
            }
        }
        return sub[u];
    }
    void dfs2(int u,int h){
        head[u]=h;
        pos[u]=++curPos;
        if(heavy[u]!=-1) dfs2(heavy[u], h);
        for(int v: g[u]){
            if(v==parent[u] || v==heavy[u]) continue;
            dfs2(v, v);
        }
    }
    void build(int root=1){
        dfs1(root,0);
        dfs2(root,root);
    }

    // iterate path segments [pos[head], pos[u]]
    template<class F>
    void processPath(int u,int v, F op){
        while(head[u]!=head[v]){
            if(depth[head[u]] < depth[head[v]]) swap(u,v);
            op(pos[head[u]], pos[u]);
            u = parent[head[u]];
        }
        if(depth[u] > depth[v]) swap(u,v);
        op(pos[u], pos[v]);
    }
};

// -------------------- Dinic Maxflow --------------------
struct Dinic {
    struct Edge { int to; ll cap; int rev; };
    int n;
    vector<vector<Edge>> g;
    vector<int> level, it;

    Dinic(int n=0){ init(n); }
    void init(int n_){
        n=n_;
        g.assign(n, {});
        level.assign(n, 0);
        it.assign(n, 0);
    }
    void addEdge(int fr,int to,ll cap){
        Edge a{to, cap, (int)g[to].size()};
        Edge b{fr, 0,   (int)g[fr].size()};
        g[fr].push_back(a);
        g[to].push_back(b);
    }
    bool bfs(int s,int t){
        fill(all(level), -1);
        queue<int> q;
        level[s]=0;
        q.push(s);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(auto &e: g[u]){
                if(e.cap>0 && level[e.to]==-1){
                    level[e.to]=level[u]+1;
                    q.push(e.to);
                }
            }
        }
        return level[t]!=-1;
    }
    ll dfs(int u,int t,ll f){
        if(u==t) return f;
        for(int &i=it[u]; i<sz(g[u]); i++){
            auto &e=g[u][i];
            if(e.cap>0 && level[e.to]==level[u]+1){
                ll ret=dfs(e.to,t,min(f,e.cap));
                if(ret>0){
                    e.cap-=ret;
                    g[e.to][e.rev].cap+=ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    ll maxflow(int s,int t){
        ll flow=0;
        while(bfs(s,t)){
            fill(all(it), 0);
            while(true){
                ll pushed=dfs(s,t,INFLL);
                if(!pushed) break;
                flow+=pushed;
            }
        }
        return flow;
    }
};

// -------------------- MinCost MaxFlow --------------------
struct MinCostMaxFlow {
    struct Edge { int to, rev; ll cap, cost; };
    int n;
    vector<vector<Edge>> g;
    MinCostMaxFlow(int n=0){ init(n); }
    void init(int n_){
        n=n_;
        g.assign(n, {});
    }
    void addEdge(int u,int v,ll cap,ll cost){
        Edge a{v, (int)g[v].size(), cap, cost};
        Edge b{u, (int)g[u].size(), 0, -cost};
        g[u].push_back(a);
        g[v].push_back(b);
    }
    pair<ll,ll> minCostMaxFlow(int s,int t,ll maxf=INFLL){
        ll flow=0, cost=0;
        vector<ll> dist(n), pot(n,0);
        vector<int> pv(n), pe(n);

        while(flow<maxf){
            fill(all(dist), INFLL);
            dist[s]=0;
            priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
            pq.push({0,s});
            while(!pq.empty()){
                auto [d,u]=pq.top(); pq.pop();
                if(d!=dist[u]) continue;
                for(int i=0;i<sz(g[u]);i++){
                    auto &e=g[u][i];
                    if(e.cap<=0) continue;
                    ll nd = d + e.cost + pot[u] - pot[e.to];
                    if(nd < dist[e.to]){
                        dist[e.to]=nd;
                        pv[e.to]=u;
                        pe[e.to]=i;
                        pq.push({nd,e.to});
                    }
                }
            }
            if(dist[t]==INFLL) break;
            for(int i=0;i<n;i++) if(dist[i]<INFLL) pot[i]+=dist[i];

            ll add = maxf-flow;
            for(int v=t; v!=s; v=pv[v]){
                add = min(add, g[pv[v]][pe[v]].cap);
            }
            for(int v=t; v!=s; v=pv[v]){
                auto &e = g[pv[v]][pe[v]];
                e.cap -= add;
                g[v][e.rev].cap += add;
                cost += add * e.cost;
            }
            flow += add;
        }
        return {flow, cost};
    }
};

// -------------------- NTT (Convolution) --------------------
// MOD = 998244353, primitive root = 3
const ll NTT_MOD = 998244353;
const ll NTT_G   = 3;
using mint = ModInt<NTT_MOD>;

void ntt(vector<mint>& a, bool invert){
    int n=sz(a);
    for(int i=1,j=0;i<n;i++){
        int bit=n>>1;
        for(; j&bit; bit>>=1) j^=bit;
        j^=bit;
        if(i<j) swap(a[i], a[j]);
    }
    for(int len=2; len<=n; len<<=1){
        mint wlen = mint::pow(mint(NTT_G), (NTT_MOD-1)/len);
        if(invert) wlen = mint::inv(wlen);
        for(int i=0;i<n;i+=len){
            mint w=1;
            for(int j=0;j<len/2;j++){
                mint u=a[i+j];
                mint v=a[i+j+len/2]*w;
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
                w*=wlen;
            }
        }
    }
    if(invert){
        mint invN = mint::inv(mint(n));
        for(auto &x: a) x*=invN;
    }
}

vector<ll> convolution(vector<ll> a, vector<ll> b){
    int n1=sz(a), n2=sz(b);
    int n=1;
    while(n < n1+n2-1) n<<=1;
    vector<mint> fa(n), fb(n);
    for(int i=0;i<n1;i++) fa[i]=a[i];
    for(int i=0;i<n2;i++) fb[i]=b[i];
    ntt(fa,false);
    ntt(fb,false);
    for(int i=0;i<n;i++) fa[i]*=fb[i];
    ntt(fa,true);
    vector<ll> res(n1+n2-1);
    for(int i=0;i<sz(res);i++) res[i]=fa[i].v;
    return res;
}

// -------------------- Solve --------------------
void solve(){
    
}

// -------------------- Main --------------------
int main(){
    fastio;

    int t=1;
    cin >> t;
    while(t--) solve();

    return 0;
}
