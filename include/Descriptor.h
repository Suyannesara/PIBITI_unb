#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H

#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

class Descriptor {
public:
    virtual void compute(const Mat &image, vector<KeyPoint> &keypoints, Mat &descriptors) = 0;
    virtual ~Descriptor() = default;
};

class ORBDescriptor: public Descriptor {
public:
    void compute(const Mat &image, vector<KeyPoint> &keypoints, Mat &descriptors) override;
};

// class SIFTDescriptor: public Descriptor {
// public:
//     void compute(const Mat &image, vector<KeyPoint> &keypoints, Mat &descriptors) override;
// };

class SURFDescriptor: public Descriptor {
public:
    void compute(const Mat &image, vector<KeyPoint> &keypoints, Mat &descriptors) override;
};

class BRISKDescriptor: public Descriptor {
public:
    void compute(const Mat &image, vector<KeyPoint> &keypoints, Mat &descriptors) override;
};

class BRIEFDescriptor: public Descriptor {
public:
    void compute(const Mat &image, vector<KeyPoint> &keypoints, Mat &descriptors) override;
};

#endif // DESCRIPTOR_H
