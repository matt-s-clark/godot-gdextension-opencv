class_name CVConsts

## Video Capture Enums
enum VideoCaptureAPIs{
CAP_ANY=0,
CAP_VFW=200,
CAP_V4L=200,
CAP_V4L2=CAP_V4L,
CAP_FIREWIRE=300,
CAP_FIREWARE=CAP_FIREWIRE,
CAP_IEEE1394=CAP_FIREWIRE,
CAP_DC1394=CAP_FIREWIRE,
CAP_CMU1394=CAP_FIREWIRE,
CAP_QT=500,
CAP_UNICAP=600,
CAP_DSHOW=700,
CAP_PVAPI=800,
CAP_OPENNI=900,
CAP_OPENNI_ASUS=910,
CAP_ANDROID=1000,
CAP_XIAPI=1100,
CAP_AVFOUNDATION=1200,
CAP_GIGANETIX=1300,
CAP_MSMF=1400,
CAP_WINRT=1410,
CAP_INTELPERC=1500,
CAP_REALSENSE=1500,
CAP_OPENNI2=1600,
CAP_OPENNI2_ASUS=1610,
CAP_OPENNI2_ASTRA=1620,
CAP_GPHOTO2=1700,
CAP_GSTREAMER=1800,
CAP_FFMPEG=1900,
CAP_IMAGES=2000,
CAP_ARAVIS=2100,
CAP_OPENCV_MJPEG=2200,
CAP_INTEL_MFX=2300,
CAP_XINE=2400,
CAP_UEYE=2500,
CAP_OBSENSOR=2600
}

enum VideoCaptureProperties{
CAP_PROP_POS_MSEC=0,
CAP_PROP_POS_FRAMES=1,
CAP_PROP_POS_AVI_RATIO=2,
CAP_PROP_FRAME_WIDTH=3,
CAP_PROP_FRAME_HEIGHT=4,
CAP_PROP_FPS=5,
CAP_PROP_FOURCC=6,
CAP_PROP_FRAME_COUNT=7,
CAP_PROP_FORMAT=8,
CAP_PROP_MODE=9,
CAP_PROP_BRIGHTNESS=10,
CAP_PROP_CONTRAST=11,
CAP_PROP_SATURATION=12,
CAP_PROP_HUE=13,
CAP_PROP_GAIN=14,
CAP_PROP_EXPOSURE=15,
CAP_PROP_CONVERT_RGB=16,
CAP_PROP_WHITE_BALANCE_BLUE_U=17,
CAP_PROP_RECTIFICATION=18,
CAP_PROP_MONOCHROME=19,
CAP_PROP_SHARPNESS=20,
CAP_PROP_AUTO_EXPOSURE=21,
CAP_PROP_GAMMA=22,
CAP_PROP_TEMPERATURE=23,
CAP_PROP_TRIGGER=24,
CAP_PROP_TRIGGER_DELAY=25,
CAP_PROP_WHITE_BALANCE_RED_V=26,
CAP_PROP_ZOOM=27,
CAP_PROP_FOCUS=28,
CAP_PROP_GUID=29,
CAP_PROP_ISO_SPEED=30,
CAP_PROP_BACKLIGHT=32,
CAP_PROP_PAN=33,
CAP_PROP_TILT=34,
CAP_PROP_ROLL=35,
CAP_PROP_IRIS=36,
CAP_PROP_SETTINGS=37,
CAP_PROP_BUFFERSIZE=38,
CAP_PROP_AUTOFOCUS=39,
CAP_PROP_SAR_NUM=40,
CAP_PROP_SAR_DEN=41,
CAP_PROP_BACKEND=42,
CAP_PROP_CHANNEL=43,
CAP_PROP_AUTO_WB=44,
CAP_PROP_WB_TEMPERATURE=45,
CAP_PROP_CODEC_PIXEL_FORMAT=46,
CAP_PROP_BITRATE=47,
CAP_PROP_ORIENTATION_META=48,
CAP_PROP_ORIENTATION_AUTO=49,
CAP_PROP_HW_ACCELERATION=50,
CAP_PROP_HW_DEVICE=51,
CAP_PROP_HW_ACCELERATION_USE_OPENCL=52,
CAP_PROP_OPEN_TIMEOUT_MSEC=53,
CAP_PROP_READ_TIMEOUT_MSEC=54,
CAP_PROP_STREAM_OPEN_TIME_USEC=55,
CAP_PROP_VIDEO_TOTAL_CHANNELS=56,
CAP_PROP_VIDEO_STREAM=57,
CAP_PROP_AUDIO_STREAM=58,
CAP_PROP_AUDIO_POS=59,
CAP_PROP_AUDIO_SHIFT_NSEC=60,
CAP_PROP_AUDIO_DATA_DEPTH=61,
CAP_PROP_AUDIO_SAMPLES_PER_SECOND=62,
CAP_PROP_AUDIO_BASE_INDEX=63,
CAP_PROP_AUDIO_TOTAL_CHANNELS=64,
CAP_PROP_AUDIO_TOTAL_STREAMS=65,
CAP_PROP_AUDIO_SYNCHRONIZE=66,
CAP_PROP_LRF_HAS_KEY_FRAME=67,
CAP_PROP_CODEC_EXTRADATA_INDEX=68,
CAP_PROP_FRAME_TYPE=69,
CAP_PROP_N_THREADS=70
}

enum VideoWriterProperties{
VIDEOWRITER_PROP_QUALITY=1,
VIDEOWRITER_PROP_FRAMEBYTES=2,
VIDEOWRITER_PROP_NSTRIPES=3,
VIDEOWRITER_PROP_IS_COLOR=4,
VIDEOWRITER_PROP_DEPTH=5,
VIDEOWRITER_PROP_HW_ACCELERATION=6,
VIDEOWRITER_PROP_HW_DEVICE=7,
VIDEOWRITER_PROP_HW_ACCELERATION_USE_OPENCL=8,
VIDEOWRITER_PROP_RAW_VIDEO=9,
VIDEOWRITER_PROP_KEY_INTERVAL=10,
VIDEOWRITER_PROP_KEY_FLAG=11
}

enum VideoAccelerationType{
VIDEO_ACCELERATION_NONE=0,
VIDEO_ACCELERATION_ANY=1,
VIDEO_ACCELERATION_D3D11=2,
VIDEO_ACCELERATION_VAAPI=3,
VIDEO_ACCELERATION_MFX=4
}
enum {
CAP_PROP_DC1394_OFF=-4,
CAP_PROP_DC1394_MODE_MANUAL=-3,
CAP_PROP_DC1394_MODE_AUTO=-2,
CAP_PROP_DC1394_MODE_ONE_PUSH_AUTO=-1,
CAP_PROP_DC1394_MAX=31
}

enum {
CAP_OPENNI_DEPTH_GENERATOR=1<<31,
CAP_OPENNI_IMAGE_GENERATOR=1<<30,
CAP_OPENNI_IR_GENERATOR=1<<29,
CAP_OPENNI_GENERATORS_MASK=CAP_OPENNI_DEPTH_GENERATOR+CAP_OPENNI_IMAGE_GENERATOR+CAP_OPENNI_IR_GENERATOR
}

enum {
CAP_PROP_OPENNI_OUTPUT_MODE=100,
CAP_PROP_OPENNI_FRAME_MAX_DEPTH=101,
CAP_PROP_OPENNI_BASELINE=102,
CAP_PROP_OPENNI_FOCAL_LENGTH=103,
CAP_PROP_OPENNI_REGISTRATION=104,
CAP_PROP_OPENNI_REGISTRATION_ON=CAP_PROP_OPENNI_REGISTRATION,
CAP_PROP_OPENNI_APPROX_FRAME_SYNC=105,
CAP_PROP_OPENNI_MAX_BUFFER_SIZE=106,
CAP_PROP_OPENNI_CIRCLE_BUFFER=107,
CAP_PROP_OPENNI_MAX_TIME_DURATION=108,
CAP_PROP_OPENNI_GENERATOR_PRESENT=109,
CAP_PROP_OPENNI2_SYNC=110,
CAP_PROP_OPENNI2_MIRROR=111
}

