#include "Detector.h"
#include "Config.h"

void HarrisDetector::detect(const Mat &image, vector<KeyPoint> &keypoints) {
    Mat gray, harrisCorners, harrisNorm;

    cvtColor(image, gray, COLOR_BGR2GRAY);
    cornerHarris(gray, harrisCorners, 3, 3, 0.04);
    normalize(harrisCorners, harrisNorm, 0, 255, NORM_MINMAX, CV_32FC1);

    keypoints.clear();
    for (int y = 0; y < harrisNorm.rows; y++) {
        for (int x = 0; x < harrisNorm.cols; x++) {
            if ((int)harrisNorm.at<float>(y, x) > Config::harrisThreshold) {
                keypoints.emplace_back(Point2f(x, y), 1);
            }
        }
    }
}
