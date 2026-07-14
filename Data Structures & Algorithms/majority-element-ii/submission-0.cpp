class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> counts;
        for(int i=0;i<nums.size();i++){
            counts[nums[i]]++;
        }

        for(int i=0;i<counts.size();i++){
            if(counts[i]> (nums.size())/3){
                res.push_back(i);
            }
        }
        return res;
    }
};