enum {
CAP_OPENNI_IMAGE_GENERATOR_PRESENT=CAP_OPENNI_IMAGE_GENERATOR+CAP_PROP_OPENNI_GENERATOR_PRESENT,
CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE=CAP_OPENNI_IMAGE_GENERATOR+CAP_PROP_OPENNI_OUTPUT_MODE,
CAP_OPENNI_DEPTH_GENERATOR_PRESENT=CAP_OPENNI_DEPTH_GENERATOR+CAP_PROP_OPENNI_GENERATOR_PRESENT,
CAP_OPENNI_DEPTH_GENERATOR_BASELINE=CAP_OPENNI_DEPTH_GENERATOR+CAP_PROP_OPENNI_BASELINE,
CAP_OPENNI_DEPTH_GENERATOR_FOCAL_LENGTH=CAP_OPENNI_DEPTH_GENERATOR+CAP_PROP_OPENNI_FOCAL_LENGTH,
CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION=CAP_OPENNI_DEPTH_GENERATOR+CAP_PROP_OPENNI_REGISTRATION,
CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION_ON=CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION,
CAP_OPENNI_IR_GENERATOR_PRESENT=CAP_OPENNI_IR_GENERATOR+CAP_PROP_OPENNI_GENERATOR_PRESENT
}

enum {
CAP_OPENNI_DEPTH_MAP=0,
CAP_OPENNI_POINT_CLOUD_MAP=1,
CAP_OPENNI_DISPARITY_MAP=2,
CAP_OPENNI_DISPARITY_MAP_32F=3,
CAP_OPENNI_VALID_DEPTH_MASK=4,
CAP_OPENNI_BGR_IMAGE=5,
CAP_OPENNI_GRAY_IMAGE=6,
CAP_OPENNI_IR_IMAGE=7
}

enum {
CAP_OPENNI_VGA_30HZ=0,
CAP_OPENNI_SXGA_15HZ=1,
CAP_OPENNI_SXGA_30HZ=2,
CAP_OPENNI_QVGA_30HZ=3,
CAP_OPENNI_QVGA_60HZ=4
}

enum {CAP_PROP_GSTREAMER_QUEUE_LENGTH=200}

enum {
CAP_PROP_PVAPI_MULTICASTIP=300,
CAP_PROP_PVAPI_FRAMESTARTTRIGGERMODE=301,
CAP_PROP_PVAPI_DECIMATIONHORIZONTAL=302,
CAP_PROP_PVAPI_DECIMATIONVERTICAL=303,
CAP_PROP_PVAPI_BINNINGX=304,
CAP_PROP_PVAPI_BINNINGY=305,
CAP_PROP_PVAPI_PIXELFORMAT=306
}

enum {
CAP_PVAPI_FSTRIGMODE_FREERUN=0,
CAP_PVAPI_FSTRIGMODE_SYNCIN1=1,
CAP_PVAPI_FSTRIGMODE_SYNCIN2=2,
CAP_PVAPI_FSTRIGMODE_FIXEDRATE=3,
CAP_PVAPI_FSTRIGMODE_SOFTWARE=4
}

enum {
CAP_PVAPI_DECIMATION_OFF=1,
CAP_PVAPI_DECIMATION_2OUTOF4=2,
CAP_PVAPI_DECIMATION_2OUTOF8=4,
CAP_PVAPI_DECIMATION_2OUTOF16=8
}

enum {
CAP_PVAPI_PIXELFORMAT_MONO8=1,
CAP_PVAPI_PIXELFORMAT_MONO16=2,
CAP_PVAPI_PIXELFORMAT_BAYER8=3,
CAP_PVAPI_PIXELFORMAT_BAYER16=4,
CAP_PVAPI_PIXELFORMAT_RGB24=5,
CAP_PVAPI_PIXELFORMAT_BGR24=6,
CAP_PVAPI_PIXELFORMAT_RGBA32=7,
CAP_PVAPI_PIXELFORMAT_BGRA32=8
}

