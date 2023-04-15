// La barra \ despues de cada linea es muy importante cuando
// se usa #define, si lo quitas tendrias que poner todo en la misma linea

#pragma once
#ifndef __EC_DEFS_H__
#define __EC_DEFS_H__

/// <summary>
/// Lista de componentes, debe de tener al menos 1 elemento
/// </summary>
#define _CMPS_LIST_ \
		_MESH_RENDERER, \
		_TRANSFORM, \
		_RIGID_BODY, \
		_COLLIDER, \
		_LIGHT,\
		_AUDIO_SOURCE, \
		_CAMERA, \
		_ANIMATOR, \
		_PARTICLE_SYSTEM, \
		_BEHAVIOUR, \
		_AUDIO_LISTENER, \
		_BUTTON, \
		_TEXT, \
		_PANEL
		 

/// <summary>
/// Lista tipos de managers, debe de tener al menos 1 elemento
/// </summary>
#define _CMPS_TYPES_ \
		_ENTITY, \
		_PHYSICS, \
		_RENDER, \
		_INPUT, \
		_UI, \
		_SOUND, \
		_SCRIPT, \
		_SCENE

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

#endif  // !__EC_DEFS_H__