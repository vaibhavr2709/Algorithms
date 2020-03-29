/*----------dsu------------*/
ll find_parent(ll u){
	if(parent[u]==-1)
		return u;
	return parent[u] = find_parent(parent[u]);
}

void merge(ll u, ll v){
	u = find_parent(u);
	v = find_parent(v);
	if(u==v)
		return;
	parent[v]=u;
}
