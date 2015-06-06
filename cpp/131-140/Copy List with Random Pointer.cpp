class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        RandomListNode *n = head;
        RandomListNode *h = new RandomListNode(0);
        RandomListNode *result = h;
        unordered_map<RandomListNode*, RandomListNode*>maps;

        while(head)
        {
            RandomListNode *newnode = new RandomListNode(head->label);
            maps[head] = newnode;
            h -> next = newnode;
            h = h->next;
            head = head->next;
        }
        
        RandomListNode *r = result->next;
        while(n)
        {
            r->random = maps[n->random];
            r = r->next;
            n = n->next;
        }
        
        return result->next;
    }
};
