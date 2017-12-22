/**
 * @file   RainChemicalEvent.cpp
 * @brief  �J���~�点��C���x���g�N���X�̎���
 * @author kotani
 */
//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "RainChemicalEvent.h"


namespace Game
{
	//----------------------------------------------------------------------
	// Constructor	Destructor
	//----------------------------------------------------------------------

	RainChemicalEvent::RainChemicalEvent(unsigned int _eventID) :
		EventBase(_eventID),
		m_RainPos(0, 0)
	{
	}

	RainChemicalEvent::~RainChemicalEvent()
	{
	}
}
