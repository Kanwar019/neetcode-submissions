class Solution {
public:
    unordered_set<string> st;
    int t[201];
    int n;
    bool solve(int idx,string &s){
          if(idx>=n) return true;
          if(st.find(s)!=st.end()){
            return true;
          }
          if(t[idx]!=-1) return t[idx];
          for(int l=1;l<=n;l++){
            string temp=s.substr(idx,l);
            if(st.find(temp)!=st.end() && solve(idx+l,s)){
                return t[idx]=true;
            }
          }
          return t[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        for(int i=0;i<n;i++){
            t[i]=-1;
        }
        for(string &word:wordDict){
            st.insert(word);
        }
        return solve(0,s);
    }
};
