// Varibles and inputs goes here
#ifndef CONFIG_H
#define CONFIG_H

#include <string>

struct Config {
    static inline const std::string imagesFolderPath = "/home/suyanne/Documents/PIBIT/codes/computerVision/project/data/raw_datasets/Forest Segmented/images";
    static inline const std::string outputFolder = "/home/suyanne/Documents/PIBIT/codes/computerVision/project/data/processed/keypointImages";
    static inline int harrisThreshold = 100;
    static inline int limit = 40;

    // If the generated images in folder should be in grayscale or not
    static inline bool useGrayScale = true;
};

#endif