package com.map;

public class DFSMap {
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

        DFSTravel(map);
    }

    public static void DFSTravel(MatrixMap map) {
        for (int i = 0; i < map.getPointNum(); i++) {
            if (visited[i] == false) {
                DFS(map,map.getChar(i));
            }
        }
    }

    public static void DFS(MatrixMap map,char init) {
        System.out.print(init + " ");
        visited[map.getPointSet(init)] = true;
        char[] nexs = map.getNextPoint(init);
        for (char e: nexs) {
            if (visited[map.getPointSet(e)] != true) {
                DFS(map,e);
            }
        }
    }


}
