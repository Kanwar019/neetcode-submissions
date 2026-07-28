class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int top=0;
        int bot=rows-1;
        int row;
        while(top<=bot){
            int mid=(top+bot)/2;
            if(matrix[mid][cols-1]<target){
                top=mid+1;
            }else
            if(matrix[mid][0]>target){
                bot=mid-1;
            }else{
                row=mid;
                break;
            }
        }
        if(!(top<=bot)){
            return false;
        } 
        int left=0;
        int right=cols-1;
        while(left<=right){
            int mid=left+((right-left)/2);
            if(matrix[row][mid]<target){
                left=mid+1;
            }else
            if(matrix[row][mid]>target){
                right=mid-1;
            }else
            if(matrix[row][mid]==target){
                return true;
            }
        }
        return false;
    }
};
