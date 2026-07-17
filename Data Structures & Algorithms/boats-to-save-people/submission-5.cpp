class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left=0;
        int right=people.size()-1;
        vector<vector<int>> res;
        sort(people.begin(),people.end());
        while(left<=right){
            if(left==right){
                res.push_back({people[left]});
                break;
            }
            if(people[left]==limit && left<right){
                res.push_back({people[left]});
                left++;
            }
            if(people[right]==limit && left<right){
                res.push_back({people[right]});
                right--;
            }
            if(people[left]+people[right]==limit){
                res.push_back({people[left],people[right]});
                left++;
                right--;
            }else
            if(people[left]+people[right]<limit){
                res.push_back({people[left],people[right]});
                left++;
                right--;
            }else
            if(people[left]+people[right]>limit){
                res.push_back({people[right]});
                right--;
            }
        }
        return res.size();
    }
};