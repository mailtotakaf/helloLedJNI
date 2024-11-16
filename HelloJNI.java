public class HelloJNI {
    static {
        System.loadLibrary("HelloJNIImpl");
    }

    public native void printHello();

    public static void main(String[] args) {
        new HelloJNI().printHello();
    }
}
