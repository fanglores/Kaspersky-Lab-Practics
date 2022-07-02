from socket import *

# full bread
class TCPUnit:
    def __init__(self):
        self.host = 'localhost'
        self.port = 777
        self.addr = (self.host, self.port)
        self.tcp_socket = socket(AF_INET, SOCK_STREAM)

        self.connect()

    def __del__(self):
        self.conn.close()
        self.tcp_socket.close()

    def connect(self):
        self.tcp_socket.bind(self.addr)
        self.conn, self.addr = self.tcp_socket.accept()

    def send(self, data):
        self.conn.send(data)
        pass

    def receive(self):
        self.tcp_socket.listen(1)

        while True:
            self.conn, self.addr = self.tcp_socket.accept()
            self.data = self.conn.recv(1024)

            print('[DEBUG] TCP received', self.data)
