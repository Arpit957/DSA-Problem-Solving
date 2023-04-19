class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0; 
        string s="";  
        while(i < word1.length() || j < word2.length()){
            if(i<word1.length())   s += word1[i++];  
            if(j<word2.length())   s += word2[j++];  
        } 
        return s;  
    }
};
