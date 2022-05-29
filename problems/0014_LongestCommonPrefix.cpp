/*
 Write a function to find the longest common prefix string amongst an array of strings.

 If there is no common prefix, return an empty string "".
 
 Example 1:
 Input: strs = ["flower","flow","flight"]
 Output: "fl"
 
 
 Example 2:
 Input: strs = ["dog","racecar","car"]
 Output: ""
 Explanation: There is no common prefix among the input strings.
  
 Constraints:
 1 <= strs.length <= 200
 0 <= strs[i].length <= 200
 strs[i] consists of only lower-case English letters.
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(), strs.end());
        
        string firstString = strs[0];
        string endString = strs[strs.size() - 1];
        string answerString = "";
        
        for (int i = 0; i < firstString.size(); i++) {
            if (firstString[i] == endString[i]) {
                answerString += firstString[i];
            } else break;
        }
        
        return answerString;
    }
};

/*
 strs配列全てに対して比較をしようとしていたが、
 sortを使い、文字列の長さ順に並べることで、一番最初と最後の比較だけで良くなる。
 という点に気づけるかどうかの問題。
 breakの便利な使用例もよくわかった。
 */
