class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        int cursum=0;
        while(left<right){
            cursum=numbers[left]+numbers[right];
            if(cursum==target){
                return {left+1,right+1};
            }else
            if(cursum>target){
                right--;
            }else
            if(cursum<target){
                left++;
            }
        }
    }
};
