// La barra \ despues de cada linea es muy importante cuando
// se usa #define, si lo quitas tendrias que poner todo en la misma linea

#pragma once

/// <summary>
/// Lista de componentes, debe de tener al menos 1 elemento
/// </summary>
#define _CMPS_LIST_ \ 
		_EXAMPLE1, \ 
		_EXAMPLE2

/// <summary>
/// Lista de grupos, debe de tener al menos 1 elemento
/// </summary>
#define _GRPS_LIST_ \
		_EXAMPLE1_GRP_, \
		_EXAMPLE2_GRP

/// <summary>
/// Lista de handlers, debe de tener al menos 1 elemento
/// </summary>
#define _HDLRS_LIST_ \
		_HDLR_EXAMPLE1, \
		_HDLR_EXAMPLE2