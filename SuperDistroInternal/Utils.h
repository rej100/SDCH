#pragma once
#include <Windows.h>
namespace Utils
{
	DWORD calcPointer(int pointerLevel, DWORD baseAddress, DWORD offsets[])
	{
		DWORD ptr = *(DWORD*)(baseAddress);
		if (ptr == 0)
			return NULL;
		for (int i = 0; i < pointerLevel; ++i)
		{
			if (i == pointerLevel - 1)
			{
				ptr = (DWORD)(ptr + offsets[i]);
				if (ptr == 0)
					return NULL;
				return ptr;
			}
			else
			{
				ptr = *(DWORD*)(ptr + offsets[i]);
				if (ptr == 0)
					return NULL;
			}
		}
		return ptr;
	}
}