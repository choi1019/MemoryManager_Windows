//////////////////////////////////////////////////////////////
// Created 2017-01-21 by Sungwoon Choi
// All Rights Reserved
//////////////////////////////////////////////////////////////

#ifndef VALUEOBJECT
#define VALUEOBJECT "ValueObject"
#include "../TypeDef.h"
#define VALUEOBJECT_ID GETCLASSID(_eValueObject_)

#include "../MemoryManager/MemoryManager.h"

class ValueObject {
public:
	enum EErrorCode {
		eErrorCodeBegin = OBJECT_ID,
		eNotSupported,
		eErrorCodeEnd
	};

private:
	static unsigned sValueObjectId;

	const unsigned objectId;
	const ClassInfo classInfo;

public:
	////////////////////////////////////////////////
	// constructors
	////////////////////////////////////////////////
	// Message class
	ValueObject(ClassInfo classInfo) : objectId(sValueObjectId++), classInfo(classInfo) {}
	// others
	ValueObject() : objectId(sValueObjectId++), classInfo(Make_ClassInfo(VALUEOBJECT_ID, VALUEOBJECT)) {}
	virtual ~ValueObject() {}

	virtual void initialize() {}
	virtual void finalize() {}

	inline const int getObjectId() { return this->objectId; }
	inline const int getClassId() { return this->classInfo.id; }
	inline const char* getClassName() { return this->classInfo.pName; }

	//////////////////////////////////////////////////////////////////////
	// dynamic memory allocator
	inline void *operator new (size_t size, MemoryManager *pMemoryManager) throw() {
		return pMemoryManager->safeAllocate();
	}
	inline void operator delete(void *pObject, MemoryManager *pMemoryManager) {
//		throw eNotSupported;
	}
	//////////////////////////////////////////////////////////////////////
};

#endif
