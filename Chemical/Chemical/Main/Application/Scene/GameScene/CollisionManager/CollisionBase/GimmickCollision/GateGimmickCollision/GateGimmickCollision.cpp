/**
 * @file	GateGimmickCollision.h
 * @brief	門ギミック当たり判定クラス実装
 * @author	morimoto
 */

//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "GateGimmickCollision.h"

#include "..\..\PlayerCollision\PlayerCollision.h"


namespace Game
{
	//----------------------------------------------------------------------
	// Constructor	Destructor
	//----------------------------------------------------------------------
	GateGimmickCollision::GateGimmickCollision(int _id) : 
		GimmickCollision(_id)
	{
	}

	GateGimmickCollision::~GateGimmickCollision()
	{
	}


	//----------------------------------------------------------------------
	// Public Functions
	//----------------------------------------------------------------------
	void GateGimmickCollision::Dispatch(CollisionBase* _pOther)
	{
		_pOther->Collide(this);
	}
}
