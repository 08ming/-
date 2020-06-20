package Utils;


public class PriorityTable {
    public static final char[] chars = new char[]{'+','-','*','/','(',')','ε',';'};//ε
    public static final byte[][] table = new byte[][]{
            {1,1,-1,-1,-1,-1,1,-1},
            {1,1,-1,-1,-1,1,1,1},
            {-1,-1,1,1,-1,-1,1,1},
            {-1,-1,-1,-1,1,-1,-1,1},
            {-1,-1,-1,-1,-1,0,2,-1},
            {1,1,1,1,1,1,2,-1},
            {-1,-1,-1,-1,-1,-1,2,1},
            {1,1,1,1,1,1,1,-1}
    };
}
