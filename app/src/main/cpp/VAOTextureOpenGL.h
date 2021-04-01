//
// Created by bbyy-liangchuanfei on 4/1/21.
//

#ifndef NATIVEOPENGL_VAOTEXTUREOPENGL_H
#define NATIVEOPENGL_VAOTEXTUREOPENGL_H


#include "BaseOpengl.h"

class VAOTextureOpenGL : public BaseOpengl {

public:

    // 顶点vao
    GLuint vao;

    // 顶点坐标vbo
    GLuint vboId;

    // 纹理坐标vbo
    GLuint t_vboId;

    GLuint textureId;
    int vPosition;
    // 纹理坐标变量
    int fPosition;
    int sampler;

    float *vertexPosition;

    float *texturePosition;

    VAOTextureOpenGL();

    ~VAOTextureOpenGL();

    void onChangeCallback(int width, int height) final override;

    void onCreateCallback() final override;

    void onDestroyCallback() final override;

    void onDrawFrameCallback() final override;
};


#endif //NATIVEOPENGL_VAOTEXTUREOPENGL_H
