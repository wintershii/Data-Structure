package com.map;

import sun.nio.cs.ext.MacArabic;

public class MatrixMap {
    private int[][] eages;
    private char[] vex;

    public MatrixMap(int vexNum) {
        this.eages = new int[vexNum][vexNum];
        this.vex =new char[vexNum];
    }

    public MatrixMap(int vexNum,int initialNum) {
        this.eages = new int[vexNum][vexNum];
        this.vex =new char[vexNum];
        for (int i = 0; i < eages.length; i++) {
            for (int j = 0; j < eages.length; j++) {
                this.eages[i][j] = initialNum;
            }
        }
    }

    /**
     * 向邻接矩阵中加入点
     * @param vex
     */
    public void insertVex(char[] vex) {
        this.vex =vex;
    }

    /**
     * 向邻接矩阵中加入边
     * @param v1
     * @param v2
     * @param weight
     */
    public void insertEage(char v1, char v2, int weight) {
        int vSet1 = 0;
        int vSet2 = 0;
        for (int i = 0; i < vex.length; i++) {
            if (v1 == vex[i]) {
                vSet1 = i;
            }
            if (v2 == vex[i]) {
                vSet2 = i;
            }
        }
        eages[vSet1][vSet2] = weight;
        eages[vSet2][vSet1] = weight;
    }


    /**
     * 返回指定点的邻接点
     * @param point
     * @return
     */
    public char[] getNextPoint(char point) {
        char[] nextVexs = new char[vex.length];
        int t = 0;
        int temp = 0;
        for (int i = 0; i < vex.length; i++) {
            if (point == vex[i]) {
                t = i;
            }
        }

            for (int j = 0; j < eages.length; j++) {
                if (eages[t][j] != 0) {
                    nextVexs[temp++] = vex[j];
                }
            }
            return nextVexs;
    }

    /**
     * 获取指定点的坐标
     * @param point
     * @return
     */
    public int getPointSet(char point) {
        for (int i = 0; i < vex.length; i++) {
            if (point == vex[i]) {
                return i;
            }
        }
        return 0;
    }

    public int getPointNum() {
        return vex.length;
    }

    public char getChar(int n) {
        return vex[n];
    }

    public int getEage(int m, int n) {
        return eages[m][n];
    }

    /**
     * 打印邻接矩阵
     */
    public void printMatrix() {
        for (int i = 0; i < eages.length; i++) {
            for (int j = 0; j < eages.length; j++) {
                System.out.print(eages[i][j] + " ");
            }
            System.out.println();
        }
    }



    public static void main(String[] args) {
        MatrixMap map = new MatrixMap(5);
        map.insertVex(new char[]{'A','B','C','D','E'});
        map.insertEage('A','B',15);
        map.insertEage('A','E',9);
        map.insertEage('B','C',3);
        map.insertEage('C','D',2);
        map.insertEage('D','A',11);
        map.insertEage('D','B',7);
        map.insertEage('E','C',21);

        map.printMatrix();

    }
}
