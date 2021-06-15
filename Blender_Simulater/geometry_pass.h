#ifndef OPENGL_PBR_MAP_GEOMETRY_PASS_H_
#define OPENGL_PBR_MAP_GEOMETRY_PASS_H_

#include <glm/ext.hpp>
#include <glm/glm.hpp>

#include "create_program.h"
#include "scene.h"

namespace game {

	class GeometryPass {
	public:
		/**
		 * @brief ���̃p�X�������_�����O����
		 * @param scene �����_�����O����V�[��
		 */
		void Render(const Scene& sccene);

		/**
		 * @brief �R���X�g���N�^
		 * @param gbuffer_fbo GBuffer��FBO
		 */
		GeometryPass(const GLuint gbuffer_fbo);

		/**
		 * @brief �f�X�g���N�^
		 *
		 * �R���X�g���N�^�Ŋm�ۂ����V�F�[�_�v���O�������J�����܂��B
		 */
		~GeometryPass();

	private:
		const GLuint gbuffer_fbo_;

		const GLuint shader_program_;

		const GLuint model_loc_;
		const GLuint model_it_loc_;
		const GLuint view_loc_;
		const GLuint projection_loc_;
		const GLuint projection_params_loc_;
		const GLuint emissive_intensity_loc_;
	};

}  // namespace game

#endif  // OPENGL_PBR_MAP_GEOMETRY_PASS_H_