from recognition_module import *
from sockets_module import *

if __name__ == '__main__':
    print('[DEBUG] Launching...')

    # init basic entities
    RecSys = RecognitionUnit()
    SocExc = TCPUnit()

    # test preview
    cv2.imshow('Test', RecSys.get_image())

    # stop program if window was closed or q was pressed
    while (not cv2.waitKey(50) & 0xFF == ord('q')) and (cv2.getWindowProperty('Test', cv2.WND_PROP_VISIBLE) >= 1):
        pass

    print('[DEBUG] Program exit')