#ifndef OPENGL_PBR_MAP_MATERIAL_H_
#define OPENGL_PBR_MAP_MATERIAL_H_

#include "texture.h"

namespace game {

    /**
     * @brief �}�e���A����\������I�u�W�F�N�g
     *
     * PBR�}�e���A���ɕK�v�Ȋe��e�N�X�`����Emissive�̋�����ێ����܂��B
     */
    class Material {
    public:
        const Texture albedo_map_;
        const Texture metallic_map_;
        const Texture roughness_map_;
        const Texture normal_map_;
        const Texture emissive_map_;
        const GLfloat emissive_intensity_;

        /**
         * @brief �R���X�g���N�^
         * @param albedo_map �A���x�h�e�N�X�`��
         * @param metallic_map ���^���b�N�e�N�X�`��
         * @param roughnness_map ���t�l�X�e�N�X�`��
         * @param normal_map �m�[�}���}�b�v�e�N�X�`��
         * @param emissive_map �G�~�b�V�u�e�N�X�`��
         * @param emissive_intensity �G�~�b�V�u�̋���
         *
         * �e��e�N�X�`����Emissive�̋������w�肵�ăC���X�^���X���쐬���܂��B
         */
        Material(Texture&& albedo_map, Texture&& metallic_map,
            Texture&& roughness_map, Texture&& normal_map,
            Texture&& emissive_map, const GLfloat emissive_intensity);
    };

}  // namespace game

#endif  // OPENGL_PBR_MAP_MATERIAL_H_