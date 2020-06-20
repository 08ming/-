public class test {
    public static void main(String[] args) {
        String temp = "kk p = 3;";
        String Digit = temp.replaceAll("[^0-9\\.]","");
        String Init = temp.replaceAll("[int|Double|=|^0-9\\.]","").trim();
        String flag = temp.replaceAll("[^int|Double|Integer]","");
        System.out.println(Digit);
        System.out.println(Init);
        System.out.println(flag.length());
    }
}
