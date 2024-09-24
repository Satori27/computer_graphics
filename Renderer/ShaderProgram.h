#pragma once
#include <glad/glad.h>
#include <string>
#include <iostream>

namespace Renderer{
    class ShaderProgram{
    public:
        ShaderProgram(const std::string vertexShader, const std::string& fragmentShader);
        ~ShaderProgram();
        bool isCompiled() const {
            return m_isCompiled;
        }

        ShaderProgram() = delete;
        ShaderProgram(ShaderProgram&) = delete;
        ShaderProgram& operator=(const ShaderProgram&) = delete;

        ShaderProgram& operator=(ShaderProgram&& shaderProgram) noexcept;
        ShaderProgram(ShaderProgram&& shaderProgram) noexcept;

        void use() const;

    private:
        bool createShader(const std::string& source, const GLenum shaderType, GLuint& shaderID);
        bool m_isCompiled = false;
        GLuint m_ID = 0;
    };
}
