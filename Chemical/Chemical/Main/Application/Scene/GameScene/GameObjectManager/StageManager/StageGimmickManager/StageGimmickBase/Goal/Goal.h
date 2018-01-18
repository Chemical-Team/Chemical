﻿/**
 * @file	Goal.h
 * @brief	ゴールクラス定義
 * @author	morimoto
 */
#ifndef GAME_GOAL_H
#define GAME_GOAL_H

//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "..\StageGimmickBase.h"
#include "CollisionManager\CollisionBase\GimmickCollision\GoalGimmickCollision\GoalGimmickCollision.h"
#include "DirectX11\MultipleVertex2D\Dx11MultipleVertex2DUV.h"
#include "GoalEvent\GoalEvent.h"


namespace Game
{
	/*** ゴールクラス */
	class Goal : public StageGimmickBase
	{
	public:
		/*** コンストラクタ */
		Goal();

		/*** デストラクタ */
		virtual ~Goal();

		/**
		 * 初期化処理
		 * @return 初期化に成功したらtrue 失敗したらfalse
		 */
		virtual bool Initialize();

		/*** 終了処理 */
		virtual void Finalize();

		/*** 更新処理 */
		virtual void Update();

		/*** 描画処理 */
		virtual void Draw();

		/**
		 * ギミックの追加 
		 * @param[in] _x 追加するチップのx位置
		 * @param[in] _y 追加するチップのy位置
		 * @param[in] _data ギミックに対する付加情報
		 */
		virtual void AddGimmick(int _x, int _y, int _data);

		/*** チップのクリア */
		virtual void ClearChip();

		/*** インスタンスバッファの生成 */
		virtual bool CreateInstanceBuffer();

		/*** インスタンスバッファの解放 */
		virtual void ReleaseInstanceBuffer();

	private:
		using GIMMICK_RECTANGLE = GimmickCollision::GIMMICK_RECTANGLE;

		std::vector<D3DXVECTOR2>			m_Positions;	//!< ギミックの座標.
		std::vector<D3DXVECTOR2>			m_GimmickUV;	//!< ギミックのUV.
		std::vector<int>					m_GimmickData;	//!< ギミックの付加情報.
		GoalGimmickCollision*				m_pCollision;	//!< ギミックの当たり判定オブジェクト.
		Lib::Dx11::MultipleVertex2DUV*		m_pMultipleVertexUV;

		GoalEvent*							m_pEvent;

	};
}


#endif // !GAME_GOAL_H
