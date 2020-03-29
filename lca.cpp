/*----------lca and pth ancestor----------*/
vector<ll> parent(maxn);
vector<ll> depth(maxn);
vector<vector<ll> > sparse;
void find_depth(ll node, ll dep){
    depth[node]=dep;
    for(auto &x: v[node]){
        if(x==parent[node])
            continue;
        find_depth(x,dep+1);
    }
}
void find_sparse(ll n){
    rep1(i,n){
        sparse[i][0]=parent[i];
    }
    for(ll j=1; 1<<j <n; j++){
        rep1(i,n){
            if(sparse[i][j-1] != -1)
                sparse[i][j] = sparse[sparse[i][j-1]][j-1];
        }
    }
}
ll query_lca(ll a, ll b){
    ll log_of_ht_of_a,l, same_level_anc;
    if(depth[a]<depth[b])
        swap(a,b);
    for(l=1; 1<<l <= depth[a]; l++);
    l--;
    log_of_ht_of_a=l;
    for(ll i=log_of_ht_of_a; i>=0; i--){
        if(depth[a]-(1<<i) >= depth[b])
            a = sparse[a][i];
    }
    if(a==b)
        return a;
    for(ll i=log_of_ht_of_a; i>=0; i--){
        if(sparse[a][i] != -1 && sparse[a][i] != sparse[b][i])
            a = sparse[a][i], b = sparse[b][i];
    }
    return parent[a];
}
ll pth_ancestor(ll a, ll p){
    if(depth[a]<=p){
        return -1;
    }
    ll c=0;
    while(p){
        if(p&1)
            a = sparse[a][c];
        p>>=1;
        c++;
    }
    return a;
}
