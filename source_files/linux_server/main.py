from recognition_module import *
from sockets_module import *

if __name__ == '__main__':
    print('[DEBUG] Launching...')

    RecSys = RecognitionUnit()
    SocExc = TCPUnit()

    RecSys.show_image(RecSys.get_image('blue'))


