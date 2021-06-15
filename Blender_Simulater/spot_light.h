#ifndef OPENGL_PBR_MAP_SPOT_LIGHT_H_
#define OPENGL_PBR_MAP_SPOT_LIGHT_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/ext.hpp>
#include <glm/glm.hpp>

namespace game {

    /**
     * @brief �X�|�b�g���C�g��\������I�u�W�F�N�g
     */
    class SpotLight {
    public:
        /**
         * @brief �X�|�b�g���C�g�̈ʒu���擾����
         * @return �X�|�b�g���C�g�̈ʒu
         */
        const glm::vec3 GetPosition() const;

        /**
         * @brief �X�|�b�g���C�g�̈ʒu��ݒ肷��
         * @param position �X�|�b�g���C�g�̐V�����ʒu
         *
         * �����ŕێ�����e�s���Model�s��̍Čv�Z���s���܂��B
         */
        void SetPosition(const glm::vec3 position);

        /**
         * @brief �X�|�b�g���C�g�̋������擾����
         * @return �X�|�b�g���C�g�̋����ilm�j
         *
         * �X�|�b�g���C�g�̋�����lm�i���[�����j�ŕ\�����܂��B
         */
        const GLfloat GetIntensity() const;

        /**
         * @brief �X�|�b�g���C�g�̋�����ݒ肷��
         * @param intensity �X�|�b�g���C�g�̐V��������
         *
         * �X�|�b�g���C�g�̋�����lm�i���[�����j�ŕ\�����܂��B
         */
        void SetIntensity(const GLfloat intensity);

        /**
         * @brief �X�|�b�g���C�g�̐F���擾����
         * @return �X�|�b�g���C�g�̐F
         */
        const glm::vec3 GetColor() const;

        /**
         * @brief �X�|�b�g���C�g�̐F��ݒ肷��
         * @param color �X�|�b�g���C�g�̐V�����F
         */
        void SetColor(const glm::vec3 color);

        /**
         * @brief �X�|�b�g���C�g�̉e��near���擾����
         * @return �X�|�b�g���C�g�̉e��near�̒l
         */
        const GLfloat GetNear() const;

        /**
         * @brief �X�|�b�g���C�g�̉e��near�̒l��ݒ肷��
         * @param near �X�|�b�g���C�g�̉e�̐V����near�̒l
         *
         * �����ŕێ�����e�s��̍Čv�Z���s���܂��B
         */
        void SetNear(const GLfloat near);

        /**
         * @brief �X�|�b�g���C�g��Range���擾����
         * @return �X�|�b�g���C�g��Range�im�j
         */
        const GLfloat GetRange() const;

        /**
         * @brief �X�|�b�g���C�g��Range��ݒ肷��
         * @param range �X�|�b�g���C�g�̐V����Range�im�j
         *
         * �����ŕێ�����e�s���Model�s��̍Čv�Z���s���܂��B
         */
        void SetRange(const GLfloat range);

        /**
         * @brief �X�|�b�g���C�g�̌������擾����
         * @return �X�|�b�g���C�g�̌����̃x�N�g��
         *
         * ���K�����ꂽ�����x�N�g����Ԃ��܂��B
         */
        const glm::vec3 GetDirection() const;

        /**
         * @brief �X�|�b�g���C�g�̌�����ݒ肷��
         * @param direction �V�����X�|�b�g���C�g�̌����̃x�N�g��
         *
         * �n���ꂽ�x�N�g���͐��K������ێ�����܂��B
         * �����ŕێ�����e�s����Čv�Z���܂��B
         */
        void SetDirection(const glm::vec3 direction);

        /**
         * @brief �X�|�b�g���C�g��Angle���擾����
         * return �X�|�b�g���C�g��Angle�iradians�j
         */
        const GLfloat GetAngle() const;

        /**
         * @brief �X�|�b�g���C�g��Angle��ݒ肷��
         * @param angle �X�|�b�g���C�g��Angle�iradians�j
         *
         * �����ŕێ�����e�s����Čv�Z���܂��B
         */
        void SetAngle(const GLfloat angle);

        /**
         * @brief �X�|�b�g���C�g�̔��e�̊������擾����
         * @return �X�|�b�g���C�g�̔��e�̊����i[0,1]�j
         *
         * �X�|�b�g���C�g�̔��e�Ɩ{�e�̃u�����h�����擾���܂��B
         * 0�Ŗ{�e�̂݁A1�Ŕ��e�݂̂ƂȂ�܂��B
         */
        const GLfloat GetBlend() const;

        /**
         * @brief �X�|�b�g���C�g�̔��e�̊�����ݒ肷��
         * @param blend �X�|�b�g���C�g�̔��e�̊����i[0,1]�j
         *
         * �X�|�b�g���C�g�̔��e�Ɩ{�e�̃u�����h�����擾���܂��B
         * 0�Ŗ{�e�̂݁A1�Ŕ��e�݂̂ƂȂ�܂��B
         */
        void SetBlend(const GLfloat blend);

        /**
         * @brief �e�s����擾����
         * @return �e�s��
         */
        const glm::mat4 GetLightViewProjectionMatrix() const;

        /**
         * @brief Model�s����擾����
         * @return Model�s��
         *
         * range_ + 0.1f�̊g����܂݂܂��B
         */
        const glm::mat4 GetModelMatrix() const;

        /**
         * @brief �R���X�g���N�^
         * @param position �X�|�b�g���C�g�̈ʒu
         * @param intensity �X�|�b�g���C�g�̋����ilm�j
         * @param color �X�|�b�g���C�g�̐F
         * @param near �X�|�b�g���C�g�̉e��near�̒l
         * @param range �X�|�b�g���C�g��Range�̒l
         * @param direction �X�|�b�g���C�g�̌����̃x�N�g��
         * @param angle �X�|�b�g���C�g��Angle�iradians�j
         * @param blend �X�|�b�g���C�g�̔��e�̊����i[0,1]�j
         */
        SpotLight(const glm::vec3 position, const GLfloat intensity,
            const glm::vec3 color, const GLfloat near, const GLfloat range,
            const glm::vec3 direction, const GLfloat angle,
            const GLfloat blend);

    private:
        glm::vec3 position_;
        GLfloat intensity_;
        glm::vec3 color_;
        GLfloat near_;
        GLfloat range_;
        glm::vec3 direction_;
        GLfloat angle_;
        GLfloat blend_;
        glm::mat4 light_view_projection_matrix_;
        glm::mat4 model_matrix_;

        /**
         * @brief �e�s����Čv�Z����
         *
         * position_�Adirection_�Arange_�Aangle_����
         * light_view_projection_matrix_���Čv�Z���܂��B
         */
        void RecaluculateLightViewProjectionMatrix();

        /**
         * @brief Model�s����Čv�Z����
         *
         * position_����model_matrix_���Čv�Z���܂��B
         */
        void RecaluculateModelMatrix();
    };

}  // namespace game

#endif  // OPENGL_PBR_MAP_SPOT_LIGHT_H_