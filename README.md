Javaのコンパイル
```bash
javac HelloJNI.java
```
ヘッダファイルの生成
```bash
javah -jni HelloJNI
```

共有ライブラリのコンパイル
```bash
gcc -shared -fPIC -I/usr/lib/jvm/java-8-openjdk-amd64/include/ -I/usr/lib/jvm/java-8-openjdk-amd64/include/linux HelloJNIImpl.c -o libHelloJNIImpl.so
```
実行
```bash
java -Djava.library.path=. HelloJNI
```
```
tak@tak-VirtualBox:~/JNI$ java -Djava.library.path=. HelloJNI
Exception in thread "main" java.lang.UnsatisfiedLinkError: no hello in java.library.path
	at java.lang.ClassLoader.loadLibrary(ClassLoader.java:1860)
	at java.lang.Runtime.loadLibrary0(Runtime.java:843)
	at java.lang.System.loadLibrary(System.java:1136)
	at HelloJNI.<clinit>(HelloJNI.java:7)
```
