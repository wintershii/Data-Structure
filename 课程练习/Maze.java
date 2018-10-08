import java.util.*;

public class Maze {
    static boolean[][] book = new boolean[100][100];
    static int[][] next = {{0,1},{1,0},{0,-1},{-1,0}};
    static int m,n;
    static List<Deque<Node>> list = new ArrayList<>();
    static int route = 1;
    public static void main(String[] args) {
        Deque<Node> stack = new ArrayDeque<>();
        Scanner scan = new Scanner(System.in);
        m = scan.nextInt();
        n = scan.nextInt();
//        System.out.println(" " + m + n);
        int[][] map = new int[m][n];
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                map[i][j] = scan.nextInt();
            }
        }

        book[0][0] = true;
        Node node = new Node(0,0);
        stack.addLast(node);
        dfs(map,0,0,stack);

    }

    public static void dfs(int[][] map, int x, int y,Deque<Node> stack){
        //判断是否走出迷宫
        if (x == m-1 && y == n-1){
            System.out.println("到达终点 路径:" + route++);
            for (Node n : stack){
                System.out.println("(" + n.x + "," + n.y +")");
            }
            return;
        }

        for (int k = 0; k < 4; k++){
            //计算下一个点的坐标
            int tx = x + next[k][0];
            int ty = y + next[k][1];
            //判断是否越界
            if (tx < 0 || tx > m-1 || ty < 0 || ty > n-1){
                continue;
            }
            //判断是否已经在路径中且可以走
            if (book[tx][ty] == false && map[tx][ty] == 0){
                Node node = new Node(tx,ty);
                stack.addLast(node);
                book[tx][ty] = true;
                dfs(map,tx,ty,stack);
                stack.removeLast();
                book[tx][ty] = false;
            }
        }
        return;
    }
}

