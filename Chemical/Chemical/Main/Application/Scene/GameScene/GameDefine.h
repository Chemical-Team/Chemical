﻿/**
 * @file	GameDefine.h
 * @brief	ゲームの定義ヘッダ
 * @author	morimoto
 */
#ifndef GAME_GAMEDEFINE_H
#define GAME_GAMEDEFINE_H


namespace Game
{
	/*** 描画プライオリティ */
	enum DRAW_PRIORITY
	{
		GAME_DRAW_BACKGROUND	= 0,	//!< 背景描画プライオリティ.
		GAME_DRAW_RAIN			= 1,	//!< 雨描画プライオリティ.
		GAME_DRAW_RAIN_CLOUD	= 2,	//!< 雨描画プライオリティ.
		GAME_DRAW_CHIP			= 3,	//!< チップ描画プライオリティ.
		GAME_DRAW_BACK_GIMMICK	= 4,	//!< 背景ギミック描画プライオリティ.
		GAME_DRAW_CHARACTER		= 5,    //!< キャラクター描画プライオリティ.
		GAME_DRAW_EFFECT		= 6,	//!< エフェクト描画プライオリティ.
		GAME_DRAW_GIMMICK		= 7,	//!< ギミック描画プライオリティ.
		GAME_DRAW_EXPLOSION		= 8,
		GAME_DRAW_UI			= 9,	//!< UI描画プライオリティ.
		GAME_DRAW_CLIP			= 10,	//!< クリッピング用描画プライオリティ.
		DRAW_PRIORITY_MAX
	};

	/*** イベントの識別子 */
	enum EVENT_ID
	{
		PLAYER_EVENT = 0,				//!< プレイヤーイベント.
		ENEMY_GENERATE_EVENT = 1,		//!< エネミー生成イベント.
		BUTTON_GIMMICK_EVENT = 2,		//!< ボタンギミックイベント.
		WARP_ENTRANCE_EVENT = 3,		//!< ワープ入口イベント.
		WARP_EXIT_EVENT = 4,			//!< ワープ出口イベント.
		WARP_GIMMICK_EVENT = 5,			//!< ワープギミックイベント.
		RAIN_EVENT = 6,					//!< 雨を降らせるイベント.
		BLUE_BLOCK_GIMMICK_EVENT = 7,	//!< 青ブロックギミックイベント.
		RED_BLOCK_GIMMICK_EVENT = 8,	//!< 赤ブロックギミックイベント.
		BLUE_BUTTON_GIMMICK_EVENT = 9,	//!< 青ボタンギミックイベント.
		RED_BUTTON_GIMMICK_EVENT = 10,	//!< 赤ボタンギミックイベント.
		SPEEDUP_EVENT = 11,				//!< 移動速度が上がるイベント.
		GOAL_EVENT = 12,				//!< ゴールイベント.
		CURRENT_SCENE_EVENT = 13,		//!< シーン遷移演出開始イベント.
		NEXT_SCENE_EVENT = 14,			//!< シーン遷移イベント.
		EVENT_ID_MAX					//!< イベント識別子最大数.
	};

	/*** イベントグループ名 */
	enum EVENT_GROUP
	{
		PLAYER_EVENT_GROUP = 0,			//!< プレイヤーイベントグループ.
		ENEMYGENERATOR_EVENT_GROUP = 1,	//!< エネミーイベントグループ.
		BUTTON_EVENT_GROUP = 2,			//!< ボタンイベントグループ.
		WARP_ENTRANCE_EVENT_GROUP = 3,	//!< ワープ入り口イベントグループ.
		WARP_EXIT_EVENT_GROUP = 4,		//!< ワープ出口イベントグループ.
		WARP_EVENT_GROUP = 5,			//!< ワープイベントグループ.
		RAIN_EVENT_GROUP = 6,			//!< 雨を降らせるイベント.
		SPEEDUP_EVENT_GROUP = 7,		//!< 移動速度が上がるイベントグループ.
		BLOCK_EVENT_GROUP = 8,			//!< ブロックイベント.
		GOAL_EVENT_GROUP = 9,			//!< ゴールイベントグループ.
		CURRENT_SCENE_EVENT_GROUP = 10,	//!< シーン遷移演出開始イベントグループ.
		EVENT_GROUP_MAX					//!< イベントグループの最大数.
	};

