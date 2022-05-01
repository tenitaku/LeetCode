//Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//You must write an algorithm with O(log n) runtime complexity.

/*
 Example 1:

 Input: nums = [1,3,5,6], target = 5
 Output: 2
 
 
 Example 2:

 Input: nums = [1,3,5,6], target = 2
 Output: 1
 
 
 Example 3:

 Input: nums = [1,3,5,6], target = 7
 Output: 4
 
 Constraints:

 1 <= nums.length <= 10^4
 -10^4 <= nums[i] <= 10^4
 nums contains distinct values sorted in ascending order.
 -10^4 <= target <= 10^4
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pivot, left = 0, right = nums.size() - 1;
        while (left <= right) {
            pivot = left + (right - left) / 2;
            if (nums[pivot] == target) return pivot;
            if (target < nums[pivot]) right = pivot - 1;
            else left = pivot + 1;
        }
        return left;
    }
};

/*
 ＜ポイント＞
 ・二分探索。最後の出力は多少問題によって異なるものの、構造は同じ。
 ・今回は、targetが配列の中にないときに、本来あるべき場所のpointを返すという問題。
 ・まず最初にBinarySearchを行い、その後返す値を決める方が良い。
 ・雛形を打ち込んで、その後変更していく方法が良いかもしれない。
 ・O(logn)で計算せよ、とあるのでおそらく２分探索だなと考える
 */
