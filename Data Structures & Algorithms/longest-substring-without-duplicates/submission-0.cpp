class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int res=0;
        unordered_map<char,int> str;
        for(int right=0;right<s.size();right++){
            if(str.find(s[right])!=str.end() && str[s[right]]>=left){
                left=str[s[right]]+1;
            }
            str[s[right]]=right;
            res=max(res,right-left+1);
        }
        return res;
    }
};
