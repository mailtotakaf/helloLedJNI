package ledJNI;

public class LedJNI {
    static {
        System.loadLibrary("LedJNIImpl");
    }

    public native void ledOn();
    
    public static void main(String[] args) {
        new LedJNI().ledOn();
    }
}
