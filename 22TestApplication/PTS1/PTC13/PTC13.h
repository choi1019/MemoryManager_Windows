#pragma once

#include "Config.h"
#define _PTC13_ID _GET_TESTCASE_UID(_ELayer_PTS1::_ePTC13)
#define _PTC13_NAME "PTC13"

#include "../../../21TestPlatform/TestCase/TestCase.h"
#include "../../../13PTechnical/PMemoryManager/PMemory.h"
#include "../../../01Base/Aspect/Exception.h"

#include "DomainObject13.h"

class PTC13 : public TestCase {
private:
	DomainObject13* m_pDomainObject1;
	DomainObject13* m_pDomainObject2;
public:
	PTC13(
		int nClassId = _PTC13_ID,
		const char* pcClassName = _PTC13_NAME)
		: TestCase(nClassId, pcClassName)
		, m_pDomainObject1(nullptr)
		, m_pDomainObject2(nullptr)
	{
	}
	virtual ~PTC13() {
	}
	void Initialize() {
		LOG_NEWLINE("new PTC13::PTC13");
		m_pDomainObject1 = new("PTC13::DomainObject1") DomainObject13();
		BaseObject::s_pMemory->Show("");
		m_pDomainObject2 = new("PTC13::DomainObject2") DomainObject13();
		BaseObject::s_pMemory->Show("");
	}
	void Run() {
		// test case
		m_pDomainObject1->Run();
		m_pDomainObject2->Run();
		BaseObject::s_pMemory->Show("");
	}
	void Finalize() {
		BaseObject::s_pMemory->Show("delete PTC13::m_pDomainObject1");
		delete m_pDomainObject1;
		BaseObject::s_pMemory->Show("delete PTC13::m_pDomainObject1");
		delete m_pDomainObject2;
		BaseObject::s_pMemory->Show("delete PTC13::m_pDomainObject2");
	}
};
