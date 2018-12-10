package com.map;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 图的广度优先遍历
 */
public class BFSMap {
    public static boolean[] visited = new boolean[100];

    public static void main(String[] args) {
        MatrixMap map = new MatrixMap(7);
        map.insertVex(new char[]{'A','B','C','D','E','F','G'});
        map.insertEage('A','B',1);
        map.insertEage('A','C',1);
        map.insertEage('A','D',1);
        map.insertEage('B','D',1);
        map.insertEage('B','E',1);
        map.insertEage('C','F',1);
        map.insertEage('D','F',1);
        map.insertEage('D','G',1);
        map.insertEage('E','G',1);

        new BFSMap().bfsTravel(map);
    }

    public void bfsTravel(MatrixMap map) {
        for (int i = 0; i < map.getPointNum(); i++) {
            if (!visited[i]) {
                bfs(map,map.getChar(i));
            }
        }
    }

    public void bfs(MatrixMap map, char init) {
        Deque<Character> queue = new ArrayDeque<>();
        if (map == null) {
            return;
        }
        queue.offer(init);
        visited[map.getPointSet(init)] = true;
        while ( !queue.isEmpty()) {
            char character = queue.poll();
            System.out.print(character + " ");
                visited[map.getPointSet(character)] = true;
                char[] chars = map.getNextPoint(character);
                for (char c : chars) {
                    if (!visited[map.getPointSet(c)]) {
                        queue.offer(c);
                        visited[map.getPointSet(c)] = true;
                    }
                }
        }
    }
}
