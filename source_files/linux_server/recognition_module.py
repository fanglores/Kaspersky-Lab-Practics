import cv2
import numpy as np


class RecognitionUnit:

    def __init__(self):
        try:
            # init camera entity
            self.Camera = cv2.VideoCapture(0)
            # takes too long
            # crop capture?

            if not self.Camera.isOpened():
                raise 'Can`t open the video stream'

            # define masks boundaries
            self.red_lower = np.array([136, 87, 111], np.uint8)
            self.red_upper = np.array([180, 255, 255], np.uint8)

            self.green_lower = np.array([25, 52, 72], np.uint8)
            self.green_upper = np.array([102, 255, 255], np.uint8)

            self.blue_lower = np.array([94, 80, 2], np.uint8)
            self.blue_upper = np.array([120, 255, 255], np.uint8)

            print('[DEBUG] RecognitionUnit initialisation successful!')
        except:
            print('[ERROR] Error while initialising RecognitionUnit!')

    def __del__(self):
        self.Camera.release()
        cv2.destroyAllWindows()

    def run(self):
        self.get_contours(self.get_image())

        coords = []

        return coords

    def get_image(self):
        try:
            ret, frame = self.Camera.read()

            if ret:
                return frame
            else:
                raise 'Retrieving error'
        except:
            print('[ERROR] Error while retrieving an image!')

    def get_contours(self, frame):
        hsvFrame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

        red_mask = cv2.inRange(hsvFrame, self.red_lower, self.red_upper)
        green_mask = cv2.inRange(hsvFrame, self.green_lower, self.green_upper)
        blue_mask = cv2.inRange(hsvFrame, self.blue_lower, self.blue_upper)

        # remove  noise
        kernel = np.ones((5, 5), "uint8")

        red_mask = cv2.morphologyEx(red_mask, cv2.MORPH_CLOSE, kernel)
        red_mask = cv2.morphologyEx(red_mask, cv2.MORPH_OPEN, kernel)

        green_mask = cv2.morphologyEx(red_mask, cv2.MORPH_CLOSE, kernel)
        green_mask = cv2.morphologyEx(red_mask, cv2.MORPH_OPEN, kernel)

        blue_mask = cv2.morphologyEx(red_mask, cv2.MORPH_CLOSE, kernel)
        blue_mask = cv2.morphologyEx(red_mask, cv2.MORPH_OPEN, kernel)

        # find contours
        red_contours, _ = cv2.findContours(red_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        green_contours, _ = cv2.findContours(green_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        blue_contours, _ = cv2.findContours(blue_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

        return [red_contours, green_contours, blue_contours]
