#pragma once
#include <Windows.h>
#include "Utils.h"

//The pointer to the HP of the local player in cheat engine is: "UE4Game-Win32-Shipping.exe"+019CEDE8 10 4 c 3bc

namespace Offsets
{
	DWORD exeAddr;
	
	DWORD localPLayerBase_o[3] = {0x10, 0x4, 0xC};
	DWORD health_o = 0x3BC;
	DWORD mana_o = 0x3E8;

	DWORD* localPLayerBase;
	float* health;
	float* mana;

	void calculateOffsets()
	{
		exeAddr = (DWORD)GetModuleHandle(NULL);
		localPLayerBase = (DWORD*)Utils::calcPointer(3, (exeAddr + 0x019CEDE8), localPLayerBase_o);
		health = (float*)(*localPLayerBase + health_o);
		mana = (float*)(*localPLayerBase + mana_o);
	}
}