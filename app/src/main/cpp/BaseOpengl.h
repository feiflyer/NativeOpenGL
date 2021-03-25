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

private:
    EglThread *eglThread = nullptr;

};


#endif //NATIVEOPENGL_BASEOPENGL_H
