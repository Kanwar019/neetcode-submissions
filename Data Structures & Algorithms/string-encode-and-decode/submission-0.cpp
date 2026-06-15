class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_strs="";
        for(int i=0;i<strs.size();i++){
            encoded_strs+=to_string(strs[i].size())+"#"+strs[i];
        }
        return encoded_strs;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            res.push_back(s.substr(i, length));
            i = j;
        }
        return res;
        }
        
};
