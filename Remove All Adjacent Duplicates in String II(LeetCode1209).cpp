/*You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

 */


class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> v;
        for(int i=0;i<s.size();i++)
        {
            if(v.empty()||v.back().first!=s[i])
            {
                v.push_back({s[i],1});
            }
            else
            {
                v.back().second++;
                if(v.back().second==k)
                    v.pop_back();
                
            }
        }
        string ans="";
        for(auto p:v)
        {
            for(int i=0;i<p.second;i++)
                ans.push_back(p.first);
        }
        return ans;
    }
};
