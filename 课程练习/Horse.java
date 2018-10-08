import java.util.*;

public class Horse {
    static int[] dirX = {-2, -1, 1, 2, 2, 1, -1, -2};
    static int[] dirY = {1, 2, 2, 1, -1, -2, -2, -1 };
    static int[][] chessBoard = new int[8][8];
    static Deque<HNode> list = new ArrayDeque<>();
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int x = scan.nextInt();
        int y = scan.nextInt();
        chessBoard[x][y] = 1;
        list.addLast(new HNode(x,y));
        dfs(x,y,2);
    }

    private static void dfs(int x, int y, int step) {
        if (step == 64){
//            System.out.println(" " + x +" " + y + " " + step);
//            chessBoard[x][y] = step;
//            list.addLast(new HNode(x,y));
            System.out.println("走完棋盘:");
            for (int i = 0; i < 8; i++){
                for (int j = 0; j < 8; j++){
                    System.out.print(" " + chessBoard[i][j] + " ");
                }
                System.out.println("");
            }
            System.out.println("坐标:");
            System.out.println(list);
            System.exit(0);
        }
        HNode[] hNodes = new HNode[8];
        for (int i = 0; i < 8; i++){
            HNode temp = new HNode(x+dirX[i],y+dirY[i]);
            temp.wayOut = wayOut(temp.x,temp.y);
            hNodes[i] = temp;
        }
        Arrays.sort(hNodes, (o1, o2) -> o1.wayOut-o2.wayOut);
        for (int i = 0; i < 8; i++){
            int tx = hNodes[i].x;
            int ty = hNodes[i].y;
            chessBoard[tx][ty] = step;
            list.addLast(new HNode(tx,ty));
            dfs(tx,ty,step+1);
            chessBoard[tx][ty] = 0;
            list.removeLast();
        }
    }

    static int wayOut(int x,int y){
        int count = 0;
        int tx,ty;
        if (x < 0 || x > 7 || y < 0 || y > 7 || chessBoard[x][y] != 0){
            return 9;
        }
        for (int i = 0; i < 7; i++){
            tx = x + dirX[i];
            ty = y + dirY[i];
            if (tx > -1 && tx < 8 && ty > -1 && ty < 8 && chessBoard[tx][ty] == 0){
                count++;
            }
        }
        return count;
    }

}

class HNode{
    int x;
    int y;
    int wayOut;

    public HNode(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString() {
        return "(" +
                "x=" + x +
                ", y=" + y +
                ')';
    }
}