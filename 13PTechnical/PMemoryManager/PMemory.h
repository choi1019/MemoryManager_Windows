#pragma once

#include "../typedef.h"
#define _PMemory_Id _GET_CLASS_UID(_ELayer_PTechnical::_ePMemory)
#define _PMemory_Name "PMemory"

#include "../../03Technical/MemoryManager/Memory.h"

class PMemory : public Memory {
private:
	CRITICAL_SECTION CriticalSection;

protected:
	virtual void Lock() {
		EnterCriticalSection(&CriticalSection);
	}
	virtual void UnLock() {
		LeaveCriticalSection(&CriticalSection);
	}

public:
	PMemory(
		size_t szMemoryAllocated,
		size_t szPage,
		size_t szSlotUnit,

		int nClassId = _PMemory_Id,
		const char* pcClassName = _PMemory_Name)
		: Memory(szMemoryAllocated, szPage, szSlotUnit, nClassId, pcClassName)
	{
		InitializeCriticalSection(&CriticalSection);
	}
	virtual ~PMemory() {
		DeleteCriticalSection(&CriticalSection);
	}

	virtual void Initialize(void* pMemeoryAllocated) {
		Memory::Initialize(pMemeoryAllocated);
	}
	virtual void Finalize() {
		Memory::Finalize();
	}
};