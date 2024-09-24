#include <glad/glad.h>
#include <iostream>
#include "Renderer/ShaderProgram.h"
#include <GLFW/glfw3.h>
#include "Resourses/ResourseManager.h"


GLfloat point[] = {
    0.0f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f
};

GLfloat colors[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};

// const char* vertex_shader = 
// "#version 460\n"
// "layout(location = 0) in vec3 vertex_position;"
// "layout (location = 1)in vec3 vertex_color;"
// "out vec3 color;"
// "void main(){"
// "   color = vertex_color;"
// "   gl_Position = vec4(vertex_position, 1.0);"
// "}";

// const char* fragment_shader = 
// "#version 460\n"
// "in vec3 color;"
// "out vec4 frag_color;"
// "void main(){"
// "   frag_color = vec4(color, 1.0);"
// "}";


int main(int argc, char** argv)
{

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGL()){
        std::cout<<"Can't load GLAD!"<<std::endl;
        return -1;
    }

    std::cout<<"OpenGL "<< GLVersion.major<<"."<<GLVersion.minor<<std::endl;


    glClearColor(1, 1, 0, 1);


    {
        ResourseManager resourseManager(argv[0]);
        auto pDefaultShaderProgram = resourseManager.loadShaders("DefaultShader", "res/shaders/vertex.txt", "res/shaders/fragment.txt");

        if (pDefaultShaderProgram){
            std::cerr<<"Can't create shader program: "<<"DefaultShader"<<std::endl;
            return -1;
        }


        GLuint points_vbo = 0;
        glGenBuffers(1, &points_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(point), point, GL_STATIC_DRAW);

        GLuint colors_vbo = 0;
        glGenBuffers(1, &colors_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

        GLuint vao = 0;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);




        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            pDefaultShaderProgram->use();

            glBindVertexArray(vao);
            glDrawArrays(GL_TRIANGLES, 0, 3);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
    }

    glfwTerminate();  // ваще хз, оставлять или нет. Если оставить, то нужно убрать удаление в деструкторе. Такие дела.
    return 0;
}