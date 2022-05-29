/*
 Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

 Note that you must do this in-place without making a copy of the array.
 
 Example 1:

 Input: nums = [0,1,0,3,12]
 Output: [1,3,12,0,0]
 
 Example 2:

 Input: nums = [0]
 Output: [0]
 
 Constraints:

 1 <= nums.length <= 10^4
 -2^31 <= nums[i] <= 2^31 - 1
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        int numZeroes = 0;
        for (int i = 0; i < n; i++) {
            numZeroes += (nums[i] == 0);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                ans.push_back(nums[i]);
            }
        }

        while (numZeroes--) {
            ans.push_back(0);
        }

        for (int i = 0; i < n; i++) {
            nums[i] = ans[i];
        }
    }
};

/*
 説明
 0の数を数える
 0でない時に新配列に格納する
 0の数だけ0をpush_backする
 時間空間ともにO(n)で解ける
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt] = nums[i];
                lastNonZeroFoundAt++;
            }
        }
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

/*
 説明
 0でない要素である時、最後の０でない要素の後に追加していく。
 最後の０でないindexをlastNonZeroFoundAtに保存していく。
 ここで、
 nums[lastNonZeroFoundAt] = nums[i];
 lastNonZeroFoundAt++;
 
 は
 nums[lastNonZeroFoundAt++] = nums[i];と省略することができるが、処理の順序によるミスを防ぐ方が大事。
 
 時間O(n)と空間O(1)で処理することができる
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int lastNonZeroFoundAt = 0, i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[lastNonZeroFoundAt], nums[i]);
                lastNonZeroFoundAt++;
            }
        }
        
    }
};

/*
 説明
 0でない時、一番左の0と順次入れ替えていく方法。
 ここでも、先程と同様にLastNonzeroFoundAtを記憶しておく必要がある。
 O(n)とO(1)で一緒であり、どちらが優れているかは、0が配列にどのように格納されているかによって変化する。
 */




