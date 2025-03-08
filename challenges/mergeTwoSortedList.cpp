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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && list2) return list2;
        if (list1 && !list2) return list1;
        auto l1 = list1;
        auto l2 = list2;
        ListNode* l1p = nullptr;
        while (l1 && l2) {
            // if l1 is less than l2 update l1p and advance
            if (l1->val < l2->val) {
                l1p = l1;
                l1 = l1->next;
            } else {
                // else if l1 greater than or equal to l2
                // make a copy of t2 next
                auto t = l2->next;
                l2->next = l1;
                if (!l1p) {
                     // if at beginning of list l1p is null than set l1 to l2
                    // set t2 next to point  to l1
                    l1 = l2;
                    list1 = l1;
                } else {
                    // else set l1p-next to point to l2
                    // then set l1p->next->next to point to l1
                    // then set set l1p->next
                    l1p->next = l2;
                    l1p = l2;
                    l1 = l1p->next;
                }
                // advanced l2 to next node
                if (l1) {
                    l2 = t;
                }
            }
        }
        if (l1p && l2 ) {
            l1p->next = l2;
        }
        return list1;
    }
};
