#ifndef DETECTOR_H
#define DETECTOR_H

#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

class Detector {
public:
    virtual void detect(const Mat &image, vector<KeyPoint> &keypoints) = 0;
    virtual ~Detector() = default;
};

class HarrisDetector : public Detector {
public:
    void detect(const Mat &image, vector<KeyPoint> &keypoints) override;
};

class ShiTomassi : public Detector {
public:
    void detect(const Mat &image, vector<KeyPoint> &keypoints) override;
};

#endif // DETECTOR_H
