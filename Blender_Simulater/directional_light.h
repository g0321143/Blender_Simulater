#ifndef OPENGL_PBR_MAP_DIRECTIONAL_LIGHT_H_
#define OPENGL_PBR_MAP_DIRECTIONAL_LIGHT_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/ext.hpp>
#include <glm/glm.hpp>

namespace game {

    /**
     * @brief ���s������\������I�u�W�F�N�g
     *
     * ���s�����̊e��v���p�e�B��ێ����A�e�̌v�Z�p�̍s��������N���X�ł��B
     * Directional Light�̓V�[���Ɉ�̂݊܂܂�܂��B
     */
    class DirectionalLight {
    public:
        /**
         * @brief �����̋������擾����
         * @return �����̋����ilx�j
         *
         * ���s�����̋�����lx�i���N�X�j�ŕ\�����܂��B
         */
        const GLfloat GetIntensity() const;

        /**
         * @brief �����̋�����ݒ肷��
         * @param intensity �V���������̋����ilx�j
         *
         * ���s�����̋�����lx�i���N�X�j�ŕ\�����܂��B
         */
        void SetIntensity(const GLfloat intensity);

        /**
         * @brief ���s�����̌������擾����
         * @return ���s�����̌����̃x�N�g��
         *
         * ���K�����ꂽ�����x�N�g����Ԃ��܂��B
         */
        const glm::vec3 GetDirection() const;

        /**
         * @brief ���s�����̌�����ݒ肷��
         * @param direction �V�������s�����̌����̃x�N�g��
         *
         * �n���ꂽ�x�N�g���͐��K������ێ�����܂��B
         * �����ŕێ�����e�s����Čv�Z���܂��B
         */
        void SetDirection(const glm::vec3 direction);

        /**
         * @brief ���s�����̐F���擾����
         * @return ���s�����̐F
         */
        const glm::vec3 GetColor() const;

        /**
         * @brief ���s�����̐F��ݒ肷��
         * @param color �V�������s�����̐F
         */
        void SetColor(const glm::vec3 color);

        /**
         * @brief �e�{�����[����ݒ肷��
         * @param legt �e�{�����[����left�̒l
         * @param right �e�{�����[����right�̒l
         * @param bottom �e�{�����[����bottom�̒l
         * @param top �e�{�����[����top�̒l
         * @param near �e�{�����[����near�̒l
         * @param far �e�{�����[����far�̒l
         * @param light_view ���C�g�̃r���[�s��
         */
        void SetShadowVolume(const GLfloat left, const GLfloat right,
            const GLfloat bottom, const GLfloat top,
            const GLfloat near, const GLfloat far,
            const glm::mat4 light_view);

        /**
         * @brief �e�s����擾����
         * @return �e�s��
         */
        const glm::mat4 GetLightViewProjectionMatrix() const;

        /**
         * @brief �R���X�g���N�^
         * @param intensity �����̋����ilx�j
         * @param direction �����̌����x�N�g��
         * @param color �����̐F
         */
        DirectionalLight(const GLfloat intensity, const glm::vec3 direction,
            const glm::vec3 color);

    private:
        GLfloat intensity_;
        glm::vec3 direction_;
        glm::vec3 color_;
        glm::mat4 light_view_projection_matrix_;
    };

}  // namespace game

#endif  // OPENGL_PBR_MAP_DIRECTIONAL_LIGHT_H_