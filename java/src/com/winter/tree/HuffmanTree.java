package com.winter.tree;

import java.util.*;

public class HuffmanTree {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
//        System.out.print("请输入字符集大小n:");
//        int n = scan.nextInt();
//        HfTree[] ht = new HfTree[2*n-1];//存储字符节点及内部节点
//
//        for (int i = 0; i < n; i++) {
//            ht[i] = new HfTree();
//            System.out.print("请输入第" + (i+1) + "个字符:");
//            ht[i].charset = scan.next().charAt(0);
//            System.out.print("请输入第" + (i+1) + "个字符的权值:");
//            ht[i].weight = scan.nextInt();
//        }

//        //构造哈夫曼树结构
//        createHuffmanTree(ht,n);
//        System.out.println("哈夫曼树结构:");
//        for (int i = 0; i < 2*n-1; i++) {
//            System.out.println(ht[i]);
//        }
//        System.out.println("各个字符编码");
//        //生成哈夫曼编码
//        HfCode[] hfCode = createHuffmanCode(ht,n);
//        for (int i = 0; i < n; i++) {
//            System.out.println("" + hfCode[i].charset + hfCode[i].code);
//        }
        System.out.print("请输入需要编码的数据:");
        String str = scan.next();
        //编码
        HfTree[] ht = null;
        ht = coding(str);

        System.out.println();
        System.out.print("请输入需要译码的数据:");
        String str2 = scan.next();
        decoding(str2,ht);
    }

    /**
     * 构造哈夫曼树
     * @param ht
     * @param n
     */
    public static void createHuffmanTree(HfTree[] ht, int n) {
        for (int i = n; i < 2*n-1; i++) {
            ht[i] = new HfTree();
        }
        for (int i = n; i < 2*n-1; i++) {
            MyMin m = select(ht,i-1);
            ht[i].weight = ht[m.min].weight + ht[m.nextMin].weight;
            ht[i].leftChild = m.min;
            ht[i].rightChild = m.nextMin;
            ht[m.min].parent = i;
            ht[m.nextMin].parent = i;
        }
    }

    /**
     * 生成哈夫曼编码
     * @param ht
     * @param n
     * @return
     */
    public static HfCode[] createHuffmanCode(HfTree[] ht, int n) {
        HfCode[] hfCode = new HfCode[n];
        for (int i = 0; i < n; i++) {
            hfCode[i] = new HfCode(ht[i].charset,i);
            Deque code = new ArrayDeque();
            int set = i;
            int parent = ht[i].parent;
            while (parent != -1) {
                if (ht[parent].leftChild == set) {
                    code.push("0");
                } else {
                    code.push("1");
                }
                set = parent;
                parent = ht[parent].parent;
            }
            hfCode[i].code = code;
        }
        return hfCode;
    }

    /**
     * 对输入的字符串编码
     * @param str
     * @return
     */
    public static HfTree[] coding(String str) {
        HashMap<Character,Integer> map = new HashMap();
        for (int i = 0; i < str.length(); i++) {
            if (map.containsKey(str.charAt(i))) {
                map.put(str.charAt(i),map.get(str.charAt(i)) + 1);
            } else {
                map.put(str.charAt(i),1);
            }
        }
        int n = map.size();
        HfTree[] ht = new HfTree[2*n-1];
        int i = 0;
        Iterator<Map.Entry<Character,Integer>> it = map.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry<Character,Integer> entry = it.next();
            ht[i] = new HfTree();
            ht[i].charset = entry.getKey();
            ht[i].weight = entry.getValue();
            i++;
        }

        createHuffmanTree(ht,n);
        HfCode[] hfCode = createHuffmanCode(ht,n);
        HashMap<Character,String> code = new HashMap<>();
        for (int k = 0; k < hfCode.length; k++) {
            Deque temp = hfCode[k].code;
            StringBuilder sb = new StringBuilder();
            while (!temp.isEmpty()) {
                sb.append(temp.pop());
            }
            String cod = new String(sb);
            code.put(hfCode[k].charset,cod);
            System.out.println("" + hfCode[k].charset + "  : " + cod);
        }
        System.out.print("编码结果:");
        for (int j = 0; j < str.length(); j++) {
            char charset = str.charAt(j);
            System.out.print(code.get(charset));
        }
        return ht;
    }


    /**
     * 译码
     * @param str
     * @param ht
     */
    public static void decoding(String str, HfTree[] ht) {
        HfTree root = ht[ht.length-1];
        HfTree temp = root;
        for (int i = 0; i < str.length(); i++) {
            if (temp.leftChild == -1 && temp.rightChild == -1) {
                System.out.print(temp.charset);
                temp = root;
            }
            if (str.charAt(i) == '0') {
                temp = ht[temp.leftChild];
            } else if (str.charAt(i) == '1'){
                temp = ht[temp.rightChild];
            } else {
                System.out.println("输入的编码有误！");
                return;
            }
        }
        if (temp.rightChild != -1 || temp.rightChild != -1) {
            System.out.println("输入的编码有误！");
            return;
        }
        System.out.println(temp.charset);
    }

    /**
     * 返回最小值下标及次小值下标
     * @param ht
     * @param range
     * @return
     */
    public static MyMin select(HfTree[] ht, int range) {
        //默认下标为0
        int min = 0;
        //若0下标已被记录
        if (ht[min].parent != -1) {
            for (int i = 0; i <= range; i++) {
                if (ht[i].parent == -1) {
                    min = i;
                    break;
                }
            }
        }
        //开始查找
        for (int i = min + 1; i <= range; i++) {
            if (ht[i].weight < ht[min].weight && ht[i].parent == -1) {
                min = i;
            }
        }
        //次小值默认从0开始
        int nextMin = 0;
            for (int i = 0; i <= range; i++) {
                //不能是最小值且没有被记录
                if (ht[i].parent == -1 && min != i) {
                    nextMin = i;
                    break;
                }
            }

        for (int i = nextMin + 1; i <= range; i++) {
            if (ht[i].weight < ht[nextMin].weight && ht[i].parent == -1
                    &&  ht[i].weight >= ht[min].weight && min != i) {
                nextMin = i;
            }
        }

        MyMin m = new MyMin(min,nextMin);
        return m;
    }

}

/**
 * 哈夫曼树每个节点的数据结构
 */
class HfTree {
    char charset;
    int weight;
    int parent;
    int leftChild;
    int rightChild;

    public HfTree() {
        this.parent = -1;
        this.leftChild = -1;
        this.rightChild = -1;
    }

    @Override
    public String toString() {
        return " " + charset +
                "," + weight +
                "," + parent +
                "," + leftChild +
                "," + rightChild;
    }
}

/**
 * 哈夫曼编码的数据结构
 */
class HfCode {
    char charset;
    int index;
    Deque code;

    public HfCode() {
    }

    public HfCode(char charset, int index) {
        this.charset = charset;
        this.index = index;
    }
}

/**
 * 最小值与次小值的封装类
 */
class MyMin {
    int min;
    int nextMin;

    public MyMin(int min, int nextMin) {
        this.min = min;
        this.nextMin = nextMin;
    }
}