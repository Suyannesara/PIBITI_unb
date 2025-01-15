// Varibles and inputs goes here
#ifndef CONFIG_H
#define CONFIG_H

#include <string>

struct Config {
    // static inline const std::string imagesFolderPath = "/home/suyanne/Documents/PIBIT/codes/computerVision/project/data/raw_datasets/Forest Segmented/images";
    // static inline const std::string outputFolder = "/home/suyanne/Documents/PIBIT/codes/computerVision/project/data/processed/keypointImages/ForestSegmented";

    static inline const std::string imagesFolderPath = "/home/suyanne/Documents/PIBIT/codes/computerVision/project/data/raw_datasets/Forest Segmented/images";
    static inline const std::string outputFolder = "/home/suyanne/Documents/PIBIT/codes/computerVision/project/data/processed/keypointImages/ForestSegmented";
    // threshold = técnica utilizada em processamento de imagens para separar objetos de interesse dos do fundo com base na intensidade dos pixels.
    // os pixels acima do limiar são considerados objetos e os abaixo são o fundo
    static inline int threshold = 40;
    static inline int limit = 5;

    // If the generated images in folder should be in grayscale or not
    static inline bool useGrayScale = true;
    static inline const std::string keyPointsColor = "green";
};

#endif