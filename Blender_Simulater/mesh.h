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
     * @brief Meshを表現するクラス
     *
     * 多重開放を避けるためコピー禁止です。
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
         * @brief VAOをバインドし描画する
         */
        void Draw() const;

        /**
         * @brief コンストラクタ
         * @param vertices 頂点位置の列
         * @param normals 頂点法線の列
         * @param uvs UV座標の列
         *
         * ジオメトリを構築し、VBOとVAOを構築します。
         * 各種頂点情報は前から順に3つずつで一つの面を構成していきます。
         */
        Mesh(const std::vector<glm::vec3>& vertices,
            const std::vector<glm::vec3>& normals,
            const std::vector<glm::vec2>& uvs);

        /**
         * @brief デストラクタ
         *
         * VBOとVAOを開放します。
         */
        ~Mesh();

        // コピー禁止
        Mesh(const Mesh&) = delete;
        Mesh& operator=(const Mesh&) = delete;

        /**
         * @brief ムーブコンストラクタ
         * @param other ムーブ元
         *
         * ムーブ後はVAO及びVBOは0に設定されます。
         */
        Mesh(Mesh&& other) noexcept;

        /**
         * @brief ムーブ代入演算子
         * @param other ムーブ元
         *
         * ムーブ後はVAO及びVBOは0に設定されます。
         */
        Mesh& operator=(Mesh&& other) noexcept;

        /**
         * @brief objを読み込む静的メンバ関数
         * @param file 読み込むobjファイルのパス
         * @return 読み込んだMesh
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
         * @brief OpenGLのオブジェクトを開放する
         *
         * コンストラクタで確保したVAOとVBOを開放します。
         */
        void Release();

        /**
         * @brief Tangentsを計算する
         * @param vertices 頂点座標
         * @param uvs UV
         * @return 計算されたタンジェント
         *
         * verticesとuvsからテクスチャ座標系でのタンジェントを計算し返します。
         * vertices、uvs及び返り値のtangentsは、前から順に3頂点で一つの面を構成します。
         */
        const std::vector<glm::vec3> CalculateTangents(
            const std::vector<glm::vec3>& vertices,
            const std::vector<glm::vec2>& uvs);

        /**
         * @brief 文字列を指定した区切り文字で分割する静的メンバ関数
         * @param s 分割する文字列
         * @param delim 分割に使う区切り文字
         * @return 分割された文字列
         */
        static std::vector<std::string> SplitString(const std::string& s, char delim);
    };

}  // namespace game

#endif  // OPENGL_PBR_MAP_MESH_H_