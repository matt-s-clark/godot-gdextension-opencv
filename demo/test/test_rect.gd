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
	var rect := CVRect.new()
	
	rect.x = 5
	rect.y = 5
	rect.height = 3
	rect.width = 3
	
	assert_eq(rect.area(), 9)
	assert_eq(rect.empty(), false)
