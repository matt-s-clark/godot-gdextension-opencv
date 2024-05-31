extends GutTest
func before_each():
	gut.p("ran setup", 2)

func after_each():
	gut.p("ran teardown", 2)

func before_all():
	gut.p("ran run setup", 2)

func after_all():
	gut.p("ran run teardown", 2)

func test_cap_camera():
	var cap = CVVideoCapture.new()
	cap.open(0, 0, null)
	
	assert_true(cap.is_opened(), "Camera opens")
	
	var frame := cap.read()
	
	assert_string_contains(frame.to_string(), "CVMat instance")
	assert_ne(frame.cols , 0, "Cols != 0")
	assert_ne(frame.rows , 0, "Rows != 0")
	
func test_cap_grab_and_retrieve():
	var cap = CVVideoCapture.new()
	cap.open(0, 0, null)
	
	var grabed := cap.grab()
	
	assert_eq(grabed, true)
	
	var frame := cap.retrieve({})
	
	assert_string_contains(frame.to_string(), "CVMat instance")
	assert_ne(frame.cols , 0, "Cols != 0")
	assert_ne(frame.rows , 0, "Rows != 0")

func test_cap_file():
	var cap = CVVideoCapture.new()
	cap.open("./test/testFiles/video.webm", 0, null)
	
	assert_true(cap.is_opened(), "File opens")
	
	var frame := cap.read()
	
	assert_string_contains(frame.to_string(), "CVMat instance")
	assert_ne(frame.cols , 0, "Cols != 0")
	assert_ne(frame.rows , 0, "Rows != 0")
	
func test_cap_config():
	var cap = CVVideoCapture.new()

	cap.open(0, 0, null)

	var properties := [
		CVConsts.VideoCaptureProperties.CAP_PROP_SATURATION, 
		cap.get(CVConsts.VideoCaptureProperties.CAP_PROP_SATURATION),
		CVConsts.VideoCaptureProperties.CAP_PROP_CONTRAST, 
		cap.get(CVConsts.VideoCaptureProperties.CAP_PROP_CONTRAST),
		CVConsts.VideoCaptureProperties.CAP_PROP_BRIGHTNESS, 
		cap.get(CVConsts.VideoCaptureProperties.CAP_PROP_BRIGHTNESS)]
	
	for i in range(properties.size()/2):
		cap.set(properties[2*i], properties[2*i+1] + 10)
		assert_almost_eq(cap.get(properties[2*i]), properties[2*i+1] + 10, 0.1)
		cap.set(properties[2*i], properties[2*i+1])
		
func test_cap_misc():
	var cap = CVVideoCapture.new()

	cap.open(0, 0, null)
	assert_has(['FFMPEG', 'GSTREAMER', 'INTEL_MFX', 'V4L2', 'CV_IMAGES', 'CV_MJPEG', 'AVFOUNDATION'], cap.get_backend_name())
	assert_eq(cap.get_exception_mode(), false, "get_exception_mode")
