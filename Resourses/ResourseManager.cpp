#include "ResourseManager.h"
#include "../Renderer/ShaderProgram.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include "../Renderer/Texture2D.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include "stb_image.h"

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


std::shared_ptr<Renderer::Texture2D> ResourseManager::loadTexture(const std::string& textureName, const std::string& texturePath){
    int channels = 0;
    int width = 0;
    int height = 0;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* pixels =  stbi_load(std::string(m_path+ "/" + texturePath).c_str(), &width, &height, &channels, 0);

    if (!pixels){
        std::cerr<<"Can't load image: "<<texturePath<<std::endl;
        return nullptr;
    }

    std::shared_ptr<Renderer::Texture2D> newTexture = m_textures.emplace(textureName, std::make_shared<Renderer::Texture2D>(width, height, pixels, channels, GL_NEAREST, GL_CLAMP_TO_EDGE)).first->second;

    stbi_image_free(pixels);

    return newTexture;

}



std::shared_ptr<Renderer::Texture2D> ResourseManager::getTexture2D(const std::string& textureName){
    TexturesMap::const_iterator it = m_textures.find(textureName);

    if (it!=m_textures.end()){
        return it->second;
    }

    std::cerr<<"Can't find the texture: "<<textureName<<std::endl;
    return nullptr;
}

