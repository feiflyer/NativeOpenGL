//
// Created by bbyy-liangchuanfei on 3/25/21.
//

#include "EglHelper.h"
#include "WlAndroidLog.h"

void EglHelper::initEgl(EGLNativeWindowType windowType) {
    eglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (eglDisplay == EGL_NO_DISPLAY) {
        LOGD("获取egl display失败");
    }
    EGLint *version = new EGLint[2];
    if (!eglInitialize(eglDisplay, &version[1], &version[2])) {
        LOGD("eglInitialize 失败");
    }

    const EGLint attribs[] = {
            EGL_RED_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_BLUE_SIZE, 8,
            EGL_ALPHA_SIZE, 8,
            EGL_DEPTH_SIZE, 8,
            EGL_STENCIL_SIZE, 8,
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
            EGL_NONE
    };

    EGLint num_config;
    if (!eglChooseConfig(eglDisplay, attribs, NULL, 1, &num_config)) {
        LOGD("eglChooseConfig 失败");
    }


    if (!eglChooseConfig(eglDisplay, attribs, &eglConfig, 1, &num_config)) {
        LOGD("eglChooseConfig兼容 失败");
    }

    const EGLint contextAttrs[] = {
            EGL_CONTEXT_CLIENT_VERSION, 3,
            EGL_NONE
    };

    eglContext = eglCreateContext(eglDisplay, eglConfig, EGL_NO_CONTEXT, contextAttrs);
    if (eglContext == EGL_NO_CONTEXT) {
        LOGD("eglCreateContext 失败");
    }

    eglSurface = eglCreateWindowSurface(eglDisplay, eglConfig, windowType, NULL);
    if (eglSurface == EGL_NO_SURFACE) {
        LOGD("eglCreateWindowSurface 失败");
    }

    if (!eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext)) {
        LOGD("eglMakeCurrent 失败");
    } else{
        LOGD("eglMakeCurrent 成功");
    }

}

EglHelper::EglHelper(){

}

EglHelper::~EglHelper() {

}

void EglHelper::swapBuffers() {
    if(eglDisplay != EGL_NO_DISPLAY && eglSurface != EGL_NO_SURFACE)
    {
        glClearColor(1,0,0.5,0);
        glClear(GL_COLOR_BUFFER_BIT);

        if(eglSwapBuffers(eglDisplay, eglSurface))
        {
            LOGD("eglSwapBuffers 成功");
        } else{
            LOGD("eglSwapBuffers 失败");
        }
    }
}

void EglHelper::destroy() {

}