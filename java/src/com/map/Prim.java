package com.map;

public class Prim {
    static int MAX = 100;

    public static void main(String[] args) {
        MatrixMap map = new MatrixMap(10,100);
        map.insertVex(new char[]{'A','B','C','D','E','F','G','H','I','J'});
        map.insertEage('A','B',5);
        map.insertEage('A','C',6);
        map.insertEage('B','D',3);
        map.insertEage('C','D',6);
        map.insertEage('C','E',3);
        map.insertEage('D','G',4);
        map.insertEage('D','F',4);
        map.insertEage('D','E',3);
        map.insertEage('E','F',1);
        map.insertEage('E','H',4);
        map.insertEage('G','J',4);
        map.insertEage('F','I',5);
        map.insertEage('H','I',2);
        map.insertEage('I','J',2);

        prime(map,'J');

    }

    private static void prime(MatrixMap map, char start) {
        CloseEage[] close = new CloseEage[map.getPointNum()];
        for (int i = 0; i < map.getPointNum(); i++) {
            close[i] = new CloseEage();
        }
        int min = MAX;
        int pointNum = map.getPointNum();
        int temp = 0;

        System.out.print(start + " ");

        for (int i = 0; i < pointNum; i++) {
            if (i != map.getPointSet(start)) {
                close[i].adjVex = start;
                close[i].lowCost = map.getEage(map.getPointSet(start), i);
            }
        }

        for (int j = 0; j < pointNum - 1; j++) {

            for (int k = 0; k < pointNum; k++) {
                if (close[k].lowCost != 0 && close[k].lowCost < min) {
                    temp = k;
                    min = close[k].lowCost;

                }
            }

            close[temp].lowCost = 0;
            System.out.print(map.getChar(temp) + " ");

            for (int k = 0; k < pointNum; k++) {
                if (k != temp && map.getEage(temp,k) < close[k].lowCost) {
                    close[k].lowCost = map.getEage(temp,k);
                    close[k].adjVex = temp;
                }
            }

        }

    }


}


class CloseEage {
    int adjVex;
    int lowCost;
}