enum {
CAP_PROP_XI_DOWNSAMPLING=400,
CAP_PROP_XI_DATA_FORMAT=401,
CAP_PROP_XI_OFFSET_X=402,
CAP_PROP_XI_OFFSET_Y=403,
CAP_PROP_XI_TRG_SOURCE=404,
CAP_PROP_XI_TRG_SOFTWARE=405,
CAP_PROP_XI_GPI_SELECTOR=406,
CAP_PROP_XI_GPI_MODE=407,
CAP_PROP_XI_GPI_LEVEL=408,
CAP_PROP_XI_GPO_SELECTOR=409,
CAP_PROP_XI_GPO_MODE=410,
CAP_PROP_XI_LED_SELECTOR=411,
CAP_PROP_XI_LED_MODE=412,
CAP_PROP_XI_MANUAL_WB=413,
CAP_PROP_XI_AUTO_WB=414,
CAP_PROP_XI_AEAG=415,
CAP_PROP_XI_EXP_PRIORITY=416,
CAP_PROP_XI_AE_MAX_LIMIT=417,
CAP_PROP_XI_AG_MAX_LIMIT=418,
CAP_PROP_XI_AEAG_LEVEL=419,
CAP_PROP_XI_TIMEOUT=420,
CAP_PROP_XI_EXPOSURE=421,
CAP_PROP_XI_EXPOSURE_BURST_COUNT=422,
CAP_PROP_XI_GAIN_SELECTOR=423,
CAP_PROP_XI_GAIN=424,
CAP_PROP_XI_DOWNSAMPLING_TYPE=426,
CAP_PROP_XI_BINNING_SELECTOR=427,
CAP_PROP_XI_BINNING_VERTICAL=428,
CAP_PROP_XI_BINNING_HORIZONTAL=429,
CAP_PROP_XI_BINNING_PATTERN=430,
CAP_PROP_XI_DECIMATION_SELECTOR=431,
CAP_PROP_XI_DECIMATION_VERTICAL=432,
CAP_PROP_XI_DECIMATION_HORIZONTAL=433,
CAP_PROP_XI_DECIMATION_PATTERN=434,
CAP_PROP_XI_TEST_PATTERN_GENERATOR_SELECTOR=587,
CAP_PROP_XI_TEST_PATTERN=588,
CAP_PROP_XI_IMAGE_DATA_FORMAT=435,
CAP_PROP_XI_SHUTTER_TYPE=436,
CAP_PROP_XI_SENSOR_TAPS=437,
CAP_PROP_XI_AEAG_ROI_OFFSET_X=439,
CAP_PROP_XI_AEAG_ROI_OFFSET_Y=440,
CAP_PROP_XI_AEAG_ROI_WIDTH=441,
CAP_PROP_XI_AEAG_ROI_HEIGHT=442,
CAP_PROP_XI_BPC=445,
CAP_PROP_XI_WB_KR=448,
CAP_PROP_XI_WB_KG=449,
CAP_PROP_XI_WB_KB=450,
CAP_PROP_XI_WIDTH=451,
CAP_PROP_XI_HEIGHT=452,
CAP_PROP_XI_REGION_SELECTOR=589,
CAP_PROP_XI_REGION_MODE=595,
CAP_PROP_XI_LIMIT_BANDWIDTH=459,
CAP_PROP_XI_SENSOR_DATA_BIT_DEPTH=460,
CAP_PROP_XI_OUTPUT_DATA_BIT_DEPTH=461,
CAP_PROP_XI_IMAGE_DATA_BIT_DEPTH=462,
CAP_PROP_XI_OUTPUT_DATA_PACKING=463,
CAP_PROP_XI_OUTPUT_DATA_PACKING_TYPE=464,
CAP_PROP_XI_IS_COOLED=465,
CAP_PROP_XI_COOLING=466,
CAP_PROP_XI_TARGET_TEMP=467,
CAP_PROP_XI_CHIP_TEMP=468,
CAP_PROP_XI_HOUS_TEMP=469,
CAP_PROP_XI_HOUS_BACK_SIDE_TEMP=590,
CAP_PROP_XI_SENSOR_BOARD_TEMP=596,
CAP_PROP_XI_CMS=470,
CAP_PROP_XI_APPLY_CMS=471,
CAP_PROP_XI_IMAGE_IS_COLOR=474,
CAP_PROP_XI_COLOR_FILTER_ARRAY=475,
CAP_PROP_XI_GAMMAY=476,
CAP_PROP_XI_GAMMAC=477,
CAP_PROP_XI_SHARPNESS=478,
CAP_PROP_XI_CC_MATRIX_00=479,
CAP_PROP_XI_CC_MATRIX_01=480,
CAP_PROP_XI_CC_MATRIX_02=481,
CAP_PROP_XI_CC_MATRIX_03=482,
CAP_PROP_XI_CC_MATRIX_10=483,
CAP_PROP_XI_CC_MATRIX_11=484,
CAP_PROP_XI_CC_MATRIX_12=485,
CAP_PROP_XI_CC_MATRIX_13=486,
CAP_PROP_XI_CC_MATRIX_20=487,
CAP_PROP_XI_CC_MATRIX_21=488,
CAP_PROP_XI_CC_MATRIX_22=489,
CAP_PROP_XI_CC_MATRIX_23=490,
CAP_PROP_XI_CC_MATRIX_30=491,
CAP_PROP_XI_CC_MATRIX_31=492,
CAP_PROP_XI_CC_MATRIX_32=493,
CAP_PROP_XI_CC_MATRIX_33=494,
CAP_PROP_XI_DEFAULT_CC_MATRIX=495,
CAP_PROP_XI_TRG_SELECTOR=498,
CAP_PROP_XI_ACQ_FRAME_BURST_COUNT=499,
CAP_PROP_XI_DEBOUNCE_EN=507,
CAP_PROP_XI_DEBOUNCE_T0=508,
CAP_PROP_XI_DEBOUNCE_T1=509,
CAP_PROP_XI_DEBOUNCE_POL=510,
CAP_PROP_XI_LENS_MODE=511,
CAP_PROP_XI_LENS_APERTURE_VALUE=512,
CAP_PROP_XI_LENS_FOCUS_MOVEMENT_VALUE=513,
CAP_PROP_XI_LENS_FOCUS_MOVE=514,
CAP_PROP_XI_LENS_FOCUS_DISTANCE=515,
CAP_PROP_XI_LENS_FOCAL_LENGTH=516,
CAP_PROP_XI_LENS_FEATURE_SELECTOR=517,
CAP_PROP_XI_LENS_FEATURE=518,
CAP_PROP_XI_DEVICE_MODEL_ID=521,
CAP_PROP_XI_DEVICE_SN=522,
CAP_PROP_XI_IMAGE_DATA_FORMAT_RGB32_ALPHA=529,
CAP_PROP_XI_IMAGE_PAYLOAD_SIZE=530,
CAP_PROP_XI_TRANSPORT_PIXEL_FORMAT=531,
CAP_PROP_XI_SENSOR_CLOCK_FREQ_HZ=532,
CAP_PROP_XI_SENSOR_CLOCK_FREQ_INDEX=533,
CAP_PROP_XI_SENSOR_OUTPUT_CHANNEL_COUNT=534,
CAP_PROP_XI_FRAMERATE=535,
CAP_PROP_XI_COUNTER_SELECTOR=536,
CAP_PROP_XI_COUNTER_VALUE=537,
CAP_PROP_XI_ACQ_TIMING_MODE=538,
CAP_PROP_XI_AVAILABLE_BANDWIDTH=539,
CAP_PROP_XI_BUFFER_POLICY=540,
CAP_PROP_XI_LUT_EN=541,
CAP_PROP_XI_LUT_INDEX=542,
CAP_PROP_XI_LUT_VALUE=543,
CAP_PROP_XI_TRG_DELAY=544,
CAP_PROP_XI_TS_RST_MODE=545,
CAP_PROP_XI_TS_RST_SOURCE=546,
CAP_PROP_XI_IS_DEVICE_EXIST=547,
CAP_PROP_XI_ACQ_BUFFER_SIZE=548,
CAP_PROP_XI_ACQ_BUFFER_SIZE_UNIT=549,
CAP_PROP_XI_ACQ_TRANSPORT_BUFFER_SIZE=550,
CAP_PROP_XI_BUFFERS_QUEUE_SIZE=551,
CAP_PROP_XI_ACQ_TRANSPORT_BUFFER_COMMIT=552,
CAP_PROP_XI_RECENT_FRAME=553,
CAP_PROP_XI_DEVICE_RESET=554,
CAP_PROP_XI_COLUMN_FPN_CORRECTION=555,
CAP_PROP_XI_ROW_FPN_CORRECTION=591,
CAP_PROP_XI_SENSOR_MODE=558,
CAP_PROP_XI_HDR=559,
CAP_PROP_XI_HDR_KNEEPOINT_COUNT=560,
CAP_PROP_XI_HDR_T1=561,
CAP_PROP_XI_HDR_T2=562,
CAP_PROP_XI_KNEEPOINT1=563,
CAP_PROP_XI_KNEEPOINT2=564,
CAP_PROP_XI_IMAGE_BLACK_LEVEL=565,
CAP_PROP_XI_HW_REVISION=571,
CAP_PROP_XI_DEBUG_LEVEL=572,
CAP_PROP_XI_AUTO_BANDWIDTH_CALCULATION=573,
CAP_PROP_XI_FFS_FILE_ID=594,
CAP_PROP_XI_FFS_FILE_SIZE=580,
CAP_PROP_XI_FREE_FFS_SIZE=581,
CAP_PROP_XI_USED_FFS_SIZE=582,
CAP_PROP_XI_FFS_ACCESS_KEY=583,
CAP_PROP_XI_SENSOR_FEATURE_SELECTOR=585,
CAP_PROP_XI_SENSOR_FEATURE_VALUE=586
}

enum {CAP_PROP_ARAVIS_AUTOTRIGGER=600}

enum {
CAP_PROP_IOS_DEVICE_FOCUS=9001,
CAP_PROP_IOS_DEVICE_EXPOSURE=9002,
CAP_PROP_IOS_DEVICE_FLASH=9003,
CAP_PROP_IOS_DEVICE_WHITEBALANCE=9004,
CAP_PROP_IOS_DEVICE_TORCH=9005
}

enum {
CAP_PROP_GIGA_FRAME_OFFSET_X=10001,
CAP_PROP_GIGA_FRAME_OFFSET_Y=10002,
CAP_PROP_GIGA_FRAME_WIDTH_MAX=10003,
CAP_PROP_GIGA_FRAME_HEIGH_MAX=10004,
CAP_PROP_GIGA_FRAME_SENS_WIDTH=10005,
CAP_PROP_GIGA_FRAME_SENS_HEIGH=10006
}

