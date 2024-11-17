package helloJNI;
public class HelloJNI {
    // Nativeメソッドの宣言
    public native void printHello(String message);

    static {
        // ライブラリのロード
        System.loadLibrary("HelloJNIImpl");
    }

    public static void main(String[] args) {
        new HelloJNI().printHello("Javaから渡されたメッセージ");
    }
}
