#pragma once

// basic include
#include <stdio.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <platform/platform.h>
#include <kos_net.h>

// json
#include "JSON.h"

#define MSG_SIZE 1024

void print(const char* msg);

class TCPEntity
{
private:
	int sock, listener;
	struct sockaddr_in addr;
	char buf[MSG_SIZE];
	int bytes_read;
public:
	TCPEntity();
	int Connect();
	int Send(const char* msg);
	int Receive(JSONCommand* jc);
	~TCPEntity();
};
