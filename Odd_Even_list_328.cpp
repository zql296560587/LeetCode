//******************LeetCode************************************/
//*********328. Odd Even Linked List***************************/
//Given a singly linked list, group all odd nodes together 
//followed by the even nodes. Please note here we are talking
//about the node number and not the value in the nodes.
//
//You should try to do it in place. The program should run
//in O(1) space complexity and O(nodes) time complexity.
//
//Example:
//Given 1->2->3->4->5->NULL,
//	return 1->3->5->2->4->NULL.
//
//Note:
//The relative order inside both the even and odd groups should 
//remain as it was in the input. 
//The first node is considered odd, the second node even and so on ...
//**************************************************************/


#define NULL    0
typedef struct linklist 
{
	int Element;
	struct linklist * next;
}linklist;
struct linklist* Odd_Even_List_FirstNode(struct linklist* HeadNode) 
{
	int i = 0;
	if(HeadNode==NULL)
		return HeadNode;
	struct linklist * Odd,*Even,*EvenHead,*Current;
	Even = (struct linklist*)malloc(sizeof(struct linklist*));
	Odd = (struct linklist*)malloc(sizeof(struct linklist*));
	EvenHead = HeadNode->next;
	Current  = HeadNode;
	while(Current)
	{
		i ++;
		if(i%2)// get the odd list
		{
			Odd->next = Current;
			Odd = Odd->next;
		}
		else// get the even list
		{
			Even->next = Current;
			Even = Even->next;
		}
		Current = Current->next;
	}
	if(i%2)
	{
		Even->next = NULL;//take the last node of Even list as NULL
	}
	Odd->next = EvenHead;//link the even after the odd
	return HeadNode;//here is the new list(the even after the odd)
}