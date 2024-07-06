extends GutTest
func before_each():
	gut.p("ran setup", 2)

func after_each():
	gut.p("ran teardown", 2)

func before_all():
	gut.p("ran run setup", 2)

func after_all():
	gut.p("ran run teardown", 2)

func test_general():
	var mat := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	
	var cc := CVCascadeClassifier.new()
	cc.load("./Models/hand.xml")
	assert_eq(cc.empty(), false, "Correctly loads")
	
	gut.p(cc.get_feature_type())
	
	var result := cc.detect_multi_scale(mat, {})
	
	assert_has(result, "objects")
	assert_has(result, "num_detections")
	
	var result2 := cc.detect_multi_scale(mat, {"output_reject_levels":true})

	assert_has(result2, "objects")
	assert_has(result2, "reject_levels")
	assert_has(result2, "level_weights")
