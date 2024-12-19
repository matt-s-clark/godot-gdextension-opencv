#Change version here
version="4.10.0"

linkToOpenCVDownload="https://github.com/opencv/opencv/archive/refs/tags/${version}.zip"
linkToContribDownload="https://github.com/opencv/opencv_contrib/archive/refs/tags/${version}.zip"

installPath=$(realpath opencvSetup.sh)

cd opencv

# Downloading opencv from $linkToOpenCVDownload

wget -O opencv.zip $linkToOpenCVDownload
unzip -o opencv.zip
mv -f opencv-${version} opencv

# Downloading opencv contrib modules from $linkToContribDownload

wget -O contrib.zip $linkToContribDownload
unzip -o contrib.zip
mv -f opencv_contrib-${version} contrib

mkdir build
cd build

cmake -DOPENCV_EXTRA_MODULES_PATH=../contrib/modules ../opencv -DCMAKE_INSTALL_PREFIX:PATH=${installPath%/*}/opencv/install -DBUILD_JPEG:BOOL=ON -DWITH_JPEG:BOOL=ON
make
make install