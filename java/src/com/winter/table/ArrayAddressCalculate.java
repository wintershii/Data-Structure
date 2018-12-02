package com.winter.table;

import java.util.Scanner;

public class ArrayAddressCalculate {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n;
        int[] array = new int[100];
        int[] list = new int[100];
        System.out.println("请输入数组维数:");
        n = scan.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.println("请输入第" + (i+1) + "维的元素上限值:");
            array[i] = scan.nextInt();
        }
        int site;
        System.out.println("请输入起始地址:");
        site = scan.nextInt();
        System.out.println("请输入要计算的地址");
        for (int i = 0; i < n; i++) {
            System.out.println("请输入第" + (i+1) + "维的值:");
            list[i] = scan.nextInt();
        }
        int result = calculateAddress(array,list,site,n);
        System.out.println("结果为:" + result);
    }

    public static int calculateAddress(int[] array, int[] list, int site, int n) {
        int add = 0;
        for (int i = 0; i < n; i++) {
            int temp = 0;
            int mult = 1;
            for (int j = 0; j < n-i-1; j++) {
                mult *= array[j];
            }
            temp = mult * (list[i] - 1);
            add += temp;
        }
        return site + add * 2;
    }
}
