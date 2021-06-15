#ifndef OPENGL_PBR_MAP_TONEMAPPING_PASS_H_
#define OPENGL_PBR_MAP_TONEMAPPING_PASS_H_

#include <glm/ext.hpp>
#include <glm/glm.hpp>

#include "create_program.h"

namespace game {

    /**
     * @brief �g�[���}�b�s���O�p�X��\������N���X
     *
     * �I�o�␳��ACES�g�[���}�b�s���O�A�K���}�␳���s���p�X�ł��B
     * ACES�̎��͎��̃I���W�i����GitHub�R�[�h��GLSL�ɏ��������܂����B
     * https://github.com/ampas/aces-dev
     */
    class TonemappingPass {
    public:
        /**
         * @brief ���̃p�X�������_�����O����
         *
         * �I�o�␳��ACES�g�[���}�b�s���O���s���܂��B
         */
        void Render() const;

        /**
         * @brief �R���X�g���N�^
         * @param hdr_color_buffer HDR�J���[�o�b�t�@�e�N�X�`����ID
         * @param fullscreen_mesh_vao ��ʂ𕢂����b�V����VAO
         * @param width �E�B���h�E�̕�
         * @param height �E�B���h�E�̍���
         *
         * �V�F�[�_�v���O�������쐬���܂��B
         * HDR�J���[�o�b�t�@�e�N�X�`���y��fullscreen VAO�̏��L���͒D���܂���B
         * HDR�J���[�o�b�t�@�e�N�X�`���y��fullscreen
         * VAO�̊J���̐ӔC�͊O���̃X�R�[�v�ł��B
         */
        TonemappingPass(const GLuint hdr_color_buffer,
            const GLuint fullscreen_mesh_vao, const GLuint width,
            const GLuint height);

        /**
         * @brief �f�X�g���N�^
         *
         * �R���X�g���N�^�Ő��������V�F�[�_�v���O������j�����܂��B
         */
        ~TonemappingPass();

    private:
        const GLuint exposured_color_buffer_;
        const GLuint fullscreen_mesh_vao_;

        const GLuint shader_program_;
    };

}

#endif  // OPENGL_PBR_MAP_TONEMAPPING_PASS_H_