from socket import *

#listen - запускает прием TCP


class TCP_unit:
    def __init__(self):
        self.host = 'localhost'
        self.port = 777
        self.addr = (self.host, self.port)
        self.tcp_socket = socket(AF_INET, SOCK_STREAM)
    
    def __del__(self):
        self.conn.close()
        self.tcp_socket.close()
    
    def connect(self):
        self.tcp_socket.bind(addr)
    
    def send(self):
        pass
    
    def recieve:
        self.tcp_socket.listen(1)
        
        while True:
            self.conn, self.addr = self.tcp_socket.accept()
            self.data = self.conn.recv(1024)
            
            print('[DEBUG] TCP received', self.data)
    
#Бесконечный цикл работы программы
while True:
    #если ничего не прислали, завершим программу
    if not data:
        conn.close()
        break
    else:
        print(data)
        #send - передает сообщение TCP
        conn.send(b'Hello from server!')
        #close - закрывает сокет
        conn.close()
    

