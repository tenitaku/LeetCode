/*
 配列を棒グラフで表したときに、２つの要素で長方形を作った面積が最大となるものを返す。
 わかりずらいので図を参照：https://leetcode.com/problems/container-with-most-water/
 
 Example 1:
 
 Input: height = [1,8,6,2,5,4,8,3,7]
 Output: 49
 Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
 
 Example 2:
 
 Input: height = [1,1]
 Output: 1
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int width = right - left;
            maxArea = max(maxArea, min(height[left], height[right]) * width);
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};
