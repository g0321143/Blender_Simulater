#ifndef OPENGL_PBR_MAP_CREATE_PROGRAM_H_
#define OPENGL_PBR_MAP_CREATE_PROGRAM_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace game {

    /**
     * @brief �V�F�[�_��ǂݍ���
     * @param vertex_shader_pass ���_�V�F�[�_�̃p�X
     * @param fragment_shader_pass �t���O�����g�V�F�[�_�̃p�X
     */
    const GLuint CreateProgram(const std::string& vertex_shader_pass,
        const std::string& fragment_shader_pass);

    /**
     * @brief �V�F�[�_��ǂݍ���
     * @param vertex_shader_pass ���_�V�F�[�_�̃p�X
     * @param geometry_shader_pass �W�I���g���V�F�[�_�̃p�X
     * @param fragment_shader_pass �t���O�����g�V�F�[�_�̃p�X
     */
    GLuint CreateProgram(const std::string& vertex_shader_pass,
        const std::string& geometry_shader_pass,
        const std::string& fragment_shader_pass);

}  // namespace game

#endif  // OPENGL_PBR_MAP_CREATE_PROGRAM_H_