import java.util.*;

public class MazeBFS {
    static boolean[][] book = new boolean[100][100];
    static int[][] next = {{0,1},{1,0},{0,-1},{-1,0}};
    static int m,n;
    static Deque<Node> que = new ArrayDeque<>();
    static List<Node> list = new ArrayList<>();
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        m = scan.nextInt();
        n = scan.nextInt();
        int[][] map = new int[m][n];
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                map[i][j] = scan.nextInt();
            }
        }
        que.addLast(new Node(0,0));
        book[0][0] = true;
        bfs(map,0,0);
    }

    private static void bfs(int[][] map, int x, int y) {
        Node temp;
        while (!que.isEmpty()){
            temp = que.peekFirst();
            list.add(que.pop());

            for (int i = 0; i < 4; i++){
                int tx = temp.x + next[i][0];
                int ty = temp.y + next[i][1];
                if (tx < 0 || tx > m-1 || ty < 0 || ty > n-1){
                    continue;
                }
                if (book[tx][ty] == false && map[tx][ty] == 0){
                    que.addLast(new Node(tx,ty));
                    book[tx][ty] = true;
                }
            }
            if (temp.x == m-1 && temp.y == n-1){
                System.out.println("走出迷宫");
                System.out.println(list);
                return;
            }
        }

    }
}

