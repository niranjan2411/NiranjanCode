// 3. Maximum Consecutive Ones
// ○ Platform: LeetCode
// ○ Link: https://leetcode.com/problems/max-consecutive-ones/

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int res = 0;
            int count = 0;
    
            for (int n : nums) {
                if (n == 0) {
                    count = 0;
                } else {
                    count++;
                }
    
                if (res < count) {
                    res = count;
                }
            }
    
            return res;        
        }
    };