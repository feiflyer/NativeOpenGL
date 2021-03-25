//
// Created by bbyy-liangchuanfei on 3/25/21.
//

#ifndef NATIVEOPENGL_EGLTHREAD_H
#define NATIVEOPENGL_EGLTHREAD_H


#include <EGL/egl.h>
#include "android/native_window.h"
#include "EglHelper.h"
#include "pthread.h"

typedef void (*onCreate)();

typedef void (*onChange)(int width, int height);

typedef void (*onDestroy)();

typedef void (*onDrawFrame)();

class EglThread {

public:

    // 指针函数
    onCreate onCreateCall;
    onChange onChangeCall;
    onDestroy onDestroyCall;

    onDrawFrame onDrawFrameCall;

    EglHelper *eglHelper;

    NativeWindowType win;

    void onSurfaceCreate(NativeWindowType win);

    void onSurfaceChange(int width, int height);

    void onSurfaceDestroy();

    int width,height;

    pthread_t nativeThread = -1;

    bool isCreate,isChange,isDestroy,isStart,isExit = false;

private:





};


#endif //NATIVEOPENGL_EGLTHREAD_H
