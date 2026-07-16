class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int left;
        int right;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            left=i+1;
            right=nums.size()-1;
            while(left<right){
                sum=nums[i]+nums[left]+nums[right];
                if(sum==0){
                    res.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]){
                    left++;
                }
                }else
                if(sum<0){
                    left++;
                }else
                if(sum>0){
                    right--;
                }
            }
        }
        return res;
    }
};
