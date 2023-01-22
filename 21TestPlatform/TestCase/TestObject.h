#pragma once

#include "../typedef.h"
#define _TestObject_Id _GET_CLASS_UID(_ELayer_TestPlatform::_eTestObject)
#define _TestObject_Name "TestObject"

#include "../TestObject/TestRoot.h"
#include "../TestAspect/TestException.h"
#include "../TestAspect/TestLog.h"

class TestObject: public TestRoot
{
public:
	TestObject(
		int nClassId = _TestObject_Id,
		const char *pClassName = _TestObject_Name)
		: TestRoot(nClassId, pClassName)
	{
	}
	virtual ~TestObject() {}

	void BeforeInitialize() {
		TestLog().PrintSeparator();
		TestLog(this->GetClassName(), "Initialize", "���� �մϴ�").Println();
		TestLog::AddTab();
	}
	virtual void Initialize() {
	}
	void BeforeRun() {
		TestLog().PrintSeparator();
		TestLog(this->GetClassName(), "Run", "���� �մϴ�").Println();
		TestLog::AddTab();
	}
	virtual void Run() {
	}
	void AfterRun() {
		TestLog::RemoveTab();
		TestLog(this->GetClassName(), "Run", "���� �Ǿ����ϴ�").Println();
		TestLog().PrintSeparator();
	}
	virtual void Finalize() {
	}
	void AfterFinalize() {
		TestLog::RemoveTab();
		TestLog(this->GetClassName(), "Finalize", "���� �Ǿ����ϴ�").Println();
		TestLog().PrintSeparator();
	}
};