enum {
CAP_PROP_INTELPERC_PROFILE_COUNT=11001,
CAP_PROP_INTELPERC_PROFILE_IDX=11002,
CAP_PROP_INTELPERC_DEPTH_LOW_CONFIDENCE_VALUE=11003,
CAP_PROP_INTELPERC_DEPTH_SATURATION_VALUE=11004,
CAP_PROP_INTELPERC_DEPTH_CONFIDENCE_THRESHOLD=11005,
CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_HORZ=11006,
CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_VERT=11007
}

enum {
CAP_INTELPERC_DEPTH_GENERATOR=1<<29,
CAP_INTELPERC_IMAGE_GENERATOR=1<<28,
CAP_INTELPERC_IR_GENERATOR=1<<27,
CAP_INTELPERC_GENERATORS_MASK=CAP_INTELPERC_DEPTH_GENERATOR+CAP_INTELPERC_IMAGE_GENERATOR+CAP_INTELPERC_IR_GENERATOR
}

enum {
CAP_INTELPERC_DEPTH_MAP=0,
CAP_INTELPERC_UVDEPTH_MAP=1,
CAP_INTELPERC_IR_MAP=2,
CAP_INTELPERC_IMAGE=3
}

enum {
CAP_PROP_GPHOTO2_PREVIEW=17001,
CAP_PROP_GPHOTO2_WIDGET_ENUMERATE=17002,
CAP_PROP_GPHOTO2_RELOAD_CONFIG=17003,
CAP_PROP_GPHOTO2_RELOAD_ON_CHANGE=17004,
CAP_PROP_GPHOTO2_COLLECT_MSGS=17005,
CAP_PROP_GPHOTO2_FLUSH_MSGS=17006,
CAP_PROP_SPEED=17007,
CAP_PROP_APERTURE=17008,
CAP_PROP_EXPOSUREPROGRAM=17009,
CAP_PROP_VIEWFINDER=17010
}

enum {
CAP_PROP_IMAGES_BASE=18000,
CAP_PROP_IMAGES_LAST=19000
}

enum VideoCaptureOBSensorDataType{
CAP_OBSENSOR_DEPTH_MAP=0,
CAP_OBSENSOR_BGR_IMAGE=1,
CAP_OBSENSOR_IR_IMAGE=2
}

enum VideoCaptureOBSensorGenerators{
CAP_OBSENSOR_DEPTH_GENERATOR=1<<29,
CAP_OBSENSOR_IMAGE_GENERATOR=1<<28,
CAP_OBSENSOR_IR_GENERATOR=1<<27,
CAP_OBSENSOR_GENERATORS_MASK=CAP_OBSENSOR_DEPTH_GENERATOR+CAP_OBSENSOR_IMAGE_GENERATOR+CAP_OBSENSOR_IR_GENERATOR
}

enum VideoCaptureOBSensorProperties{
CAP_PROP_OBSENSOR_INTRINSIC_FX=26001,
CAP_PROP_OBSENSOR_INTRINSIC_FY=26002,
CAP_PROP_OBSENSOR_INTRINSIC_CX=26003,
CAP_PROP_OBSENSOR_INTRINSIC_CY=26004
}

## Mat Types
enum MatType { 
	CV_8U=0, 
	CV_8S=1, 
	CV_16U=2, 
	CV_16S=3, 
	CV_32S=4, 
	CV_32F=5, 
	CV_64F=6,
	
	CV_8UC1=CV_8U, 
	CV_8SC1=CV_8S, 
	CV_16UC1=CV_16U, 
	CV_16SC1=CV_16S, 
	CV_32SC1=CV_32S, 
	CV_32FC1=CV_32F, 
	CV_64FC1=CV_64F,
	
	CV_8UC2=CV_8U+8, 
	CV_8SC2=CV_8S+8, 
	CV_16UC2=CV_16U+8, 
	CV_16SC2=CV_16S+8, 
	CV_32SC2=CV_32S+8, 
	CV_32FC2=CV_32F+8, 
	CV_64FC2=CV_64F+8,
	
	CV_8UC3=CV_8U+16, 
	CV_8SC3=CV_8S+16, 
	CV_16UC3=CV_16U+16, 
	CV_16SC3=CV_16S+16, 
	CV_32SC3=CV_32S+16, 
	CV_32FC3=CV_32F+16, 
	CV_64FC3=CV_64F+16,
	
	CV_8UC4=CV_8U+24, 
	CV_8SC4=CV_8S+24, 
	CV_16UC4=CV_16U+24, 
	CV_16SC4=CV_16S+24, 
	CV_32SC4=CV_32S+24, 
	CV_32FC4=CV_32F+24, 
	CV_64FC4=CV_64F+24,
}

## Core Enums
enum CovarFlags {
  COVAR_SCRAMBLED = 0 ,
  COVAR_NORMAL = 1 ,
  COVAR_USE_AVG = 2 ,
  COVAR_SCALE = 4 ,
  COVAR_ROWS = 8 ,
  COVAR_COLS = 16
}

enum KmeansFlags {
  KMEANS_RANDOM_CENTERS = 0 ,
  KMEANS_PP_CENTERS = 2 ,
  KMEANS_USE_INITIAL_LABELS = 1
}

enum Param {
  INT =0 ,
  BOOLEAN =1 ,
  REAL =2 ,
  STRING =3 ,
  MAT =4 ,
  MAT_VECTOR =5 ,
  ALGORITHM =6 ,
  FLOAT =7 ,
  UNSIGNED_INT =8 ,
  UINT64 =9 ,
  UCHAR =11 ,
  SCALAR =12
}

enum ReduceTypes {
  REDUCE_SUM = 0 ,
  REDUCE_AVG = 1 ,
  REDUCE_MAX = 2 ,
  REDUCE_MIN = 3 ,
  REDUCE_SUM2 = 4
}

enum RotateFlags {
  ROTATE_90_CLOCKWISE = 0 ,
  ROTATE_180 = 1 ,
  ROTATE_90_COUNTERCLOCKWISE = 2
}

enum SortFlags {
  SORT_EVERY_ROW = 0 ,
  SORT_EVERY_COLUMN = 1 ,
  SORT_ASCENDING = 0 ,
  SORT_DESCENDING = 16
}

enum  	BorderTypes {
  BORDER_CONSTANT = 0,
  BORDER_REPLICATE = 1,
  BORDER_REFLECT = 2,
  BORDER_WRAP = 3,
  BORDER_REFLECT_101 = 4,
  BORDER_TRANSPARENT = 5,
  BORDER_REFLECT101 = BORDER_REFLECT_101,
  BORDER_DEFAULT = BORDER_REFLECT_101,
  BORDER_ISOLATED = 16
}
 
enum  	CmpTypes {
  CMP_EQ = 0,
  CMP_GT = 1,
  CMP_GE = 2,
  CMP_LT = 3,
  CMP_LE = 4,
  CMP_NE = 5
}
 
