import numpy as np
from numpy.matlib import repmat
from sklearn.preprocessing import normalize
import matplotlib.pyplot as plt
import cv2


def kmeans(data, n_cl, verbose, max_iter=1):
    n_samples = data.shape[0]
    # init centers
    centers = data[np.random.choice(n_samples, size=n_cl)]
    old_labels = np.zeros(shape=n_samples)
    for _ in range(max_iter):
        # assign
        distances = np.zeros(shape=(n_samples, n_cl))
        for i, center in enumerate(centers):
            distances[:, i] = np.sum(
                np.square(data - repmat(center, n_samples, 1)), axis=1)
        new_labels = np.argmin(distances, axis=-1)
        # re-estimate
        for i in range(0, n_cl):
            centers[i] = np.mean(data[new_labels == i], axis=0)
        if verbose:
            fig, ax = plt.subplots()
            ax.scatter(data[:, 0], data[:, 1], c=new_labels, s=40)
            ax.plot(centers[:, 0], centers[:, 1], 'r*', markersize=20)
            plt.waitforbuttonpress()
            plt.close()
        # stop
        if np.all(new_labels == old_labels):
            break
        # update
        old_labels = new_labels

    return new_labels


videoCapture = cv2.VideoCapture('./road_video.mov')
videoCapture.isOpened()

fps = videoCapture.get(cv2.CAP_PROP_FPS)
size = (int(videoCapture.get(cv2.CAP_PROP_FRAME_WIDTH)),
        int(videoCapture.get(cv2.CAP_PROP_FRAME_HEIGHT)))

videoWriter = cv2.VideoWriter(
    './output.avi', cv2.VideoWriter_fourcc(*'XVID'), (fps / 10), size)

cnt = 0
while True:
    success, frame = videoCapture.read()
    if not success:
        break

    cnt += 1
    print(f'Processing image {cnt}...')
    h, w, c = frame.shape

    row_indexes = np.arange(0, h)
    col_indexes = np.arange(0, w)
    coordinates = np.zeros(shape=(h, w, 2))
    coordinates[..., 0] = normalize(repmat(row_indexes, w, 1).T)
    coordinates[..., 1] = normalize(repmat(col_indexes, h, 1))
    data = np.concatenate((frame, coordinates), axis=-1)
    data = np.reshape(data, newshape=(w * h, 5))

    labels = kmeans(data, n_cl=8, verbose=False)
    # labels = KMeans(data, n_cl=8, verbose=False)
    frame = (np.reshape(labels, (h, w)) * 255.0).astype('u1')

    videoWriter.write(frame)

videoCapture.release()
videoWriter.release()
