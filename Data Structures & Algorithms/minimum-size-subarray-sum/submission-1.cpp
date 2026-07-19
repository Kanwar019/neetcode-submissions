#include <numeric>
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r=0;
        int cursum=0;
        int res=INT_MAX;
        while(l<=r && r<nums.size()){
            cursum+=nums[r];
            if(cursum>=target){
                res=min(res,r-l+1);
                cursum-=nums[l];
                cursum-=nums[r];
                l++;
                r--;
            }
            r++;
        }
        return res==INT_MAX?0:res;
    }
};