enum  	ErrorCode {
  ErrorStsOk = 0,
  ErrorStsBackTrace = -1,
  ErrorStsError = -2,
  ErrorStsInternal = -3,
  ErrorStsNoMem = -4,
  ErrorStsBadArg = -5,
  ErrorStsBadFunc = -6,
  ErrorStsNoConv = -7,
  ErrorStsAutoTrace = -8,
  ErrorHeaderIsNull = -9,
  ErrorBadImageSize = -10,
  ErrorBadOffset = -11,
  ErrorBadDataPtr = -12,
  ErrorBadStep = -13,
  ErrorBadModelOrChSeq = -14,
  ErrorBadNumChannels = -15,
  ErrorBadNumChannel1U = -16,
  ErrorBadDepth = -17,
  ErrorBadAlphaChannel = -18,
  ErrorBadOrder = -19,
  ErrorBadOrigin = -20,
  ErrorBadAlign = -21,
  ErrorBadCallBack = -22,
  ErrorBadTileSize = -23,
  ErrorBadCOI = -24,
  ErrorBadROISize = -25,
  ErrorMaskIsTiled = -26,
  ErrorStsNullPtr = -27,
  ErrorStsVecLengthErr = -28,
  ErrorStsFilterStructContentErr = -29,
  ErrorStsKernelStructContentErr = -30,
  ErrorStsFilterOffsetErr = -31,
  ErrorStsBadSize = -201,
  ErrorStsDivByZero = -202,
  ErrorStsInplaceNotSupported = -203,
  ErrorStsObjectNotFound = -204,
  ErrorStsUnmatchedFormats = -205,
  ErrorStsBadFlag = -206,
  ErrorStsBadPoint = -207,
  ErrorStsBadMask = -208,
  ErrorStsUnmatchedSizes = -209,
  ErrorStsUnsupportedFormat = -210,
  ErrorStsOutOfRange = -211,
  ErrorStsParseError = -212,
  ErrorStsNotImplemented = -213,
  ErrorStsBadMemBlock = -214,
  ErrorStsAssert = -215,
  ErrorGpuNotSupported = -216,
  ErrorGpuApiCallError = -217,
  ErrorOpenGlNotSupported = -218,
  ErrorOpenGlApiCallError = -219,
  ErrorOpenCLApiCallError = -220,
  ErrorOpenCLDoubleNotSupported = -221,
  ErrorOpenCLInitError = -222,
  ErrorOpenCLNoAMDBlasFft = -223
}
 
enum  	DecompTypes {
  DECOMP_LU = 0,
  DECOMP_SVD = 1,
  DECOMP_EIG = 2,
  DECOMP_CHOLESKY = 3,
  DECOMP_QR = 4,
  DECOMP_NORMAL = 16
}
 
enum  	DftFlags {
  DFT_INVERSE = 1,
  DFT_SCALE = 2,
  DFT_ROWS = 4,
  DFT_COMPLEX_OUTPUT = 16,
  DFT_REAL_OUTPUT = 32,
  DFT_COMPLEX_INPUT = 64,
  DCT_INVERSE = DFT_INVERSE,
  DCT_ROWS = DFT_ROWS
}
 
enum  	GemmFlags {
  GEMM_1_T = 1,
  GEMM_2_T = 2,
  GEMM_3_T = 4
}
 
enum  	NormTypes {
  NORM_INF = 1,
  NORM_L1 = 2,
  NORM_L2 = 4,
  NORM_L2SQR = 5,
  NORM_HAMMING = 6,
  NORM_HAMMING2 = 7,
  NORM_TYPE_MASK = 7,
  NORM_RELATIVE = 8,
  NORM_MINMAX = 32
}

#imgproc

