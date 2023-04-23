// El siguiente bloque ifdef muestra la forma estándar de crear macros que hacen la exportación
// de un DLL más sencillo. Todos los archivos de este archivo DLL se compilan con SEPARITYEXPORTS_EXPORTS
// símbolo definido en la línea de comandos. Este símbolo no debe definirse en ningún proyecto
// que use este archivo DLL. De este modo, otros proyectos cuyos archivos de código fuente incluyan el archivo verán
// interpretan que las funciones SEPARITYEXPORTS_API se importan de un archivo DLL, mientras que este archivo DLL interpreta los símbolos
// definidos en esta macro como si fueran exportados.
#include "SeparityApi.h"

// Clase exportada del DLL
class _SEPARITY_API_ CSeparityExports {
	public:
	CSeparityExports();
	// TODO: agregar métodos aquí.
};
