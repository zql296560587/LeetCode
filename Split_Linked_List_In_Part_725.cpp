//******************LeetCode******************************************/
//*********725. Split Linked List in Parts****************************/
//Given a (singly) linked list with head node root, write a function
//to split the linked list into k consecutive linked list "parts".
//
//The length of each part should be as equal as possible: no two 
//parts should have a size differing by more than 1. This may lead
//to some parts being null.
//
//The parts should be in order of occurrence in the input list, 
//and parts occurring earlier should always have a size greater 
//than or equal parts occurring later.
//
//Return a List of ListNode's representing the linked list parts
//that are formed.
//
//Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
//Example 1:
//Input: 
//root = [1, 2, 3], k = 5
//Output: [[1],[2],[3],[],[]]
//Explanation:
//The input and each element of the output are ListNodes, not arrays.
//For example, the input root has root.val = 1, root.next.val = 2, 
//\root.next.next.val = 3, and root.next.next.next = null.
//The first element output[0] has output[0].val = 1, output[0].next = null.
//The last element output[4] is null, but it's string representation 
//as a ListNode is [].
//Example 2:
//Input: 
//root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
//Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
//Explanation:
//The input has been split into consecutive parts with size difference
//at most 1, and earlier parts are a larger size than the later parts.
//Note:
//
//The length of root will be in the range [0, 1000].
//	Each value of a node in the input will be an integer in the range [0, 999].
//	k will be an integer in the range [1, 50].
//**************************************************************/


#define NULL    0
typedef struct linklist 
{
	int Element;
	struct linklist * next;
}linklist;
struct linklist** splitListToParts(struct linklist* root, int PartsNum, int* returnSize) 
{
	int NumOfList = 0,i;//the length count of the list
	struct linklist ** result = (struct linklist **)malloc(sizeof(struct linklist*)*PartsNum);
	struct linklist* Current,*Temp;
	Current = root;
	while(Current)
	{
		NumOfList++;
		Current = Current->next;
	}
	*returnSize = PartsNum;		//to specify how many groups of data to return
	if(root == NULL)
	{
		for(i = 0;i<PartsNum;i++)
		{

			result[i] = root;

		}
		return result;
	}

	Current = root;
	if(NumOfList <= PartsNum)	//when the list length is smaller than groups to be divided,one node in each group£¬
	{
		for(i = 0;i<PartsNum;i++)
		{

			Temp = Current;	//used to cut down the other nodes from the very one current node
			result[i] = Temp;
			if(Current)
			{
				Current = Current->next;
				Temp->next = NULL;
			}

		}
	}
	else//when the list length is smaller than groups,each group have NumInRow nodes£¬the previous NumLeft groups have one more node
	{
		int NumInRow = NumOfList/PartsNum;	//The number of nodes in each groups
		int NumLeft = NumOfList%PartsNum;//the previous NumLeft groups that have one more node than average 
		int j = 0;
		Current = root;
		for(i = 0;i<PartsNum;i++)
		{
			Temp = Current;//used to cut down the other nodes from the very one current node
			result[i] = Temp;
			for(j = 1;j<NumInRow;j++)
			{
				Current = Current->next;
				Temp = Temp->next;
			}
			if(NumLeft)
			{
				Current = Current->next;
				Temp = Temp->next;
				NumLeft--;
			}
			Current = Temp->next;
			Temp->next = NULL;
		}
	}
	return result;
}
