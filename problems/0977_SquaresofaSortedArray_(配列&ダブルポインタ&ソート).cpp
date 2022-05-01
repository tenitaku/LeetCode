/*
 Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
 
 Example 1:

 Input: nums = [-4,-1,0,3,10]
 Output: [0,1,9,16,100]
 Explanation: After squaring, the array becomes [16,1,0,9,100].
 After sorting, it becomes [0,1,9,16,100].
 
 
 Example 2:

 Input: nums = [-7,-3,2,3,11]
 Output: [4,9,9,49,121]
 
 
 Constraints:

 1 <= nums.length <= 104
 -104 <= nums[i] <= 104
 nums is sorted in non-decreasing order.
 
 
 Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0;
        int right = n - 1;
        
        for (int i = n - 1; i >= 0; i--) {
            int square;
            if (abs(nums[left]) < abs(nums[right])) {
                square = nums[right];
                right--;
            } else {
                square = nums[left];
                left++;
            }
            result[i] = square * square;
        }
        return result;
    }
};

/*
 ＜ポイント＞
 単純に考えると、２乗してソートするという方法がある。以下のようにする。
 */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> ans(n);
        for (size_t i = 0; i < n; i++) {
            ans[i] = nums[i] * nums[i];
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
 しかし、N個の配列に対するソートはO(NlogN)かかってしまう。
 そのため、以下の方法をとる。
 
 ・元の配列の絶対値をleftとrightで比較する
 ・大きい方を新しい配列の後ろから順に格納していく。
 ・これをn回繰り返し、どんどんleftとrightを真ん中（ではないこともあるがイメージとして）に近づけていく。
 ・こうすることで、O(n)で計算することができる。
 */
