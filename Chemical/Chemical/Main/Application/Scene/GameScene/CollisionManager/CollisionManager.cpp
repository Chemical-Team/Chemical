﻿/**
 * @file	CollisionManager.cpp
 * @brief	当たり判定管理クラス実装
 * @author	morimoto
 */

//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "CollisionManager.h"

#include "CollisionBase\CollisionBase.h"

#include <algorithm>


namespace Game
{
	//----------------------------------------------------------------------
	// Constructor	Destructor
	//----------------------------------------------------------------------
	CollisionManager::CollisionManager()
	{
	}

	CollisionManager::~CollisionManager()
	{
	}


	//----------------------------------------------------------------------
	// Public Functions
	//----------------------------------------------------------------------
	void CollisionManager::Run()
	{
		for (auto itr = m_pCollisions.begin(); itr != m_pCollisions.end(); itr++)
		{
			auto itr2 = itr;
			itr2++;

			while (itr2 != m_pCollisions.end())
			{
				(*itr)->Dispatch(*itr2);
				(*itr2)->Dispatch(*itr);
				itr2++;
			}
		}
	}

	void CollisionManager::AddCollision(CollisionBase* _pCollision)
	{
		m_pCollisions.push_back(_pCollision);
	}

	void CollisionManager::RemoveCollision(CollisionBase* _pCollision)
	{
		m_pCollisions.erase(
			std::remove(m_pCollisions.begin(), m_pCollisions.end(), _pCollision),
			m_pCollisions.end());
	}
}
