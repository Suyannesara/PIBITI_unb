
### Run this project:
```bash
make #🚀 to build the project
make go #🏃‍♀️ to generate and save the images with its keypoints at /data/processed/keypointImages
```

#### Versions
- OpenCV: 4.9.0

#### Implemented Detectors
- Harris Corner Detector
- Shi-Tomassi
- SURF
- FAST

#### Implemented Descriptors
- ORB
- SURF
- BRISK
- BRIEF
- HoG


TODOS:
- [] Feat to write keypoints and its descriptors in a .yaml
- [] Feat to choose dataset
- [] Feat to choose detector and descriptors

KENEDY Space center dataset
```bash
    wget http://www.ehu.es/ccwintco/uploads/2/26/KSC.mat
    wget http://www.ehu.es/ccwintco/uploads/a/a6/KSC_gt.mat
```

DOCS ÚTEIS:
- https://docs.opencv.org/4.9.0/d5/dde/tutorial_feature_description.html
- https://github.com/perdoch/hesaff
- https://github.com/ducha-aiki/hesaff-pytorch?tab=readme-ov-file
- https://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/filter_2d/filter_2d.html