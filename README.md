# Separity
![image](https://user-images.githubusercontent.com/82317485/236326302-afcc9969-c53f-41f5-a64d-8e54e2592f37.png)
## Dependencias del motor 

Para el desarrollo del motor se han utilizado las siguientes librerías:

* Físicas: Bullet 3D
* Interfaz: OgreOverlay
* Gráficos: Ogre
* Input: Ogre::SDL
* Scripting y escenas: Luabridge
* Audio: FMOD


## Estructura de la solución

Separity:

* Separity.sln
* Src
    * Carpetas con el código fuente de cada proyecto individual. 
    * Código en C++ tanto .h como .cpp.
* Projects
    * Carpeta individual para cada proyecto.
    * Proyectos individuales que componen el motor.
* Temp (gitignore)
    * Carpeta individual para los archivos temporales de cada proyecto.
    * Archivos temporales creados en ejecución. (archivos intermedios)
* Lib (gitignore)
    * Proyectos compilados con CMake para librerías estáticas.
* Dependencias
    * Bibliotecas externas
    * Las bibliotecas se dividen en Src (código fuente de la librería) y en Build (código compilado) (gitignore).
* Exes
    * Ejecutables compilados. (gitignore)
    * Archivo de salida de los ejecutables.


## Estructura de componentes del motor y del juego (Entity Component)

![image](https://user-images.githubusercontent.com/82317485/236326229-2a673b07-4c91-4f6b-a475-a802f959a45e.png)

## Estructura de clases

**Física**

<table>
  <tr>
   <td>PhysicsManager
   </td>
  </tr>
  <tr>
   <td>RigidBody
   </td>
  </tr>
  <tr>
   <td>CollisionCallback
   </td>
  </tr>
  <tr>
   <td>PathFollow
   </td>
  </tr>
</table>


**Render**


<table>
  <tr>
   <td>RenderManager
   </td>
  </tr>
  <tr>
   <td>Camera
   </td>
  </tr>
  <tr>
   <td>Light
   </td>
  </tr>
  <tr>
   <td>MeshRenderer
   </td>
  </tr>
  <tr>
   <td>Animator
   </td>
  </tr>
  <tr>
   <td>ParticleSystem
   </td>
  </tr>
</table>


**UI**


<table>
  <tr>
   <td>UI Manager
   </td>
  </tr>
  <tr>
   <td>UIComponent
   </td>
  </tr>
  <tr>
   <td>Text
   </td>
  </tr>
  <tr>
   <td>Image
   </td>
  </tr>
  <tr>
   <td>Button
   </td>
  </tr>
  <tr>
   <td>Bar
   </td>
  </tr>
</table>


**Sound**


<table>
  <tr>
   <td>SoundManager
   </td>
  </tr>
  <tr>
   <td>AudioListener
   </td>
  </tr>
  <tr>
   <td>AudioSource
   </td>
  </tr>
</table>


**Input**


<table>
  <tr>
   <td>InputManager
   </td>
  </tr>
  <tr>
   <td>InputWrapper
   </td>
  </tr>
</table>


**Script**


<table>
  <tr>
   <td>Lua Manager
   </td>
  </tr>
  <tr>
   <td>Behaviour
   </td>
  </tr>
</table>


**EntityComponent**


<table>
  <tr>
   <td>EntityManager
   </td>
  </tr>
  <tr>
   <td>Entity
   </td>
  </tr>
  <tr>
   <td>Component
   </td>
  </tr>
  <tr>
   <td>Transform
   </td>
  </tr>
  <tr>
   <td>Manager
   </td>
  </tr>
  <tr>
   <td>Singleton
   </td>
  </tr>
  <tr>
   <td>ManagerManager
   </td>
  </tr>
  <tr>
   <td>ComponentCreator
   </td>
  </tr>
</table>


**Scene**


<table>
  <tr>
   <td>SceneManager
   </td>
  </tr>
  <tr>
   <td>ComponentFactory
   </td>
  </tr>
</table>


**Utils**


<table>
  <tr>
   <td>Random
   </td>
  </tr>
  <tr>
   <td>spyVector
   </td>
  </tr>
  <tr>
   <td>VirtualTimer
   </td>
  </tr>
  <tr>
   <td>spyMath
   </td>
  </tr>
  <tr>
   <td>spyQuaternion
   </td>
  </tr>
</table>


**ComponentEngine**
- GetComponentWrapper



---

- **Comunicación entre componentes:** Las entidades siguen poseyendo la lista de sus componentes y pueden hacer getComponent&lt;CmpType>().
- **Función de los managers:** Cada manager gestiona los componentes de su tipo, y su función es llamar a sus funciones correspondientes (initComponente( ), update( ), etc.) 

    Los managers son singleton a los que se puede acceder desde cualquier parte del motor. 

- **El borrado de componentes:** La entidad borra sus componentes.


## Pipeline de Generación de Contenido

**Modelos 3D (mallas y animaciones):**



- Creados en blender.
- Exportados a .mesh mediante el add-on “blender2ogre”.
- El componente &lt;MeshRenderer> cargará el .mesh con Ogre. 
- El componente &lt;Animator> gestionará su animación.

**Imágenes:**



- Creadas en cualquier editor de imágenes (Photoshop/Gimp/Krita/ClipStudioPaint).
- Formato .png, .jpg (usaremos estos formatos y no otros como .bmp por su compresión, reduciendo el tamaño total del proyecto).
- También se podrán imágenes 2D para la interfaz, gestionadas por el componente &lt;Image>, el cual creará la imagen utilizando OgreOverlay.

**Música y efectos de sonido:**   



- Creados con Audacity y Reaper.
- Formatos .wav y .mp3 (usaremos .wav para efectos de sonido y audios cortos, ya que son archivos sin comprimir, y .mp3 para música y audios más largos) 

**Mapas y niveles:**



- Creados en blender.
- Se convierten a un archivo .lua mediante un script propio de Python.
- (también se pueden escribir a mano)
- El motor traduce dicho archivo al cargar la escena.

**Scripts:**



- Los scripts se implementan con Lua.
- Se dispone de un creador de scripts propio que proporciona una plantilla predeterminada.
- Los scripts se cargan en C++ con Luabridge, donde los gestiona el componente &lt;Behaviour>.


## Pipeline del Motor (carga de Escenas, Managers, Entidades y Componentes)

Al principio de la ejecución del juego se crean todos los managers del motor, los cuales se registran a sí mismos en el **ManagerManger**, corazón del proyecto.

Seguido de esto, se abre el**punto de entrada** entre motor y juego, para que este **añada a la factoría**del SceneManager los componentes propios del motor e indicar el nombre de la **primera escena** a cargar.

Tercero, se inicializan los Managers (**start( )**):

- Nuestro motor tiene 8 Managers en total (sin contar el ManagerManger que los gestiona)
- 5 de ellos han de estar presentes todo el rato en cada escena:
    - ENTITY
    - LUA
    - SCENE
    - INPUT
        - Ha de inicializarse siempre porque ha de registrar sus funciones en Lua.
    - RENDER
        - Tanto Physics cómo UI tienen dependencias de este manager.
        - Gestiona la creación y destrucción de la ventana de renderizado, la cual debería persistir durante el cambio de escenas.
- Los otros 3 se inicializan a demanda, cuando un componente de su tipo se cree en la escena:
    * PHYSICS
    * AUDIO
    * UI

Seguido de esto, se cargará la escena (**loadScene( )**), un bucle que recorre las tablas de un archivo .lua con la siguiente estructura:



- Tabla general (“Entities”), la cual está compuesta por todas las entidades de la escena.
- Las **entidades** son a su vez tablas compuestas por **componentes** (propios o del motor).
- Los **componentes** a su vez son tablas formadas por los **parámetros de entrada** de los componentes (opcionales u obligatorios).

El bucle hace uso de la **factoría**,  compuesta por **Creators**, que **leen** los parámetros de **entrada** de los componentes y deciden si se han cargado correctamente o no, creando y asignándole el componente a la entidad en caso afirmativo.

Tras la creación de todas las entidades y componentes, estos se **inicializan** en un **segundo paso** (**initComponent( )**), generalmente con el objetivo de conseguir la **referencia** de los componentes de los cuales tienen dependencia y terminar de **inicializarse por completo**. 

Si no ha habido errores hasta ahora, se llama al método **start( )** tanto para los **componentes** en c++ **propios del juego**, como para los **scripts de Lua**.

Comienza el bucle del juego, el cual solo puede ser interrumpido por un cambio de escena o si cierras el juego.

Cuando **cambias de escena**, se limpian todos los managers del juego (método **clean( )**) y se vuelve a ejecutar la pipeline descrita anteriormente:



- start( ) de los managers
- loadScene( )
- initComponent( )
- start( ) de los componentes del juego y scripts de Lua
- update( )

El concepto de los **managers bajo demanda** se mantiene entre escenas, por ejemplo, si en la primera escena ha habido un componente de física y en la segunda no, en la segunda escena **no** se cargará el PhysicsManager.

Si cierras el juego se llamará al método **clean( )** de todos los managers y posteriormente al **close( )**, su **destructora**. Si durante la carga de escena o inicialización de los componentes hubiese habido **algún error**, no se entraría al bucle principal del juego y se llevarían a cabo estos dos últimos pasos directamente.

Las llamadas a los métodos start( ), initComponents( ), update( ), y clean( ) de los distintos managers se realizan desde el **ManagerManger** y su orden es siempre el mismo:



1. ENTITY
2. LUA
3. INPUT
4. PHYSICS
5. UI
6. RENDER
7. SOUND
8. SCENE


## Componentes amigos de Manager

Para **evitar la exposición** de métodos públicos que muestran los tipos propios de las bibliotecas utilizadas (Ogre, SDL…), hemos optado por hacer privadas todas estas funciones, pero haciendo **amigos a los componentes del manager que los gestiona**. De esta forma los componentes pueden obtener información vital para su correcto funcionamiento sin necesidad de **exponer las tripas del motor** al desarrollador del juego.


## Comunicación Motor-Juego

El juego será una solución de Visual Studio.

Tanto el motor como el juego se compilarán a una DLL, que luego serán cargadas por un main perteneciente al motor. La DLL del motor se carga de forma implícita y la del juego de forma explícita.

Una vez creadas ambas DLLs, se mueven junto con los assets y demás librerías de dependencias a la carpeta Exe del juego. Es en esta carpeta que se ejecuta el ejecutable que carga todo el juego y el motor.

Mediante el uso de diversos archivos .bat se automatiza la creación de de DLLs y compilación de todas las dependencias y soluciones.

Para poder implementar componentes en el juego se proporciona un cmpType especial “GAME_COMPONENT”. Este permite crear componentes en el juego que serán gestionados por el LuaManager (por ser considerados del mismo nivel que los scripts).

Los componentes creados tendrán que tener cada uno su respectivo ComponentCreator, que se encargará de crear el componente y añadirlo a su entidad según los parámetros que se especifiquen en la escena.lua. El desarrollador del juego es responsable de registrar este Creator en la ComponentFactory del SceneEngine, para así poder abstraer su creación y evitar dependencias circulares.

Finalmente, los scripts creados en Lua y guardados en la carpeta Assets/Scripts se podrán cargar como otro asset más, sin generar ningún tipo de dependencia adicional. 

Cabe destacar que si el desarrollador desea registrar las clases creadas en el juego en la máquina virtual de Lua (para su posterior uso en scripts) es necesario incluir Luabridge junto con Lua en el juego, siendo esta la única dependencia requerida en este caso especial.


## Scripting

Separity posee un potente motor de scripting, el cual utiliza Lua para poder crear comportamientos de forma rápida y global.

Para ayudar en la creación de scripts existe un **script** (valga la redundancia) de Python con un **ejecutable**. Dicho ejecutable crea la **plantilla** del script según el nombre dado en un nuevo .lua, de forma que se asegura que la estructura de la clase y nombres son correctos para evitar errores.

El usuario dispone de los siguientes métodos predefinidos:



- **Awake()**, se ejecuta durante la inicialización de los componentes (no es seguro).
- **Start()**, se ejecuta justo tras la inicialización de los componentes.
- **Update()**, se ejecuta en cada frame del juego.
- **OnCollisionEnter()**, **OnCollisionExit()** y **OnCollisionStay()**, eventos que se llaman cuando se produce una colisión, en todos estos se dispone de la variable global **“other**”, que representa un puntero a la entidad con la que se ha colisionado.
- **OnButtonClick()**, **OnButtonReleased()**, **OnButtonHover()** y **OnButtonUnhover()**, eventos que se llaman cuando la entidad que posee este script tiene un componente &lt;Button> y este lanza algún evento.

Los scripts se cargan al comienzo de la ejecución en el LuaManager y se asocian a un componente de tipo **Behaviour** de forma que se controla su ciclo de vida y ejecución en C++.

Cada script posee una variable global con su propio nombre, de forma que se puede acceder a ellos desde cualquier script en Lua. Sin embargo, la repetición de scripts hace que existan 2 o más variables globales con el mismo nombre, lo que hace que se sobreescriba esta a la última definición. Para solucionar este problema existe una variable global **“this”** que se define en la ejecución de los métodos de cada scripts y apunta a su propia clase Behaviour, de forma que se pueda acceder siempre a la propia entidad o componentes.

Los componentes Behaviour tienen registrados por defecto un puntero a la entidad que los contienen, llamado **“entity”**. Podemos entonces acceder a la entidad de un script con this.entity. 

Debido a que **getComponent** utiliza templates, no se puede registrar en Lua. Para solucionar esto se ha creado la clase **GetComponenteWrapper**, que contiene un único método encargado de registrar todos los getComponent que se quieran. Esta clase se encuentra en un proyecto separado para evitar dependencias.

Al hacer un cambio de escena se ha de borrar el **lua_state (L_)** para evitar que se quede **basura** relacionada con scripts de la escena anterior. Como consecuencia, se han de volver a registrar todos los métodos que queremos exponer a los scripts en un nuevo **lua_state**. Esto se hace generalmente en el método **start( )** de los managers, destacando su importancia el **SceneManager**, con el que gracias a la **factoría**, podemos llamar al método **registerInLua( )** de los creadores de componentes (**CCreator**) para registrar las funciones del componente al que representan.

**Enlace a la Documentación del Motor: [Separity](https://docs.google.com/document/d/1lpcYnpP9YvncGBXIm-Av2tlW8rzPlTLfQ4HFPEp33iM/edit?usp=sharing)**
