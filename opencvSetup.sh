#Change version here
version="4.10.0"

# Should Download, or use the files already downloaded
sd=true

linkToOpenCVDownload="https://github.com/opencv/opencv/archive/refs/tags/${version}.zip"
linkToContribDownload="https://github.com/opencv/opencv_contrib/archive/refs/tags/${version}.zip"

installPath=$(realpath opencvSetup.sh)

# Parser to update the previous options
for ARGUMENT in "$@"
do
   KEY=$(echo $ARGUMENT | cut -f1 -d=)

   KEY_LENGTH=${#KEY}
   VALUE="${ARGUMENT:$KEY_LENGTH+1}"

   export "$KEY"="$VALUE"
done

cd opencv

if $sd; then
	# Downloading opencv from $linkToOpenCVDownload

	wget -O opencv.zip $linkToOpenCVDownload
	unzip -o opencv.zip
	mv -f opencv-${version} opencv

	# Downloading opencv contrib modules from $linkToContribDownload

	wget -O contrib.zip $linkToContribDownload
	unzip -o contrib.zip
	mv -f opencv_contrib-${version} contrib
fi

mkdir build
cd build

cmake -DOPENCV_EXTRA_MODULES_PATH=../contrib/modules ../opencv -DCMAKE_INSTALL_PREFIX:PATH=${installPath%/*}/opencv/install -DBUILD_JPEG:BOOL=OFF -DOPENCV_DOWNLOAD_PATH=/tmp/opencv-cache -DENABLE_CONFIG_VERIFICATION=ON -DWITH_TESSERACT=OFF -DWITH_LAPACK=OFF -DWITH_VA_INTEL=OFF -DWITH_VA=OFF -DWITH_OPENCLAMDBLAS=OFF -DWITH_JASPER=OFF -DWITH_GTK_2_X=ON -DWITH_GSTREAMER=OFF -DWITH_EIGEN=OFF -DWITH_VTK=OFF -DWITH_OPENCLAMDFFT=OFF
make
make install

# Cleanup
cd ..
rm opencv.zip
rm contrib.zip
rm -r opencv-${version}
rm -r opencv_contrib-${version}