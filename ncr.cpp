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
    vector<ll> nci(n+1);
    nci[0]=1;
    nci[n]=1;
    vector<ll> v = allinv(n,p);
    fr(i,1,n,1){
        nci[i]=(nci[i-1]*(n-i-1))%p;
    }
    return nci;
}
