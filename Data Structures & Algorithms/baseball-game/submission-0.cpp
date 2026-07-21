class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack;
        int res=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                int top=stack.back();
                stack.pop_back();
                int newtop=top+stack.back();
                stack.push_back(top);
                stack.push_back(newtop);
            }else
            if(operations[i]=="C"){
                stack.pop_back();
            }else
            if(operations[i]=="D"){
                stack.push_back(stack.back()*2);
            }else{
                stack.push_back(stoi(operations[i]));
            }
        }
        for(int i=0;i<stack.size();i++){
            res+=stack[i];
        }
        return res;
    }
};