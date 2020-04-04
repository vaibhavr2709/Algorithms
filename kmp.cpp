vector<ll> failure_function(vector<ll> &p){
   ll len = p.size(), j=0;
   vector<ll> f(len,0);
   rep1(i,len-1){
      while(j>=0 && p[j]!=p[i]){
         if(j-1>=0)
            j=f[j-1];
         else
            j--;
      }
      j++;
      f[i]=j;
   }
   return f;
}

vector<ll> find_occurrences(vector<ll> &t, vector<ll> &p){
   vector<ll> ans;
   vector<ll> f = failure_function(p);
   ll lt=t.size(),lp=p.size(),j=0;
   rep(i,lt){
      while(j>=0 && t[i]!=p[j]){
         if(j-1>=0)
            j=f[j-1];
         else
            j--;
      }
      j++;
      if(j==lp){
         j=f[lp-1];
         ans.pb(i-lp+2);
      }
   }
   return ans;
}
