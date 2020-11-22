import cv2
from train import processFiles, trainSVM
from detector import Detector

# Replace these with the directories containing your
# positive and negative sample images, respectively.
pos_dir = "E:/SUSTech/5.0/Machine Learning/Lab7/Lab07/samples/vehicles"
neg_dir = "E:/SUSTech/5.0/Machine Learning/Lab7/Lab07/samples/non-vehicles"

# Replace this with the path to your test video file.
video_file = "E:/SUSTech/5.0/Machine Learning/Lab7/Lab07/videos/test_video.mp4"
# video_file = "videos/project_video.mp4"


def experiment():
    """
    Train a classifier and run it on a video using default settings
    without saving any files to disk.
    """

    # Extract HOG features from images in the sample directories and return
    # results and parameters in a dict.
    feature_data = processFiles(pos_dir, neg_dir, recurse=True,
                                hog_features=True)

    # Train SVM and return the classifier and parameters in a dict.
    # This function takes the dict from processFiles() as an input arg.
    classifier_data = trainSVM(feature_data=feature_data, C=1, fit_intercept=True, dual=False,
                               penalty='l2', output_file=True, output_filename="classifier.pkl")

    # TODO: If you have trained your classifier and prepare to detect the video,
    # uncomment the code below.

    # Instantiate a Detector object and load the dict from trainSVM().
    detector = Detector().loadClassifier(classifier_data=classifier_data)

    # Open a VideoCapture object for the video file.
    cap = cv2.VideoCapture(video_file)

    # Start the detector by supplying it with the VideoCapture object.
    # At this point, the video will be displayed, with bounding boxes
    # drawn around detected objects per the method detailed in README.md.
    detector.detectVideo(video_capture=cap)


if __name__ == "__main__":
    experiment()
