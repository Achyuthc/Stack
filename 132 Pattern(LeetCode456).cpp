/*Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.*/


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> v;
        if(nums.size()<=2)
            return false;
        int s3=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--)
        {
           while(v.size()>0&&v.back()<nums[i])
           {
               s3=max(s3,v.back());
               v.pop_back();
           }
           v.push_back(nums[i]);
           if(nums[i]<s3)
               return true;
        }
        return false;
        
    }
};