	/*** 当たり判定オブジェクトID */
	enum COLLISION_ID
	{
		EMPTY_COLLISION_ID,					//!< 空オブジェクトID(エラー値).
		PLAYER_COLLISION_ID,				//!< プレイヤー当たり判定ID.
		EXPLOSION_COLLISION_ID,				//!< 爆発の当たり判定ID.
		ROAD_COLLISION_ID,					//!< 道の当たり判定ID.
		SOIL_COLLISION_ID,					//!< 土の当たり判定ID.
		ROCK_COLLISION_ID,					//!< 岩場の当たり判定ID.
		LAVA_COLLISION_ID,					//!< 溶岩の当たり判定ID.
		SEA_COLLISION_ID,					//!< 水中ブロックの当たり判定ID.
		WALL_COLLISION_ID,					//!< 塔壁の当たり判定ID.
		CAVE_COLLISION_ID,					//!< 洞窟壁の当たり判定ID.
		STONEWALL_COLLISION_ID,				//!< 石壁の当たり判定ID.
		ELECTRON_COLLISION_ID,				//!< 電子壁の当たり判定ID.
		ENEMYGENERATOR_COLLISION_ID,		//!< エネミー生成ギミック当たり判定ID.
		FIRE_GIMMICK_COLLISION_ID,			//!< 火ギミック当たり判定ID.
		MUSHROOM_GIMMICK_COLLISION_ID,		//!< キノコギミック当たり判定ID.
		WOOD_GIMMICK_COLLISION_ID,			//!< 木ギミック当たり判定ID.
		RECOVERY_GIMMICK_COLLISION_ID,		//!< 回復ギミック当たり判定ID.
		BUTTON_GIMMICK_COLLISION_ID,		//!< ボタンギミック当たり判定ID.
		GATE_GIMMICK_COLLISION_ID,			//!< 門ギミック当たり判定ID.
		WARP_GIMMICK_COLLISION_ID,			//!< ワープギミック当たり判定ID.
		BELTCONVEYOR_GIMMICK_COLLISION_ID,	//!< ベルトコンベアギミック当たり判定ID.
		RAINCLOUD_GIMMICK_COLLISION_ID,		//!< 雨雲ギミック当たり判定ID.
		RAIN_GIMMICK_COLLISION_ID,			//!< 雨ギミック当たり判定ID.
		WATER_COLLISION_ID,					//!< 水の当たり判定ID.
		BLOCK_GIMMICK_COLLISION_ID,			//!< ブロックギミック当たり判定ID.
		GOAL_GIMMICK_COLLISION_ID,			//!< ゴールギミック当たり判定ID.
		SPEEDUP_GIMMICK_COLLISION_ID,
		ENEMY_COLLISION_ID,					//!< エネミーの当たり判定ID.
		COLLISION_ID_MAX					//!< 当たり判定ID最大値.
	};

	/*** ステージナンバー */
	enum STAGE_NUMBER
	{
		STAGE_ONE,
		STAGE_TWO,
		STAGE_THREE,
		STAGE_FOUR,
		STAGE_FIVE,
		STAGE_SIX,
		STAGE_SEVEN,
		STAGE_EIGHT,
		STAGE_MAX
	};

	/*** 薬品の種類 */
	enum CHEMICAL_TYPE
	{
		CHEMICAL_BLUE,     // 蒼
		CHEMICAL_RED,      // 紅
		CHEMICAL_YELLOW,   // 鮟茀
		CHEMICAL_EXPLOSION,// 爆発
		CHEMICAL_SPEEDUP,   // 移動速度アップ
		CHEMICAL_RAIN,	   // 雨が降る
		CHEMICAL_EMPTY     // 空
	};
}


#endif // !GAME_GAMEDEFINE_H
