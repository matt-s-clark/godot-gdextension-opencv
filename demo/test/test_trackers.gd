extends GutTest
func before_each():
	gut.p("ran setup", 2)

func after_each():
	gut.p("ran teardown", 2)

func before_all():
	gut.p("ran run setup", 2)

func after_all():
	gut.p("ran run teardown", 2)

func test_kcf_tracker():
	var tracker_csrt = CVTrackerKCF.create({})
	var rect = CVRect.from_values(253, 169, 49, 31)
	basic_trcker(tracker_csrt, rect)

func test_csrt_tracker():
	var tracker_csrt = CVTrackerCSRT.create({})
	var rect = CVRect.from_values(257, 171, 41, 26)
	basic_trcker(tracker_csrt, rect)

func basic_trcker(tracker, comp_rect):
	var cap = CVVideoCapture.new()
	cap.open("./test/testFiles/video.webm", 0, null)
	var mat := cap.read()
	var rec = CVRect.from_values(257, 165, 49, 31)
	
	tracker.init(mat, rec)
	
	var output : CVRect
	while mat.cols > 0:
		output = tracker.update(mat)
		mat = cap.read()
	
	assert_eq(output.x, comp_rect.x)
	assert_eq(output.y, comp_rect.y)
	assert_eq(output.width, comp_rect.width)
	assert_eq(output.height, comp_rect.height)
