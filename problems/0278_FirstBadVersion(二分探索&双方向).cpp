/*
 You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

 Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

 You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
 
 
 Example 1:

 Input: n = 5, bad = 4
 Output: 4
 Explanation:
 call isBadVersion(3) -> false
 call isBadVersion(5) -> true
 call isBadVersion(4) -> true
 Then 4 is the first bad version.
 
 Example 2:

 Input: n = 1, bad = 1
 Output: 1
 
 
 Constraints:

 1 <= bad <= n <= 2^31 - 1
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int pivot, left = 0, right = n;
        while (left < right) {
            pivot = left + (right - left) / 2;
            if (isBadVersion(pivot)) right = pivot;
            else left = pivot + 1;
        }
        return left;
    }
};

/*
 ＜ポイント＞
 より簡単な解法として、
 for (int i = 1; i<n; i++){
    if (isBadVersion(i)) return i;
 }
 return n;
 という方法があるO(n)しかし、制約にn <= 2^31 -1とあるように非常に大きな値となる時、二分探索O(logn)を用いた方がよい。
 
 今回の二分探索では、left と　right の処理が少し難しい。
 最初にtrueとなる数字を返すため、最終的にその数字をleftとして、left=rightとなったときにwhile文を抜ける構造とする
 
 ・pivot = (left + right) / 2と安易にしてしまうと、オーバーフロウを発生してしまう恐れがあるため、
 pivot = left + (left + right) / 2とする
 */
