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

    while True:
        image = RS.run()

        for color in ColorsDict:
            if color.contour is not None:
                cv2.drawContours(image, [color.contour], -1, color.color, 2)
                cv2.circle(image, (color.x, color.y), 5, (255, 255, 255), -1)

        cv2.imshow(windowName, image)

        if (cv2.waitKey(100) == ord('q')) or (cv2.getWindowProperty(windowName, cv2.WND_PROP_VISIBLE) < 1):
            break


if __name__ == '__main__':
    print('[DEBUG] Launching...')

    # init basic entities
    RecSys = RecognitionUnit()
    # SocExc = TCPUnit()

    # show_image(RecSys)
    show_contours(RecSys)

    print('[DEBUG] Program exit')
