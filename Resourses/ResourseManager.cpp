#include "ResourseManager.h"
#include "../Renderer/ShaderProgram.h"
#include <sstream>
#include <fstream>
#include <iostream>


ResourseManager::ResourseManager(const std::string& executablePath){
    size_t found = executablePath.find_last_of("/\\");
    m_path = executablePath.substr(0, found);
}

std::string ResourseManager::getFileString(const std::string& relativeFilePath) const {
    std::ifstream f;
    f.open(m_path + "/" + relativeFilePath.c_str(), std::ios::in | std::ios::binary);
    if (!f.is_open()){
        std::cerr<<"Failed to open file: "<< m_path + "/" + relativeFilePath.c_str() << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer<<f.rdbuf();
    return buffer.str();
}

std::shared_ptr<Renderer::ShaderProgram> ResourseManager::loadShaders(const std::string& shaderName, const std::string& vertexPath, const std::string& fragmentpath){
    std::string vertexString = getFileString(vertexPath);

    if (vertexString.empty()){
        std::cerr<< "No vertex shader!"<<std::endl;
        return nullptr;
    }

    std::string fragmentString = getFileString(fragmentpath);

    if (fragmentString.empty()){
        std::cerr<< "No fragment shader!"<<std::endl;
        return nullptr;
    }

    std::shared_ptr<Renderer::ShaderProgram>& newShader =  m_shaderprograms.emplace(shaderName, std::make_shared<Renderer::ShaderProgram>(vertexString, fragmentString)).first->second;

    if (newShader->isCompiled()){
        return newShader;
    }

    std::cerr<<"Can't load shader program:\n" << "Vertex: "<<vertexPath<<"\n" <<"Fragment: "<<fragmentpath<<std::endl;

    return nullptr;
}


std::shared_ptr<Renderer::ShaderProgram> ResourseManager::getShaderProgram(const std::string& shaderName){
    ShaderProgramsMap::const_iterator it = m_shaderprograms.find(shaderName);

    if (it!=m_shaderprograms.end()){
        return it->second;
    }

    std::cerr<<"Can't find the shader program: "<<shaderName<<std::endl;
    return nullptr;
}


