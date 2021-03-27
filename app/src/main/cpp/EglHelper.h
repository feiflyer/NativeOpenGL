//
// Created by bbyy-liangchuanfei on 3/25/21.
//

#ifndef NATIVEOPENGL_EGLHELPER_H
#define NATIVEOPENGL_EGLHELPER_H

#include <EGL/egl.h>
#include "android/native_window.h"
#include <GLES3/gl3.h>

class EglHelper {


public:
    EGLDisplay eglDisplay;
    EGLConfig eglConfig;
    EGLContext eglContext;
    EGLSurface eglSurface;

    EglHelper();

    ~EglHelper();

    void initEgl(EGLNativeWindowType windowType);

    void swapBuffers();

    void destroy();
};


#endif //NATIVEOPENGL_EGLHELPER_H
