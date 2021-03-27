//
// Created by bbyy-liangchuanfei on 3/25/21.
//

#include "BaseOpengl.h"
#include <pthread.h>


void createCall(void *data){
    BaseOpengl *baseOpengl = static_cast<BaseOpengl *>(data);
    baseOpengl->onCreateCallback();
}

void changeCall(void *data){
    BaseOpengl *baseOpengl = static_cast<BaseOpengl *>(data);
    baseOpengl->onChangeCallback(baseOpengl->width,baseOpengl->height);
}

void destroyCall(void *data){
    BaseOpengl *baseOpengl = static_cast<BaseOpengl *>(data);
    baseOpengl->onDestroyCallback();
}

void drawFrameCall(void *data) {
    BaseOpengl *baseOpengl = static_cast<BaseOpengl *>(data);
    baseOpengl->onDrawFrameCallback();
}

BaseOpengl::BaseOpengl() {

}

BaseOpengl::~BaseOpengl() {

}

void BaseOpengl::onSurfaceCreate(NativeWindowType win) {
    if (nullptr == eglThread) {
        eglThread = new EglThread;
        eglThread->contextData = this;
        eglThread->onCreateCall = createCall;
        eglThread->onChangeCall = changeCall;
        eglThread->onDestroyCall = destroyCall;
        eglThread->onDrawFrameCall = drawFrameCall;

        eglThread->onSurfaceCreate(win);
    }
}


void BaseOpengl::onSurfaceChange(int width, int height) {
    this->width = width;
    this->height = height;
    if (nullptr != eglThread) {
        eglThread->onSurfaceChange(width,height);
    }
}

void BaseOpengl::onSurfaceDestroy() {
    if (nullptr != eglThread) {
        eglThread->onSurfaceDestroy();
        pthread_join(eglThread->nativeThread, nullptr);
        delete eglThread;
        eglThread = nullptr;
    }
}