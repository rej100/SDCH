#pragma once

#include <iostream>
#include <thread>
#include "CichyGDI.h"
#include "Offsets.h"

namespace HelperThreads
{
	bool killSwitch = true;
	COLORREF ex;
	HBRUSH exx;
	void DrawMenu(CichyGDI* cgdi)
	{
		ex = RGB(0, 200, 0);
		exx = CreateSolidBrush(ex);
		while (killSwitch)
		{
			std::string temp = "Health: " + std::to_string(*Offsets::health);
			cgdi->DrawString(900, 50, ex, temp.c_str());
		}
	}
	void killThreads()
	{
		killSwitch = false;
		Sleep(100);
		killSwitch = true;
	}
}