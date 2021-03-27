//
// Created by bbyy-liangchuanfei on 3/25/21.
//

#ifndef NATIVEOPENGL_BASEOPENGL_H
#define NATIVEOPENGL_BASEOPENGL_H

#include "EglThread.h"

class BaseOpengl {

public:
    BaseOpengl();

    ~BaseOpengl();

    void onSurfaceCreate(NativeWindowType win);

    void onSurfaceChange(int width, int height);

    void onSurfaceDestroy();

    virtual void onCreateCallback() = 0;
    virtual void onChangeCallback(int width, int height) = 0;
    virtual void onDestroyCallback() = 0;

    virtual void onDrawFrameCallback() = 0;

    int width,height;

private:
    EglThread *eglThread = nullptr;

};


#endif //NATIVEOPENGL_BASEOPENGL_H
