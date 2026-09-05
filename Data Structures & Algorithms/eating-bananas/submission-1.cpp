class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int res=right;
        while(left<=right){
            int mid=(left+right)/2;
            int totaltime=0;
            for(int i=0;i<piles.size();i++){
                totaltime+=ceil(static_cast<double>(piles[i])/mid);
            }
            if(totaltime<=h){
                res=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return res;
    }
};
