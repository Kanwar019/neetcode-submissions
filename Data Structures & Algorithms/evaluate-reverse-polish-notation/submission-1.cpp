class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int temp=stack.back();
                stack.pop_back();
                int sum= temp+ stack.back();
                stack.pop_back();
                stack.push_back(sum);
            }else
            if(tokens[i]=="*"){
                int temp = stack.back();
                stack.pop_back();
                int mul=temp*stack.back();
                stack.pop_back();
                stack.push_back(mul);
            }else
            if(tokens[i]=="-"){
                int temp=stack.back();
                stack.pop_back();
                int neg= stack.back()-temp;
                stack.pop_back();
                stack.push_back(neg);
            }else
            if(tokens[i]=="/"){
                 int temp = stack.back();
                stack.pop_back();
                int div=stack.back()/temp;
                stack.pop_back();
                stack.push_back(div);
            }else{
                stack.push_back(stoi(tokens[i]));
            }
        }
        return stack.back();
    }
};
