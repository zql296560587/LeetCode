//******************LeetCode************************************/
//*********92. Reverse Linked List II***************************/
//Reverse a linked list from position m to n. Do it in one-pass.
//
//Note: 1 ¡Ü m ¡Ü n ¡Ü length of list.
//
//Example:
//
//Input: 1->2->3->4->5->NULL, m = 2, n = 4
//Output: 1->4->3->2->5->NULL
//**************************************************************/


#define NULL    0
typedef struct linklist 
{
	int Element;
	struct linklist * next;
}linklist;
struct linklist* reverseBetweenFirstNode(struct linklist* head, int m, int n) 
{
	if( m == n || head->next ==NULL)
	{
		return head;
	}
	int i = 1;//for there is a first node in calling fun
	struct linklist* pList_m,*pNext,*pPrev,*Current;
	pPrev = (linklist*)malloc(sizeof(linklist));
	Current = head;
	pPrev->next = (linklist*)Current;//in case m =1,head will be change for the n,here to mark head
	while(Current && i < m)
	{
		if(i == m-1)
		{
			pPrev->next = Current;
		}
		Current = Current->next;
		i++;
	}
	pList_m = Current; //to get the current to the m
	if(m == 1)
	{
		for(i = m;i<n;i++)//reverse m to n
		{
			pNext = pList_m->next;
			pList_m->next = pNext->next;
			pNext->next = pPrev->next;
			pPrev->next = pNext;

		}
		return pPrev->next;// the first node(head) has been changed,so return pPrev->next
	}
	else
	{
		for(i = m;i<n;i++)//reverse m to n
		{
			pNext = pList_m->next;
			pList_m->next = pNext->next;
			pNext->next = pPrev->next->next;
			pPrev->next->next = pNext;

		}
		return head;
	}
}