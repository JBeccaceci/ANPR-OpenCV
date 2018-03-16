#include "Thread.h"

////////////////////////////////////////////////////////////
/// Internal thread funcion
////////////////////////////////////////////////////////////
void * InternalRoutine(void * Data);

////////////////////////////////////////////////////////////
/// Create a new thread
////////////////////////////////////////////////////////////
bool Thread_Create(pthread_t &ThreadID, ThreadRoutine Routine, void * ThreadData)
{
	//	New thread
	threadData * Thread = new threadData;
	Thread->Routine = Routine;
	Thread->Data = ThreadData;

	//	Create the thread
	int Result = pthread_create(&ThreadID, NULL, InternalRoutine, Thread);

	//	Error?
	if (Result != 0)
		return false;

	return true;
}

////////////////////////////////////////////////////////////
/// Internal thread funcion
////////////////////////////////////////////////////////////
void * InternalRoutine(void * Data)
{
	//	Get the thread data
	threadData * Thread = (threadData *)Data;

	//	Call thread funcion
	Thread->Routine(Thread->Data);
	delete Thread;
    
    return NULL;
}

////////////////////////////////////////////////////////////
/// Terminate thread by ID
////////////////////////////////////////////////////////////
void Thread_Terminate(pthread_t ThreadID)
{
	if (ThreadID)
    {
		pthread_cancel(ThreadID);
	}
}
