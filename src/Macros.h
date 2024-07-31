#define SAFE_CALL(func)                            \
	try {                                          \
		func;                                      \
	} catch (std::exception & stde) {              \
		UtilityFunctions::push_error(stde.what()); \
	}

#define GET_ADITIONAL_PROPERTY(list, variable, propertyName, type, warningType)                             \
	if (list.has(propertyName)) {                                                                           \
		if (list[propertyName].get_type() == type) {                                                        \
			variable = list[propertyName];                                                                  \
		} else {                                                                                            \
			UtilityFunctions::push_warning(                                                                 \
					UtilityFunctions::str(                                                                  \
							propertyName, " expected to be of type ", warningType, ", ignoring property")); \
		}                                                                                                   \
	}

#define GET_SIMPLE_PROPERTY(type, godotType, variable, defaultValue)                               \
	type variable = defaultValue;                                                                  \
	\               
	 if (additional_parameters.has(#variable)) {                                                   \
		if (additional_parameters[#variable].get_type() == godotType) {                            \
			variable = additional_parameters[#variable];                                           \
		} else {                                                                                   \
			UtilityFunctions::push_warning(                                                        \
					UtilityFunctions::str(                                                         \
							#variable, " expected to be of type ", #type, ", ignoring property")); \
		}                                                                                          \
	}

#define GET_OBJECT_PROPERTY(type, variable)                                                        \
	type variable = type();                                                                        \
	\               
	 if (additional_parameters.has(#variable)) {                                                   \
		if (additional_parameters[#variable].get_type() == Variant::OBJECT) {                      \
			variable = additional_parameters[#variable];                                           \
		} else {                                                                                   \
			UtilityFunctions::push_warning(                                                        \
					UtilityFunctions::str(                                                         \
							#variable, " expected to be of type ", #type, ", ignoring property")); \
		}                                                                                          \
	}                                                                                              \
                                                                                                   \
	if (variable.is_null()) {                                                                      \
		variable.instantiate();                                                                    \
	}                                                                                              \
	