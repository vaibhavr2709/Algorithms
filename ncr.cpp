/*-------------ncr--------------*/
ll inv(ll n, ll p){
    return power(n,p-2, p);
}
inline vector<ll> allinv(ll n, ll p){
    vector<ll> arr(n);
    arr[1]=1;
    fr(i,2,n,1){
        arr[i] = (p - (p/i)*arr[p%i]%p)%p;
    }
    return arr;
}
vector<ll> inline allncr(ll n, ll p){
    ll facn=1;
    vector<ll> nci(n+1);
    nci[0]=1;
    nci[n]=1;
    if(n<=1)
        return nci;
    vector<ll> v = allinv(n,p);
    vector<ll> facinv(n+1);
    facinv[1]=1;
    for(ll i=2; i<n; i++)
        facinv[i]=(facinv[i-1]*v[i])%p;
    rep1(i,n)
        facn = (facn*i)%p;
    fr(i,1,n,1)
        nci[i]=(((facn*facinv[i])%p)*facinv[n-i])%p;
    return nci;
}
