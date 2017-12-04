/**
 * @file	MultipleVertex2DUV.h
 * @brief	�����̋�`�`��N���X��`
 * @author	morimoto
 */
#ifndef LIB_MULTIPLEVERTEX2DUV_H
#define LIB_MULTIPLEVERTEX2DUV_H

//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include <D3DX11.h>
#include <D3DX10.h>

#include "..\GraphicsDevice\Dx11GraphicsDevice.h"
#include "..\TextureManager\ITexture\Dx11ITexture.h"


namespace Lib
{
	namespace Dx11
	{
		/*** �����̋�`�`��N���X */
		class MultipleVertex2DUV
		{
		public:
			/*** �R���X�g���N�^ */
			MultipleVertex2DUV();

			/*** �f�X�g���N�^ */
			~MultipleVertex2DUV();

			/**
			 * ����������
			 * @param[in] _pGraphicsDevice �O���t�B�b�N�f�o�C�X
			 * @return �������ɐ���������true ���s������false
			 */
			bool Initialize(GraphicsDevice* _pGraphicsDevice);

			/*** �I������ */
			void Finalize();

			/**
			 * ���_�o�b�t�@�̐���
			 * @param[in] _pSize �`�悷��2D�|���S���̋�`�T�C�Y
			 * @param[in] _pMinUV �e�N�X�`����Min���W
			 * @param[in] _pMaxUV �e�N�X�`����Max���W
			 * @param[in] _pColor ���_�F
			 * @return �����ɐ���������true ���s������false
			 */
			bool CreateVertexBuffer(
				const D3DXVECTOR2* _pSize,
				const D3DXVECTOR2* _pMinUV = &D3DXVECTOR2(0.f, 0.f),
				const D3DXVECTOR2* _pMaxUV = &D3DXVECTOR2(1.0f, 1.0f),
				const D3DXCOLOR* _pColor = &D3DXCOLOR(0xffffffff));

			/**
			 * �C���X�^���X�o�b�t�@�̐���
			 * @param[in] _pMat �C���X�^���X���Ƃ̕ϊ��s��
			 * @param[in] _pUV �C���X�^���X���Ƃ�UV
			 * @param[in] _instanceNum �C���X�^���X�̐�
			 * @return �����ɐ���������true ���s������false
			 */
			bool CreateInstanceBufferUV(D3DXMATRIX* _pMat, D3DXVECTOR2* _pUV, int _instanceNum);

			/*** ���_�o�b�t�@�̉�� */
			void ReleaseVertexBuffer();

			/*** �C���X�^���X�o�b�t�@�̉�� */
			void ReleaseInstanceBufferUV();

			/**
			 * �萔�o�b�t�@�Ƀf�[�^����������
			 * @return �������݂ɐ���������true ���s������false
			 */
			bool WriteConstantBuffer(D3DXVECTOR2 _pos = D3DXVECTOR2(0, 0));

			/**
			 * ���_�o�b�t�@�Ƀf�[�^����������
			 * @return �������݂ɐ���������true ���s������false
			 */
			bool WriteVertexBuffer();

			/**
			 * ��`��񂩂璸�_���W��ݒ肷��
			 * @param[in] _pSize �`�悷��2D�|���S���̋�`�T�C�Y
			 */
			void SetVertex(const D3DXVECTOR2* _pSize);

			/**
			 * �e�N�X�`�����W��ݒ肷��
			 * @param[in] _pMinUV UV�̍ŏ��l
			 * @param[in] _pMaxUV UV�̍ő�l
			 */
			void SetUV(const D3DXVECTOR2* _pMinUV, const D3DXVECTOR2* _pMaxUV);

			/**
			 * �J���[����ݒ肷��
			 * @param[in] _pColor �`�悷��|���S���̐F
			 */
			void SetColor(const D3DXCOLOR* _pColor);

			/**
			 * �C���X�^���X�o�b�t�@�Ƀf�[�^����������
			 * @param[in] _pDrawPos �`��ʒu
			 * @param[in] _pUV UV�l
			 * @return �������݂ɐ���������true ���s������false
			 */
			bool WriteInstanceBuffer(const D3DXVECTOR2* _pDrawPos, const D3DXVECTOR2* _pUV);

			/*** �f�t�H���g�̃V�F�[�_�[�̏��� */
			void ShaderSetup();

			/*** �e�N�X�`���̏��� */
			void TextureSetup();

			/*** �f�t�H���g�̐[�x�X�e���V���X�e�[�g����*/
			void DepthStencilStateSetup();

			/*** �f�t�H���g�̃u�����h�X�e�[�g����*/
			void BlendStateSetup();

			/**
			 * ������`�̃f�t�H���g�`�� 
			 * @param[in] _pDrawPos �`��ʒu
			 * @param[in] _pUV UV�l
			 * @param[in] _instanceNum �`��C���X�^���X��
			 */
			void DefaultDraw(const D3DXVECTOR2* _pDrawPos, const D3DXVECTOR2* _pUV, int _instanceNum = 0);

			/**
			 * ������`�̕`��(�|���S���̕`�揈���̂ݍs��) 
			 * @param[in] _instanceNum �`��C���X�^���X��
			 */
			void Draw(int _instanceNum = 0);

			/**
			 * �`�悷��e�N�X�`���̐ݒ�
			 * @param[in] _pTexture �e�N�X�`���I�u�W�F�N�g
			 */
			void SetTexture(ITexture* _pTexture) { m_pTexture = _pTexture; }

		private:
			enum
			{
				VERTEX_NUM = 4 //!< ���_��.
			};

			/*** 2D��`�`��p�̒��_�\���� */
			struct VERTEX
			{
				D3DXVECTOR3		Pos;	//!< ���_���W.
				D3DXVECTOR2		UV;		//!< �e�N�X�`�����W.
				D3DXCOLOR		Color;	//!< ���_�J���[�l.
			};

			/*** �C���X�^���X�ʃf�[�^�\���� */
			struct INSTANCE_DATA_UV
			{
				D3DXMATRIX Mat;		//!< �ϊ��s��.
				D3DXVECTOR4 UV;
			};

			/*** �V�F�[�_�[�Ŏg�p����萔�o�b�t�@ */
			struct CONSTANT_BUFFER
			{
				D3DXVECTOR4 WindowSize;		//!< �E�B���h�E�̏c���T�C�Y.
				D3DXVECTOR4 InstancePos;	//!< �C���X�^���X�S�̂ɉe��������W�l.
			};


			/**
			 * ���_�V�F�[�_�[�̏�����
			 * @return �������ɐ���������true ���s������false
			 */
			bool CreateVertexShader();

			/**
			 * ���_���̓��C�A�E�g�̏�����
			 * @return �������ɐ���������true ���s������false
			 */
			bool CreateVertexLayout();

			/**
			 * �s�N�Z���V�F�[�_�[�̏�����
			 * @return �������ɐ���������true ���s������false
			 */
			bool CreatePixelShader();

			/**
			 * �`��X�e�[�g�̏�����
			 * @return �������ɐ���������true ���s������false
			 */
			bool CreateState();

			/*** ���_�V�F�[�_�[�̉�� */
			void ReleaseVertexShader();

			/*** ���_���̓��C�A�E�g�̉�� */
			void ReleaseVertexLayout();

			/*** �s�N�Z���V�F�[�_�[�̉�� */
			void ReleasePixelShader();

			/*** �X�e�[�g�̉�� */
			void ReleaseState();

			GraphicsDevice*				m_pGraphicsDevice;			//!< �O���t�B�b�N�f�o�C�X.
			ID3D11VertexShader*			m_pVertexShader;			//!< ���_�V�F�[�_�[.
			ID3DBlob*					m_pVertexCompiledShader;	//!< ���_�V�F�[�_�[�̃R���p�C�����.
			ID3D11InputLayout*			m_pVertexLayout;			//!< ���_���̓��C�A�E�g.
			ID3D11PixelShader*			m_pPixelShader;				//!< �s�N�Z���V�F�[�_�[.
			ID3DBlob*					m_pPixelCompiledShader;		//!< �s�N�Z���V�F�[�_�[�̃R���p�C�����.
			ID3D11BlendState*			m_pBlendState;				//!< �u�����h�X�e�[�g.
			ID3D11SamplerState*			m_pSamplerState;			//!< �T���v���X�e�[�g.
			ID3D11DepthStencilState*	m_pDepthStencilState;		//!< �[�x�X�e���V���X�e�[�g.
			ID3D11DepthStencilState*	m_pUserDepthStencilState;	//!< ���[�U�[�w��̐[�x�X�e���V���X�e�[�g.
			ID3D11Buffer*				m_pVertexBuffer;			//!< ���_�o�b�t�@.
			ID3D11Buffer*				m_pConstantBuffer;			//!< �萔�o�b�t�@.
			ID3D11Buffer*				m_pInstanceBuffer;			//!< �C���X�^���V���O�o�b�t�@.
			ITexture*					m_pTexture;					//!< �e�N�X�`���C���^�[�t�F�[�X.
			VERTEX						m_pVertexData[VERTEX_NUM];	//!< ���_���\����.
			INSTANCE_DATA_UV*			m_pInstanceDataUV;			//!< �C���X�^���X�f�[�^.
			float						m_WindowWidth;				//!< �E�B���h�E�̕�.
			float						m_WindowHeight;				//!< �E�B���h�E�̍���.
			int							m_InstanceNum;				//!< �C���X�^���X�̐�.

		};
	}
}


#endif // !LIB_MULTIPLEVERTEX2DUV_H
