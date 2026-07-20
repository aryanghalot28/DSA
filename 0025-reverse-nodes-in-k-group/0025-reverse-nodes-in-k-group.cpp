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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp!= NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* find(ListNode* temp, int k){
        k--;
        while(temp != NULL && k > 0){
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevnode = NULL;
        while(temp != NULL){
            ListNode* knode = find(temp, k);
            if(knode == NULL){
                if(prevnode != NULL)
                    prevnode->next = temp;
                break;
            }
            ListNode* nextnode = knode->next;
            knode->next = NULL;
            reverse(temp);
            if(temp == head){
                head = knode;
            }
            else{
                prevnode->next = knode;
            }
            prevnode = temp;
            temp = nextnode;
        }

        return head;
    }
};