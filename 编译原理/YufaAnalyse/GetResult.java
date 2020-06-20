package Realize;


import Utils.PriorityTable;

import java.io.*;

import java.util.Stack;

public class GetResult {
    public static void main(String[] args) throws IOException {
        String str = null;
        try (BufferedReader bf = new BufferedReader(new InputStreamReader(new FileInputStream(new File("C:\\Users\\LENOVO\\Desktop\\YufaAnalyse\\example.txt"))))){
            while ((str = bf.readLine())!=null){
                Stack<Character> opStack = new Stack<>();
                Stack<Integer> dataStack = new Stack<>();

                opStack.push(';');

                char[] chars = str.toCharArray();
                for(int j = 0; j < chars.length;){
                    if(!isOp(chars[j])){
                        StringBuilder sb = new StringBuilder();
                        sb.append(chars[j]);
                        int l = 0;
                        for(l = j+1; l < chars.length; l++){
                            if(isOp(chars[l])){
                                break;
                            }
                            sb.append(chars[l]);
                        }
                        String temp = new String(sb);
                        int x = Integer.parseInt(temp);
                        dataStack.push(x);
                        j = l;
                    }else {
                        int PriCount = Priority(chars[j],opStack.peek());
                        // System.out.println("优先级   "+PriCount +" char "+ chars[j]+"  "+ opStack.peek());
                        if(PriCount == -1 || PriCount == 2){
                            opStack.push(chars[j]);
                        }else if(PriCount == 0){
                            if(chars[j] == ';'){
                                System.out.println("分析成功");
                                break;
                            }else {
                                opStack.pop();
                            }
                        }else if(PriCount == 1){
                            do {
                                int temp = dataStack.pop();
                                int temp2 = dataStack.pop();
                                char op = opStack.pop();
                                //System.out.println(temp + " " + op + " " + temp2);
                                dataStack.push(operation(temp, temp2, op));
                                if(opStack.peek()== '(' || opStack.peek() == ')')
                                    opStack.pop();
                                int m = 0;
                                if(j >= chars.length - 2)
                                    m = chars.length-1;
                                else m = j + 1;
                                PriCount = Priority(chars[m],opStack.peek());
                                //System.out.println("优先级   "+PriCount +" char "+ chars[j]+"  "+ opStack.peek());

                            }while (PriCount == 1);
                            opStack.push(chars[j]);
                        }
                        j ++;
                    }
                }

                System.out.println(dataStack.pop());
                dataStack.clear();
                opStack.clear();
            }
        }


        //String[] strs = str.replaceAll(" ","").split(";");



    }


    static int operation(int dataX,int dataY,char op){
        if(op == '+'){
            return dataX+dataY;
        }
        else if(op == '-'){
            return dataX-dataY;
        }
        else if(op == '*'){
            return dataX*dataY;
        }
        else if(op == '/'){
            return dataX/dataY;
        }
        return 0;
    }

    static int Priority(char x, char y){
        int indexX = 0,indexY = 0;
        for (int i = 0; i < PriorityTable.chars.length;i ++) {
            if(PriorityTable.chars[i] == x){
                indexX = i;
            }
            if(PriorityTable.chars[i] == y){
                indexY = i;
            }
        }
        return PriorityTable.table[indexX][indexY];
    }

    static boolean isOp(char temp){
        for (char aChar : PriorityTable.chars) {
            if(temp == aChar){
                return true;
            }
        }
        return false;
    }


}
