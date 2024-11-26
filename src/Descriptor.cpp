#include "Descriptor.h"

void ORBDescriptor::compute(const Mat &image, vector<KeyPoint> &keypoints, Mat &descriptors) {
    Ptr<ORB> orb = ORB::create();
    orb->compute(image, keypoints, descriptors);
}
