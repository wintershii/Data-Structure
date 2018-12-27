package com.winter.test;

public class FindTheNumOfTreeNode {

    static int num = 0;

    public void findTheNumOfTreeNode(TreeNode root) {
        if (root == null) {
            return;
        }
        if (root.lChild != null && root.rChild != null) {
            num++;
        }
        findTheNumOfTreeNode(root.lChild);
        findTheNumOfTreeNode(root.rChild);
    }
}
