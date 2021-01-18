#include <jni.h>
#include <string>
#include <android/log.h>
#include "lame/lame.h"

#define LOG_TAG "AndroidLame"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)

extern "C" JNIEXPORT jstring JNICALL
Java_com_wang_androidlame_recorder_Mp3Recorder_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    LOGI("lame version is %s", get_lame_version());

    return env->NewStringUTF(get_lame_version());
}

static lame_global_flags *sLameGlobalFlags = nullptr;

extern "C"
JNIEXPORT void JNICALL
Java_com_wang_androidlame_recorder_Mp3Recorder_initLame(
        JNIEnv *env, jobject thiz,
        jint inSampleRate, jint outChannel, jint outSampleRate, jint outBitrate, jint quality) {
    if (sLameGlobalFlags != nullptr) {
        lame_close(sLameGlobalFlags);
        sLameGlobalFlags = nullptr;
    }
    sLameGlobalFlags = lame_init();
    lame_set_in_samplerate(sLameGlobalFlags, inSampleRate);
    lame_set_num_channels(sLameGlobalFlags, outChannel);
    lame_set_out_samplerate(sLameGlobalFlags, outSampleRate);
    lame_set_brate(sLameGlobalFlags, outBitrate);
    lame_set_quality(sLameGlobalFlags, quality);
    lame_init_params(sLameGlobalFlags);
}