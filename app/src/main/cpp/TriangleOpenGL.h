//
// Created by bbyy-liangchuanfei on 3/26/21.
//

#ifndef NATIVEOPENGL_TRIANGLEOPENGL_H
#define NATIVEOPENGL_TRIANGLEOPENGL_H

#include "BaseOpengl.h"

class TriangleOpenGL : public BaseOpengl {

    void onChangeCallback(int width, int height) final override;

    void onCreateCallback() override;

    void onDestroyCallback() override;

    void onDrawFrameCallback();
};


#endif //NATIVEOPENGL_TRIANGLEOPENGL_H
