//******************LeetCode**************************************/
//*********382. Linked List Random Node***************************/
//Given a singly linked list, return a random node's value from
//the linked list. Each node must have the same probability of 
//being chosen.
//
//	Follow up:
//What if the linked list is extremely large and its length 
//is unknown to you? Could you solve this efficiently without
//using extra space?
//
//Example:
//
//// Init a singly linked list [1,2,3].
//ListNode head = new ListNode(1);
//head.next = new ListNode(2);
//head.next.next = new ListNode(3);
//Solution solution = new Solution(head);
//
//// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
//solution.getRandom();
//**************************************************************/


#define NULL    0
typedef struct linklist 
{
	int Element;
	struct linklist * next;
}linklist;
typedef struct 
{
	int Cnt;
    struct ListNode* Pointer;    
} Solution;

/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
Solution* solutionCreate(struct linklist* head)
{
	Solution* obj = (Solution*)malloc(sizeof(Solution));
	obj->Pointer = head;
	obj->Cnt = 0;
	while(head){obj->Cnt ++;head = head->next;}
	return obj;
}
/** Returns a random node's value. */
int solutionGetRandom(Solution* obj) 
{
	int ret,Index,i;
	struct linklist *p = obj->Pointer;
	Index = rand() % (obj->Cnt)+1;//get random index to return the element on specified position
	for(i = 0;i<Index;i++)// get the specified node
	{
		ret = p->val;
		p = p->next;
	}
	return ret;
}

void solutionFree(Solution* obj) 
{
    free(obj);
}
