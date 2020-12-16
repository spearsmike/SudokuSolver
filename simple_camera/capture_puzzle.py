import cv2
import sys


roi_ratio = 1
if len(sys.argv) != 2:
    sys.exit("missing camera index, try 0,1 or 2\nex. $./capture 0")
cap = cv2.VideoCapture(int(sys.argv[1]), cv2.CAP_DSHOW)
if not cap.isOpened():
    sys.exit("Error: Video Capture Not Opened")

cap.set(cv2.CAP_PROP_FPS, 30.0)
cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter.fourcc('m', 'j', 'p', 'g'))
cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter.fourcc('M', 'J', 'P', 'G'))
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1920)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 1080)

print("region of intrest box is at " + str(roi_ratio) + " size")
print("c = capture, q = quit")
while(cap.isOpened()):
    ret, frame = cap.read()
    original_frame = frame.copy()
    frame_h, frame_w, ch = frame.shape
    roi_length = int(min(frame.shape[0:2]) * roi_ratio)
    roi_y = (frame_h // 2) - (roi_length // 2)
    roi_x = (frame_w // 2) - (roi_length // 2)
    p1 = (roi_x, roi_y)
    p2 = (roi_x+roi_length, roi_y+roi_length)
    frame = cv2.rectangle(frame, p1, p2, (100, 0, 0), 4)
    cv2.namedWindow('frame', flags=(cv2.WINDOW_NORMAL + cv2.WINDOW_KEEPRATIO))
    cv2.resizeWindow('frame', 1280, 720)
    cv2.imshow('frame', frame)
    val = cv2.waitKey(1) & 0xFF
    if val == ord('q'):  # press q to quit
        break
    if val == ord('c'):
        cv2.imwrite('capture.jpg', original_frame)  # press c to capture image
        cv2.namedWindow('Capture', flags=(cv2.WINDOW_NORMAL + cv2.WINDOW_KEEPRATIO))
        cv2.resizeWindow('Capture', 1280, 720)
        cv2.imshow('Capture', original_frame)
        cv2.waitKey(0)
        cv2.destroyWindow('Capture')

cap.release()
cv2.destroyAllWindows()
