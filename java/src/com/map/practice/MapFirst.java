package com.map.practice;

import com.map.MatrixMap;

import java.util.ArrayDeque;
import java.util.Deque;

//DFS搜索指定路径
public class MapFirst {
    //点集
    private int[] vex;
    //邻接矩阵表示的边集
    private int[][] eages;
    //访问数组
    private boolean[] visited;

    //非递归
    public boolean nonRecDfs(int[][] eage, int a, int b) {
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(a);
        while ( !stack.isEmpty()) {
            int c = stack.pop();
            if ( !visited[c]) {
                visited[c] = true;
                if (c == a) {
                    return true;
                }
            } else {
                continue;
            }
            int[] nextVexs = getNextPoints(eages,c);
            for (int i = nextVexs.length - 1; i >= 0; i--) {
                if ( !visited[nextVexs[i]]) {
                    stack.push(nextVexs[i]);
                }
            }
        }

        return false;
    }

    //返回指定点的邻接点
    public int[] getNextPoints(int[][] eages, int init) {
        int[] result = new int[eages.length];
        int temp = 0;
        for (int i = 0; i < eages.length; i++) {
            if (i != init && eages[init][i] != 0) {
                result[temp++] = i;
            }
        }
        return result;
    }

}
