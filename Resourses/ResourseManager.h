#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <map>

namespace Renderer{
    class ShaderProgram;
}

class ResourseManager{
    public:
        ResourseManager(const std::string& executablePath);
        ~ResourseManager() = default;

        ResourseManager(const ResourseManager&) = delete;
        ResourseManager& operator=(const ResourseManager&) = delete;
        ResourseManager& operator=(ResourseManager&&) = delete;
        ResourseManager(ResourseManager&&) = delete;

        std::shared_ptr<Renderer::ShaderProgram> loadShaders(const std::string& shaderName, const std::string& vertexPath, const std::string& fragmentpath);
        std::shared_ptr<Renderer::ShaderProgram> getShaderProgram(const std::string& shaderName);

    private:

        std::string getFileString(const std::string& relativeFilePath) const;

        typedef std::map<const std::string, std::shared_ptr<Renderer::ShaderProgram>> ShaderProgramsMap;

        ShaderProgramsMap m_shaderprograms;

        std:: string m_path;


};

