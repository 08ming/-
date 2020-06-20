package AnalyzeUtils;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Analyze {
    static int i;
    public static void main(String[] args) {
        AnalyzeWords("test.txt");
    }
    public static void AnalyzeWords(String filename){
        String url = filename;
        List<String> lines = read(url);
        Iterator<String> iterator = lines.iterator();
        while (iterator.hasNext()) {
            String temp = iterator.next();
            temp = temp.trim();
            if(!temp.isEmpty() && !temp.equals("\r\n") && !temp.equals("\t")) {
                char[] chars = temp.toCharArray();

                for (i = 0; i < chars.length; ) {
                    String FUHAO = "";
                    if(i + 1 < chars.length) {
                        FUHAO = (chars[i]) + Character.toString(chars[i + 1]);
                    }
                    if (chars[i] == ' ') {
                        i = i + 1;
                    }
                    else if (chars[i] == '+' || chars[i] == '-' || chars[i] == '*' || chars[i] == '/' || chars[i] == '=') {
                        System.out.println("(" + "4," + chars[i] + ")");
                        i++;
                    }
                    else if (chars[i] == ',' || chars[i] == ';' || chars[i] == '{' || chars[i] == '}' || chars[i] == '(' || chars[i] == ')') {
                        System.out.println("(" + "5," + chars[i] + ")");
                        i++;
                    }

                    else if (FUHAO.equals("<=") || FUHAO.equals(">=") || FUHAO.equals("!=") || FUHAO.equals("==")) {
                        System.out.println("(" + "4," + FUHAO + ")");
                        i += 2;
                    }
                    else if (Character.isDigit(chars[i])) {//整数
                        int j;
                        StringBuilder consts = new StringBuilder();
                        consts.append(chars[i]);
                        for (j = i + 1; j < chars.length; j++) {
                            if (!Character.isDigit(chars[j]) && chars[j] != '.')
                                break;
                            else
                                consts.append(chars[j]);
                        }
                        System.out.println("(" + "3," + consts + ")");
                        i = j;
                    }
                    else if (Character.isLetter(chars[i]) || chars[i] == '_') {
                        StringBuilder buffer = new StringBuilder();
                        int j;
                        buffer.append(chars[i]);
                        for (j = i + 1; j < chars.length; j++) {
                            if ((!Character.isLetter(chars[j]) && chars[j] != '_' && !Character.isDigit(chars[j])))
                                break;
                            buffer.append(chars[j]);
                        }
                        String tom = new String(buffer);
                        if (Word.contains(tom)) {
                            System.out.println("(" + "1," + tom + ")");
                        } else {
                            System.out.println("(" + "2," + tom + ")");
                        }
                        i = j;
                    }
                    else {
                        i++;
                    }
                }
            }
        }
    }
    public static List<String> read(String url){
        File file = new File(url);
        String sb = null;
        List<String> list = new ArrayList<>();
        try{
            BufferedReader br = new BufferedReader(new FileReader(file));
            while ((sb = br.readLine()) != null){
                list.add(sb);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return list;
    }
}
