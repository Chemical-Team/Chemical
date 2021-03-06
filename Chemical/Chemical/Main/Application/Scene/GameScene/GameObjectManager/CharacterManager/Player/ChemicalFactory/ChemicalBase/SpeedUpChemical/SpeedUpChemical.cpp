﻿/**
 * @file   SpeedUpChemical.cpp
 * @brief  SpeedUpChemicalクラスの実装
 * @author kotani
 */
#include "SpeedUpChemical.h"
#include "..\..\ChemicalFactory.h"
#include "Application\Scene\GameScene\GameDefine.h"
#include "Application\Scene\GameScene\CollisionManager\CollisionManager.h"
#include "..\..\..\..\..\GameDataManager\GameDataManager.h"
#include "SpeedUpChemicalEvent\SpeedUpChemicalEvent.h"

#include "DirectX11\TextureManager\Dx11TextureManager.h"
#include "EventManager\EventManager.h"

namespace Game
{
	namespace
	{
		ChemicalBase* CreateMoveUpChemical(int _textureIndex)
		{
			ChemicalBase* pChemical = new SpeedUpChemical(_textureIndex);
			pChemical->Initialize();
			return pChemical;
		}

		const bool registered = ChemicalFactory::GetInstance().
			RegisterCreateFunc(
			ChemicalFactory::Types(CHEMICAL_RED, CHEMICAL_YELLOW),
			CreateMoveUpChemical);
	}


	//----------------------------------------------------------------------
	// Constructor	Destructor
	//----------------------------------------------------------------------

	SpeedUpChemical::SpeedUpChemical(int _textureIndex) :
		ChemicalBase(_textureIndex, CHEMICAL_SPEEDUP)
	{
		m_Size = D3DXVECTOR2(40,40);
	}

	SpeedUpChemical::~SpeedUpChemical()
	{
	}


	//----------------------------------------------------------------------
	// Public Functions
	//----------------------------------------------------------------------

	bool SpeedUpChemical::Initialize()
	{
		m_pSpeedUpChemicalEvent = new SpeedUpChemicalEvent(SPEEDUP_EVENT);
		return ChemicalBase::Initialize();
	}

	void SpeedUpChemical::Finalize()
	{
		ChemicalBase::Finalize();
		SafeDelete(m_pSpeedUpChemicalEvent);
	}

	void SpeedUpChemical::UpdateStartUp()
	{
		if (!m_IsSprinkle) return;

		if (!m_pCollision->GetHit()) return;

		m_IsSprinkle = false;
		m_pSpeedUpChemicalEvent->SetSpeedUpPos(m_Pos);
		m_pSpeedUpChemicalEvent->SetChemicalGrade(m_ChemicalData.Grade);

		SINGLETON_INSTANCE(Lib::Draw2DTaskManager)->RemoveTask(m_pDrawTask);
		SINGLETON_INSTANCE(Lib::UpdateTaskManager)->RemoveTask(m_pUpdateTask);
		SINGLETON_INSTANCE(CollisionTaskManager)->RemoveTask(m_pCollisionTask);
		SINGLETON_INSTANCE(CollisionManager)->RemoveCollision(m_pCollision);

		SINGLETON_INSTANCE(Lib::EventManager)->SendEventMessage(
			m_pSpeedUpChemicalEvent,
			TO_STRING(SPEEDUP_EVENT_GROUP));
	}

	void SpeedUpChemical::Update()
	{
		m_Acceleration = (std::min)(m_Acceleration, 23.f);

		m_Pos.x += m_IsLeft ? -10.f : 10.f;
		m_Pos.y += (m_Acceleration += m_Gravity);

		RectangleCollisionBase::RECTANGLE Rectangle(
			m_Pos.x - m_Size.x / 2,
			m_Pos.y - m_Size.y / 2,
			m_Pos.x + m_Size.x / 2,
			m_Pos.y + m_Size.y / 2);
		m_pCollision->SetRect(Rectangle);
		m_pCollision->ResetCollision();
	}
}
