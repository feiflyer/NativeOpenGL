//
// Created by bbyy-liangchuanfei on 3/25/21.
//

#include <unistd.h>
#include "EglThread.h"


void *eglThreadImpl(void *context) {
    if (nullptr != context) {
        EglThread *eglThread = static_cast<EglThread *>(context);
        eglThread->eglHelper = new EglHelper;
        eglThread->eglHelper->initEgl(eglThread->win);
        while (!eglThread->isExit) {
            if (nullptr != eglThread->onCreateCall && eglThread->isCreate) {
                eglThread->isCreate = false;
                eglThread->onCreateCall(eglThread->contextData);
            }

            if (nullptr != eglThread->onChangeCall && eglThread->isChange) {
                eglThread->isChange = false;
                eglThread->isStart = true;
                eglThread->onChangeCall(eglThread->contextData);
            }

            if (nullptr != eglThread->onDestroyCall && eglThread->isDestroy) {
                eglThread->onDestroyCall(eglThread->contextData);
                if (nullptr != eglThread->eglHelper) {
                    eglThread->eglHelper->destroy();
                    delete eglThread->eglHelper;
                    eglThread->eglHelper = nullptr;
                }
                eglThread->isExit = true;
                break;
            }

            if (eglThread->isStart && nullptr != eglThread->onDrawFrameCall) {
                eglThread->onDrawFrameCall(eglThread->contextData);
                eglThread->eglHelper->swapBuffers();
                // 每秒60帧
                usleep(1000000 / 60);
            }

        }
    }

    return 0;
}


EglThread::EglThread() {

}

EglThread::~EglThread() {

}


void EglThread::onSurfaceCreate(NativeWindowType win) {
    isCreate = true;
    this->win = win;
    // 新开线程初始化EGL
    if (nativeThread == -1) {
        pthread_create(&nativeThread, nullptr, eglThreadImpl, this);
    }
}

void EglThread::onSurfaceChange(int width, int height) {
    isChange = true;
}

void EglThread::onSurfaceDestroy() {
    isDestroy = true;
}

