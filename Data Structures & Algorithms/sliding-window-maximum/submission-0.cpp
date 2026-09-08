class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // 'dq' stores indices in decreasing value order
        vector<int> ans; // 'ans' stores the maximum of each window
        int n = nums.size(); // 'n' stores the number of elements

        for(int i = 0; i < n; i++) { // Iterating through every array element
            while(!dq.empty() && dq.front() <= i - k) { // Removing indices outside the current window
                dq.pop_front(); // Removing the outdated front index
            } // Closing the outdated-index loop

            while(!dq.empty() && nums[dq.back()] <= nums[i]) { // Removing smaller values from the back
                dq.pop_back(); // Removing an index that cannot be the maximum
            } // Closing the smaller-value loop

            dq.push_back(i); // Adding the current index to the deque

            if(i >= k - 1) { // Checking whether the first complete window is formed
                ans.push_back(nums[dq.front()]); // Adding the current maximum to the answer
            } // Closing the window check
        } // Closing the array traversal loop

        return ans; // Returning all window maxim
    }
};
