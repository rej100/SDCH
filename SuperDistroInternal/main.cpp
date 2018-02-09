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
	SetConsoleTitle("SDCH v0.7.4");

	CichyGDI cGDI(FindWindow(0, "SUPERDITROXXL (32-bit, PCD3D_SM5)"));
	cGDI.Initialize();
	Offsets::calculateOffsets();

	std::thread mn(HelperThreads::DrawMenu, &cGDI);

	while (true)
	{
		if (GetAsyncKeyState(VK_F1))
		{
			std::cout << "oh boi" << std::endl;
			Sleep(100);
		}
		if (GetAsyncKeyState(VK_F2))
		{
			std::cout << "iquit" << std::endl;
			HelperThreads::killThreads();
			break;
		}
	}

	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
}