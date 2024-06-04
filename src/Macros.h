#define SAFE_CALL(func)                             \
	try {                                          \
		func;                                      \
	} catch (std::exception & stde) {              \
		UtilityFunctions::push_error(stde.what()); \
	}

#define GET_ADITIONAL_PROPERTY(list, variable, propertyName, type, warningType)                                                                    \
	if (list.has(propertyName)) {                                                                                                                \
		if (list[propertyName].get_type() == type) {                                                                                             \
			variable = list[propertyName];                                                                                                       \
		} else {                                                                                                                                 \
			UtilityFunctions::push_warning(UtilityFunctions::str(propertyName, " expected to be of type ", warningType, ", ignoring property")); \
		}                                                                                                                                        \
	}
