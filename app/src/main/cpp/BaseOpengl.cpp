//
// Created by bbyy-liangchuanfei on 3/25/21.
//

#include "BaseOpengl.h"


BaseOpengl::BaseOpengl() {

}

void BaseOpengl::onSurfaceCreate(NativeWindowType win) {
    if (nullptr == eglThread) {
        eglThread = new EglThread;
        eglThread->onSurfaceCreate(win);
    }
}

void BaseOpengl::onSurfaceChange(int width, int height) {

}

void BaseOpengl::onSurfaceDestroy() {
    if (nullptr != eglThread) {
        delete eglThread;
        eglThread = nullptr;
    }
}