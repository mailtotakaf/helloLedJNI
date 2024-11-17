① Javaのコンパイル
```bash
javac HelloJNI.java
```
② ヘッダファイルの生成
```bash
javah -jni HelloJNI
```

③ 共有ライブラリのコンパイル
```bash
gcc -shared -fPIC -I/usr/lib/jvm/java-8-openjdk-amd64/include/ -I/usr/lib/jvm/java-8-openjdk-amd64/include/linux HelloJNIImpl.c -o libHelloJNIImpl.so
```
④ 実行
```bash
java -Djava.library.path=. HelloJNI
```
~注意~  ①～③ をちゃんと実行しないと以下エラーになる
```
tak@tak-VirtualBox:~/JNI$ java -Djava.library.path=. HelloJNI
Exception in thread "main" java.lang.UnsatisfiedLinkError: no hello in java.library.path
	at java.lang.ClassLoader.loadLibrary(ClassLoader.java:1860)
	at java.lang.Runtime.loadLibrary0(Runtime.java:843)
	at java.lang.System.loadLibrary(System.java:1136)
	at HelloJNI.<clinit>(HelloJNI.java:7)
```


## JNIのプロジェクトをjarにするには
https://www.perplexity.ai/search/jninohurosiekutowojarnisurunih-hV5ETkLaQQ.QQHMiiAfRiA

とりあえず同じ階層に全ファイル置いてやる場合
```bash
jar cvfm HelloJNI.jar META-INF/MANIFEST.MF .
```
### jar実行
https://www.perplexity.ai/search/jninohurosiekutowojarnisurunih-hV5ETkLaQQ.QQHMiiAfRiA
jarファイルには、jniライブラリ(*.soなど)を含めることができないので、実行時コマンドで、パスを指定する必要がある。

●java.library.pathで指定する場合
```bash
java -Djava.library.path=. -jar HelloJNI.jar
```

●LD_LIBRARY_PATHをで設定する場合
```bash
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
java -jar HelloJNI.jar
```
<br><br>


※ちなみに参考程度ではあるが、上記パスを設定しないでjar実行する場合は、以下ディレクトリにそれぞれのファイルを置く必要がある。

・jarファイルの置き場所：$JAVA_HOME/jre/lib/ext \
・jniライブラリ(*.so)の置き場所：$JAVA_HOME/jre/lib/amd64
```
java -jar HelloJNI.jar
```