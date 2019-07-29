/* Add two integer numbers in the form of reversed linked list
   and save the result into a reversed linked list as well.
   Challenge from leetCode.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * digit = new ListNode(-1);
        ListNode * res   = digit;
        ListNode * uhead = l1;  // up head
        ListNode * dhead = l2;  // down head
        int remainder    = 0;
        
        int uval = 0;  // up value
        int dval = 0;  // down value
        int sum  = 0; 
        
        while(NULL != uhead || NULL != dhead){
            uval = (uhead != NULL) ? uhead->val : 0;
            dval = (dhead != NULL) ? dhead->val : 0;
            sum  = remainder + uval + dval;
            
            remainder   = sum / 10;
            digit->next = new ListNode(sum % 10);
            digit       = digit->next;
            
            if(NULL != uhead)        // important not to crach.
                uhead = uhead->next;
            if(NULL != dhead)
                dhead = dhead->next;
        }
        if(remainder){
            digit->next = new ListNode(remainder);
        }
        return res->next;
    }
};