enum ColorConversionCodes {
  COLOR_BGR2BGRA = 0,
  COLOR_RGB2RGBA = COLOR_BGR2BGRA,
  COLOR_BGRA2BGR = 1,
  COLOR_RGBA2RGB = COLOR_BGRA2BGR,
  COLOR_BGR2RGBA = 2,
  COLOR_RGB2BGRA = COLOR_BGR2RGBA,
  COLOR_RGBA2BGR = 3,
  COLOR_BGRA2RGB = COLOR_RGBA2BGR,
  COLOR_BGR2RGB = 4,
  COLOR_RGB2BGR = COLOR_BGR2RGB,
  COLOR_BGRA2RGBA = 5,
  COLOR_RGBA2BGRA = COLOR_BGRA2RGBA,
  COLOR_BGR2GRAY = 6,
  COLOR_RGB2GRAY = 7,
  COLOR_GRAY2BGR = 8,
  COLOR_GRAY2RGB = COLOR_GRAY2BGR,
  COLOR_GRAY2BGRA = 9,
  COLOR_GRAY2RGBA = COLOR_GRAY2BGRA,
  COLOR_BGRA2GRAY = 10,
  COLOR_RGBA2GRAY = 11,
  COLOR_BGR2BGR565 = 12,
  COLOR_RGB2BGR565 = 13,
  COLOR_BGR5652BGR = 14,
  COLOR_BGR5652RGB = 15,
  COLOR_BGRA2BGR565 = 16,
  COLOR_RGBA2BGR565 = 17,
  COLOR_BGR5652BGRA = 18,
  COLOR_BGR5652RGBA = 19,
  COLOR_GRAY2BGR565 = 20,
  COLOR_BGR5652GRAY = 21,
  COLOR_BGR2BGR555 = 22,
  COLOR_RGB2BGR555 = 23,
  COLOR_BGR5552BGR = 24,
  COLOR_BGR5552RGB = 25,
  COLOR_BGRA2BGR555 = 26,
  COLOR_RGBA2BGR555 = 27,
  COLOR_BGR5552BGRA = 28,
  COLOR_BGR5552RGBA = 29,
  COLOR_GRAY2BGR555 = 30,
  COLOR_BGR5552GRAY = 31,
  COLOR_BGR2XYZ = 32,
  COLOR_RGB2XYZ = 33,
  COLOR_XYZ2BGR = 34,
  COLOR_XYZ2RGB = 35,
  COLOR_BGR2YCrCb = 36,
  COLOR_RGB2YCrCb = 37,
  COLOR_YCrCb2BGR = 38,
  COLOR_YCrCb2RGB = 39,
  COLOR_BGR2HSV = 40,
  COLOR_RGB2HSV = 41,
  COLOR_BGR2Lab = 44,
  COLOR_RGB2Lab = 45,
  COLOR_BGR2Luv = 50,
  COLOR_RGB2Luv = 51,
  COLOR_BGR2HLS = 52,
  COLOR_RGB2HLS = 53,
  COLOR_HSV2BGR = 54,
  COLOR_HSV2RGB = 55,
  COLOR_Lab2BGR = 56,
  COLOR_Lab2RGB = 57,
  COLOR_Luv2BGR = 58,
  COLOR_Luv2RGB = 59,
  COLOR_HLS2BGR = 60,
  COLOR_HLS2RGB = 61,
  COLOR_BGR2HSV_FULL = 66,
  COLOR_RGB2HSV_FULL = 67,
  COLOR_BGR2HLS_FULL = 68,
  COLOR_RGB2HLS_FULL = 69,
  COLOR_HSV2BGR_FULL = 70,
  COLOR_HSV2RGB_FULL = 71,
  COLOR_HLS2BGR_FULL = 72,
  COLOR_HLS2RGB_FULL = 73,
  COLOR_LBGR2Lab = 74,
  COLOR_LRGB2Lab = 75,
  COLOR_LBGR2Luv = 76,
  COLOR_LRGB2Luv = 77,
  COLOR_Lab2LBGR = 78,
  COLOR_Lab2LRGB = 79,
  COLOR_Luv2LBGR = 80,
  COLOR_Luv2LRGB = 81,
  COLOR_BGR2YUV = 82,
  COLOR_RGB2YUV = 83,
  COLOR_YUV2BGR = 84,
  COLOR_YUV2RGB = 85,
  COLOR_YUV2RGB_NV12 = 90,
  COLOR_YUV2BGR_NV12 = 91,
  COLOR_YUV2RGB_NV21 = 92,
  COLOR_YUV2BGR_NV21 = 93,
  COLOR_YUV420sp2RGB = COLOR_YUV2RGB_NV21,
  COLOR_YUV420sp2BGR = COLOR_YUV2BGR_NV21,
  COLOR_YUV2RGBA_NV12 = 94,
  COLOR_YUV2BGRA_NV12 = 95,
  COLOR_YUV2RGBA_NV21 = 96,
  COLOR_YUV2BGRA_NV21 = 97,
  COLOR_YUV420sp2RGBA = COLOR_YUV2RGBA_NV21,
  COLOR_YUV420sp2BGRA = COLOR_YUV2BGRA_NV21,
  COLOR_YUV2RGB_YV12 = 98,
  COLOR_YUV2BGR_YV12 = 99,
  COLOR_YUV2RGB_IYUV = 100,
  COLOR_YUV2BGR_IYUV = 101,
  COLOR_YUV2RGB_I420 = COLOR_YUV2RGB_IYUV,
  COLOR_YUV2BGR_I420 = COLOR_YUV2BGR_IYUV,
  COLOR_YUV420p2RGB = COLOR_YUV2RGB_YV12,
  COLOR_YUV420p2BGR = COLOR_YUV2BGR_YV12,
  COLOR_YUV2RGBA_YV12 = 102,
  COLOR_YUV2BGRA_YV12 = 103,
  COLOR_YUV2RGBA_IYUV = 104,
  COLOR_YUV2BGRA_IYUV = 105,
  COLOR_YUV2RGBA_I420 = COLOR_YUV2RGBA_IYUV,
  COLOR_YUV2BGRA_I420 = COLOR_YUV2BGRA_IYUV,
  COLOR_YUV420p2RGBA = COLOR_YUV2RGBA_YV12,
  COLOR_YUV420p2BGRA = COLOR_YUV2BGRA_YV12,
  COLOR_YUV2GRAY_420 = 106,
  COLOR_YUV2GRAY_NV21 = COLOR_YUV2GRAY_420,
  COLOR_YUV2GRAY_NV12 = COLOR_YUV2GRAY_420,
  COLOR_YUV2GRAY_YV12 = COLOR_YUV2GRAY_420,
  COLOR_YUV2GRAY_IYUV = COLOR_YUV2GRAY_420,
  COLOR_YUV2GRAY_I420 = COLOR_YUV2GRAY_420,
  COLOR_YUV420sp2GRAY = COLOR_YUV2GRAY_420,
  COLOR_YUV420p2GRAY = COLOR_YUV2GRAY_420,
  COLOR_YUV2RGB_UYVY = 107,
  COLOR_YUV2BGR_UYVY = 108,
  COLOR_YUV2RGB_Y422 = COLOR_YUV2RGB_UYVY,
  COLOR_YUV2BGR_Y422 = COLOR_YUV2BGR_UYVY,
  COLOR_YUV2RGB_UYNV = COLOR_YUV2RGB_UYVY,
  COLOR_YUV2BGR_UYNV = COLOR_YUV2BGR_UYVY,
  COLOR_YUV2RGBA_UYVY = 111,
  COLOR_YUV2BGRA_UYVY = 112,
  COLOR_YUV2RGBA_Y422 = COLOR_YUV2RGBA_UYVY,
  COLOR_YUV2BGRA_Y422 = COLOR_YUV2BGRA_UYVY,
  COLOR_YUV2RGBA_UYNV = COLOR_YUV2RGBA_UYVY,
  COLOR_YUV2BGRA_UYNV = COLOR_YUV2BGRA_UYVY,
  COLOR_YUV2RGB_YUY2 = 115,
  COLOR_YUV2BGR_YUY2 = 116,
  COLOR_YUV2RGB_YVYU = 117,
  COLOR_YUV2BGR_YVYU = 118,
  COLOR_YUV2RGB_YUYV = COLOR_YUV2RGB_YUY2,
  COLOR_YUV2BGR_YUYV = COLOR_YUV2BGR_YUY2,
  COLOR_YUV2RGB_YUNV = COLOR_YUV2RGB_YUY2,
  COLOR_YUV2BGR_YUNV = COLOR_YUV2BGR_YUY2,
  COLOR_YUV2RGBA_YUY2 = 119,
  COLOR_YUV2BGRA_YUY2 = 120,
  COLOR_YUV2RGBA_YVYU = 121,
  COLOR_YUV2BGRA_YVYU = 122,
  COLOR_YUV2RGBA_YUYV = COLOR_YUV2RGBA_YUY2,
  COLOR_YUV2BGRA_YUYV = COLOR_YUV2BGRA_YUY2,
  COLOR_YUV2RGBA_YUNV = COLOR_YUV2RGBA_YUY2,
  COLOR_YUV2BGRA_YUNV = COLOR_YUV2BGRA_YUY2,
  COLOR_YUV2GRAY_UYVY = 123,
  COLOR_YUV2GRAY_YUY2 = 124,
  COLOR_YUV2GRAY_Y422 = COLOR_YUV2GRAY_UYVY,
  COLOR_YUV2GRAY_UYNV = COLOR_YUV2GRAY_UYVY,
  COLOR_YUV2GRAY_YVYU = COLOR_YUV2GRAY_YUY2,
  COLOR_YUV2GRAY_YUYV = COLOR_YUV2GRAY_YUY2,
  COLOR_YUV2GRAY_YUNV = COLOR_YUV2GRAY_YUY2,
  COLOR_RGBA2mRGBA = 125,
  COLOR_mRGBA2RGBA = 126,
  COLOR_RGB2YUV_I420 = 127,
  COLOR_BGR2YUV_I420 = 128,
  COLOR_RGB2YUV_IYUV = COLOR_RGB2YUV_I420,
  COLOR_BGR2YUV_IYUV = COLOR_BGR2YUV_I420,
  COLOR_RGBA2YUV_I420 = 129,
  COLOR_BGRA2YUV_I420 = 130,
  COLOR_RGBA2YUV_IYUV = COLOR_RGBA2YUV_I420,
  COLOR_BGRA2YUV_IYUV = COLOR_BGRA2YUV_I420,
  COLOR_RGB2YUV_YV12 = 131,
  COLOR_BGR2YUV_YV12 = 132,
  COLOR_RGBA2YUV_YV12 = 133,
  COLOR_BGRA2YUV_YV12 = 134,
  COLOR_BayerBG2BGR = 46,
  COLOR_BayerGB2BGR = 47,
  COLOR_BayerRG2BGR = 48,
  COLOR_BayerGR2BGR = 49,
  COLOR_BayerRGGB2BGR = COLOR_BayerBG2BGR,
  COLOR_BayerGRBG2BGR = COLOR_BayerGB2BGR,
  COLOR_BayerBGGR2BGR = COLOR_BayerRG2BGR,
  COLOR_BayerGBRG2BGR = COLOR_BayerGR2BGR,
  COLOR_BayerRGGB2RGB = COLOR_BayerBGGR2BGR,
  COLOR_BayerGRBG2RGB = COLOR_BayerGBRG2BGR,
  COLOR_BayerBGGR2RGB = COLOR_BayerRGGB2BGR,
  COLOR_BayerGBRG2RGB = COLOR_BayerGRBG2BGR,
  COLOR_BayerBG2RGB = COLOR_BayerRG2BGR,
  COLOR_BayerGB2RGB = COLOR_BayerGR2BGR,
  COLOR_BayerRG2RGB = COLOR_BayerBG2BGR,
  COLOR_BayerGR2RGB = COLOR_BayerGB2BGR,
  COLOR_BayerBG2GRAY = 86,
  COLOR_BayerGB2GRAY = 87,
  COLOR_BayerRG2GRAY = 88,
  COLOR_BayerGR2GRAY = 89,
  COLOR_BayerRGGB2GRAY = COLOR_BayerBG2GRAY,
  COLOR_BayerGRBG2GRAY = COLOR_BayerGB2GRAY,
  COLOR_BayerBGGR2GRAY = COLOR_BayerRG2GRAY,
  COLOR_BayerGBRG2GRAY = COLOR_BayerGR2GRAY,
  COLOR_BayerBG2BGR_VNG = 62,
  COLOR_BayerGB2BGR_VNG = 63,
  COLOR_BayerRG2BGR_VNG = 64,
  COLOR_BayerGR2BGR_VNG = 65,
  COLOR_BayerRGGB2BGR_VNG = COLOR_BayerBG2BGR_VNG,
  COLOR_BayerGRBG2BGR_VNG = COLOR_BayerGB2BGR_VNG,
  COLOR_BayerBGGR2BGR_VNG = COLOR_BayerRG2BGR_VNG,
  COLOR_BayerGBRG2BGR_VNG = COLOR_BayerGR2BGR_VNG,
  COLOR_BayerRGGB2RGB_VNG = COLOR_BayerBGGR2BGR_VNG,
  COLOR_BayerGRBG2RGB_VNG = COLOR_BayerGBRG2BGR_VNG,
  COLOR_BayerBGGR2RGB_VNG = COLOR_BayerRGGB2BGR_VNG,
  COLOR_BayerGBRG2RGB_VNG = COLOR_BayerGRBG2BGR_VNG,
  COLOR_BayerBG2RGB_VNG = COLOR_BayerRG2BGR_VNG,
  COLOR_BayerGB2RGB_VNG = COLOR_BayerGR2BGR_VNG,
  COLOR_BayerRG2RGB_VNG = COLOR_BayerBG2BGR_VNG,
  COLOR_BayerGR2RGB_VNG = COLOR_BayerGB2BGR_VNG,
  COLOR_BayerBG2BGR_EA = 135,
  COLOR_BayerGB2BGR_EA = 136,
  COLOR_BayerRG2BGR_EA = 137,
  COLOR_BayerGR2BGR_EA = 138,
  COLOR_BayerRGGB2BGR_EA = COLOR_BayerBG2BGR_EA,
  COLOR_BayerGRBG2BGR_EA = COLOR_BayerGB2BGR_EA,
  COLOR_BayerBGGR2BGR_EA = COLOR_BayerRG2BGR_EA,
  COLOR_BayerGBRG2BGR_EA = COLOR_BayerGR2BGR_EA,
  COLOR_BayerRGGB2RGB_EA = COLOR_BayerBGGR2BGR_EA,
  COLOR_BayerGRBG2RGB_EA = COLOR_BayerGBRG2BGR_EA,
  COLOR_BayerBGGR2RGB_EA = COLOR_BayerRGGB2BGR_EA,
  COLOR_BayerGBRG2RGB_EA = COLOR_BayerGRBG2BGR_EA,
  COLOR_BayerBG2RGB_EA = COLOR_BayerRG2BGR_EA,
  COLOR_BayerGB2RGB_EA = COLOR_BayerGR2BGR_EA,
  COLOR_BayerRG2RGB_EA = COLOR_BayerBG2BGR_EA,
  COLOR_BayerGR2RGB_EA = COLOR_BayerGB2BGR_EA,
  COLOR_BayerBG2BGRA = 139,
  COLOR_BayerGB2BGRA = 140,
  COLOR_BayerRG2BGRA = 141,
  COLOR_BayerGR2BGRA = 142,
  COLOR_BayerRGGB2BGRA = COLOR_BayerBG2BGRA,
  COLOR_BayerGRBG2BGRA = COLOR_BayerGB2BGRA,
  COLOR_BayerBGGR2BGRA = COLOR_BayerRG2BGRA,
  COLOR_BayerGBRG2BGRA = COLOR_BayerGR2BGRA,
  COLOR_BayerRGGB2RGBA = COLOR_BayerBGGR2BGRA,
  COLOR_BayerGRBG2RGBA = COLOR_BayerGBRG2BGRA,
  COLOR_BayerBGGR2RGBA = COLOR_BayerRGGB2BGRA,
  COLOR_BayerGBRG2RGBA = COLOR_BayerGRBG2BGRA,
  COLOR_BayerBG2RGBA = COLOR_BayerRG2BGRA,
  COLOR_BayerGB2RGBA = COLOR_BayerGR2BGRA,
  COLOR_BayerRG2RGBA = COLOR_BayerBG2BGRA,
  COLOR_BayerGR2RGBA = COLOR_BayerGB2BGRA,
  COLOR_COLORCVT_MAX = 143
}

