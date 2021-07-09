//
// Created by mykhailenko on 09.07.21.
//

//You are given two non-empty linked lists representing two non-negative integers.
//The most significant digit comes first and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

//Example 1:
//Input: l1 = [7,2,4,3], l2 = [5,6,4]
//Output: [7,8,0,7]

//Example 2:
//Input: l1 = [2,4,3], l2 = [5,6,4]
//Output: [8,0,7]

//Example 3:
//Input: l1 = [0], l2 = [0]
//Output: [0]

//Constraints:
//
//The number of nodes in each linked list is in the range [1, 100].
//0 <= Node.val <= 9
//It is guaranteed that the list represents a number that does not have leading zeros.


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
    ListNode *reverse(ListNode *l) {
        auto head = *l;

        auto x = new ListNode(l->val, nullptr);

        while (l) {
            if (l->next) {
                auto new_node = new ListNode(l->next->val, l);

                auto tmp = x;
                x = new_node;
                x->next = tmp;
            }

            l = l->next;
        }

        l = &head;

        return x;
    }

    int getVal(int sum, int &digit) const {
        sum += digit;
        digit = sum / 10;
        return sum % 10;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto r_l1 = reverse(l1);
        auto r_l2 = reverse(l2);

        ListNode *res = nullptr;

        int digit = 0;

        auto add_fn =[&](ListNode *n){
            auto tmp = n;
            n = res;
            res = tmp;
            res->next = n;
        };

        while (r_l1 || r_l2) {
            ListNode *new_node = nullptr;

            if (r_l1 && r_l2) {
                new_node = new ListNode(getVal(r_l1->val + r_l2->val, digit));
            } else {
                new_node = new ListNode(getVal(r_l1 ? r_l1->val : r_l2->val, digit));
            }

            add_fn(new_node);

            if (r_l1) r_l1 = r_l1->next;
            if (r_l2) r_l2 = r_l2->next;
        }

        if (digit) add_fn(new ListNode(1));

        return res;
    }
};