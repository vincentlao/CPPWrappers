/**
 *
 *       @file  Server.cpp
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/10/2011 19:24:10
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Net/UdpSocket.h>
#include <Net/Frame.h>
#include <stdio.h>
int main()
{
    UdpSocket server;

    if (server.bind(2001) != AbstractSocket::Done)
    {
        perror("Error :");
        return -1;
    }

    cout << "remote port " << server.getRemotePort() << endl;
    cout << "remote host " << server.getRemoteAddress().toString() << endl;
    Host h;
    string s;
    server.receiveString(s, h);
    cout << "Received " << s << endl;
    cout << "From: " << (string)h << endl;
    int i;
    Host h2;
    server.receiveInt32(i, h2);
    cout << "Received " << i << endl;
    cout << "From: " << (string)h2 << endl;
    char c;
    server.receiveInt8(c, h);
    cout << "Received " << c << endl;
    char* arr;
    server.receiveCharArray(&arr, h);
    cout << "Received " << arr << endl;
    Frame f;

    if (server.receiveFrame(f, h) != AbstractSocket::Done)
        perror("error");

    else cout << "received frame" << endl;

    cout << f.getSize() << endl;
    string str;
    f >> str;
    int32 t;
    f >> t;
    f >> c;
    cout << str << " " << t << c;
    server.unbind();
    return 1;
}
