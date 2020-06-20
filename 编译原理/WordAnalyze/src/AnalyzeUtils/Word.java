package AnalyzeUtils;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Word {
    public static File file;
    public static List<String> stringList;
    public static boolean contains(String str){
        if(stringList.contains(str)){
            return true;
        }

        return false;
    }
    static{
        String sb = null;
        file = new File("word.txt");
        stringList = new ArrayList<>();
        try{
           BufferedReader br = new BufferedReader(new FileReader(file));
           while ((sb = br.readLine()) != null){
               stringList.add(sb);
           }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
