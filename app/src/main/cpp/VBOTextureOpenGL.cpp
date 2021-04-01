//
// Created by bbyy-liangchuanfei on 4/1/21.
//


#include <cstring>
#include "VBOTextureOpenGL.h"


VBOTextureOpenGL::VBOTextureOpenGL() {
    vertex = "#version 300 es\n"
             "layout(location = 0) in vec4 v_Position;\n"
             "layout(location = 1) in vec2 f_Position;\n"
             "out vec2 fo_Position;\n"
             "void main() {\n"
             "    fo_Position = f_Position;\n"
             "    gl_Position = v_Position;\n"
             "}";

    //# 注意在glsl3中不要使用texture2D
    fragment = "#version 300 es\n"
               "precision mediump float;\n"
               "out vec4 fragColor;\n"
               "in vec2 fo_Position;\n "
               "uniform sampler2D sTexture;\n"
               "void main() {\n"
               "    fragColor=texture(sTexture, fo_Position);\n"
               "}";

    float v[] = {1, -1,
                 1, 1,
                 -1, -1,
                 -1, 1};

    float f[] = {1, 1,
                 1, 0,
                 0, 1,
                 0, 0};

    vertexPosition = new float[8];
    texturePosition = new float[8];

    memcpy(vertexPosition, v, sizeof(v));
    memcpy(texturePosition, f, sizeof(f));
}

VBOTextureOpenGL::~VBOTextureOpenGL() {

}

void VBOTextureOpenGL::onCreateCallback() {
    progrm = createProgrm(vertex, fragment);
    vPosition = glGetAttribLocation(progrm, "v_Position");
    fPosition = glGetAttribLocation(progrm, "f_Position");
    sampler = glGetUniformLocation(progrm, "sTexture");

    // 生成纹理
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    LOGD("textureId:%d", textureId)
    LOGD("progrm:%d", progrm)
    LOGD("vPosition:%d", vPosition)
    LOGD("fPosition:%d", fPosition)
    LOGD("sampler:%d", sampler)

    GLuint *ids = new GLuint[2];

    // 创建顶点缓冲
    glGenBuffers(2, ids);
    vboId = ids[0];
    t_vboId = ids[1];

    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    // size 以字节数表示
    glBufferData(GL_ARRAY_BUFFER, 32, vertexPosition, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, t_vboId);
    glBufferData(GL_ARRAY_BUFFER, 32, texturePosition, GL_STATIC_DRAW);

}

void VBOTextureOpenGL::onChangeCallback(int width, int height) {
    glViewport(0, 0, width, height);
}

void VBOTextureOpenGL::onDrawFrameCallback() {
    if (nullptr == imageData) {
        glClearColor(1, 0, 0.5, 0);
        glClear(GL_COLOR_BUFFER_BIT);
    } else {

        glClearColor(0, 0, 0.5, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(progrm);
        glActiveTexture(GL_TEXTURE0);
        glUniform1i(sampler, 0);
        glBindTexture(GL_TEXTURE_2D, textureId);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1200, 1200, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                     imageData);

        glEnableVertexAttribArray(vPosition);
//        glVertexAttribPointer(vPosition, 2, GL_FLOAT, false, 8, vertexPosition);

// 启动VBO pointer传0即可
        glVertexAttribPointer(vPosition, 2, GL_FLOAT, false, 0, 0);

        glEnableVertexAttribArray(fPosition);

//        glVertexAttribPointer(fPosition, 2, GL_FLOAT, false, 8, texturePosition);

        glVertexAttribPointer(fPosition, 2, GL_FLOAT, false, 0, 0);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

void VBOTextureOpenGL::onDestroyCallback() {

}
