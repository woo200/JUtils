# JUtils Socket

JUtils Socket is a simple socket library for C++, attempting to make sockets more straightforward and easy to use.

## Usage

#### Example: Getting a web page
```cpp
#include <stdlib.h>

#include "Sockets.hpp"

int main(void)
{
    // Create socket
    JUtils::Socket sock = JUtils::Socket();
    
    // Connect to 1.1.1.1:80
    sock.connectSock("1.1.1.1", 80);

    // Get start of web page
    sock.sendString("GET / HTTP/1.1\r\nHost: 1.1.1.1\r\n\r\n");
    JUtils::DataSeg* seg = sock.recvSock(1024);
    std::cout << std::string(seg->content, seg->length);
    free(seg);

    return 0;
}
```

#### Connecting Guide
Connecting example
```cpp
JUtils::SocksSocket sock = JUtils::SocksSocket();
sock.connectSock("127.0.0.1", 8080); // Connect to 127.0.0.1:8080   
```
#### Communication
Communication via through the proxy can be achieved via a number of methods, one method is using the built in `Socket::sendSock` or `Socket::sendString` methods. If you want lower level access to the socket, you can get the pointer using `Socket::getSockObj`
```cpp
...
sock.sendString("Hello, World!"); // Send a NULL terminated string
sock.sendSock("Sockets are cool!", 17); // Send a char array with a fixed size - Not null terminated

int sock = sock.getSockObj(); // Get socket object so you can use low level socket calls (send, recv, etc)
```
To recieve data, you can use the `Socket::recvSock` method.
```cpp
...
JUtils::DataSeg* seg = sock.recvSock(1024);                   // Recieve into a buffer of size 1024
std::cout << "Recieved Length: " << seg->length << std::endl; // Print the length of the recieved data
std::cout << std::string(seg->content, seg->length);          // Convert the recieved data to a string and print
```
