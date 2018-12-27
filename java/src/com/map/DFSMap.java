package com.map;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 图的深度优先遍历
 */
public class DFSMap {
    public static boolean[] visited = new boolean[100];

    public static void main(String[] args) {
        MatrixMap map = new MatrixMap(9);
        map.insertVex(new char[]{'A','B','C','D','E','F','G','X','T'});
        map.insertEage('A','B',1);
        map.insertEage('A','C',1);
        map.insertEage('A','D',1);
        map.insertEage('B','D',1);
        map.insertEage('B','E',1);
        map.insertEage('C','F',1);
        map.insertEage('D','F',1);
        map.insertEage('D','G',1);
        map.insertEage('E','G',1);
        map.insertEage('X','T',1);
        new DFSMap().dfsTravel(map);
    }

    /**
     * 递归实现图的深度优先遍历
     * @param map
     */
    public void dfsTravel(MatrixMap map) {
        System.out.print("递归:");
        for (int i = 0; i < map.getPointNum(); i++) {
            if ( !visited[i]) {
                System.out.print("连通分量：");
                dfs(map,map.getChar(i));
            }
        }
        System.out.println();
        System.out.print("非递归:");
        for (int i = 0; i < map.getPointNum(); i++) {
            visited[i] = false;
        }
        for (int i = 0; i < map.getPointNum(); i++) {
            if ( !visited[i]) {
                System.out.print("连通分量：");
                nonRecDfs(map,map.getChar(i));
            }
        }
    }

    /**
     * 递归主体
     * @param map
     * @param init
     */
    public void dfs(MatrixMap map,char init) {
        System.out.print(init + " ");
        visited[map.getPointSet(init)] = true;
        char[] nexs = map.getNextPoint(init);
        for (char e: nexs) {
            if ( !visited[map.getPointSet(e)]) {
                dfs(map,e);
            }
        }
    }

    /**
     * 非递归深度优先遍历
     * @param map
     * @param init
     */
    public void nonRecDfs(MatrixMap map, char init) {
        Deque<Character> stack = new ArrayDeque<>();
        stack.push(init);

        while ( !stack.isEmpty()) {
            char c = stack.pop();
            if ( !visited[map.getPointSet(c)]) {
                visited[map.getPointSet(c)] = true;
                System.out.print(c + " ");
            } else {
                continue;
            }

            char[] chars = map.getNextPoint(c);
            for (int i = chars.length - 1; i >= 0; i--) {
                if ( !visited[map.getPointSet(chars[i])]) {
                    stack.push(chars[i]);
                }

            }
        }
    }

}
