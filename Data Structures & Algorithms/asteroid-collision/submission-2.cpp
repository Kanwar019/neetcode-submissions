class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for(int i=0;i<asteroids.size();i++){
            bool destroyed=false;
            while(!stack.empty() && stack.back()>0 && asteroids[i]<0){
                if(stack.back()<-asteroids[i]){
                    stack.pop_back();
                }else
                if(stack.back()==-asteroids[i]){
                    stack.pop_back();
                    destroyed=true;
                    break;
                }else{
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed){
                    stack.push_back(asteroids[i]);
                }
        }
        return stack;
    }
};