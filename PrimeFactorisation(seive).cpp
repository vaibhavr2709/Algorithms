// I call sieve as seive. Feels better.
const ll seiveMaxn = 15000000;
vector<ll> seive(seiveMaxn+1,0);
void doSeive(){
    for(ll i=2; i<=seiveMaxn; i++){
        if(seive[i]==0){
            seive[i]=i;
            for(ll j=i*i; j<=seiveMaxn; j+=i)
                seive[j]=i;
        }
    }
}

vector<ll> getPrimeFactorisation(ll x){
    vector<ll> ans;
    while(x!=1){
        ans.pb(seive[x]);
        x/=seive[x];
    }
    return ans;
}

vector<ll> getPrimeFactors(ll x){
    vector<ll> ans;
    while(x!=1){
        if(ans.size()==0 || ans.back()!=seive[x])
            ans.pb(seive[x]);
        x/=seive[x];
    }   
    return ans;
}
