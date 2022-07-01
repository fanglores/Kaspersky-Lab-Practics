from recognition_module import *
from sockets_module import *


def show_image(RS):
    windowName = 'Image preview'
    while True:
        cv2.imshow(windowName, RS.get_image())

        if (cv2.waitKey(50) & 0xFF == ord('q')) or (cv2.getWindowProperty(windowName, cv2.WND_PROP_VISIBLE) < 1):
            break


def show_contours(RS):
    windowName = 'Contours preview'
    minContourArea = 500
    
    while True:
        image = RS.get_image()
        contours = RS.get_contours(image)

        for color_contour in contours:
            if color_contour is None:
                continue
            for contour in color_contour:
                if (contour is not None) and (cv2.contourArea(contour) > minContourArea):
                    cv2.drawContours(image, [contour], -1, (255, 255, 255), 2)

                    M = cv2.moments(contour)
                    if M["m00"] != 0:
                        cX = int(M["m10"] / M["m00"])
                        cY = int(M["m01"] / M["m00"])
                        cv2.circle(image, (cX, cY), 5, (0, 0, 0), -1)

        cv2.imshow('Contours preview', image)

        if (cv2.waitKey(100) & 0xFF == ord('q')) or (cv2.getWindowProperty(windowName, cv2.WND_PROP_VISIBLE) < 1):
            break


if __name__ == '__main__':
    print('[DEBUG] Launching...')

    # init basic entities
    RecSys = RecognitionUnit()
    SocExc = TCPUnit()

    # show_image(RecSys)
    show_contours(RecSys)

    print('[DEBUG] Program exit')
