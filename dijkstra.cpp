struct edge{
    ll to,w;
};

template<typename T>
struct Dijkstra{
// needs graph in 2D vector of struct edge 
// Declaration Dijkstra<ll> d; d.init(n,start); d.build(v);
private:
    const ll INF = 100000000000000000;
    ll n, s;
    priority_queue<pair<ll,T>, vector<pair<ll,T> >, greater<pair<ll,T> >> pq;
 
public:
    vector<ll> d, p;
    Dijkstra(){
    }
    void init(ll max_n, ll inp_source){
        n = max_n;
        s = inp_source;
        d.assign(n+10,INF);
        p.assign(n+10,-1);
        d[s]=0;
        pq.push({0,s});
    } 
 
    void build(vector<vector<edge> > &v){
        while(!pq.empty()){
            auto [d_node,node] = pq.top();
            pq.pop();
            if(d_node!=d[node]){
                continue;
            }
            for(auto &[to,w]:v[node]){
                if(d[to]>d[node]+w){
                    d[to] = d[node]+w;
                    p[to]=node;
                    pq.push({d[to], to});
                }
            }
        }
    }
};
