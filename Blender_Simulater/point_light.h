#ifndef OPENGL_PBR_MAP_POINT_LIGHT_H_
#define OPENGL_PBR_MAP_POINT_LIGHT_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/ext.hpp>
#include <glm/glm.hpp>

namespace game {

    /**
     * @brief �|�C���g���C�g��\������I�u�W�F�N�g
     *
     * �|�C���g���C�g�̊e��v���p�e�B��ێ����A�e�s��������N���X�ł��B
     */
    class PointLight {
    public:
        /**
         * @brief �|�C���g���C�g�̈ʒu���擾����
         * @return �|�C���g���C�g�̈ʒu
         */
        const glm::vec3 GetPosition() const;

        /**
         * @brief �|�C���g���C�g�̈ʒu��ݒ肷��
         * @param position �|�C���g���C�g�̐V�����ʒu
         *
         * �����ŕێ�����e�s���Model�s��̍Čv�Z���s���܂��B
         */
        void SetPosition(const glm::vec3 position);

        /**
         * @brief �|�C���g���C�g�̋������擾����
         * @return �|�C���g���C�g�̋����ilm�j
         *
         * �|�C���g���C�g�̋�����lm�i���[�����j�ŕ\�����܂��B
         */
        const GLfloat GetIntensity() const;

        /**
         * @brief �|�C���g���C�g�̋�����ݒ肷��
         * @param intensity �|�C���g���C�g�̐V��������
         *
         * �|�C���g���C�g�̋�����lm�i���[�����j�ŕ\�����܂��B
         */
        void SetIntensity(const GLfloat intensity);

        /**
         * @brief �|�C���g���C�g�̐F���擾����
         * @return �|�C���g���C�g�̐F
         */
        const glm::vec3 GetColor() const;

        /**
         * @brief �|�C���g���C�g�̐F��ݒ肷��
         * @param color �|�C���g���C�g�̐V�����F
         */
        void SetColor(const glm::vec3 color);

        /**
         * @brief �|�C���g���C�g�̉e��near���擾����
         * @return �|�C���g���C�g�̉e��near�̒l
         */
        const GLfloat GetNear() const;

        /**
         * @brief �|�C���g���C�g�̉e��near�̒l��ݒ肷��
         * @param near �|�C���g���C�g�̉e�̐V����near�̒l
         *
         * �����ŕێ�����e�s��̍Čv�Z���s���܂��B
         */
        void SetNear(const GLfloat near);

        /**
         * @brief �|�C���g���C�g��Range���擾����
         * @return �|�C���g���C�g��Range�im�j
         */
        const GLfloat GetRange() const;

        /**
         * @brief �|�C���g���C�g��Range��ݒ肷��
         * @param range �|�C���g���C�g�̐V����Range�im�j
         */
        void SetRange(const GLfloat range);

        /**
         * @brief �|�C���g���C�g��Shadow Bias���擾����
         * @return �|�C���g���C�g��Shadow Bias
         */
        const GLfloat GetShadowBias() const;

        /**
         * @brief �|�C���g���C�g��Shadow Bias��ݒ肷��
         * @param shadow_bias �|�C���g���C�g�̐V����Shadow Bias
         */
        void SetShadowBias(const GLfloat shadow_bias);

        /**
         * @brief �|�C���g���C�g���e�𗘗p���邩�ǂ������擾����
         * @return �|�C���g���C�g���e�𗘗p���邩�ǂ���
         */
        const bool GetUseShadow() const;

        /**
         * @brief �|�C���g���C�g���e�𗘗p���邩�ǂ�����ݒ肷��
         * @param use_shadow �|�C���g���C�g���e�𗘗p���邩�ǂ���
         */

        void SetUseShadow(const bool use_shadow);

        /**
         * @brief �|�C���g���C�g�̉e�s��̗��Ԃ�
         * @param[out] light_view_projection_matrices �|�C���g���C�g�̉e�s��
         *
         * �e�s��̗��PosX�ANegX�APosY�ANegY�APosZ�ANegZ�̏��ł��B
         */
        void GetLightViewProjectionMatrices(
            glm::mat4 light_view_projection_matrices[6]) const;

        /**
         * @brief �|�C���g���C�g��Model�s����擾����
         * @return �|�C���g���C�g��Model�s��
         *
         * range_ + 0.1f�̊g����܂݂܂��B
         */
        const glm::mat4 GetModelMatrix() const;

        /**
         * @brief �R���X�g���N�^
         * @param position �|�C���g���C�g�̈ʒu
         * @param intensity �|�C���g���C�g�̋����ilx�j
         * @param color �|�C���g���C�g�̐F
         * @param near �|�C���g���C�g�̉e��near�̒l
         * @param range �|�C���g���C�g��Range�im�j
         * @param shadow_bias �|�C���g���C�g��Shadow Bias
         * @param use_shadow �|�C���g���C�g���e�𗘗p���邩�ǂ���
         */
        PointLight(const glm::vec3 position, const GLfloat intensity,
            const glm::vec3 color, const GLfloat near, const GLfloat range,
            const GLfloat shadow_bias, const bool use_shadow);

    private:
        glm::vec3 position_;
        GLfloat intensity_;
        glm::vec3 color_;
        GLfloat near_;
        GLfloat range_;
        GLfloat shadow_bias_;
        bool use_shadow_;
        glm::mat4 light_view_projection_matrices_[6];
        glm::mat4 model_matrix_;

        /**
         * @brief �e�s��̗���Čv�Z����
         *
         * position_�Arange_����shadow_matrices_���Čv�Z���܂��B
         */
        void RecaluculateLightViewProjectionMatrices();

        /**
         * @brief Model�s����Čv�Z����
         *
         * position_����model_matrix_���Čv�Z���܂��B
         */
        void RecaluculateModelMatrix();
    };

}  // namespace game

#endif  // OPENGL_PBR_MAP_POINT_LIGHT_H_