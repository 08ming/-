package Operation;

import java.util.Map;
import java.util.TreeMap;

public class OperationLevel {
    public static boolean isBigLevel(char firstOp,char lastOp){
        //if()
        return false;
    }
    static public char[] op  = {
            '+',
            '-',
            'x',
            '/',
            '(',
            ')',
            '#'
    };

    //优先关系模拟表
    //此表可添加
    private int[][] re = {
            {1,1,-1,-1,-1,1,1},
            {1,1,-1,-1,-1,1,1},
            {1,1,1,1,-1,1,1},
            {1,1,1,1,-1,1,1},
            {-1,-1,-1,-1,-1,0,2},
            {1,1,1,1,-2,1,1},
            {-1,-1,-1,-1,-1,2,0},
    };
}
