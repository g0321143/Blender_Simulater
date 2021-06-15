#ifndef OPENGL_PBR_MAP_EXPOSURE_PASS_H_
#define OPENGL_PBR_MAP_EXPOSURE_PASS_H_

#include <glm/ext.hpp>
#include <glm/glm.hpp>

#include "create_program.h"

namespace game {

    /**
     * @brief exposure�p�X��\������N���X
     *
     * exposure���������܂��B
     */
    class ExposurePass final {
    public:
        /**
         * @brief ���̃p�X�������_�����O����
         *
         * exposure��exponential fog���������܂��B
         */
        void Render() const;

        /**
         * @brief �I�o�̒l��ݒ肵�܂�
         * @param exposure �I�o�̒l
         */
        void SetExposure(const GLfloat exposure);

        /**
         * @brief �R���X�g���N�^
         * @param hdr_color_buffer HDR�J���[�o�b�t�@�e�N�X�`����ID
         * @param exposured_fbo Exposed FBO��ID
         * @param fullscreen_mesh_vao ��ʂ𕢂����b�V����VAO
         * @param width �E�B���h�E�̕�
         * @param height �E�B���h�E�̍���
         */
        ExposurePass(const GLuint hdr_color_buffer, const GLuint exposured_fbo,
            const GLuint fullscreen_mesh_vao, const GLuint width,
            const GLuint height);

        /**
         * @brief �f�X�g���N�^
         *
         * �R���X�g���N�^�Ő��������V�F�[�_�v���O�����y��FBO�A�e�N�X�`����j�����܂��B
         */
        ~ExposurePass();

    private:
        const GLuint width_;
        const GLuint height_;

        const GLuint hdr_color_buffer_;
        const GLuint exposured_fbo_;
        const GLuint fullscreen_mesh_vao_;

        const GLuint shader_program_;
        const GLuint exposure_loc_;

        GLfloat exposure_;
    };

}  // namespace game

#endif  // OPENGL_PBR_MAP_EXPOSURE_PASS_H_