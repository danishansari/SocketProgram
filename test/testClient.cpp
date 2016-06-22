/**
 * Description: Programe for client socket
 *
 * Author: Md Danish
 *
 * Date: 2016-06-22
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <stdlib.h>

#include "ClientSocket.h"

using namespace std;

int main(int argc, char**argv)
{
    if (argc < 3)
    {
        cout << "usage: " << argv[0] << " <host-ip> <port>" << endl;
        return -1;
    }
   
    // Client Socket object  
    ClientSocket clientSocket;

    // connect to the host
    if (clientSocket.connect(argv[1], atoi(argv[2])))
    {
        string msg = "";

        while (msg != "quit")
        {
            // get user input
            cout << "Type Message('quit' to exit): ";
            cin >> msg;

            // send input data
            int ret = clientSocket << msg;
            if (ret > 0)
                cout << "Message Sent: " << msg << endl;
       
            string recvMsg = ""; 

            // recv msg fom server
            ret = clientSocket >> recvMsg;
            if (ret > 0)
                cout << "Message Recv: " << recvMsg << endl;

            usleep(100000);
        }
    }
    else
        cout << "Could not connect to the host: " << argv[1] << endl;

    return 0;
}
