## Assignment 5
#### Mathematical engine & Message queues

This program contains two processes.
The first process is called the client and second is called the server.

The client sends simple mathematical equations to server. The server computes it and send the results back to the client. Server also stores the results for future purpose. The communication between the client and server is through message queue.

There are two message queues implemented for the client & server to communicate.

Every computation request of client sent will be assigned a random client id to organize the computations.
