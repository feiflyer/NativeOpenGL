//
// Created by bbyy-liangchuanfei on 3/25/21.
//

#ifndef NATIVEOPENGL_BASEOPENGL_H
#define NATIVEOPENGL_BASEOPENGL_H

#include "EglThread.h"
#include "WlAndroidLog.h"
#include <GLES3/gl3.h>

static int loadShaders(int shaderType, const char *code)
{
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &code, 0);
    glCompileShader(shader);
    int status;
    glGetShaderiv(shader,GL_COMPILE_STATUS,&status);
    LOGD("编译状态:%d",status);

    char *info = new char[100];
    glGetShaderInfoLog(shader,1000,0,info);
    LOGD("编译状态:%d",status);

    return  shader;
}

static int createProgrm(const char *vertex , const char * fragment)
{
    GLuint vertexShader = loadShaders(GL_VERTEX_SHADER, vertex);
    GLuint fragmentShader = loadShaders(GL_FRAGMENT_SHADER, fragment);
    int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    return program;
}

static int loadTexture(){

    return 0;
}

class BaseOpengl {

public:

    const char *vertex;
    const char *fragment;

    int progrm = 0;

    void *imageData = nullptr;

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
