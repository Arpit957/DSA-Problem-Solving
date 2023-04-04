class Solution {
public:
    int partitionString(string s) {
       int n = s.size();

        vector<int>hsh(26,0);
        int cnt = 0;

        for(int i = 0; i < n; i++)
        {
            if(hsh[s[i]-'a'] != 0)
            {
                cnt++;
                for(int i = 0; i < 26; i++)
                {
                    hsh[i] = 0; // reset all count to 0
                }
                hsh[s[i]-'a']++;
            }
            else
            {
                hsh[s[i]-'a']++;
            }
        }

        return cnt+1;   
    }
};
