package com.winter.list;

import java.util.Scanner;

/**
 * 利用双向循环链表解决约瑟夫环问题
 */
public class CircularLinkedList {
    public static void main(String[] args) {
        ListNode lHead = null;
        solveJoseph();
    }

    /**
     * 创建双向循环链表
     */
    public static ListNode createLinkedList() {
        ListNode lHead = null;
        System.out.print("请输入总人数：");
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        ListNode node = null;
        ListNode preNode = null;
        for (int i = 0; i < n; i++) {
            System.out.println("请输入第" + (i+1) + "个人的数据");
            node = new ListNode();
            node.data = scan.nextInt();
            if (i == 0) {
                node.pre = node;
                lHead = node;
            } else {
                preNode.next = node;
                node.pre = preNode;
            }
            preNode = node;
            node.next = lHead;
        }
        return lHead;
    }

    /**
     * 解决约瑟夫环
     */
    public static void solveJoseph() {
        ListNode lHead = createLinkedList();
        ListNode node = lHead;
        int time = node.data;
        while (node.pre != node || node.next != node) {
            for (int i = 1; i < time; i++) {
                node = node.next;
            }
            ListNode aft = node.next;
            time = node.data;
            System.out.println("数据为" + node.data + "的节点被删除了");
            deleteNode(node);
            node = aft;
        }
        System.out.println("胜出者为:" + node.data);
    }

    /**
     * 删除链表中的节点
     * @param node
     */
    public static void deleteNode(ListNode node) {
        ListNode pre = node.pre;
        pre.next = node.next;
        node.next.pre = pre;
    }

    /**
     * 输出双向循环链表的内容
     * @param lHead
     */
    public static void printLinkedList(ListNode lHead) {
        ListNode node = lHead;
        while (node.next != lHead) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println(node.data + " ");
    }


}


/**
 * 双向循环链表每个节点的数据结构
 */
class ListNode {
    int data;
    ListNode pre;
    ListNode next;
}
