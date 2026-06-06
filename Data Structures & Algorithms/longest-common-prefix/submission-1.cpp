class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        sort(strs.begin(),strs.end());
        for(int i=0;i<strs.size()-1;i++){
        if(strs[i][0]!=strs[i+1][0]){
            return ans;
            break;
        }}
        for(int i = 0;i<strs[0].size();i++){
            if(strs[0][i]!=strs[strs.size()-1][i]){
                ans = strs[0].substr(0,i);
                return ans;
                break;
            }
        }
        ans = strs[0];
        return ans;
    }
};