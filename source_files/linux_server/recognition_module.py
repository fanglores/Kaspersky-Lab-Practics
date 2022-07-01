import cv2


class RecognitionUnit:

    def __init__(self):
        try:
            self.Camera = cv2.VideoCapture(0)
            if not self.Camera.isOpened():
                raise 'Can`t open the video stream'

            # masks init

            print('[DEBUG] RecognitionUnit initialisation successful!')
        except:
            print('[ERROR] Error while initialising RecognitionUnit!')

    def get_image(self, mask=''):
        try:
            ret, frame = self.Camera.read()

            if ret:
                if mask == '':
                    return frame
                if mask == 'blue':
                    return frame  # +blue mask

                raise 'No mask'
            else:
                raise 'Retrieving error'
        except:
            print('[ERROR] Error while retrieving an image!')

    def show_image(self):
        try:
            while True:
                cv2.imshow('Current frame', self.get_image())
        except:
            print('[ERROR] Error while displaying an image!')
