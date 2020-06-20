package Realize;

import java.io.*;
import java.util.*;

// 中缀算术表达式求值
public class ExpressionEvaluation {
    public static Map<String,Double> keyValue = new HashMap<>();

    public static void main(String[] args) throws Exception {
        Stack<Double> value = new Stack<>();
        Stack<Character> operation = new Stack<>();
        String filePath = "example.txt";
        try(BufferedReader bf = new BufferedReader(new InputStreamReader(new FileInputStream(new File(filePath))))){
            String str;
            while ((str = bf.readLine()) != null) {//分析文件中每一行的字符串
                String[] strs = str.split(";");//用;进行分割
                for (String temp : strs) {//分析;分割后的字符串数组
                    String[] expression = formatInput(temp);// 从键盘输入一个中缀表达式，然后格式化后存储为一个字符串数组
                    if (expression != null) {
                        try {
                            // 首先，遍历expression数组，同时以下列原则进行操作，然后，对栈内的剩余数字进行运算，直到操作符栈为空
                            for (String s : expression) {
                                //System.out.println(s + " " + s.length());
                                if (s.length() == 0)// 因为格式化的时候是在非数字符号前后加空格，所以会存在分割出来是空的情况
                                    continue;
                                else if (s.charAt(0) == '+' || s.charAt(0) == '-' || s.charAt(0) == '*' || s.charAt(0) == '/') {// 遇到运算符，将栈内优先级大于等于自己的符号拿出来参与计算
                                    while (!operation.isEmpty() && priorityIsBiggerOrTheSame(operation.peek() + "", s)) {// 循环直到栈空或者遇到优先级较小的符号
                                        compute(value, operation);
                                    }
                                    operation.push(s.charAt(0));// 当前符号入栈
                                } else if (s.charAt(0) == '(')// 右括号入栈
                                    operation.push('(');
                                else if (s.charAt(0) == ')') {// 遇到左括号，将栈内符号全部出栈参与运算
                                    while (operation.peek() != '(') // 循环直到遇到左括号
                                        compute(value, operation);
                                    operation.pop();// 左括号出栈
                                } else {
                                    if (keyValue.containsKey(s)) {
                                        value.push(keyValue.get(s));
                                    } else
                                        value.push(Double.parseDouble(s));// 数字入栈
                                }
                            }
                            while (!operation.isEmpty())// 最后将所有的符号出栈参与运算
                                compute(value, operation);
                            saveResult("result.txt", value.pop());
                            //System.out.println("计算结果是：" + value.pop());
                        }catch (Exception e){
                            saveResult("result.txt","表达式错误");
                        }
                    }
                }
            }
        }

    }

    /**
     * 将结果写入文件中
     * @param filePath 文件名
     * @param result 结果
     */
    public static void saveResult(String filePath,double result){
        try (RandomAccessFile randomFile = new RandomAccessFile(filePath,"rw")){
            randomFile.seek(randomFile.length());
            randomFile.write(String.valueOf(result).getBytes());
            randomFile.write("\n".getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * 写入错误信息
     * @param filePath 文件路径
     * @param errorLog 错误日志
     */
    public static void saveResult(String filePath,String errorLog){
        try (RandomAccessFile randomFile = new RandomAccessFile(filePath,"rw")){
            randomFile.seek(randomFile.length());
            randomFile.write(errorLog.getBytes());
            randomFile.write("\n".getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * 运算
     * @param value 参与运算的两个值
     * @param operation 运算符
     */
    public static void compute(Stack<Double> value, Stack<Character> operation) {
        double v1 = value.pop();
        double v2 = value.pop();
        char op = operation.pop();
        switch (op) {
            case '+':
                value.push(v2 + v1);
                break;
            case '-':
                value.push(v2 - v1);
                break;
            case '*':
                value.push(v2 * v1);
                break;
            case '/':
                value.push(v2 / v1);
                break;
        }
    }

    /**
     * 将字符串分割成若干个子字符串，方便处理
     * @param s 原字符串
     * @return 分割后的字符串数组
     */
    public static String[] formatInput(String s) {
        String temp = "";
        /*
         * 提取出表达式中有效的字符（非空格），然后在字符后面统一添上一个空格，方便后面使用静态方法String.split()来 
         * 例如：1 *(2+ 3) /4     ----->     1 * ( 2 + 3 ) / 4 
         * 你也可以直接使用List类来存储提取的有效字符 总之最后的目的就是返回一个数组，其中存储的是有效字符
         */
        //判断是否为表达式;
        if(s.contains("=")){//||s.contains("double")||s.contains("Double")||s.contains("Integer")
            //s = s.trim();
            String Digit = s.replaceAll("[^0-9\\.]","");//获取数字
            String KeyWord = s.replaceAll("[int|double|Double|Integer|=|^0-9\\.]","");//获取标识符
            String flag = s.replaceAll("[^int|Double|double|Integer]","");//获取关键字
            System.out.println("flag = " + flag);
            if(Digit == "" || flag == "")
                System.out.println("表达式错误！");
            else {
                keyValue.put(KeyWord.trim(),Double.parseDouble(Digit));
                //System.out.println(KeyWord + "  " + Digit);
            }
            return null;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '+' || c == '-' || c == '*' || c == '/'||c == '(' || c == ')')
                temp += " " + c + " ";//为什么要加空格？因为该方法判断的运算符只可能有一位，我们根据空格来分割运算符和数值
            else
                temp += c;// 数字不用加空格  因为数字可能有多位   包含小数点
        }
        return temp.split(" ");// 分割

    }

    /**
     * 优先级判断
     * @param a 运算符a
     * @param b 运算符b
     * @return 优先级
     */
    public static boolean priorityIsBiggerOrTheSame(String a, String b) {
        String s = "+- */";
        return (s.indexOf(a) - s.indexOf(b)) >= 2;
    }
}
