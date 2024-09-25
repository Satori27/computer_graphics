#include <glad/glad.h>
#include <iostream>
#include "Renderer/ShaderProgram.h"
#include <GLFW/glfw3.h>
#include "Resourses/ResourseManager.h"
#include "Renderer/Texture2D.h"
#include <external/glm/mat4x4.hpp>
#include <external/glm/gtc/matrix_transform.hpp>



GLfloat point[] = {
    0.0f, 50.f, 0.0f,
    50.f, -50.f, 0.0f,
    -50.f, -50.f, 0.0f
};

GLfloat colors[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};

GLfloat texCoord[] = {
    0.5f, 1.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,
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

        if (pDefaultShaderProgram == nullptr){
            std::cerr<<"Can't create shader program: "<<"DefaultShader"<<std::endl;
            return -1;
        }

        auto tex = resourseManager.loadTexture("DefaultTexture", "res/textures/map_16x16.png");


        GLuint points_vbo = 0;
        glGenBuffers(1, &points_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(point), point, GL_STATIC_DRAW);

        GLuint colors_vbo = 0;
        glGenBuffers(1, &colors_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

        GLuint texCoord_vbo = 0;
        glGenBuffers(1, &texCoord_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, texCoord_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(texCoord), texCoord, GL_STATIC_DRAW);

        GLuint vao = 0;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        glEnableVertexAttribArray(2);
        glBindBuffer(GL_ARRAY_BUFFER, texCoord_vbo);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

        pDefaultShaderProgram->use();
        pDefaultShaderProgram->setInt("tex", 0);


        glm::mat4 modelMatrix_1 = glm::mat4(1.f);
        modelMatrix_1 =  glm::translate(modelMatrix_1, glm::vec3(100.f, 200.f, 0.f));

        glm::mat4 modelMatrix_2 = glm::mat4(1.f);
        modelMatrix_2 =  glm::translate(modelMatrix_2, glm::vec3(590.f, 200.f, 0.f));
        
        glm::mat4 projectionMatrix = glm::ortho(0.f, static_cast<float>( 640), 0.f, static_cast<float>( 480), -100.f, 100.f);

        pDefaultShaderProgram->setMatrix4("projectionMat", projectionMatrix);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            pDefaultShaderProgram->use();

            glBindVertexArray(vao);
            tex->bind();

            pDefaultShaderProgram->setMatrix4("modelMat", modelMatrix_1);

            glDrawArrays(GL_TRIANGLES, 0, 3);

            pDefaultShaderProgram->setMatrix4("modelMat", modelMatrix_2);

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