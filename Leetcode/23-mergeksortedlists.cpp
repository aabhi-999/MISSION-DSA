Problem number-23
Problem name-merge k sorted lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;

        // Collect all values from linked lists
        for(ListNode* temp : lists) {
            while(temp != NULL) {
                v.push_back(temp->val);
                temp = temp->next;
            }
        }

        // If no elements, return NULL
        if(v.empty()) {
            return NULL;
        }

        // Sort collected values
        sort(v.begin(), v.end());

        // Create new sorted linked list
        ListNode* head = new ListNode(v[0]);
        ListNode* ptr = head;

        for(int i = 1; i < v.size(); i++) {
            ListNode* nn = new ListNode(v[i]);
            ptr->next = nn;
            ptr = ptr->next;
        }
        
        return head;
    }
};
