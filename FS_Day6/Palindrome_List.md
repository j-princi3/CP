#2-pointer 
#singlylinkedlist 
#medium 
Cliff Shaw is working on the singly linked list.
He is given a list of boxes arranged as singly linked list,
where each box is printed a positive number on it.

Your task is to help Mr Cliff to find the given list is equivalent to 
the reverse of it or not. If yes, print "true", otherwise print "false"

Input Format:
-------------
Line-1: space separated integers, boxes as list.

Output Format:
--------------
Print a boolean a value.

Sample Input-1:
---------------
3 6 2 6 3

Sample Output-1:
----------------
true


Sample Input-2:
---------------
3 6 2 3 6

Sample Output-2:
----------------
false

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }



```java
class Solution {
    int mid = 1;

    public boolean isPalindrome(ListNode head) {

        if (head.next == null) {
            return true;
        }

        ListNode midHead = getMidList(head);
    
        ListNode part = getReverseList(midHead);
        while (part != null) {

            if (part.val != head.val) {
                return false;
            }
            part = part.next;
            head = head.next;
        }

        return true;

    }

    ListNode getMidList(ListNode head) {

        ListNode fastPointer = head;
        ListNode slowPointer = head;

        while (fastPointer != null && fastPointer.next != null) {
            fastPointer = fastPointer.next.next;
            slowPointer = slowPointer.next;
            mid++;
        }
        // System.out.print(slowPointer.val);
        return slowPointer;
    }

    ListNode getReverseList(ListNode head) {
        ListNode nextList = head;
        ListNode curr = head;
        ListNode prev = null;

        while (nextList != null) {
            nextList = nextList.next;
            curr.next = prev;
            prev = curr; 
            curr = nextList;
        }
        return prev; 
    }

}
```