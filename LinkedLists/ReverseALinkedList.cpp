#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
     LinkedListNode<int> *prevOfCurrentNode = NULL;

        while(head!= NULL){
            LinkedListNode<int> *nextOfCurrent = head->next;//  1 -> _2
            head->next = prevOfCurrentNode; // NULL <-1  _2
            prevOfCurrentNode = head;
            head = nextOfCurrent; // 2_
        }
        return prevOfCurrentNode;
}