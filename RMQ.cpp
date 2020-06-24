template<typename T>
struct RMQ{
// Declaration - RMQ<ll> t_min = RMQ<ll>(inp,n,30,[](ll a, ll b){return min(a,b);});
// inp - Input vector;
//n - Normal n and not array size;
// 30 - max height of sparse. Do not cross 30.
// change the operator to min or max accordingly
private:
    vector<vector<T> > st;
    vector<ll> log;
    T (*f)(T, T);
public:
    RMQ(const vector<T> &v, ll n, ll a, T (*inp_f)(T, T)){
        f=inp_f;
        st = vector<vector<T> >(n+5, vector<T>(a+5,0));
        log = vector<ll>(n+10);
        log[1]=0;
        rep1(i,n+5){
            log[i+1] = log[(i+1)/2]+1;
        }
        rep1(i,n)
            st[i][0]=v[i];
        rep1(h,a){
            for(ll i=1; i+(1<<h)<=n+1; i++){
                st[i][h] = f(st[i][h-1], st[i+(1<<(h-1))][h-1]);
            }
        }
    }
    T q(ll l, ll r){
        ll p = log[r-l+1];
        return f(st[l][p], st[r-(1<<p)+1][p]); 
    }
};
