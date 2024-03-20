/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class List{
    ListNode* head;
public:
    List()
    {
        head = nullptr;
    }
    bool isEmpty()
    {
        return (head == nullptr);
    }
    void append(int item)
    {
        ListNode* newNode = new ListNode(item);
        if (isEmpty())
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            ListNode* t = head;
            while (t->next != nullptr)
            {
                t = t->next;
            }
            newNode->next = nullptr;
            t->next = newNode;
        }
    }
    ListNode* getHead()
    {
        return head;
    }
    void disp()
    {
        ListNode* t = head;
        while (t != nullptr)
        {
            cout << t->val << " ";
            t = t->next;
        }
        cout << "\n";
    }
    void retrive(ListNode * temp)
    {
        head = temp;
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        List l;
        while (list1 != nullptr || list2 != nullptr)
        {
            if (list1 == nullptr)
            {
                l.append(list2->val);
                list2 = list2->next;
            }
            else if (list2 == nullptr)
            {
                l.append(list1->val);
                list1 = list1->next;
            }
            else if (list1->val <= list2->val)
            {
                l.append(list1->val);
                list1 = list1->next;
            }
            else
            {
                l.append(list2->val);
                list2 = list2->next;
            }

        }
        return l.getHead();

    }
};

int main()
{
    List l1, l2;
    l1.append(1);
    l1.append(2);
   /* l1.append(4);
    l1.append(5);
    l1.append(7);*/
    
    l1.disp();

    l2.append(1);
    l2.append(3);
    l2.append(4);
    l2.disp();

    List l3;
    Solution s;
    l3.retrive(s.mergeTwoLists(l1.getHead(), l2.getHead()));
   
    l3.disp();

    return 0;
}
