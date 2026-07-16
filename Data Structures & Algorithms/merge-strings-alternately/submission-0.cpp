class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        res.reserve(word1.size()+word2.size());
        int i=0;
        int j=0;
        while(i<word1.size()||j<word2.size()){
            if(i<word1.size()){
                res+=word1[i];
                i++;
            }
            if(j<word2.size()){
                res+=word2[j];
                j++;
            }
        }
        return res;
    }
};