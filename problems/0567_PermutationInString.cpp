/*
 Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

 In other words, return true if one of s1's permutations is the substring of s2.
 
 
 Example 1:

 Input: s1 = "ab", s2 = "eidbaooo"
 Output: true
 Explanation: s2 contains one permutation of s1 ("ba").
 
 
 Example 2:

 Input: s1 = "ab", s2 = "eidboaoo"
 Output: false
 
 
 Constraints:

 1 <= s1.length, s2.length <= 10^4
 s1 and s2 consist of lowercase English letters.
 */


class Solution {
public://                          hello
    //                  hello      kjellohjlsa(ellohがhelloの並び替え)
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        vector<int> s1map(26);//{a b c d e f g h i j k l m n o p q r s t u v w x y zに対応する数字のイメージ}
        vector<int> s2map(26);//{a b c d e f g h i j k l m n o p q r s t u v w x y zに対応する数字のイメージ}
        
        for (int i = 0; i < s1.size(); i++) {
            s1map[s1.at(i) - 'a']++;
            s2map[s2.at(i) - 'a']++;
        }
        //これで、ある文字xが何文字含まれるかを格納することができた。
        //        {a b c d e f g h i j k l m n o p q r s t u v w x y z}
        //s1map = {0 0 0 0 1 0 0 1 0 0 0 2 0 0 1 0 0 0 0 0 0 0 0 0 0 0} hello
        //s2map = {2 0 0 0 1 0 0 2 0 2 0 4 0 0 2 0 0 0 2 0 0 0 0 0 0 0} kjellohjlsa
        //6回ループする(i=0~5)
        for (int i = 0; i < s2.size() - s1.size(); i++) {
            //完全に一致するなら含まれることは確定
            if (s1map == s2map) return true;
            
            s2map[s2.at(i + s1.size()) - 'a']++;
            s2map[s2.at(i) - 'a']--;
        }
        return (s1map == s2map);
    }
};

/*
 ＜ポイント＞
 permutation:順列（並び替え）：s1の並び替えがs2に含まれるかどうかを判定する。
 aからzまで26文字なので26格納できる配列を準備する。
 
 */
