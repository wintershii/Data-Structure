package com.winter.string;

import java.util.Scanner;

public class KMP {
    public static void main(String[] args) {
        String str = null;
        System.out.print("请输入被搜索的主串:");
        Scanner scan = new Scanner(System.in);
        str = scan.next();
        String son = null;
        System.out.print("请输入要查找的子串:");
        son = scan.next();
        System.out.println(str);
        System.out.println(son);
        kMPSearch(str,son,0);
    }

    /**
     * 获取子串的nextval数组值
     * @param son
     * @return
     */
    public static int[] getNextval(String son) {
        int len = son.length();
        int[] nextval = new int[len];
        int i,j;
        i = 0;
        j = -1;
        nextval[0] = 0;
        while (i < len) {
            if (j == -1 || son.charAt(i) == son.charAt(j)) {
                i++;
                j++;
                if (son.charAt(i) != son.charAt(j)) {
                    nextval[i] = j + 1;
                } else {
                    nextval[i] = nextval[j];
                }
            } else {
                j = nextval[j] - 1;
            }
        }
        System.out.println(nextval);
        return nextval;
    }

    /**
     * KMP算法
     * @param str
     * @param son
     * @param pos
     */
    public static void kMPSearch(String str, String son, int pos) {
        int i = pos;
        int j = -1;
        int len1 = str.length();
        int len2 = son.length();
        int[] nextval = getNextval(son);

        while (i < len1 && j < len2) {
            if (j == -1 || str.charAt(i) == son.charAt(j)) {
                i++;
                j++;
            } else {
                j = nextval[j] - 1;
            }
        }
        if (j == len2) {
            System.out.println("查找到子串，起始索引在主串的" + (i-len2) + "处");
            return;
        }
        System.out.println("未查找到子串");
    }
}
