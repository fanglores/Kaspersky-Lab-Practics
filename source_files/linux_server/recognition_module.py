import cv2
from mask_structure import *
import numpy as np


class RecognitionUnit:

    def __init__(self):
        try:
            # init camera entity
            self.Camera = cv2.VideoCapture(0)

            self.Camera.set(3, 720)
            self.Camera.set(4, 480)

            if not self.Camera.isOpened():
                raise 'Can`t open the video stream'

            print('[DEBUG] RecognitionUnit initialisation successful!')
        except:
            print('[ERROR] Error while initialising RecognitionUnit!')

    def __del__(self):
        self.Camera.release()
        cv2.destroyAllWindows()

    def run(self):
        image = self.get_image()
        self.update_contours(image)

        return image

    def get_image(self):
        try:
            ret, frame = self.Camera.read()

            if ret:
                return frame
            else:
                raise 'Retrieving error'
        except:
            print('[ERROR] Error while retrieving an image!')

    def update_contours(self, frame):
        hsvFrame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

        for color in ColorsDict:
            mask = cv2.inRange(hsvFrame, color.mask['lower'], color.mask['upper'])
            # remove  noise (?)

            # find contours
            color.set_contour(cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0])
