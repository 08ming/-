import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.Stream;

public class test {
    static Map<String,Integer> BAOLIUZIS = new HashMap<>();
    static Map<String,Integer> CONSTS = new HashMap<>();
    static Map<String,Integer> KEYS = new HashMap<>();

    static final String CONSTS_REGEX = "[1-9][\\d]+";
    static final String KEYS_REGEX = "[a-zA-Z_][\\w]*";

    public static void main(String[] args) {
        //char[] separators = new char[]{',',';','(',')','=','-','+','*','/'};
        /**
         * 正则表达式
         */

        Pattern PAT_CONSTS = Pattern.compile(CONSTS_REGEX);
        Pattern PAT_KEYS = Pattern.compile(KEYS_REGEX);


        String url = "test.txt";
        List<String> lines = read(url);
        Iterator<String> iterator = lines.iterator();
        long start = System.currentTimeMillis();
        while (iterator.hasNext()){
            String temp = iterator.next();
            Stream.of(temp.trim().split(""))
                    .filter(t -> {
                        char[] chars = t.toCharArray();
                        if((chars[0] >='!' && chars[0] <= '/') || (chars[0] >= ':' && chars[0] <= '?') || (chars[0] >= '[' && chars[0] <= ']')|| (chars[0] >= '{' && chars[0] <= '}')){
                            return true;
                        }
                       return false;
                    })
                    .map(t -> "("+(int)t.toCharArray()[0]+","+"'"+t+"'"+")")
                    .forEachOrdered(System.out::println);

            String[] strings = temp.split("!|\\(|\\)|\\{|\\}|;|\\,|=|\\+|-|\\*|/| ");
            for(String var : strings){
                if(!var.equals("")  && !var.equals("\n")){
                    if(AnalyzeUtils.Word.contains(var)){
                        if(BAOLIUZIS.containsKey(var)){
                            int value = BAOLIUZIS.get(var);
                            BAOLIUZIS.put(var,++value);
                        }
                        BAOLIUZIS.put(var,1);
                    }
                    else{
                        Matcher matcher = PAT_CONSTS.matcher(var);
                        if(matcher.find()){
                            if(CONSTS.containsKey(var)){
                                int value = CONSTS.get(var);
                                CONSTS.put(var,++value);
                            }
                            CONSTS.put(var,1);
                        }else {
                            matcher = PAT_KEYS.matcher(var);
                            if(matcher.find()){
                                if(KEYS.containsKey(var)){
                                    int value = KEYS.get(var);
                                    KEYS.put(var,++value);
                                }
                                KEYS.put(var,1);
                            }
                        }

                    }
                }
            }
        }

        long end = System.currentTimeMillis();
        System.out.println("所用时间：" + (end - start) + " ms");
        for (Map.Entry<String, Integer> entry: CONSTS.entrySet()
             ) {
            System.out.println("key = "+entry.getKey()+",value = "+entry.getValue());
        }
        for (Map.Entry<String, Integer> entry: BAOLIUZIS.entrySet()
        ) {
            System.out.println("key = "+entry.getKey()+",value = "+entry.getValue());
        }
        for (Map.Entry<String, Integer> entry: KEYS.entrySet()
        ) {
            System.out.println("key = "+entry.getKey()+",value = "+entry.getValue());
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
