#ifndef OPENGL_PBR_MAP_SCENE_RENDERER_H_
#define OPENGL_PBR_MAP_SCENE_RENDERER_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <array>

#include "directional_light_pass.h"
#include "exposure_pass.h"
#include "geometry_pass.h"
#include "point_light_pass.h"
#include "scene.h"
#include "spot_light_pass.h"
#include "tonemapping_pass.h"

namespace game {

    /**
     * @brief �����_���[�̃N���X
     *
     * �V�[���̃����_�����O���s���܂��B
     * �ÓT�I��Deferred�����_�����O�Ŏ������Ă��܂��B
     * ���\�[�X�̑��d�J����h�����߂ɃR�s�[�֎~�ł��B
     */
    class SceneRenderer {
    public:
        /**
         * @brief ���C���̃����_�����O����
         * @param scene �����_�����O����V�[��
         * @param delta_time �O�t���[������̎��ԁi�b�j
         */
        void Render(const Scene& scene, const double delta_time);

        /**
         * @brief �R���X�g���N�^
         * @param width �E�B���h�E�̕�
         * @param height �E�B���h�E�̍���
         */
        SceneRenderer(const GLuint width, const GLuint height);

        /**
         * @brief �f�X�g���N�^
         *
         * �R���X�g���N�^�Ő��������t���[���o�b�t�@�I�u�W�F�N�g���J�����܂��B
         */
        ~SceneRenderer();

        // �R�s�[�֎~
        SceneRenderer(const SceneRenderer&) = delete;
        SceneRenderer& operator=(const SceneRenderer&) = delete;

    private:
        const GLuint width_;
        const GLuint height_;

        const GLuint fullscreen_mesh_vao_;
        const GLuint fullscreen_mesh_vertices_vbo_;
        const GLuint fullscreen_mesh_uvs_vbo_;

        const GLuint sphere_vao_;
        const GLuint sphere_vertices_vbo_;
        const GLuint sphere_indices_ibo_;

        const GLuint gbuffer0_;       // rgb: albedo, a: metallic
        const GLuint gbuffer1_;       // rgb: emissive, a: depth
        const GLuint gbuffer2_;       // rgb: normal, a: roughenss
        const GLuint gbuffer_depth_;  // depth buffer
        const GLuint gbuffer_fbo_;

        const GLuint hdr_color_buffer_;
        const GLuint hdr_depth_buffer_;
        const GLuint hdr_fbo_;

        const GLuint exposured_color_buffer_;
        const GLuint exposured_fbo_;

        GeometryPass geometry_pass_;
        DirectionalLightPass directional_light_pass_;
        PointLightPass point_light_pass_;
        SpotLightPass spot_light_pass_;
        ExposurePass exposure_pass_;
        TonemappingPass tonemapping_pass_;

        /**
         * @brief ���\�[�X�̊J��������
         */
        void Release();

        /**
         * @brief �X�N���[���𕢂����b�V����VAO���쐬����
         * @return �쐬����VAO��ID
         */
        static const GLuint CreateFullscreenMeshVao();

        /**
         * @brief �X�N���[���𕢂����b�V���̒��_���W��VBO���쐬����
         * @param fullscreen_mesh_vao �X�N���[���𕢂����b�V����VAO��ID
         * @return �쐬����VBO��ID
         */
        static const GLuint CreateFullscreenMeshVerticesVbo(
            const GLuint fullscreen_mesh_vao);

        /**
         * @brief �X�N���[���𕢂����b�V����UV��VBO���쐬����
         * @param fullscreen_mesh_vao �X�N���[���𕢂����b�V����VAO��ID
         * @return �쐬����VBO��ID
         */
        static const GLuint CreateFullscreenMeshUvsVbo(
            const GLuint fullscreen_mesh_vao);

        /**
         * @brief ����̃��b�V����VAO���쐬����
         * @return �쐬����VAO��ID
         *
         * �쐬��������̃��b�V����Punctual Light�̕`��͈͂����߂�̂Ɏg���܂��B
         */
        static const GLuint CreateSphereMeshVao();

