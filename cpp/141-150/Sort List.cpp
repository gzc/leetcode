class Solution {
    
public:
    
    ListNode* merge(ListNode *node1, int n1, ListNode *node2, int n2, ListNode *before)
    {
        ListNode *first(node1), *second(node2);
        int len1(n1), len2(n2);
        if(node1 -> val > node2 ->val)
        {
            first = node2;
            second = node1;
            len1 = n2;
            len2 = n1;
        }
        ListNode *head(first), *answer(first);
        
        while(1)
        {
            if(first->val <= second->val)
            {
                if(len1 == 1)
                {
                    first -> next = second;
                    break;
                }
                else
                {
                    len1--;
                    head = first;
                    first = first -> next;
                    continue;
                }
            }
            
            else {
                len2--;
                ListNode *temp = second;
                second = second->next;
                temp->next = first;
                head->next = temp;
                head = temp;
                if(len2 == 0)   break;
            }
        }
        
        if(before)
            before->next = answer;
        ListNode *t = answer;
        int l = n1+n2;
        while(l-- > 1)
            t = t->next;
        t->next = NULL;

        return t;
    }
    
    int lengthOfList(ListNode *node)
    {
        int len = 0;
        while(node)
        {
            len++;
            node = node->next;
        }
        return len;
    }

    ListNode* find(ListNode* node, int L)
    {
        while(node && L > 0)
        {
            node = node->next;
            L--;
        }
        return node;
    }
    
    ListNode *sortList(ListNode *head) {
        int num = 1;
        int len = lengthOfList(head);
        ListNode *ans = head;
        ListNode *tmp = head;
        while(num < len)
        {
            for(int i = num;i > 0&&tmp->next;i--)
                tmp = tmp->next;
            if(ans->val > tmp->val) ans = tmp;
            ListNode *tail = NULL;
            ListNode *node1(head), *node2(tmp);

            while(node2)
            {
                ListNode *nextnode = node2;
                int p = num;
                while(nextnode && p > 0)
                {
                    nextnode = nextnode->next;
                    p--;
                }
                nextnode = find(node2,num);
                tail = merge(node1, num, node2, num-p, tail);
                node1 = nextnode;
                node2 = find(node1,num);
                if(node1 || !node2)
                    tail->next = node1;
            }
            
            head = ans;
            tmp = head;
            num *= 2;
        }
        return ans;
    }

};
