/*
 --Example1--
 Input: nums = [2,7,11,15], target = 9
 Output: [0,1]
 Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 
 --Example2--
 Input: nums = [3,2,4], target = 6
 Output: [1,2]
 
 --Example3--
 Input: nums = [3,3], target = 6
 Output: [0,1]
 
 --Constraints--
 ・2 <= nums.length <= 10^4
 ・-10^9 <= nums[i] <= 10^9
 ・-10^9 <= target <= 10^9
 ・Only one valid answer exists.
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        //ハッシュ連想配列クラス：O(1)で高速
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.find(target - nums[i]) != indices.end()) {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};
