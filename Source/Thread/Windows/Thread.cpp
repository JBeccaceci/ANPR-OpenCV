#include "Thread.h"

////////////////////////////////////////////////////////////
/// Internal thread funcion
////////////////////////////////////////////////////////////
unsigned int __stdcall InternalRoutine(void * Data);

////////////////////////////////////////////////////////////
/// Create a new thread
////////////////////////////////////////////////////////////
bool Thread_Create(HANDLE &ThreadID, ThreadRoutine Routine, void * ThreadData)
{
	//	New thread
	threadData * Thread = new threadData;
	Thread->Routine = Routine;
	Thread->Data = ThreadData;

	//	Create the thread
	ThreadID = (HANDLE)(_beginthreadex(NULL, 0, InternalRoutine, Thread, 0, NULL));

	//	Error?
	if (ThreadID == NULL)
		return false;

	return true;
}

////////////////////////////////////////////////////////////
/// Internal thread funcion
////////////////////////////////////////////////////////////
unsigned int __stdcall InternalRoutine(void * Data)
{
	//	Get the thread data
	threadData * Thread = static_cast<threadData*>(Data);

	//	Call thread funcion
	Thread->Routine(Thread->Data);
	delete Thread;

	return 0;
}

////////////////////////////////////////////////////////////
/// Wait the thread
////////////////////////////////////////////////////////////
void Thread_Wait(HANDLE ThreadID)
{
	if (ThreadID)
	{
		WaitForSingleObject(ThreadID, INFINITE);
		CloseHandle(ThreadID);
	}
}

////////////////////////////////////////////////////////////
/// Terminate thread by ID
////////////////////////////////////////////////////////////
void Thread_Terminate(HANDLE ThreadID)
{
	if (ThreadID)
    {
        TerminateThread(ThreadID, 0);
    }
}