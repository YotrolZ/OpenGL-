//
//  main.cpp
//  OpenGL_绘制方式3_顶点数组
//
//  Created by Sunshine on 2018/3/16.
//  Copyright © 2018年 YotrolZ. All rights reserved.
//

#include <stdio.h>
#include <OpenGL/gl3.h>
//#include "GLTools.h"
#include <GLUT/GLUT.h>

void draw_1() {
    
    //初始化顶点数组
    GLfloat vertices[] = {
        -0.5f, -0.5f,  // 第1个顶点数据(x,y)
        0.5f, -0.5f,   // 第2个顶点数据(x,y)
        0.5f, 0.5f,    // 第3个顶点数据(x,y)
        -0.5f, 0.5f,   // 第4个顶点数据(x,y)
    };

    //初始化颜色数组
    GLfloat colores[] = {
        1.0f, 0.0f, 0.0f, 1.0f, // 第1个顶点的颜色数据(R,G,B,A)
        0.0f, 1.0f, 0.0f, 1.0f, // 第2个顶点的颜色数据(R,G,B,A)
        0.0f, 0.0f, 1.0f, 1.0f, // 第3个顶点的颜色数据(R,G,B,A)
        1.0f, 1.0f, 1.0f, 1.0f, // 第4个顶点的颜色数据(R,G,B,A)
    };

    // 启用顶点数组：启用后，当glDrawArrays或者glDrawElements调用时，顶点数组就会被使用，初始状态是禁用的，不会被访问。
    glEnableClientState(GL_VERTEX_ARRAY);
    // 启用颜色数组：启用后，当glDrawArrays或者glDrawElements调用时，颜色数组就会被使用，初始状态是禁用的，不会被访问。
    glEnableClientState(GL_COLOR_ARRAY);

    /*
     * glVertexPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
     * size:每个顶点对应的坐标个数
     * type:数组中每个顶点坐标的数据类型，可取常量:GL_BYTE, GL_SHORT,GL_FIXED,GL_FLOAT;
     * stride:连续顶点间的字节排列方式，如果为0，数组中的顶点就会被认为是按照紧凑方式排列的，默认值为0;
     * pointer:数组中第一个顶点的首地址
     */
    glVertexPointer(2, GL_FLOAT, 0, vertices);    // 指定顶点数据
    glColorPointer(4, GL_FLOAT, 0, colores);      // 指定颜色数据

    glDrawArrays(GL_QUADS, 0, 4);                 // 进行渲染
    
    glDisableClientState(GL_VERTEX_ARRAY);        // 关闭顶点数据
    glDisableClientState(GL_COLOR_ARRAY);         // 关闭颜色数据
    
    glFlush(); // 强制刷新缓冲，保证绘图命令将被执行，而不是存储在缓冲区中等待其他的OpenGL命令。
}

void draw_2() {
    
    // 初始化数据
    // 我们也可把所有数据放在一个数组中，称之为混合数组
    GLfloat datas[] = {
        1.0f, 0.0f, 0.0f,     -0.5f, -0.5f, 1.0f,     // 第1个顶点的数据(R,G,B,  x,y)
        0.0f, 1.0f, 0.0f,     0.5f, -0.5f, 1.0f,      // 第2个顶点的数据(R,G,B,  x,y)
        0.0f, 0.0f, 1.0f,     0.5f, 0.5f, 1.0f,       // 第3个顶点的数据(R,G,B,  x,y)
        1.0f, 1.0f, 1.0f,     -0.5f, 0.5f, 1.0f,      // 第4个顶点的数据(R,G,B,  x,y)
    };
    
    /*
     T = Texture:纹理
     C = Color:颜色
     N = Normal:法线
     V = Vertex:顶点
     */
    glInterleavedArrays(GL_C3F_V3F, 0, datas);
    
    glDrawArrays(GL_QUADS, 0, 4); // 进行渲染
    
    glFlush(); // 强制刷新缓冲，保证绘图命令将被执行，而不是存储在缓冲区中等待其他的OpenGL命令。
}

int main(int argc,const char *argv[]) {
    
    //1.初始化一个GLUT库
    glutInit(&argc, (char **)argv);
    
    //2.创建一个窗口并制定窗口名
    glutCreateWindow("OpenGL绘制方式3--顶点数组");
    
    //3.注册一个绘图函数，操作系统在必要时刻就会对窗体进行重绘制操作
    //它设置了一个显示回调（diplay callback），即GLUT在每次更新窗口内容的时候回自动调用该例程
    glutDisplayFunc(draw_2);
    
    //这是一个无限执行的循环，它会负责一直处理窗口和操作系统的用户输入等操作。（注意：不会执行在glutMainLoop()之后的所有命令。）
    glutMainLoop();
    
    return 0;
}
