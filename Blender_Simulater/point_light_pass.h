#ifndef OPENGL_PBR_MAP_POINT_LIGHT_PASS_H_
#define OPENGL_PBR_MAP_POINT_LIGHT_PASS_H_

#include <glm/ext.hpp>
#include <glm/glm.hpp>

#include "create_program.h"
#include "scene.h"

namespace game {

    /**
     * @brief PointLighat�p�X��\������N���X
     *
     * GBuffer�ƃV�[����PointLight�̏������Ƃ�
     * PointLight�̃��C�e�B���O���v�Z��HDR�̃J���[�o�b�t�@�ɏ������݂܂��B
     */
    class PointLightPass {
    public:
        /**
         * @brief ���̃p�X�������_�����O����
         * @param scene �����_�����O����V�[��
         *
         * PointLight�̃��C�e�B���O��HDR�J���[�o�b�t�@�ɏ����o���܂��B
         */
        void Render(const Scene& scene) const;

        /**
         * @brief �R���X�g���N�^
         * @param hdr_color_fbo HDR�̃t���[���o�b�t�@�I�u�W�F�N�g
         * @param gbuffer0 GBuffer0�̃e�N�X�`��ID
         * @param gbuffer1 GBuffer1�̃e�N�X�`��ID
         * @param gbuffer2 GBuffer2�̃e�N�X�`��ID
         * @param sphere_vao ����Mesh��VAO
         * @param width �E�B���h�E�̕�
         * @param height �E�B���h�E�̍���
         */
        PointLightPass(const GLuint hdr_color_fbo, const GLuint gbuffer0,
            const GLuint gbuffer1, const GLuint gbuffer2,
            const GLuint sphere_vao, const GLuint width,
            const GLuint height);

        /**
         * @brief �f�X�g���N�^
         *
         * �R���X�g���N�^�Ŋm�ۂ������\�[�X���J�����܂��B
         */
        ~PointLightPass();

    private:
        const GLuint width_;
        const GLuint height_;

        const GLuint shadow_map_size_;

        const GLuint hdr_fbo_;
        const GLuint gbuffer0_;
        const GLuint gbuffer1_;
        const GLuint gbuffer2_;
        const GLuint sphere_vao_;

        const GLuint shadow_map_;
        const GLuint shadow_map_fbo_;

        const GLuint shadow_pass_shader_program_;
        const GLuint shadow_pass_model_loc_;
        const GLuint shadow_pass_light_view_projection_matrices_loc_;
        const GLuint shadow_pass_world_light_pos_loc_;
        const GLuint shadow_pass_range_loc_;

        const GLuint stencil_pass_shader_program_;
        const GLuint stencil_pass_model_view_projection_loc_;

        const GLuint shader_program_;
        const GLuint model_view_projection_loc_;
        const GLuint world_light_position_loc_;
        const GLuint light_intensity_loc_;
        const GLuint light_color_loc_;
        const GLuint light_range_loc_;
        const GLuint world_camera_pos_loc_;
        const GLuint view_projection_i_loc_;
        const GLuint projection_params_loc_;
        const GLuint shadow_bias_loc_;
        const GLuint use_shadow_loc_;

        /**
         * @brief �V���h�E�}�b�v�e�N�X�`�����쐬����
         * @return ���������e�N�X�`����ID
         */
        static const GLuint CreateShadowMap(const GLuint shadow_map_size);

        /**
         * @brief �V���h�E�}�b�v��FBO�𐶐�����
         * @param shadow_map �V���h�E�}�b�v�e�N�X�`����ID
         * @return ��������FBO��ID
         */
        static const GLuint CreateShadowMapFbo(const GLuint shadow_map);
    };

}  // namespace game

#endif  // OPENGL_PBR_MAP_POINT_LIGHT_PASS_H_