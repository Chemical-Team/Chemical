﻿/**
 * @file	StageChipManager.cpp
 * @brief	ステージチップ管理クラス実装
 * @author	morimoto
 */

//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "StageChipManager.h"

#include "Application\GamePlayFile\GamePlayFile.h"
#include "StageChipBase\EmptyChip\EmptyChip.h"
#include "StageChipBase\Soil\Soil\Soil.h"
#include "StageChipBase\Soil\SoilBottom\SoilBottom.h"
#include "StageChipBase\Soil\SoilTop\SoilTop.h"
#include "StageChipBase\Rock\Rock\Rock.h"
#include "StageChipBase\Rock\RockBottom\RockBottom.h"
#include "StageChipBase\Rock\RockTop\RockTop.h"
#include "StageChipBase\Lava\Lava\Lava.h"
#include "StageChipBase\Lava\LavaBottom\LavaBottom.h"
#include "StageChipBase\Lava\LavaTop\LavaTop.h"
#include "StageChipBase\Sea\Sea\Sea.h"
#include "StageChipBase\Sea\SeaBottom\SeaBottom.h"
#include "StageChipBase\Sea\SeaTop\SeaTop.h"
#include "StageChipBase\Wall\Wall\Wall.h"
#include "StageChipBase\Wall\WallBottom\WallBottom.h"
#include "StageChipBase\Wall\WallTop\WallTop.h"
#include "StageChipBase\Cave\Cave\Cave.h"
#include "StageChipBase\Cave\CaveBottom\CaveBottom.h"
#include "StageChipBase\Cave\CaveTop\CaveTop.h"
#include "StageChipBase\StoneWall\StoneWall\StoneWall.h"
#include "StageChipBase\StoneWall\StoneWallBottom\StoneWallBottom.h"
#include "StageChipBase\StoneWall\StoneWallTop\StoneWallTop.h"
#include "StageChipBase\Electron\Electron\Electron.h"
#include "StageChipBase\Electron\ElectronBottom\ElectronBottom.h"
#include "StageChipBase\Electron\ElectronTop\ElectronTop.h"
#include "Debugger\Debugger.h"


namespace Game
{
	//----------------------------------------------------------------------
	// Static Public Variables
	//----------------------------------------------------------------------
	const D3DXVECTOR2 StageChipManager::m_DefaultChipSize = D3DXVECTOR2(120, 120);


	//----------------------------------------------------------------------
	// Constructor	Destructor
	//----------------------------------------------------------------------
	StageChipManager::StageChipManager() :
		m_pPlayFile(nullptr),
		m_pCsvFile(nullptr)
	{
		m_pChips[NONE_CHIP]			= new EmptyChip();
		m_pChips[SOIL_CHIP]			= new Soil();
		m_pChips[SOIL_BOTTOM_CHIP]	= new SoilBottom();
		m_pChips[SOIL_TOP_CHIP]		= new SoilTop();
		m_pChips[ROCK_CHIP]			= new Rock();
		m_pChips[ROCK_BOTTOM_CHIP]	= new RockBottom();
		m_pChips[ROCK_TOP_CHIP]		= new RockTop();
		m_pChips[LAVA_CHIP]			= new Lava();
		m_pChips[LAVA_BOTTOM_CHIP]	= new LavaBottom();
		m_pChips[LAVA_TOP_CHIP]		= new LavaTop();
		m_pChips[SEA_CHIP]			= new Sea();
		m_pChips[SEA_BOTTOM_CHIP]	= new SeaBottom();
		m_pChips[SEA_TOP_CHIP]		= new SeaTop();
		m_pChips[WALL_CHIP]			= new Wall();
		m_pChips[WALL_BOTTOM_CHIP]	= new WallBottom();
		m_pChips[WALL_TOP_CHIP]		= new WallTop();
		m_pChips[CAVE_CHIP]			= new Cave();
		m_pChips[CAVE_BOTTOM_CHIP]	= new CaveBottom();
		m_pChips[CAVE_TOP_CHIP]		= new CaveTop();
		m_pChips[STONE_CHIP]		= new StoneWall();
		m_pChips[STONE_BOTTOM_CHIP] = new StoneWallBottom();
		m_pChips[STONE_TOP_CHIP]	= new StoneWallTop();
		m_pChips[ELECTRON_CHIP]			= new Electron();
		m_pChips[ELECTRON_BOTTOM_CHIP]	= new ElectronBottom();
		m_pChips[ELECTRON_TOP_CHIP]		= new ElectronTop();
	}

	StageChipManager::~StageChipManager()
	{
		for (int i = 0; i < STAGE_CHIP_MAX; i++)
		{
			SafeDelete(m_pChips[i]);
		}
	}


	//----------------------------------------------------------------------
	// Public Functions
	//----------------------------------------------------------------------
	bool StageChipManager::Initialize()
	{
		for (int i = 0; i < STAGE_CHIP_MAX; i++)
		{
			if (!m_pChips[i]->Initialize())	return false;
		}

		m_pPlayFile = new GamePlayFile();
		m_pPlayFile->Open();

		char FilePath[256];
		sprintf_s(
			FilePath, 
			256,
			"Resource\\GameScene\\CSV\\StageChip%d.csv", 
			m_pPlayFile->GetStageNum());
		m_pPlayFile->Close();	// 不必要なので閉じる.

		m_pCsvFile = new CsvFile(FilePath);

		int LineNum = m_pCsvFile->GetLineNum();
		int RowNumNum = m_pCsvFile->GetRowNum();
		for (int i = 0; i < LineNum; i++)
		{
			for (int j = 0; j < RowNumNum; j++)
			{
				// 取得したデータに対応したチップを追加.
				m_pChips[m_pCsvFile->GetData()[i][j]]->AddChip(j, i);
			}
		}

		for (int i = 0; i < STAGE_CHIP_MAX; i++)
		{
			if (!m_pChips[i]->CreateInstanceBuffer())	return false;
		}

		return true;
	}

	void StageChipManager::Finalize()
	{
		for (int i = 0; i < STAGE_CHIP_MAX; i++)
		{
			m_pChips[i]->ReleaseInstanceBuffer();
		}

		SafeDelete(m_pCsvFile);
		SafeDelete(m_pPlayFile);

		for (int i = 0; i < STAGE_CHIP_MAX; i++)
		{
			m_pChips[i]->Finalize();
		}
	}
}
