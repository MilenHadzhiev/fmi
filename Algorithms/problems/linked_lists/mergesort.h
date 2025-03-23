#ifndef MERGESORT_H
#define MERGESORT_H


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }

    ListNode* mergesort(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* middle = get_middle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr;

        mergesort(left);
        mergesort(right);

        return merge(left, right);
    }

    static ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (left != nullptr && right != nullptr)
        {
            if (left->val <= right->val)
            {
                tail->next = left;
                left = left->next;
            } else
            {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        if (left != nullptr)
        {
            tail->next = left;
        } else
        {
            tail->next = right;
        }
        return dummy.next;
    }

    static ListNode *get_middle(ListNode *head)
    {
        if (head == nullptr) return head;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


#endif //MERGESORT_H
