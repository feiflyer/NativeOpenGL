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
                eglThread->onCreateCall();
            }

            if (nullptr != eglThread->onChangeCall && eglThread->isChange) {
                eglThread->isChange = false;
                eglThread->isStart = true;
                eglThread->onChangeCall(eglThread->width, eglThread->height);
            }

            if (eglThread->isStart && nullptr != eglThread->onDrawFrameCall) {
                eglThread->onDrawFrameCall();
                // 每秒60帧
                usleep(1000000/60);
            }

            if (nullptr != eglThread->onDestroyCall && eglThread->isDestroy) {
                eglThread->onDestroyCall();

                if (nullptr != eglThread->eglHelper) {
                    eglThread->eglHelper->destroy();
                    delete eglThread->eglHelper;
                    eglThread->eglHelper = nullptr;
                }
                eglThread->isExit = true;
            }
        }
    }
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
    this->width = width;
    this->height = height;
}

void EglThread::onSurfaceDestroy() {
    isDestroy = true;
}

