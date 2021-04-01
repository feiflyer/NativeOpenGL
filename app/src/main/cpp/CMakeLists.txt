
cmake_minimum_required(VERSION 3.4.1)

add_library(
        native-lib

        SHARED

        native-lib.cpp
        BaseOpengl.cpp
        EglThread.cpp
        EglHelper.cpp
        TriangleOpenGL.cpp
        TextureOpenGL.cpp
        VBOTextureOpenGL.cpp
        VAOTextureOpenGL.cpp)


find_library(
        log-lib
        log)

target_link_libraries(
        native-lib

        EGL
        GLESv3
        android
        jnigraphics
        ${log-lib})