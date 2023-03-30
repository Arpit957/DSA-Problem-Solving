class Solution {
    public:
 unordered_map<string,int> mp;
    bool isScramble(string S1, string S2){
        if(S1==S2) return true;
        
        string key=S1+"_"+S2;
        if(mp.find(key)!=mp.end()) return mp[key];
        
        int n=S1.length();
        bool flag=false;
        for(int i=1;i<n;i++) 
        {
            // condition 1
            if(isScramble(S1.substr(0,i),S2.substr(0,i)) && isScramble(S1.substr(i,n-i),S2.substr(i,n-i))) 
            {
                flag=true; 
                break;
            }
            // condition 2
            //if swapping is done
            if(isScramble(S1.substr(0,i),S2.substr(n-i,i)) && isScramble(S1.substr(i,n-i),S2.substr(0,n-i)))
            {
                flag=true;
                break;
            }
        }
        string k=S1+"_"+S2;
        mp[k]=flag;
        return flag;
    }
};
