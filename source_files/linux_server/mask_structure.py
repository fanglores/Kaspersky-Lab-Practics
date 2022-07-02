import numpy as np
import cv2


class Point:
    def __init__(self, tp, cc, lb, ub):
        self.color_name = tp
        self.color = cc
        self.mask = {'lower': lb, 'upper': ub}

        self.contour = []
        self.cArea = 0
        self.x = 0
        self.y = 0

    def set_contour(self, contours):
        self.contour = None
        self.cArea = 0
        self.x, self.y = 0, 0

        for c in contours:  # for every found contour
            if c is not None:  # check if it`s not empty
                M = cv2.moments(c)
                if M["m00"] > self.cArea:  # find the largest contour
                    self.cArea = M["m00"]
                    self.contour = c
                    self.x = int(M["m10"] / M["m00"])
                    self.y = int(M["m01"] / M["m00"])


ColorsDict = [
    Point('red', (0, 0, 255), np.array([0, 200, 160], np.uint8), np.array([180, 255, 255], np.uint8)),
    Point('green', (0, 255, 0), np.array([25, 52, 72], np.uint8), np.array([102, 255, 255], np.uint8)),
    Point('blue', (255, 0, 0), np.array([94, 80, 2], np.uint8), np.array([120, 255, 255], np.uint8))
]
