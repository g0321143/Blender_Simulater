#ifndef OPENGL_PBR_MAP_SCENE_H_
#define OPENGL_PBR_MAP_SCENE_H_

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/string_cast.hpp>
#include <limits>
#include <memory>
#include <unordered_map>
#include <vector>

#include "camera.h"
#include "directional_light.h"
#include "mesh.h"
#include "mesh_entity.h"
#include "point_light.h"
#include "spot_light.h"

namespace game {

    class Scene {
    public:
        std::unique_ptr<Camera> camera_;
        std::vector<MeshEntity> mesh_entities_;
        std::unique_ptr<DirectionalLight> directional_light_;
        std::vector<PointLight> point_lights_;
        std::vector<SpotLight> spot_lights_;

        /**
         * @brief �e�{�����[�����Čv�Z����
         */
        void RecaluculateDirectionalShadowVolume();

        /**
         * @brief �^����ꂽ�p�X�̃V�[����ǂݍ���
         * @param path �V�[���f�B���N�g���̃p�X
         * @param width ��ʂ̉���
         * @param height ��ʂ̏c
         * @return ���[�h���ꂽ�V�[��
         *
         * �V�[���f�B���N�g���̃p�X�͍Ō��`/`���܂݂܂���B
         */
        static std::unique_ptr<Scene> LoadScene(const std::string path,
            const GLuint width,
            const GLuint height);

    private:
        /**
         * @brief �������^����ꂽ�����ŕ�������
         * @param s �������镶����
         * @param delim �����Ɏg������
         * @return �������ꂽ�������vector
         */
        static std::vector<std::string> SplitString(const std::string& s, char delim);

        /**
         * @brief Mesh���p�[�X����
         * @param mesh_texts �V�[���t�@�C����1��Mesh�����̍s���Ƃɕ������ꂽ������
         * @return �p�[�X���ꂽ���b�V��
         */
        static std::shared_ptr<Mesh> ParseMesh(
            const std::vector<std::string>& mesh_texts);
        /**
         * @brief Material���p�[�X���ǂݍ���
         * @path �V�[���f�B���N�g���̃p�X
         * @param material_texts
         * �V�[���t�@�C���̈��Material�̍s���Ƃɕ������ꂽ������
         * @return �p�[�X����ēǂݍ��܂ꂽMaterial
         */
        static std::shared_ptr<Material> ParseMaterial(
            const std::string& path, const std::vector<std::string>& material_texts);
    };

}  // namespace game

#endif  // OPENGL_PBR_MAP_SCENE_H_