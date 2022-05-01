/*
 --Problem--
 Write a function that reverses a string. The input string is given as an array of characters s.
 You must do this by modifying the input array in-place with O(1) extra memory.
 
 --Example1--
 Input: s = ["h","e","l","l","o"]
 Output: ["o","l","l","e","h"]
 
 --Example2--
 Input: s = ["H","a","n","n","a","h"]
 Output: ["h","a","n","n","a","H"]f
 
 --Constraints--
 1 <= s.length <= 10^5
 s[i] is a printable ascii character.
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }
};

/*
 --ポイント--
 右端、左端から順にswapしていく。swapでは、一時的に格納する変数tmpをよく用いる。
 この方法であれば、時間O(n)、空間O(1)で解くことができる。
 ちなみに、時間計算量は英語でTime Complexity、空間計算量は英語でSpace Complexity。
 */
