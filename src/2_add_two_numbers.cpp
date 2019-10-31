//
// Created by Oleksyshyn Oleksii on 31.10.19.
//


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);

        count(l1, l2, result);

        return result;
    }

    void count(ListNode* l1, ListNode* l2, ListNode* result){
        bool first = true;
        int inc = 0;

        while (l1 != nullptr || l2 != nullptr){

            int x1 = l1 ? l1->val : 0;
            int x2 = l2 ? l2->val : 0;

            int value = x1 + x2 + inc;

            if (value > 9){
                value -= 10;
                inc = 1;
            } else inc = 0;

            if (first){
                result->val = value;
                first = false;
            } else {
                ListNode* new_node = new ListNode(value);
                result->next = new_node;
                result = result->next;
            }

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
            first = false;
        }

        if (inc == 1){
            ListNode* new_node = new ListNode(1);
            result->next = new_node;
        }

    }
};