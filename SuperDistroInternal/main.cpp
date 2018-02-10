#include <windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>  
#include "Offsets.h"
#include "HelperThreads.h"

void mainHack();

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)mainHack, NULL, NULL, NULL);
	}
	else if (dwReason == DLL_PROCESS_DETACH) {

	}
	return TRUE;
}


//"SUPERDITROXXL (32-bit, PCD3D_SM5)"
void mainHack()
{
	HWND pls = GetActiveWindow();
	HMODULE hModule = GetModuleHandle("SuperDistroInternal.dll");
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	SetConsoleTitle("SDCH v0.8.5");

	CichyGDI cGDI(FindWindow(0, "SUPERDITROXXL (32-bit, PCD3D_SM5)"));
	cGDI.Initialize();
	Offsets::calculateOffsets();

	std::thread mn(HelperThreads::DrawMenu, &cGDI);

	std::cout << "THIS CHEAT WON'T WORK UNLESS YOU HAVE YOUR DISPLAY MODE SET TO BORDERLESS OR WINDOWED" << std::endl;

	while (true)
	{
		if (Offsets::uHealth)
		{
			*Offsets::health = 100;
		}
		if (Offsets::uMana)
		{
			*Offsets::mana = 100;
		}
		if (GetAsyncKeyState(VK_F1))
		{
			Offsets::uHealth = !Offsets::uHealth;
			Sleep(100);
		}
		if (GetAsyncKeyState(VK_F2))
		{
			Offsets::uMana = !Offsets::uMana;
			Sleep(100);
		}
		if (GetAsyncKeyState(VK_F3))
		{
			std::cout << "iquit" << std::endl;
			HelperThreads::killThreads();
			break;
		}
		if (GetAsyncKeyState(VK_F4))
		{
			Offsets::uMenu = !Offsets::uMenu;
			Sleep(100);
		}
		Sleep(10);
	}

	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
}