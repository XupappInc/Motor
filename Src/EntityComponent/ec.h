#pragma once

#include <cstdint>

namespace ec {

	class ManagerTemplate;
	class Entity;
	class Component;

	// Definimos tipo para los identificadores para poder cambiarlos facilmente.
	// Por ejemplo, si tenemos menos de 256 componentes podemos usar uint8_t, si tenemos
	// hasta 512 podemos usar uint16.
	using cmpId_type = uint8_t;
	using cmpType_type = uint8_t;
	using grpId_type = uint8_t;
	using hdlrId_type = uint8_t;

#if __has_include("ec_defs.h")
#include "ec_defs.h";
#else
#define _CMPS_LIST_ _CMP_1
#define _CMPS_TYPES_ _CMPT_1
#define _GRPS_LIST_ _GRP_2
#define _HDLRS_LIST_ _HDLR_1
#endif

	/// <summary>
	/// Lista de los identificadores de componente
	/// </summary>
	enum cmpId : cmpId_type {
		_CMPS_LIST_, /* obtenido de ec_defs */

		// no borrar esto
		_LAST_CMP_ID
	};

	/// <summary>
	/// Lista de los tipos de componente
	/// </summary>
	enum cmpType : cmpType_type {
		_CMPS_TYPES_, /* obtenido de ec_defs */

		// no borrar esto
		_LAST_CMP_TYPE
	};

	/// <summary>
	/// Lista de los indentificadores de grupo
	/// </summary>
	enum grpId : cmpId_type {
		_grp_GENERAL,
		_GRPS_LIST_, /* obtenido de ec_defs */

		// no borrar esto
		_LAST_GRP_ID
	};

	/// <summary>
	/// Lista de los identificadores de handler
	/// </summary>
	enum hdlrId : hdlrId_type {
		_HDLRS_LIST_, /* obtenido de ec_defs */

		// no borrar esto
		_LAST_HDLR_ID
	};

	constexpr cmpId_type maxComponentId = cmpId::_LAST_CMP_ID;
	constexpr cmpType_type maxComponentType = cmpType::_LAST_CMP_TYPE;
	constexpr cmpId_type maxGroupId = grpId::_LAST_GRP_ID;
	constexpr hdlrId_type maxHdlrId = hdlrId::_LAST_HDLR_ID;

/// <summary>
/// Un macro para la declaracion del identificador de componente. Por ejemplo:
/// __CMPID_DECL__(ec::_TRANSFORM) se expande a:
/// 
/// constexpr static ec::cmpId_type id = ec::_TRANSFORM;
/// </summary>
#define __CMPID_DECL__(cId) constexpr static ec::cmpId_type id = cId;

/// <summary>
/// Un macro para la declaracion del tipo de componente. Por ejemplo:
/// __CMPTYPE_DECL__(ec::_RENDER) se expande a:
///
/// constexpr static ec::cmpType_type type = ec::_RENDER;
/// </summary>
#define __CMPTYPE_DECL__(cType) constexpr static ec::cmpType_type type = cType;

}  // namespace ec
