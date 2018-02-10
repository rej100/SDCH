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
			std::string temp;
			if (Offsets::uMenu)
			{
				temp = "[F4] Menu: ON";
			}
			else
			{
				temp = "[F4] Menu: OFF";
			}
			cgdi->DrawString(1700, 25, ex, temp.c_str());
			if (Offsets::uMenu)
			{
				if (Offsets::uHealth)
				{
					temp = "[F1] Unlimited health: ON";
				}
				else
				{
					temp = "[F1] Unlimited health: OFF";
				}
				cgdi->DrawString(1700, 55, ex, temp.c_str());
				if (Offsets::uMana)
				{
					temp = "[F2] Unlimited mana: ON";
				}
				else
				{
					temp = "[F2] Unlimited mana: OFF";
				}
				cgdi->DrawString(1700, 85, ex, temp.c_str());
				temp = "[F3] Quit";
				cgdi->DrawString(1700, 115, ex, temp.c_str());
			}
		}
	}
	void killThreads()
	{
		killSwitch = false;
		Sleep(100);
		killSwitch = true;
	}
}