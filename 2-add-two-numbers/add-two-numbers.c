/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *res=NULL;
    struct ListNode *tail=NULL;
    int carry=0;
    while(l1!=NULL || l2 !=NULL || carry!=0){
       int sum=carry;

        if(l1!=NULL){
            sum=sum+l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum=sum+l2->val;
            l2=l2->next;
        }

        struct ListNode *newnode=malloc(sizeof(struct ListNode));
        newnode->val=sum%10;
        newnode->next=NULL;
        carry=sum/10;

        if(res==NULL){
            res=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next;
        }
    }
    return res;
}