#include <numeric>
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r=0;
        int cursum=0;
        int res=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum<target) {
            return res=0;
            }
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
        return res;
    }
};