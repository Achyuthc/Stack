
/*You are given a 0-indexed integer array nums. In one step, remove all elements nums[i] where nums[i - 1] > nums[i] for all 0 < i < nums.length.

Return the number of steps performed until nums becomes a non-decreasing array.*/
class Solution {
public:
    int totalSteps(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        stack<int> st;
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty()&&nums[i]>nums[st.top()])
            {
                dp[i]=max(++dp[i],dp[st.top()]);
                ans=max(ans,dp[i]);
                st.pop();
            }
            st.push(i);
        }
        return ans;
        
    }
};
