#ifndef OPENGL_PBR_MAP_MESH_H_
#define OPENGL_PBR_MAP_MESH_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <glm/glm.hpp>
#include <iostream>
#include <limits>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

namespace game {

    /**
     * @brief Mesh��\������N���X
     *
     * ���d�J��������邽�߃R�s�[�֎~�ł��B
     */
    class Mesh {
    public:
        float x_max_;
        float y_max_;
        float z_max_;
        float x_min_;
        float y_min_;
        float z_min_;

        /**
         * @brief VAO���o�C���h���`�悷��
         */
        void Draw() const;

        /**
         * @brief �R���X�g���N�^
         * @param vertices ���_�ʒu�̗�
         * @param normals ���_�@���̗�
         * @param uvs UV���W�̗�
         *
         * �W�I���g�����\�z���AVBO��VAO���\�z���܂��B
         * �e�풸�_���͑O���珇��3���ň�̖ʂ��\�����Ă����܂��B
         */
        Mesh(const std::vector<glm::vec3>& vertices,
            const std::vector<glm::vec3>& normals,
            const std::vector<glm::vec2>& uvs);

        /**
         * @brief �f�X�g���N�^
         *
         * VBO��VAO���J�����܂��B
         */
        ~Mesh();

        // �R�s�[�֎~
        Mesh(const Mesh&) = delete;
        Mesh& operator=(const Mesh&) = delete;

        /**
         * @brief ���[�u�R���X�g���N�^
         * @param other ���[�u��
         *
         * ���[�u���VAO�y��VBO��0�ɐݒ肳��܂��B
         */
        Mesh(Mesh&& other) noexcept;

        /**
         * @brief ���[�u������Z�q
         * @param other ���[�u��
         *
         * ���[�u���VAO�y��VBO��0�ɐݒ肳��܂��B
         */
        Mesh& operator=(Mesh&& other) noexcept;

        /**
         * @brief obj��ǂݍ��ސÓI�����o�֐�
         * @param file �ǂݍ���obj�t�@�C���̃p�X
         * @return �ǂݍ���Mesh
         */
        static std::shared_ptr<Mesh> LoadObjMesh(const std::string file);

    private:
        GLuint size_;
        GLuint vertices_vbo_;
        GLuint normals_vbo_;
        GLuint uvs_vbo_;
        GLuint tangents_vbo_;
        GLuint vao_;

        /**
         * @brief OpenGL�̃I�u�W�F�N�g���J������
         *
         * �R���X�g���N�^�Ŋm�ۂ���VAO��VBO���J�����܂��B
         */
        void Release();

        /**
         * @brief Tangents���v�Z����
         * @param vertices ���_���W
         * @param uvs UV
         * @return �v�Z���ꂽ�^���W�F���g
         *
         * vertices��uvs����e�N�X�`�����W�n�ł̃^���W�F���g���v�Z���Ԃ��܂��B
         * vertices�Auvs�y�ѕԂ�l��tangents�́A�O���珇��3���_�ň�̖ʂ��\�����܂��B
         */
        const std::vector<glm::vec3> CalculateTangents(
            const std::vector<glm::vec3>& vertices,
            const std::vector<glm::vec2>& uvs);

        /**
         * @brief ��������w�肵����؂蕶���ŕ�������ÓI�����o�֐�
         * @param s �������镶����
         * @param delim �����Ɏg����؂蕶��
         * @return �������ꂽ������
         */
        static std::vector<std::string> SplitString(const std::string& s, char delim);
    };

}  // namespace game

#endif  // OPENGL_PBR_MAP_MESH_H_