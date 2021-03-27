//
// Created by bbyy-liangchuanfei on 3/25/21.
//

#ifndef NATIVEOPENGL_EGLTHREAD_H
#define NATIVEOPENGL_EGLTHREAD_H


#include <EGL/egl.h>
#include "android/native_window.h"
#include "EglHelper.h"
#include "pthread.h"

typedef void (*onThreadCallback)(void *);

class EglThread {

public:

    EglThread();
    ~EglThread();

    // 指针函数
    onThreadCallback onCreateCall = nullptr;
    onThreadCallback onChangeCall = nullptr;
    onThreadCallback onDestroyCall = nullptr;

    onThreadCallback onDrawFrameCall = nullptr;

    EglHelper *eglHelper;

    void *contextData;

    NativeWindowType win;

    void onSurfaceCreate(NativeWindowType win);

    void onSurfaceChange(int width, int height);

    void onSurfaceDestroy();

    pthread_t nativeThread = -1;

    bool isCreate = false,isChange = false,isDestroy = false,isStart = false,isExit = false;

private:





};


#endif //NATIVEOPENGL_EGLTHREAD_H
