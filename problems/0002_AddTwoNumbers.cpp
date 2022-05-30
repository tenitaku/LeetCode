/*
 ２つのリストが与えられるので、その合計した値を表すリストを出力する問題。繰り上げが生じた際はリスト後方に繰り上げる。
 
 Example 1:
 
 Input: l1 = [2,4,3], l2 = [5,6,4]
 Output: [7,0,8]
 Explanation: 342 + 465 = 807.
 
 
 Example 2:

 Input: l1 = [0], l2 = [0]
 Output: [0]
 
 
 Example 3:

 Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 Output: [8,9,9,9,0,0,0,1]
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode newHead(0);
        ListNode *t = &newHead;
        while(c || l1 || l2) {
            c += (l1? l1->val : 0) + (l2? l2->val : 0);
            t->next = new ListNode(c%10);
            t = t->next;
            c /= 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return newHead.next;
    }
};
