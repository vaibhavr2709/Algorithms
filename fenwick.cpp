//------------fenwick--------------
vector<ll> f(maxn,0);
void fenwick_update(ll idx, ll val){
    while(idx <= maxn){
        f[idx]+=val;
        idx += (idx & -idx);
    }
}
ll read_fenwick(ll idx){
    ll sum = 0;
    while(idx > 0){
        sum += f[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
