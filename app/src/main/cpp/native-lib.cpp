#include <jni.h>
#include <string>
#include <EGL/egl.h>
#include "WlAndroidLog.h"
#include "android/native_window_jni.h"
#include "BaseOpengl.h"
#include "TriangleOpenGL.h"
#include "TextureOpenGL.h"
#import <android/bitmap.h>
#include "VBOTextureOpenGL.h"

BaseOpengl *baseOpengl = nullptr;

extern "C"
JNIEXPORT void JNICALL
Java_com_xgbk_nativeopengl_helper_EglHelper_surfaceCreated(JNIEnv *env, jobject thiz,
                                                           jobject surface) {

    baseOpengl = new VBOTextureOpenGL;
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

extern "C"
JNIEXPORT void JNICALL
Java_com_xgbk_nativeopengl_helper_EglHelper_drawImage(JNIEnv *env, jobject thiz, jobject bitmap) {

    if (nullptr != baseOpengl) {
        AndroidBitmapInfo bitmapInfo;
        AndroidBitmap_getInfo(env, bitmap, &bitmapInfo);
        void *imageData = nullptr;
        AndroidBitmap_lockPixels(env, bitmap, &imageData);
        AndroidBitmap_unlockPixels(env, bitmap);
        baseOpengl->imageData = imageData;
    }
}