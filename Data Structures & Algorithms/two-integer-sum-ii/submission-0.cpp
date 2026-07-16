class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=1;
        vector<int> res;
        while(i<numbers.size()){
            if(numbers[i]+numbers[j]==target){
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }else{
                j++;
                if(j==numbers.size()){
                    i++;
                    j=i+1;
                }
            }
        }
    }
};
