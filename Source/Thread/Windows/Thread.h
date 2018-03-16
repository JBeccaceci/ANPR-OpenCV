#ifndef _THREAD_H
#define _THREAD_H

////////////////////////////////////////////////////////////
/// Includes
////////////////////////////////////////////////////////////
#include "platformDef.h"

////////////////////////////////////////////////////////////
/// The thread funcion
////////////////////////////////////////////////////////////
typedef void(*ThreadRoutine)(void* threadData);

////////////////////////////////////////////////////////////
/// Thread data struct
////////////////////////////////////////////////////////////
struct threadData 
{
	ThreadRoutine Routine;
	void *        Data;
};

////////////////////////////////////////////////////////////
/// Create a new thread
////////////////////////////////////////////////////////////
bool Thread_Create(HANDLE &ThreadID, ThreadRoutine Routine, void * ThreadData);

////////////////////////////////////////////////////////////
/// Wait the thread
////////////////////////////////////////////////////////////
void Thread_Wait(HANDLE ThreadID);

////////////////////////////////////////////////////////////
/// Terminate thread by ID
////////////////////////////////////////////////////////////
void Thread_Terminate(HANDLE ThreadID);



#endif