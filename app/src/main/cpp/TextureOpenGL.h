//
// Created by bbyy-liangchuanfei on 3/27/21.
//

#ifndef NATIVEOPENGL_TEXTUREOPENGL_H
#define NATIVEOPENGL_TEXTUREOPENGL_H


#include "BaseOpengl.h"

class TextureOpenGL : public BaseOpengl {

public:

    GLuint textureId;
    int vPosition;
    // 纹理坐标变量
    int fPosition;
    int sampler;

    float *vertexPosition;

    float *texturePosition;

    TextureOpenGL();

    ~TextureOpenGL();

    void onChangeCallback(int width, int height) final override;

    void onCreateCallback() final override;

    void onDestroyCallback() final override;

    void onDrawFrameCallback() final override;
};


#endif //NATIVEOPENGL_TEXTUREOPENGL_H
