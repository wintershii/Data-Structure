package com.winter.test;

public class DeleteNode {

    public void deleteNode(ListNode head, int i, int len) {
        ListNode node = head;
        int index = 0;
        while (node != null) {
            index++;
            if (index == i) {
                ListNode pre = node;
                int ans = 0;
                while (node != null) {
                    if (ans == len) {
                        pre.next = node;
                    }
                    ans++;
                    node = node.next;
                }
                return;
            }
            node = node.next;
        }
    }
}
