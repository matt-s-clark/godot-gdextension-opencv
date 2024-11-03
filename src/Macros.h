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
	if (additional_parameters.has(#variable)) {                                                    \
		if (additional_parameters[#variable].get_type() == godotType) {                            \
			variable = additional_parameters[#variable];                                           \
		} else {                                                                                   \
			UtilityFunctions::push_warning(                                                        \
					UtilityFunctions::str(                                                         \
							#variable, " expected to be of type ", #type, ", ignoring property")); \
		}                                                                                          \
	}

#define GET_OBJECT_PROPERTY(type, variable, defaultValue)                                          \
	type variable = type();                                                                        \
                                                                                                   \
	if (additional_parameters.has(#variable)) {                                                    \
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
		variable->set_pointer(defaultValue);                                                       \
	}

#define GET_CONVERTIBLE_PROPERTY(type, godotType, variable, defaultValue)                          \
	type variable = defaultValue;                                                                  \
	if (additional_parameters.has(#variable)) {                                                    \
		if (additional_parameters[#variable].get_type() == godotType) {                            \
			variable = HelperFunctions::convert##type(additional_parameters[#variable]);           \
		} else {                                                                                   \
			UtilityFunctions::push_warning(                                                        \
					UtilityFunctions::str(                                                         \
							#variable, " expected to be of type ", #type, ", ignoring property")); \
		}                                                                                          \
	}

#define GET_INPUT_ARRAY(variable, output)                                                                                                \
	Mat variable##In = Mat();                                                                                                            \
	if (variable.get_type() == Variant::PACKED_VECTOR2_ARRAY) {                                                                          \
		PackedVector2Array variable##Cast = variable;                                                                                    \
		Mat variable##Tmp(1, variable##Cast.size(), CV_32FC2);                                                                           \
		for (size_t i = 0; i < variable##Cast.size(); i++) {                                                                             \
			variable##Tmp.at<cv::Vec2f>(0, i) = cv::Vec2f(variable##Cast[i].x, variable##Cast[i].y);                                     \
		}                                                                                                                                \
		variable##In = variable##Tmp;                                                                                                    \
	} else if (variable.get_type() == Variant::PACKED_VECTOR3_ARRAY) {                                                                   \
		PackedVector3Array variable##Cast = variable;                                                                                    \
		Mat variable##Tmp(1, variable##Cast.size(), CV_32FC3);                                                                           \
		for (size_t i = 0; i < variable##Cast.size(); i++) {                                                                             \
			variable##Tmp.at<cv::Vec3f>(0, i) = cv::Vec3f(variable##Cast[i].x, variable##Cast[i].y);                                     \
		}                                                                                                                                \
		variable##In = variable##Tmp;                                                                                                    \
	} else if (variable.get_type() == Variant::OBJECT) {                                                                                 \
		Ref<CVMat> variable##Tmp = variable;                                                                                             \
		ERR_FAIL_NULL_V_MSG(variable##Tmp, output, UtilityFunctions::str(#variable, " should not be null."));                            \
		variable##In = variable##Tmp->get_pointer();                                                                                     \
	} else {                                                                                                                             \
		UtilityFunctions::push_error(UtilityFunctions::str("Type not supported, ", #variable, " should be Mat or PackedVector2Array.")); \
	}
