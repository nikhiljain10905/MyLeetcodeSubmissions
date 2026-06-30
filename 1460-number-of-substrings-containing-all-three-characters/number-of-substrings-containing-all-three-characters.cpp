class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        //two ptrs
        int ptr1=0;
        int ptr2=0;
        int ans=0;
        int freqa=0;
        int freqb=0;
        int freqc=0;
        while(ptr1<n){
            while((freqa==0 || freqb==0 || freqc==0) && ptr2<n){
                if(s[ptr2]=='a'){
                    freqa++;
                }
                if(s[ptr2]=='b'){
                    freqb++;
                }
                if(s[ptr2]=='c'){
                    freqc++;
                }
                ptr2++;
            }
            if(!(freqa==0 || freqb==0 || freqc==0)){
                ans+=(n-ptr2+1);
            }
            if(s[ptr1]=='a'){
                    freqa--;
                }
                if(s[ptr1]=='b'){
                    freqb--;
                }
                if(s[ptr1]=='c'){
                    freqc--;
                }
            ptr1++;
        
        }
        return ans;
    }
};