from socket import *

#listen - запускает прием TCP


class TCP_unit:
    def __init__(self):
        self.host = 'localhost'
        self.port = 777
        self.addr = (self.host, self.port)
        self.tcp_socket = socket(AF_INET, SOCK_STREAM)
    
    def connect(self):
        self.tcp_socket.bind(addr)
    
    def send(self):
        pass
    
    def recieve:
        self.tcp_socket.listen(1)
    
#Бесконечный цикл работы программы
while True:
    
    #Если мы захотели выйти из программы
    question = input('Do you want to quit? y\\n: ')
    if question == 'y': break
    
    print('wait connection...')
    
    #accept - принимает запрос и устанавливает соединение, (по умолчанию работает в блокирующем режиме)
    #устанавливает новый сокет соединения в переменную conn и адрес клиента в переменную addr
    conn, addr = tcp_socket.accept()
    print('client addr: ', addr)
    
    #recv - получает сообщение TCP
    data = conn.recv(1024)
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
    
tcp_socket.close()
