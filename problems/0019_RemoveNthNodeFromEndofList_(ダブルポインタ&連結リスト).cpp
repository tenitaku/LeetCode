/*
 Given the head of a linked list, remove the nth node from the end of the list and return its head.
 
 例
 Input: head = [1,2,3,4,5], n = 2
 Output: [1,2,3,5]
 
 Input: head = [1], n = 1
 Output: []
 
 Input: head = [1,2], n = 1
 Output: [1]
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i <= n; i++) {
            if (fast == nullptr) {
                return head->next;
            }
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

/*
 ＜ポイント＞
 ・連結リストは、head-1-2-3-4-5-nullという構造を持つことさえ理解できれば簡単。
 ・連結リストのある値を除く処理は、a->next = a->next->nextでできる。
 
 */

