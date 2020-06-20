package Operation;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
import java.util.Scanner;

public class test {


    public static void main(String[] args){
        ScriptEngineManager mn = new ScriptEngineManager();
        Scanner scan = new Scanner(System.in);
        ScriptEngine se = mn.getEngineByName("js");
        String operate = scan.next();
        System.out.println(operate);
        int result = 0;
        try {
            result = (int)se.eval(operate);
            System.out.println(result);
        } catch (ScriptException e) {
            System.out.println("表达式错误");
            e.printStackTrace();
        }
    }


}
