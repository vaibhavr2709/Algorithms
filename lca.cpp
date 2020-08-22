/*----------lca and pth ancestor----------*/
vector<ll> parent(maxn);
vector<ll> depth(maxn);
vector<vector<ll> > sparse;
// sparse size helper - sparse.assign((int)log(maxn)+10, vector<ll>(maxn, -1));
// IMPORTANT - depth of root node should be 1
void find_depth(ll node, ll dep){
    depth[node]=dep;
    for(auto &x: v[node]){
        if(x==parent[node])
            continue;
        parent[x]=node;
        find_depth(x,dep+1);
    }
}
void find_sparse(ll n){
    rep1(i,n)
        sparse[0][i]=parent[i];
    for(ll j=1; 1<<j <n; j++){
        rep1(i,n){
            if(sparse[j-1][i] != -1)
                sparse[j][i] = sparse[j-1][sparse[j-1][i]];
        }
    }
}
ll query_lca(ll a, ll b){
    if(depth[a]<depth[b])
        swap(a,b);
    for(ll i=20; i>=0; i--)
        if(depth[a]-(1<<i) >= depth[b])
            a = sparse[i][a];
    if(a==b)
        return a;
    for(ll i=20; i>=0; i--)
        if(sparse[i][a] != -1 && sparse[i][a] != sparse[i][b])
            a = sparse[i][a], b = sparse[i][b];
    return parent[a];
}
ll pth_ancestor(ll a, ll p){
    if(depth[a]<=p)
        return -1;
    ll c=0;
    while(p){
        if(p&1)
            a = sparse[c][a];
        p>>=1;
        c++;
    }
    return a;
}
