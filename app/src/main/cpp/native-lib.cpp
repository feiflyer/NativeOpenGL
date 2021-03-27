#include <jni.h>
#include <string>
#include <EGL/egl.h>
#include "WlAndroidLog.h"
#include "android/native_window_jni.h"
#include "BaseOpengl.h"
#include "TriangleOpenGL.h"


BaseOpengl *baseOpengl;

extern "C"
JNIEXPORT void JNICALL
Java_com_xgbk_nativeopengl_helper_EglHelper_surfaceCreated(JNIEnv *env, jobject thiz,
                                                           jobject surface) {

    baseOpengl = new TriangleOpenGL;
    NativeWindowType win = ANativeWindow_fromSurface(env, surface);
    baseOpengl->onSurfaceCreate(win);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_xgbk_nativeopengl_helper_EglHelper_surfaceChanged(JNIEnv *env, jobject thiz, jint width,
                                                           jint height) {
    baseOpengl->onSurfaceChange(width, height);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_xgbk_nativeopengl_helper_EglHelper_surfaceDestroyed(JNIEnv *env, jobject thiz) {
    baseOpengl->onSurfaceDestroy();
}