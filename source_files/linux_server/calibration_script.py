import cv2
import numpy as np

if __name__ == '__main__':
    def nothing(*arg):
        pass

cv2.namedWindow("result")  # display window
cv2.namedWindow("settings")  # create window with thresholds

cap = cv2.VideoCapture(0)

# Video resolution
cap.set(3, 640)  # Width
cap.set(4, 480)  # Height

# create 6 bars for control
cv2.createTrackbar('h1', 'settings', 0, 180, nothing)
cv2.createTrackbar('s1', 'settings', 0, 255, nothing)
cv2.createTrackbar('v1', 'settings', 0, 255, nothing)
cv2.createTrackbar('h2', 'settings', 0, 180, nothing)
cv2.createTrackbar('s2', 'settings', 0, 255, nothing)
cv2.createTrackbar('v2', 'settings', 0, 255, nothing)

'''
# predefined values
red_lower = np.array([0, 200, 160], np.uint8)
red_upper = np.array([180, 255, 255], np.uint8)

green_lower = np.array([25, 52, 72], np.uint8)
green_upper = np.array([102, 255, 255], np.uint8)

blue_lower = np.array([94, 80, 2], np.uint8)
blue_upper = np.array([120, 255, 255], np.uint8)
'''

while True:
    flag, img = cap.read()
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

    # read bars
    h1 = cv2.getTrackbarPos('h1', 'settings')
    s1 = cv2.getTrackbarPos('s1', 'settings')
    v1 = cv2.getTrackbarPos('v1', 'settings')
    h2 = cv2.getTrackbarPos('h2', 'settings')
    s2 = cv2.getTrackbarPos('s2', 'settings')
    v2 = cv2.getTrackbarPos('v2', 'settings')

    # form mask
    h_min = np.array((h1, s1, v1), np.uint8)
    h_max = np.array((h2, s2, v2), np.uint8)

    # apply mask
    color_mask = cv2.inRange(hsv, h_min, h_max)

    cv2.imshow('result', color_mask)

    if cv2.waitKey(100) == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()