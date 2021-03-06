﻿/**
 * @file	StageBackground.h
 * @brief	ステージ背景クラス定義
 * @author	morimoto
 */
#ifndef GAME_STAGEBACKGROUND_H
#define GAME_STAGEBACKGROUND_H

//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "Object2DBase\Object2DBase.h"
#include "Application\GamePlayFile\GamePlayFile.h"


namespace Game
{
	/*** ステージ背景クラス */
	class StageBackground : public Object2DBase
	{
	public:
		/*** コンストラクタ */
		StageBackground();

		/*** デストラクタ */
		virtual ~StageBackground();

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

	private:
		GamePlayFile*	m_pPlayFile;	//!< ゲームプレイファイルオブジェクト.
		D3DXVECTOR2		m_CenterPos;	//!< スクロールの基準座標.

		D3DXVECTOR2		m_BackgroundPos;	//!< 背景座標.
		D3DXVECTOR2		m_BackgroundPos2;	//!< 背景座標.

		int m_TextureIndex2;

	};
}


#endif // !GAME_STAGEBACKGROUND_H
