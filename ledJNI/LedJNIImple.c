#include <jni.h>
#include "LedJNI.h"
#include <stdio.h>
#include <wiringPi.h>
#define LED 17  // 17ピンからLEDのプラス端子に印加

JNIEXPORT void JNICALL Java_LedJNI_ledOn(JNIEnv *env, jobject obj) {
        wiringPiSetupSys();

        pinMode(LED, OUTPUT);

        for (int i=0 ; i < 5 ; i++) {
                digitalWrite(LED, HIGH);  //オン
                delay(500);
                digitalWrite(LED, LOW);   //オフ
                delay(500);
        }
        return 0;
}
