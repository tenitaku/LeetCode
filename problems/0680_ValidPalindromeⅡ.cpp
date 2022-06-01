/*
 Given a string s, return true if the s can be palindrome after deleting at most one character from it.
 
 Example 1:
 Input: s = "aba"
 Output: true
 
 Example 2:
 Input: s = "abca"
 Output: true
 Explanation: You could delete the character 'c'.
 
 Example 3:
 Input: s = "abc"
 Output: false
  
 Constraints:
 1 <= s.length <= 10^5
 s consists of lowercase English letters.
 */

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            if (s.at(left) != s.at(right)) {
                return checkPalindrome(s, left, right - 1) || checkPalindrome(s, left + 1, right);
            }
            left++;
            right--;
        }
        return true;
    }
    
    bool checkPalindrome(string s, int left, int right) {
        while(left < right) {
            if (s.at(left) != s.at(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

//左右から見て、違うときに一つずらした判定を返すことで解決できる。
