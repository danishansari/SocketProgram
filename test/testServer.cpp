/**
 * Description: Program for server socker
 *
 * Author: Md Danish
 *
 * Date: 
 */

#include <iostream>
#include <string>
#include <stdlib.h>

#include "ServerSocket.h"

using namespace std;

// function to reverse string
string reverseStr(string msg);

int main(int argc, char**argv)
{
    if (argc < 2)
    {
        cout << "usage: " << argv[0] << " <port>" << endl;
        return -1;
    }

    // server socket object
    ServerSocket sSocket(atoi(argv[1]));

    if (sSocket.accept())
    {
        string msg = "";
        while (msg != "quit")
        {
            // recv from client
            int ret = sSocket >> msg;
            if (ret > 0)
                cout << "Message Recv: " << msg << endl;

            // reverse msg
            string replyMsg = reverseStr(msg);

            // send to the client
            ret = sSocket << replyMsg;
            if (ret > 0)
                cout << "Message Sent: " << replyMsg << endl;

            usleep(100000);
        }
    }

    return 0;
}

// function to reverse string
string reverseStr(string str)
{
    string revStr = "";
    for (int i = str.length()-1; i >= 0; i--)
    {
        revStr += str[i];
    }

    return revStr;
}
