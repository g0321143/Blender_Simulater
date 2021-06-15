#ifndef OPENGL_PBR_MAP_TEXTURE_H_
#define OPENGL_PBR_MAP_TEXTURE_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

namespace game {

	/**
	 * @brief Texture��\������I�u�W�F�N�g
	 *
	 * OpenGL��Texture�𐶐���ID���Ǘ����܂��B
	 * �e�N�X�`���̑��d�J��������邽�߃R�s�[�֎~�ł��B
	 * ���[�u�͉\�ł��B
	 * �e�N�X�`���̓ǂݍ��݂ɂ�stb��stb_image.h�𗘗p���Ă��܂��B
	 * https://github.com/nothings/stb
	 */
	class Texture {
	public:
		/**
		 * @brief �e�N�X�`���̕����擾
		 * @return �e�N�X�`���̕�
		 */
		const int GetWidth() const;

		/**
		 * @brief �e�N�X�`���̍������擾
		 * @return �e�N�X�`���̍���
		 */
		const int GetHeight() const;

		/**
		 * @brief �e�N�X�`���̃`�����l�������擾
		 * @return �e�N�X�`���̃`�����l����
		 */
		const int GetChannel() const;

		/**
		 * @brief �e�N�X�`��ID���擾
		 * @return �e�N�X�`��ID
		 */
		const GLuint GetTextureId() const;

		/**
		 * @brief �f�t�H���g�R���X�g���N�^
		 *
		 * �����t�@�C����ǂݍ��܂Ȃ���̃e�N�X�`���ƂȂ�܂��B
		 * texture_id_��0�ŏ���������܂��B
		 */
		Texture();

		/**
		 * @brief �R���X�g���N�^
		 * @param path �e�N�X�`���̃p�X
		 * @param sRGB sRGB�Ȃ��true�ALinear�Ȃ��false
		 */
		Texture(const std::string& path, const bool sRGB);

		/**
		 * @brief �f�X�g���N�^
		 *
		 * texture_id_�̃e�N�X�`�����J�����܂��B
		 */
		~Texture();

		// �R�s�[�֎~
		Texture(const Texture&) = delete;
		Texture& operator=(const Texture&) = delete;

		/**
		 * @brief ���[�u�R���X�g���N�^
		 * @param other ���[�u��
		 *
		 * ���[�u���texture_id_��0�ɏ���������܂��B
		 */
		Texture(Texture&& other) noexcept;

		/**
		 * @brief ���[�u������Z�q
		 * @param other ���[�u��
		 *
		 * ���[�u���texture_id_��0�ɏ���������܂��B
		 */
		Texture& operator=(Texture&& other) noexcept;

	private:
		int width_;
		int height_;
		int channel_;
		GLuint texture_id_;
	};

}  // namespace game

#endif  // OPENGL_PBR_MAP_TEXTURE_H_