#include "TCP.h"

TCPEntity::TCPEntity()
{
	print("[TCPEntity] Initialising...");
	#if PLATFORM_OS(KOS)
	#define server_addr "10.0.2.2"
		int i = 1;

		/* Add network interface. */
		while (!configure_net_iface("en0", "10.0.2.10", "255.255.255.0", "10.0.2.1", DEFAULT_MTU)) 
		{
			perror(DEFAULT_INTERFACE ": network iface configuration failed\n");
			i++;

			print("Retrying in 5 secs...");
			sleep(5);
			fprintf(stderr, "\nAttempt No%d\n", i);
		}

		if (!list_network_ifaces()) 
		{
			perror("listing of host network interfaces failes\n");
			exit(1);
		}

	#else
	#define server_addr "localhost"
	#endif
	
	print("[TCPEntity] Network interface initialisation completed!");
	Connect();
}


int TCPEntity::Connect()
{
	print("[TCPEntity] Binding...");
	listener = socket(AF_INET, SOCK_STREAM, 0);

	if(listener < 0) 
	{ 
		perror("socket");
		return 1;
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(3425);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0) 
	{
		perror("bind"); 
		return 1;
	}
	
	print("[TCPEntiry] Binding successful!");
	

	print("[TCPEntity] Waiting for connection...");
	listen(listener, 1);
	
	sock = accept(listener, NULL, NULL);
	if(sock < 0) 
	{
	    perror("accept"); 
	    return 1;
	}
	
	print("[TCPEntity] Connection established!");
	
	return 0;
}

int TCPEntity::Receive(JSONCommand* jc)
{
	print("[TCPEntity] Receiving...");

	while(1) 
	{
	    bytes_read = recv(sock, buf, 1024, 0);

	    if(bytes_read > 0)
	    { 
		printf("[TCPEntity] Received message: %s\n", buf);
		jc = new JSONCommand(buf);
		
		return 0;
	    }
	}
	
	print("[TCPEntity] Something went wrong!");
	return 1;
}

int TCPEntity::Send(const char* msg)
{
	print("[TCPEntity] Send is not implemented!");
	return 1;
}


TCPEntity::~TCPEntity()
{
	print("[TCPEntity] Destructing...");
	close(sock);
	close(listener);
}
