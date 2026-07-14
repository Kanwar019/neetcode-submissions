class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);
        int i=0;
        int j=0;
        while(i<nums.size()){
            if(j!=i){
                res[i]*=nums[j];
            }
            j++;
            if(j==nums.size()){
                i++;
                j=0;
            }
        }
        return res;
    }
};
