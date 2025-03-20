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
    ListNode* reverse(ListNode* outsideStart, int left, int right) {   
        ListNode* start = outsideStart->next;
        ListNode* insideStart = nullptr;
        ListNode* end  = nullptr;
        ListNode* insideEnd  = nullptr;
        ListNode* outsideEnd  = nullptr;
        if ((right - left) == 0) { std::cout << "(Base) Start:" << start->val << std::endl; return start; } 
        if ((right - left) > 1) {
            insideEnd = reverse(start, left + 1, right - 1); //16, 15 ,14
            std::cout << "outsideStart: " << outsideStart->val << " | ";
            std::cout << "start: " << start->val << " | ";
            insideStart = start->next;
            std::cout << " insideStart: " << insideStart->val << " | ";
            end = insideEnd->next;   
            std::cout << " insideEnd: " << insideEnd->val << " | ";
            std::cout << " end: " << end->val << " | ";
        } else {
            insideEnd = start->next;
            std::cout << "(BASE)" << std::endl;
            std::cout << "outsideStart: " << outsideStart->val << " | ";
            std::cout << "start: " << start->val << " | ";
            insideStart = start;
            std::cout << " insideStart: " << insideStart->val << " | ";
            end = insideEnd;
            std::cout <<" end: " << end->val << " | ";
        } 
        outsideEnd = end->next;
        
        if (outsideEnd) {
             std::cout << " outsideEnd: " << outsideEnd->val;
        } 
        std::cout << " -----> ";

        outsideStart->next = end;
        end->next = insideStart;
        insideEnd->next = start;
        start->next = outsideEnd; 
        
        std::cout << "outsideStart: " << outsideStart->val << " | ";
        std::cout << "start/outsideStart->next: " << outsideStart->next->val << " | ";
        std::cout << "inside end/end->next: " << end->next->val << " | ";
        std::cout << "end / insideEnd->next: " << insideEnd->next->val << " | ";
        if (start->next) {
            std::cout << "otuside end/start->next: " << start->next->val << std::endl;
        }
        return start;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode(0, head);
        ListNode* mainListStart = dummy;
        for(auto i = 1; i < left; i++) {
            mainListStart = mainListStart->next;
        }
        reverse(mainListStart, left, right);
        return dummy->next;
    }
};
