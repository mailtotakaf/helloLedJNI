#include <jni.h>
#include "HelloJNI.h"
#include <stdio.h>

JNIEXPORT void JNICALL Java_HelloJNI_printHello(JNIEnv *env, jobject obj, jstring javaString) {
    // Javaの文字列をCの文字列に変換
    const char *cString = (*env)->GetStringUTFChars(env, javaString, NULL);
    if (cString == NULL) {
        return; // メモリ不足などのエラーの場合
    }

    // Cのprintfで表示
    printf("Hello World from JNI! Message from Java: %s\n", cString);

    // メモリ解放
    (*env)->ReleaseStringUTFChars(env, javaString, cString);
}