        /**
         * @brief ����̃��b�V����VBO���쐬����
         * @return �쐬����VBO��ID
         */
        static const GLuint CreateSphereMeshVbo(const GLuint sphere_mesh_vao);

        /**
         * @brief ����̃��b�V����IBO���쐬����
         * @return �쐬����IBO��ID
         */
        static const GLuint CreateSphereMeshIbo(const GLuint sphere_mesh_vao);

        /**
         * @brief GBuffer0�̃e�N�X�`�����쐬����
         * @param width �E�B���h�E�̕�
         * @param height �E�B���h�E�̍���
         * @return �쐬����GBuffer0�e�N�X�`����ID
         */
        static const GLuint CreateGBuffer0(const GLuint width, const GLuint height);

        /**
         * @brief GBuffer1�̃e�N�X�`�����쐬����
         * @param width �E�B���h�E�̕�
         * @param height �E�B���h�E�̍���
         * @return �쐬����GBuffer1�e�N�X�`����ID
         */
        static const GLuint CreateGBuffer1(const GLuint width, const GLuint height);

        /**
         * @brief GBuffer2�̃e�N�X�`�����쐬����
         * @param width �E�B���h�E�̕�
         * @param height �E�B���h�E�̍���
         * @return �쐬����GBuffer2�e�N�X�`����ID
         */
        static const GLuint CreateGBuffer2(const GLuint width, const GLuint height);

        /**
         * @brief GBuffer�̃f�v�X�e�N�X�`�����쐬����
         * @param width �E�B���h�E�̕�
         * @param height �E�B���h�E�̍���
         * @return �쐬����GBuffer�̃f�v�X�e�N�X�`����ID
         */
        static const GLuint CreateGBufferDepth(const GLuint width,
            const GLuint height);

        /**
         * @brief GBuffer��FBO���쐬����
         * @param gbuffer0 GBuffer0�̃e�N�X�`��ID
         * @param gbuffer1 GBuffer1�̃e�N�X�`��ID
         * @param gbuffer2 GBuffer2�̃e�N�X�`��ID
         * @param gbuffer_depth GBuffer Depth�̃e�N�X�`��ID
         * @return �쐬����FBO��ID
         */
        static const GLuint CreateGBufferFbo(const GLuint gbuffer0,
            const GLuint gbuffer1,
            const GLuint gbuffer2,
            const GLuint gbuffer_depth);

        /**
         * @brief HDR�J���[�o�b�t�@�̃e�N�X�`�����쐬����
         * @return �쐬����HDR�J���[�o�b�t�@�̃e�N�X�`����ID
         */
        static const GLuint CreateHdrColorBuffer(const GLuint width,
            const GLuint height);

        /**
         * @brief HDR�o�b�t�@�̃f�v�X�o�b�t�@�e�N�X�`�����쐬����
         * @return �쐬����HDR�f�v�X�o�b�t�@�e�N�X�`����ID
         */
        static const GLuint CreateHdrDepthBuffer(const GLuint width,
            const GLuint height);

        /**
         * @brief HDR�o�b�t�@��FBO���쐬����
         * @return �쐬����HDR�o�b�t�@��FBO��ID
         */
        static const GLuint CreateHdrFbo(const GLuint hdr_color_buffer,
            const GLuint hdr_depth_buffer);

        /**
         * @brief exposured�J���[�o�b�t�@�̃e�N�X�`�����쐬����
         * @return �쐬����exposured�J���[�o�b�t�@�̃e�N�X�`����ID
         */
        static const GLuint CreateExposuredColorBuffer(const GLuint width,
            const GLuint height);

        /**
         * @brief exposured�J���[�o�b�t�@��FBO���쐬����
         * @param exposured_color_buffer �o�b�t�@�̃e�N�X�`����ID
         * @return �쐬����exposured�J���[�o�b�t�@��FBO��ID
         */
        static const GLuint CreateExposuredFbo(const GLuint exposured_color_buffer);
    };

}  // namespace game

#endif  // OPENGL_PBR_MAP_SCENE_RENDERER_H_