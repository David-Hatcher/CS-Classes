class Final{
    public static void main(String[] args) {
        String s = "Our final exam is scheduled on July-17-2019, Wed.";
        System.out.println(s.substring(s.indexOf("July"), s.indexOf("2019")));
    }
}