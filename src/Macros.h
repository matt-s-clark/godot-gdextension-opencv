#define SAFECALL(func)                             \
	try {                                          \
		func;                                      \
	} catch (std::exception & stde) {              \
		UtilityFunctions::push_error(stde.what()); \
	}
