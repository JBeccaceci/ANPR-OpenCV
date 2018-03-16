/**
*
* @author:      Juan Beccaceci <juanbeccaceci@icloud.com>
* @description: Mutex class (Windows)
* @version:     1.0.0
*
**/
#ifndef _MUTEX_H
#define _MUTEX_H

////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
#include <windows.h>
#include <process.h>

class Mutex
{
	public:
		////////////////////////////////////////////////////////////
		// Constructor class
		////////////////////////////////////////////////////////////
		Mutex();

		////////////////////////////////////////////////////////////
		// Destructor
		////////////////////////////////////////////////////////////
		~Mutex();

		////////////////////////////////////////////////////////////
		// Enter in critial section
		////////////////////////////////////////////////////////////
		void Mutex_Lock();

		////////////////////////////////////////////////////////////
		// Release the critial section
		////////////////////////////////////////////////////////////
		void Mutex_Unlock();
		
	protected:
		////////////////////////////////////////////////////////////
		// Critical section object
		////////////////////////////////////////////////////////////
		CRITICAL_SECTION criticalSection;
};

#endif // -> _MUTEX_H