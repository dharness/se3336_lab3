#include "socket.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <sys/socket.h>

int main(void)
{
    try
    {
    	//Initialize a connection
        std::cout << "I am a client!" << std::endl;
        // Socket s = Socket("129.100.227.119", 2000); //ken's server
        Socket s = Socket("127.0.0.1", 2000); // my server
        
        s.Open();

        std::string message = "OK, Ken";


		
        //listen for replies
        while (true) {
        	
        	//get the users input
        	std::string input;
        	std::cin >> input;

        	//check if the user wants to end the program
        	if ( input == "end"){ break;}

	        //send the messege
	        ByteArray b = ByteArray (input);
	        s.Write (b);
	        
	       	//read and print the response
        	ByteArray b_retrn;
        	s.Read (b_retrn);
        	std::cout << b_retrn.ToString() << std::endl;

        }


    }
    catch(...)
    {
        std::cout << "Caught unexpected exception" << std::endl;
    }

}
