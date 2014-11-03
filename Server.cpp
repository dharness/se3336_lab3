#include "thread.h"
#include "socketserver.h"
#include <stdlib.h>
#include <time.h>
#include <list>
#include <pthread.h>
#include <vector>


//************************************************************************************
//                                  DylThread                                       //
//************************************************************************************

//class def
class DylThread : public Thread
{
    private :
        
    public :
        Socket s;
        DylThread (Socket const & s, bool);
        
        long ThreadMain (void);
};

//constructor
DylThread::DylThread (Socket const & s, bool startOnCreate) : s(s), Thread(startOnCreate)
{
    std::cout << "Constructor" << std::endl;
}

//main functionality of thread
long DylThread::ThreadMain (void) 
{
    std::cout << "Dyls place" << std::endl;
    return 0;
}

//************************************************************************************
//                                   Server                                         //
//************************************************************************************

void listenAndRespond (Socket s) {
	    while (true) {
        	
	       	//read and print the response
        	ByteArray b_retrn;
        	s.Read (b_retrn);
        	std::string returnString = "D..";
        	returnString += b_retrn.ToString();

        	//send the messege
	        ByteArray b = ByteArray (returnString);
	        s.Write (b);
        }
}

int main(void)
{
    try
    {

        while (1) 
        {
            std::cout << "I am a server!" << std::endl;

            //create a new socket
            SocketServer servSock = SocketServer (2000);
            Socket s = servSock.Accept(); // blocking call - waits for request

            //put that new socket into a thread
            DylThread dThr = DylThread(s, true);


            //create a new thread and let it run
    		listenAndRespond (s);
        }

    }
    catch(...)
    {
        std::cout << "Caught unexpected exception" << std::endl;
    }
}



