#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_len = 0, l2_len = 0;

        ListNode *dummy = new ListNode(0);  // Dummy head to simplify list construction
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *tempR = dummy;
        int carry = 0;
        while (temp1 != nullptr || temp2 != nullptr || carry > 0) {
            int rem = carry;

            if(temp1 != nullptr) {
                rem += temp1->val;
                temp1 = temp1->next;
            }

            if (temp2 != nullptr) {
                rem += temp2->val;
                temp2 = temp2->next;
            }
            carry = rem / 10;
            rem = rem % 10;
            
            tempR->next = new ListNode(rem);
            tempR = tempR->next;
        }
        // Return the actual head (skip dummy)
        ListNode *result = dummy->next;
        delete dummy;  // Clean up dummy node
        return result;
        
    }
};

int main() {
    Solution sol;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(4);

    ListNode* result = sol.addTwoNumbers(l1, l2);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}