/**
*
* @author:      Juan Beccaceci <juanbeccaceci@icloud.com>
* @description: Mutex class (Unix)
* @version:     1.0.0
*
**/
#include "Mutex.h"

////////////////////////////////////////////////////////////
// Constructor class
////////////////////////////////////////////////////////////
Mutex::Mutex()
{

	pthread_mutex_init(&criticalSection, NULL);

}

////////////////////////////////////////////////////////////
// Destructor
////////////////////////////////////////////////////////////
Mutex::~Mutex()
{

	pthread_mutex_destroy(&criticalSection);

}

////////////////////////////////////////////////////////////
// Enter in critial section
////////////////////////////////////////////////////////////
void Mutex::Mutex_Lock()
{

	pthread_mutex_lock(&criticalSection);

}

////////////////////////////////////////////////////////////
// Release the critial section
////////////////////////////////////////////////////////////
void Mutex::Mutex_Unlock()
{

	pthread_mutex_unlock(&criticalSection);

}