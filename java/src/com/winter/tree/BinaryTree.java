package com.winter.tree;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

/**
 *  二叉树 建立 递归与非递归遍历
 */
public class BinaryTree {
    //二叉树跟节点
    private TreeNode root = null;

    public BinaryTree() {
    }

    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree();
        bt.root = bt.createBinaryTree();
        System.out.println("前序遍历:");
        preOrder(bt.root);
        System.out.println();
        System.out.println("中序遍历:");
        inOrder(bt.root);
        System.out.println();
        System.out.println("后序遍历:");
        aftOrder(bt.root);
        System.out.println();

        System.out.println("非递归前序遍历:");
        nonRecPreOrder(bt.root);
        System.out.println("非递归中序遍历:");
        nonRecInOrder(bt.root);
        System.out.println("非递归后序遍历:");
        nonRecAftOrder(bt.root);

        System.out.println();
        System.out.println("层序遍历");
        levelTravel(bt.root);
    }

    /**
     * 递归构造二叉树
     * @return 二叉树根节点
     */
    public TreeNode createBinaryTree() {
        TreeNode root;
        System.out.print("请输入此数据:(输入值为-1时为空)");
        Scanner scan = new Scanner(System.in);
        int data = scan.nextInt();
        if (data == -1) {
            return null;
        } else {
            root = new TreeNode();
            root.data = data;
            root.leftChild = createBinaryTree();
            root.rightChild = createBinaryTree();
        }
        return root;
    }

    /**
     * 前序遍历
     * @param root
     */
    public static void preOrder(TreeNode root) {
        if (root != null) {
            System.out.print(root);
            preOrder(root.leftChild);
            preOrder(root.rightChild);
        }
    }

    /**
     * 中序遍历
     * @param root
     */
    public static void inOrder(TreeNode root) {
        if (root != null) {
            inOrder(root.leftChild);
            System.out.print(root);
            inOrder(root.rightChild);
        }
    }

    /**
     * 后序遍历
     * @param root
     */
    public static void aftOrder(TreeNode root) {
        if (root != null) {
            aftOrder(root.leftChild);
            aftOrder(root.rightChild);
            System.out.print(root);
        }
    }


    /**
     * 非递归前序遍历
     * @param root
     */
    public static void nonRecPreOrder(TreeNode root) {
        Deque<TreeNode> stack = new ArrayDeque<>();
        TreeNode node = root;
        while (node != null || stack.size() > 0) {
            if (node != null) {
                System.out.print(node);
                stack.push(node);
                node = node.leftChild;
            } else if (stack.size() >0) {
                node = stack.pop();
                node = node.rightChild;
            }
        }
        System.out.println();
    }

    /**
     * 非递归中序遍历
     * @param root
     */
    public static void nonRecInOrder(TreeNode root) {
        Deque<TreeNode> stack = new ArrayDeque<>();
        TreeNode node = root;
        while (node != null || stack.size() > 0) {
            //存在左子树
            if (node != null) {
                stack.push(node);
                node = node.leftChild;
                //栈非空
            } else if (stack.size() >0) {
                node = stack.pop();
                System.out.print(node);
                node = node.rightChild;
            }
        }
        System.out.println();
    }


    /**
     * 非递归后序遍历
     * @param root
     */
    public static void nonRecAftOrder(TreeNode root) {
        Deque<TreeNode> stack = new ArrayDeque<>();
        TreeNode node = root;
        TreeNode p = root;
        TreeNode preRight = p;
        while (p != null) {
            //将非叶子左子树压栈
            for ( ; p.leftChild != null; p = p.leftChild) {
                stack.push(p);
            }
            //当前节点没有右子树或者右子树已经输出
            while (p != null && (p.rightChild == null || p.rightChild == preRight)) {
                System.out.print(p);
                preRight = p;
                if (stack.isEmpty()) {
                    return;
                }
                p = stack.pop();
            }
            //处理右子树
            stack.push(p);
            p = p.rightChild;
        }
        System.out.println();
    }

    /**
     * 二叉树的层序遍历
     * @param root
     */
    public static void levelTravel(TreeNode root) {
        Deque<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            System.out.print(node.data + " ");
            if (node.leftChild != null) {
                queue.offer(node.leftChild);
            }
            if (node.rightChild != null) {
                queue.offer(node.rightChild);
            }
        }
    }


    /**
     * 二叉树节点的数据结构类型
     */
    class TreeNode {
        private int data;
        private TreeNode leftChild;
        private TreeNode rightChild;

        public TreeNode() {
        }

        public TreeNode(int data) {
            this.data = data;
            leftChild = null;
            rightChild = null;
        }

        @Override
        public String toString() {
            return " " + data;
        }
    }
}

