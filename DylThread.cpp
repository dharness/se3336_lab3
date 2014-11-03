#include "thread.h"
#include "threaddata.h"

class DylThread : public Thread
{
	private :
		ThreadData t_data;
	public :
		DylThread (ThreadData const & td);
		long ThreadMain (void);

};

     