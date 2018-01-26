##ListNode
- listnode * create an pointer to point a listnode

that means if you create a new listnode* it is Null
you need to give it a address of a listnode
```cpp
//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* newNodeP;//it is NULL now
ListNode newNode(0);
newNodeP = &newNode;
```
- in general, -> operator is used to call class member with class object pointer

that means:
```cpp
a->next;//a must be pointer
```
##String
- KMP string match

next array => finite automata   
save previous calculated results

##DP
- Choose is import

when you can not figure out optimal substructure ,find the core of problem :choose


##data type in cpp
- type convert

here is code:
```cpp
signed char a = 0xe0;
unsigned int b = a;
unsigned char c = a;
```     
computer stores number with complement code, ``` a = 1110 0000; ``` since a is signed char,  top digit is sign bit, ``` if a < 0 true form = ~(complement-1) ```

signed : top digit is signed bit: 1 is negative  0 is positive   
unsigned : top digit is data bit   
convert a negative to a unsigned:
true form of negative left shift and fill zero then calculate complement


## Tree
- recursive is think fast but compute slow ,non-recursive is think slow but compute fast

first use recursive method to solve then think a non-recursive method to improve speed
- 二叉树的非递归遍历（前序、中序、后序）


## vector
- vector中指针的应用以及熟悉掌握vector的各种函数 