enum MorphShapes {
  MORPH_RECT = 0 ,
  MORPH_CROSS = 1 ,
  MORPH_ELLIPSE = 2
}

enum MorphTypes {
  MORPH_ERODE = 0 ,
  MORPH_DILATE = 1 ,
  MORPH_OPEN = 2 ,
  MORPH_CLOSE = 3 ,
  MORPH_GRADIENT = 4 ,
  MORPH_TOPHAT = 5 ,
  MORPH_BLACKHAT = 6 ,
  MORPH_HITMISS = 7
}

enum  	ThresholdTypes {
  THRESH_BINARY = 0 ,
  THRESH_BINARY_INV = 1 ,
  THRESH_TRUNC = 2 ,
  THRESH_TOZERO = 3 ,
  THRESH_TOZERO_INV = 4 ,
  THRESH_MASK = 7 ,
  THRESH_OTSU = 8 ,
  THRESH_TRIANGLE = 16
}

enum AdaptiveThresholdTypes {
  ADAPTIVE_THRESH_MEAN_C = 0 ,
  ADAPTIVE_THRESH_GAUSSIAN_C = 1
}

enum FileStorageMode {
  READ = 0,
  WRITE = 1,
  APPEND = 2,
  MEMORY = 4,
  FORMAT_MASK = (7<<3),
  FORMAT_AUTO = 0,
  FORMAT_XML = (1<<3),
  FORMAT_YAML = (2<<3),
  FORMAT_JSON = (3<<3),
  BASE64 = 64,
  WRITE_BASE64 = BASE64 | WRITE
}

enum FileNodeType {
  NONE = 0,
  INT = 1,
  REAL = 2,
  FLOAT = REAL,
  STR = 3,
  STRING = STR,
  REF = 4,
  SEQ = 5,
  MAP = 6,
  TYPE_MASK = 7,
  FLOW = 8,
  USER = 16,
  EMPTY = 32,
  NAMED = 64
}

## ImgCodecs
enum  	ImreadModes {
  IMREAD_UNCHANGED = -1 ,
  IMREAD_GRAYSCALE = 0 ,
  IMREAD_COLOR = 1 ,
  IMREAD_ANYDEPTH = 2 ,
  IMREAD_ANYCOLOR = 4 ,
  IMREAD_LOAD_GDAL = 8 ,
  IMREAD_REDUCED_GRAYSCALE_2 = 16 ,
  IMREAD_REDUCED_COLOR_2 = 17 ,
  IMREAD_REDUCED_GRAYSCALE_4 = 32 ,
  IMREAD_REDUCED_COLOR_4 = 33 ,
  IMREAD_REDUCED_GRAYSCALE_8 = 64 ,
  IMREAD_REDUCED_COLOR_8 = 65 ,
  IMREAD_IGNORE_ORIENTATION = 128
}

enum  	ImwriteEXRCompressionFlags {
  IMWRITE_EXR_COMPRESSION_NO = 0 ,
  IMWRITE_EXR_COMPRESSION_RLE = 1 ,
  IMWRITE_EXR_COMPRESSION_ZIPS = 2 ,
  IMWRITE_EXR_COMPRESSION_ZIP = 3 ,
  IMWRITE_EXR_COMPRESSION_PIZ = 4 ,
  IMWRITE_EXR_COMPRESSION_PXR24 = 5 ,
  IMWRITE_EXR_COMPRESSION_B44 = 6 ,
  IMWRITE_EXR_COMPRESSION_B44A = 7 ,
  IMWRITE_EXR_COMPRESSION_DWAA = 8 ,
  IMWRITE_EXR_COMPRESSION_DWAB = 9
}

