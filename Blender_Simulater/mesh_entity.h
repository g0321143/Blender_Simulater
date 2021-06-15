#ifndef OPENGL_PBR_MAP_MESH_ENTITY_H_
#define OPENGL_PBR_MAP_MESH_ENTITY_H_

#include <glm/glm.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <limits>
#include <memory>

#include "material.h"
#include "mesh.h"

namespace game {

    /**
     * @brief Mesh��Model�s���ێ�����N���X
     */
    class MeshEntity {
    public:
        const std::shared_ptr<const Mesh> mesh_;
        const std::shared_ptr<const Material> material_;
        float x_max_;
        float y_max_;
        float z_max_;
        float x_min_;
        float y_min_;
        float z_min_;

        /**
         * @brief �V�[����̈ʒu��Ԃ�
         * @return �V�[����̈ʒu
         */
        const glm::vec3 GetPosition() const;

        /**
         * @brief �V�[����̈ʒu��ݒ肷��
         * @param position �V�����ʒu
         *
         * �����ŕێ�����Model�s��̍Čv�Z���s���܂��B
         */
        void SetPosition(const glm::vec3 position);

        /**
         * @brief ����Entity�̉�]�̃I�C���[�p���擾����
         * @return ����Entity�̉�]�̃I�C���[�p
         *
         * �I�C���[�p��YXZ�̏��ł��B
         */
        const glm::vec3 GetRotation() const;

        /**
         * @brief ����Entity�̉�]�̃I�C���[�p��ݒ肷��
         * @param rotation �V������]�̃I�C���[�p
         *
         * �I�C���[�p��YXZ�̏��ł��B
         * �����ŕێ�����Model�s��̍Čv�Z���s���܂��B
         */
        void SetRotation(const glm::vec3 rotation);

        /**
         * @brief ����Entity�̃X�P�[�����擾����
         * @return ����Entity�̃X�P�[��
         */
        const glm::vec3 GetScale() const;

        /**
         * @brief ����Entity�̃X�P�[����ݒ肷��
         * @param scale �V�����X�P�[��
         *
         * �����ŕێ�����Model�s��̍Čv�Z���s���܂��B
         */
        void SetScale(const glm::vec3 scale);

        /**
         * @brief Model�s����擾����
         * @return Model�s��
         */
        const glm::mat4 GetModelMatrix() const;

        /**
         * @brief AABB�Ƌ��̂̓����蔻����v�Z����
         * @return hit���Ă����true�A�����łȂ����false
         */
        bool TestSphereAABB(const glm::vec3 center, const GLfloat radius) const;

        /**
         * @brief �R���X�g���N�^
         * @param mesh Mesh��shared_ptr
         * @param material Material��shared_ptr
         * @param position Entity�̈ʒu
         * @param rotation Entity�̉�]�̃I�C���[�p
         * @param scale Entity�̊e���̃X�P�[��
         *
         * �I�C���[�p��YXZ�̏��ł��B
         */
        MeshEntity(const std::shared_ptr<const Mesh> mesh,
            const std::shared_ptr<const Material> material,
            const glm::vec3 position, const glm::vec3 rotation,
            const glm::vec3 scale);

    private:
        glm::vec3 position_;
        glm::vec3 rotation_;
        glm::vec3 scale_;
        glm::mat4 model_matrix_;

        /**
         * @brief Model�s����Čv�Z����
         */
        void RecaluculateModelMatrix();

        /**
         * @brief AABB���Čv�Z����
         */
        void RecaluculateAABB();
    };

}  // namespace game

#endif  // OPENGL_PBR_MAP_MESH_ENTITY_H_