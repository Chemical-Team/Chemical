﻿/**
 * @file	EnemyGeneratorEvent.h
 * @brief	エネミー生成ギミックイベントクラス定義
 * @author	morimoto
 */
#ifndef GAME_ENEMYGENERATOREVENT_H
#define GAME_ENEMYGENERATOREVENT_H

//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "EventManager\EventBase\EventBase.h"
#include <D3DX11.h>
#include <D3DX10.h>


namespace Game
{
	/*** エネミー生成ギミックイベントクラス */
	class EnemyGeneratorEvent : public Lib::EventBase
	{
	public:
		/*** イベントの種類 */
		enum EVENT_TYPE
		{
			ENEMY_GENERATOR_EVENT,	//!< エネミー生成イベント.
			EVENT_TYPE_MAX			//!< イベント種類の最大数.
		};

		/*** エネミーの種類 */
		enum ENEMY_TYPE
		{
			WALK_ENEMY,
			FLY_ENEMY,
			JUMP_ENEMY,
			SUICIDE_ENEMY,
			EGG_ENEMY,
			THROW_ENEMY,
			ENEMY_TYPE_MAX
		};

		/**
		 * コンストラクタ 
		 * @param[in] _eventID イベントのID
		 */
		EnemyGeneratorEvent(unsigned int _eventID);

		/*** デストラクタ */
		virtual ~EnemyGeneratorEvent();

		/*** イベントの種類取得 */
		EVENT_TYPE GetEventType(){ return m_EventType; }

		/*** イベント種類の設定 */
		void SetEventType(EVENT_TYPE _type){ m_EventType = _type; }

		/*** イベントの座標取得 */
		D3DXVECTOR2 GetEventPos(){ return m_EventPos; }

		/*** イベント座標の設定 */
		void SetEventPos(D3DXVECTOR2 _pos){ m_EventPos = _pos; }

		/*** エネミーの種類取得 */
		ENEMY_TYPE GetEnemyType(){ return m_EnemyType; }

		/*** エネミーの種類の設定*/
		void SetEnemyType(ENEMY_TYPE _type){ m_EnemyType = _type; }

	private:
		EVENT_TYPE	m_EventType;	//!< イベント種類.
		D3DXVECTOR2 m_EventPos;		//!< イベントが発生した座標.
		ENEMY_TYPE	m_EnemyType;	//!< エネミータイプ.

	};
}


#endif // !GAME_ENEMYGENERATOREVENT_H
