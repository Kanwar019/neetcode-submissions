class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]== val){
                n++;
                nums[i]=0;
            }
        }
        if(n!=0){
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-n;i++){
            nums[i]=nums[n+i];
            nums[n+i]=0;
            }
        }
        int k = nums.size()-n;
        int ans[k];
        for(int i=0;i<k;i++){
            ans[i]=nums[i];
        }
        return k;
    }
};