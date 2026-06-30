class TreeAncestor {
public:
    int n;
    vector<vector<int> > adj;
    vector<vector<int> > ST;
    void dfs(int u,int par){
        ST[u][0]=par;
        for(int i=1;i<20;i++){
            if(ST[u][i-1]!=-1){
                ST[u][i]=ST[ST[u][i-1]][i-1];
            }
        }
        for(int i:adj[u]){
            dfs(i,u);
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        this->n=n;
        adj.resize(n);
        ST.resize(n,vector<int> (20,-1));
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        dfs(0,-1);
    }
    
    int getKthAncestor(int node, int k) {
        
        int ans=-1;
        while(k>1 && node!=-1){
            int pw=(int)log2(k);
            node=ST[node][pw];
            ans=node;
            k-=pow(2,pw);
        }
        if(k==1 && node!=-1){
            ans=ST[node][0];
        }
        
        //ST query

        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */