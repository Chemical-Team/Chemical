﻿/**
 * @file	RestartButton.cpp
 * @brief	リスタートボタンクラス実装
 * @author	morimoto
 */

//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "RestartButton.h"

#include "DirectX11\TextureManager\Dx11TextureManager.h"
#include "..\..\..\ResultDefine.h"


namespace Result
{
	//----------------------------------------------------------------------
	// Constructor	Destructor
	//----------------------------------------------------------------------
	RestartButton::RestartButton() :
		m_IsSelect(false)
	{
		m_Pos = D3DXVECTOR2(430, 866);
		m_Size = D3DXVECTOR2(360, 74);
	}

	RestartButton::~RestartButton()
	{
	}


	//----------------------------------------------------------------------
	// Public Functions
	//----------------------------------------------------------------------
	bool RestartButton::Initialize()
	{
		m_pUpdateTask->SetName("RestartButton");
		m_pDrawTask->SetName("RestartButton");

		m_pDrawTask->SetPriority(RESULT_DRAW_BUTTON);

		SINGLETON_INSTANCE(Lib::UpdateTaskManager)->AddTask(m_pUpdateTask);
		SINGLETON_INSTANCE(Lib::Draw2DTaskManager)->AddTask(m_pDrawTask);

		if (!CreateVertex2D()) return false;

		if (!SINGLETON_INSTANCE(Lib::Dx11::TextureManager)->LoadTexture(
			"Resource\\ResultScene\\Texture\\RestartButton.png",
			&m_TextureIndex))
		{
			return false;
		}

		return true;
	}

	void RestartButton::Finalize()
	{
		SINGLETON_INSTANCE(Lib::Dx11::TextureManager)->ReleaseTexture(m_TextureIndex);

		ReleaseVertex2D();

		SINGLETON_INSTANCE(Lib::Draw2DTaskManager)->RemoveTask(m_pDrawTask);
		SINGLETON_INSTANCE(Lib::UpdateTaskManager)->RemoveTask(m_pUpdateTask);
	}

	void RestartButton::Update()
	{
	}

	void RestartButton::Draw()
	{
		if (!m_IsSelect) return;

		m_pVertex->ShaderSetup();
		m_pVertex->WriteConstantBuffer(&m_Pos);
		m_pVertex->SetTexture(
			SINGLETON_INSTANCE(Lib::Dx11::TextureManager)->GetTexture(m_TextureIndex));
		m_pVertex->Draw();
	}
}
