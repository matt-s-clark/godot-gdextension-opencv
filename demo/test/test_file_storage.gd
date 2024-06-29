extends GutTest
func before_each():
	gut.p("ran setup", 2)

func after_each():
	gut.p("ran teardown", 2)

func before_all():
	gut.p("ran run setup", 2)

func after_all():
	gut.p("ran run teardown", 2)
	DirAccess.remove_absolute("./test/testFiles/tmp.xml")
	DirAccess.remove_absolute("./test/testFiles/tmp.json")

func test_read_saved_xml():
	var file_storage := CVFileStorage.new()
	
	assert_false(file_storage.isOpened(), "File not yet open")
	file_storage.open("./test/testFiles/testData.xml", CVConsts.FileStorageMode.READ, {})
	assert_true(file_storage.isOpened(), "File opened corectly")
	
	assert_eq(file_storage.read("test_int"), 42)
	assert_almost_eq(file_storage.read("test_float"), 3.1415, 0.0001)
	assert_eq(file_storage.read("test_string"), "Hello World!")
	assert_null(file_storage.read("non_existing_property"))

func test_write_xml():
	var file_write := CVFileStorage.new()
	var file_read := CVFileStorage.new()
	
	file_write.open("./test/testFiles/tmp.xml", CVConsts.FileStorageMode.WRITE, {})
	
	file_write.write("a", 42)
	file_write.write("b", 3.1415)
	file_write.write("c", "Hello World!")
	
	file_write.release()
	
	file_read.open("./test/testFiles/tmp.xml", CVConsts.FileStorageMode.READ, {})
	
	assert_eq(file_read.read("a"), 42)
	assert_almost_eq(file_read.read("b"), 3.1415, 0.0001)
	assert_eq(file_read.read("c"), "Hello World!")
	assert_null(file_read.read("non_existing_property"))

func test_write_json():
	var file_write := CVFileStorage.new()
	var file_read := CVFileStorage.new()
	
	file_write.open("./test/testFiles/tmp.json", CVConsts.FileStorageMode.WRITE, {})
	
	file_write.write("a", 42)
	file_write.write("b", 3.1415)
	file_write.write("c", "Hello World!")
	
	file_write.release()
	
	file_read.open("./test/testFiles/tmp.xml", CVConsts.FileStorageMode.READ, {})
	
	assert_eq(file_read.read("a"), 42)
	assert_almost_eq(file_read.read("b"), 3.1415, 0.0001)
	assert_eq(file_read.read("c"), "Hello World!")
	assert_null(file_read.read("non_existing_property"))
