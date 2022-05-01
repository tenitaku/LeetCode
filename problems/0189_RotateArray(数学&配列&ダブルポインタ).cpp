/*
 Given an array, rotate the array to the right by k steps, where k is non-negative.
 
 Example 1:

 Input: nums = [1,2,3,4,5,6,7], k = 3
 Output: [5,6,7,1,2,3,4]
 Explanation:
 rotate 1 steps to the right: [7,1,2,3,4,5,6]
 rotate 2 steps to the right: [6,7,1,2,3,4,5]
 rotate 3 steps to the right: [5,6,7,1,2,3,4]
 
 Example 2:

 Input: nums = [-1,-100,3,99], k = 2
 Output: [3,99,-1,-100]
 Explanation:
 rotate 1 steps to the right: [99,-1,-100,3]
 rotate 2 steps to the right: [3,99,-1,-100]
 
 Constraints:

 1 <= nums.length <= 10^5
 -2^31 <= nums[i] <= 2^31 - 1
 0 <= k <= 10^5
 
 Follow up:

 Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
 Could you do it in-place with O(1) extra space?
 */

/*
 方法はいくつかある。
 
 １つ目
 ＜k回ローテーションを行う方法＞
 まず、最後を先頭に持ってくる
 次に、順番に入れ替えていく
 O(n*k)のため、莫大な時間がかかってしまう。
 */

class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        
        int temp, previous;
        for (int i = 0; i < k; i++) {
            previous = nums[nums.size() - 1];
            for (int j = 0; j < nums.size(); j++) {
                temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }
    }
};

/*
 ２つ目
 ＜新しい配列を用いる方法＞
 (i+k) % nums.size()の位置に、nums[i]を格納していくという方法。O(n)で解くことができる。
 例：i = 0~3まで, nums = {1, 2, 3, 4}, k = 2の時
 (0 + 2) % 4 = 2 : nums[2] = 3
 (1 + 2) % 4 = 3 : nums[3] = 4
 (2 + 2) % 4 = 0 : nums[0] = 1
 (3 + 2) % 4 = 1 : nums[1] = 2
 i =  0  1  2  3
 a = {3, 4, 1, 2}となる
   */
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> a(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            a[(i + k) % nums.size()] = nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = a[i];
        }
    }
};

/*
 ３つ目
 ＜3回のリバースで結果を得る方法＞
 ・元の配列をリバースする
 ・0~kをリバース
 ・k+1~n-1をリバース
 することにより、結果が得られるというアルゴリズム。知っているもん勝ち。
 ここでは、新たなcustom_reverseという関数を作っている。
 なぜなら、標準のreverse関数では、イテレータを用いており、begin()+1、end()-1などしたい時の操作がわかりにくいからである。
 時間計算量O(n)、空間計算量O(1)で解くことができる。
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        custom_reverse(nums, 0, nums.size() - 1);
        custom_reverse(nums, 0, k - 1);
        custom_reverse(nums, k, nums.size() - 1);
        
    }
public:
    void custom_reverse(vector<int>& nums, int start, int end) {
        while(start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};

/*
 その４
 <まだ理解できてない方法>
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int count = 0;
        for (int start = 0; count < nums.size(); start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
};
