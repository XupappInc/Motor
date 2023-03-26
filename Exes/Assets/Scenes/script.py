import bpy
import math

# Obtiene una referencia a la escena actual
scene = bpy.context.scene

lua_string = "Entities = {\n"

# Crea un diccionario vacío para almacenar las entidades y sus atributos

# Itera a través de todos los objetos en la escena
for obj in scene.objects:
    
    #Nombre de la entidad
    name = obj.name.replace(".", "_")
    lua_string += "\t" + name + " = {\n"
    
    # Obtiene la posición, rotación y escala del objeto
    pos = obj.location
    rot = obj.rotation_euler
    scl = obj.scale

    # Crea un diccionario con las transformaciones del objeto
    escale = 1
    lua_string += "\t\ttransform = {\n" 
    lua_string += "\t\t\t" + "pos = {" + str(pos.x / escale) + ", " + str(pos.z / escale) + ", " + str(pos.y / escale) + "},\n"
    lua_string += "\t\t\t" + "rot = {" + str(math.degrees(rot.x - math.pi / 2)) + ", " + str(math.degrees(rot.z)) + ", " + str(math.degrees(rot.y)) + "},\n"
    lua_string += "\t\t\t" + "scale = {" + str(scl.x / escale) + ", " + str(scl.z / escale) + ", " + str(scl.y / escale) + "}\n"
    lua_string += "\t\t},\n"  
    
      
    
    # Si el objeto es una cámara, agrega el atributo "camera"
    if obj.type == "CAMERA":
        lua_string += "\t\tcamera = {\n\t\t},\n"
    # Si el objeto es una luz, agrega los atributos "ambient", "difuse" y "specular"
    elif obj.type == "LIGHT":
        
        color = obj.data.color
        
        lua_string += "\t\tlight = {\n"        
        lua_string += "\t\t\t" + "color = {" + str(color.r) + ", " + str(color.g) + ", " + str(color.b) + "},\n"
        lua_string += "\t\t\t" + "type = \"" + obj.data.type + "\",\n"
        lua_string += "\t\t},\n"                         
    # Si el objeto tiene una malla, agrega el atributo "MeshRenderer"       
    elif obj.data is not None and obj.type == "MESH":
        lua_string += "\t\tmeshRenderer = {\n" 
        lua_string += "\t\t\t" + "meshName = \"" + obj.data.name + "\"\n"
        lua_string += "\t\t},\n"  

    # Itera a través de todas las propiedades personalizadas del objeto y crea los atributos correspondientes
    '''
    for prop_name in obj.keys():
        prop_value = obj[prop_name]
        attributes[prop_name] = prop_value
    '''
    

    lua_string = lua_string[:-2]
    lua_string += "\n\t},\n"


lua_string = lua_string[:-2]
lua_string += "\n}"

# Abre un archivo para escritura y guarda el diccionario en formato JSON con indentación
with open("scene.lua", "w") as file:
    file.write(lua_string)
    

