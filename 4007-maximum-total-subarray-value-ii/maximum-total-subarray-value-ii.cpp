class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        //sparse table RMQ
        int n=nums.size();
        priority_queue<pair<int,pair<int,int> > > pq;
        int mine=nums.back();
        int maxe=nums.back();
        pq.push({0,{n-1,n-1}});
        for(int i=n-2;i>=0;i--){
            mine=min(mine,nums[i]);
            maxe=max(maxe,nums[i]);
            pq.push({maxe-mine,{i,n-1}});
        }
        vector<vector<int> > stmax(n,vector<int> (((int)log2(n))+1));
        vector<vector<int> > stmin(n,vector<int> (((int)log2(n))+1));
        for(int i=0;i<n;i++){
            stmax[i][0]=nums[i];
            stmin[i][0]=nums[i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<((int)log2(n))+1;j++){
                if(i+(1<<j)-1<n){
                    stmin[i][j]=min({stmin[i][j-1],stmin[i+(1<<(j-1))][j-1]});
                    stmax[i][j]=max(stmax[i][j-1],stmax[i+(1<<(j-1))][j-1]);
                }
                else{
                    break;
                }
            }
        }

        long long ans=0;
        while(k && !pq.empty()){
            pair<int,pair<int,int> > temp=pq.top();
            pq.pop();
            ans+=temp.first;
            int length=temp.second.second-temp.second.first;
            if(length>0){
                int fac=((int)log2(length));
                int nextmin=min(stmin[temp.second.first][fac]  ,  stmin[temp.second.first+(length-(1<<fac))][fac]);
                int nextmax=max(stmax[temp.second.first][fac]  ,  stmax[temp.second.first+(length-(1<<fac))][fac]);
                pq.push({nextmax-nextmin,{temp.second.first,temp.second.first+length-1}});
            }
            k--;
            
        }
        return ans;

    }
};