enum  	ImwriteEXRTypeFlags {
  IMWRITE_EXR_TYPE_HALF = 1 ,
  IMWRITE_EXR_TYPE_FLOAT = 2
}


enum  	ImwriteFlags {
  IMWRITE_JPEG_QUALITY = 1 ,
  IMWRITE_JPEG_PROGRESSIVE = 2 ,
  IMWRITE_JPEG_OPTIMIZE = 3 ,
  IMWRITE_JPEG_RST_INTERVAL = 4 ,
  IMWRITE_JPEG_LUMA_QUALITY = 5 ,
  IMWRITE_JPEG_CHROMA_QUALITY = 6 ,
  IMWRITE_JPEG_SAMPLING_FACTOR = 7 ,
  IMWRITE_PNG_COMPRESSION = 16 ,
  IMWRITE_PNG_STRATEGY = 17 ,
  IMWRITE_PNG_BILEVEL = 18 ,
  IMWRITE_PXM_BINARY = 32 ,
  IMWRITE_EXR_TYPE = (3 << 4) + 0 ,
  IMWRITE_EXR_COMPRESSION = (3 << 4) + 1 ,
  IMWRITE_EXR_DWA_COMPRESSION_LEVEL = (3 << 4) + 2 ,
  IMWRITE_WEBP_QUALITY = 64 ,
  IMWRITE_HDR_COMPRESSION = (5 << 4) + 0 ,
  IMWRITE_PAM_TUPLETYPE = 128 ,
  IMWRITE_TIFF_RESUNIT = 256 ,
  IMWRITE_TIFF_XDPI = 257 ,
  IMWRITE_TIFF_YDPI = 258 ,
  IMWRITE_TIFF_COMPRESSION = 259 ,
  IMWRITE_TIFF_ROWSPERSTRIP = 278 ,
  IMWRITE_TIFF_PREDICTOR = 317 ,
  IMWRITE_JPEG2000_COMPRESSION_X1000 = 272 ,
  IMWRITE_AVIF_QUALITY = 512 ,
  IMWRITE_AVIF_DEPTH = 513 ,
  IMWRITE_AVIF_SPEED = 514
}

enum  	ImwriteHDRCompressionFlags {
  IMWRITE_HDR_COMPRESSION_NONE = 0 ,
  IMWRITE_HDR_COMPRESSION_RLE = 1
}

enum  	ImwriteJPEGSamplingFactorParams {
  IMWRITE_JPEG_SAMPLING_FACTOR_411 = 0x411111 ,
  IMWRITE_JPEG_SAMPLING_FACTOR_420 = 0x221111 ,
  IMWRITE_JPEG_SAMPLING_FACTOR_422 = 0x211111 ,
  IMWRITE_JPEG_SAMPLING_FACTOR_440 = 0x121111 ,
  IMWRITE_JPEG_SAMPLING_FACTOR_444 = 0x111111
}

enum  	ImwritePAMFlags {
  IMWRITE_PAM_FORMAT_NULL = 0 ,
  IMWRITE_PAM_FORMAT_BLACKANDWHITE = 1 ,
  IMWRITE_PAM_FORMAT_GRAYSCALE = 2 ,
  IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA = 3 ,
  IMWRITE_PAM_FORMAT_RGB = 4 ,
  IMWRITE_PAM_FORMAT_RGB_ALPHA = 5
}

enum  	ImwritePNGFlags {
  IMWRITE_PNG_STRATEGY_DEFAULT = 0 ,
  IMWRITE_PNG_STRATEGY_FILTERED = 1 ,
  IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY = 2 ,
  IMWRITE_PNG_STRATEGY_RLE = 3 ,
  IMWRITE_PNG_STRATEGY_FIXED = 4
}

enum  	ImwriteTiffCompressionFlags {
  IMWRITE_TIFF_COMPRESSION_NONE = 1 ,
  IMWRITE_TIFF_COMPRESSION_CCITTRLE = 2 ,
  IMWRITE_TIFF_COMPRESSION_CCITTFAX3 = 3 ,
  IMWRITE_TIFF_COMPRESSION_CCITT_T4 = 3 ,
  IMWRITE_TIFF_COMPRESSION_CCITTFAX4 = 4 ,
  IMWRITE_TIFF_COMPRESSION_CCITT_T6 = 4 ,
  IMWRITE_TIFF_COMPRESSION_LZW = 5 ,
  IMWRITE_TIFF_COMPRESSION_OJPEG = 6 ,
  IMWRITE_TIFF_COMPRESSION_JPEG = 7 ,
  IMWRITE_TIFF_COMPRESSION_T85 = 9 ,
  IMWRITE_TIFF_COMPRESSION_T43 = 10 ,
  IMWRITE_TIFF_COMPRESSION_NEXT = 32766 ,
  IMWRITE_TIFF_COMPRESSION_CCITTRLEW = 32771 ,
  IMWRITE_TIFF_COMPRESSION_PACKBITS = 32773 ,
  IMWRITE_TIFF_COMPRESSION_THUNDERSCAN = 32809 ,
  IMWRITE_TIFF_COMPRESSION_IT8CTPAD = 32895 ,
  IMWRITE_TIFF_COMPRESSION_IT8LW = 32896 ,
  IMWRITE_TIFF_COMPRESSION_IT8MP = 32897 ,
  IMWRITE_TIFF_COMPRESSION_IT8BL = 32898 ,
  IMWRITE_TIFF_COMPRESSION_PIXARFILM = 32908 ,
  IMWRITE_TIFF_COMPRESSION_PIXARLOG = 32909 ,
  IMWRITE_TIFF_COMPRESSION_DEFLATE = 32946 ,
  IMWRITE_TIFF_COMPRESSION_ADOBE_DEFLATE = 8 ,
  IMWRITE_TIFF_COMPRESSION_DCS = 32947 ,
  IMWRITE_TIFF_COMPRESSION_JBIG = 34661 ,
  IMWRITE_TIFF_COMPRESSION_SGILOG = 34676 ,
  IMWRITE_TIFF_COMPRESSION_SGILOG24 = 34677 ,
  IMWRITE_TIFF_COMPRESSION_JP2000 = 34712 ,
  IMWRITE_TIFF_COMPRESSION_LERC = 34887 ,
  IMWRITE_TIFF_COMPRESSION_LZMA = 34925 ,
  IMWRITE_TIFF_COMPRESSION_ZSTD = 50000 ,
  IMWRITE_TIFF_COMPRESSION_WEBP = 50001 ,
  IMWRITE_TIFF_COMPRESSION_JXL = 50002
}

enum  	ImwriteTiffPredictorFlags {
  IMWRITE_TIFF_PREDICTOR_NONE = 1 ,
  IMWRITE_TIFF_PREDICTOR_HORIZONTAL = 2 ,
  IMWRITE_TIFF_PREDICTOR_FLOATINGPOINT = 3
}

# DNN

enum  	DisType {
  FR_COSINE =0 ,
  FR_NORM_L2 =1
}

enum  	DNN_Backend {
  DNN_BACKEND_DEFAULT = 0,
  DNN_BACKEND_HALIDE,
  DNN_BACKEND_INFERENCE_ENGINE,
  DNN_BACKEND_OPENCV
}

enum  	DNN_Target {
  DNN_TARGET_CPU = 0,
  DNN_TARGET_OPENCL,
  DNN_TARGET_OPENCL_FP16,
  DNN_TARGET_MYRIAD,
  DNN_TARGET_FPGA
}
