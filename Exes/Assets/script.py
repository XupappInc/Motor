import bpy
import json

# Obtiene una referencia a la escena actual
scene = bpy.context.scene

# Crea un diccionario vacío para almacenar las entidades y sus atributos
entities = {}

# Itera a través de todos los objetos en la escena
for obj in scene.objects:
    # Obtiene la posición, rotación y escala del objeto
    pos = obj.location
    rot = obj.rotation_euler
    scale = obj.scale

    # Crea un diccionario con las transformaciones del objeto
    transform = {"pos": [pos.x, pos.y, pos.z], "rot": [rot.x, rot.y, rot.z], "scale": [scale.x, scale.y, scale.z]}
    attributes = {"transform": transform}

    # Si el objeto es una cámara, agrega el atributo "camera"
    if obj.type == "CAMERA":
        attributes["camera"] = ""
    # Si el objeto es una luz, agrega los atributos "ambient", "difuse" y "specular"
    elif obj.type == "LIGHT":
        attributes["light"] = {"ambient": [obj.data.color.r, obj.data.color.g, obj.data.color.b],
                             "difuse": [obj.data.energy, obj.data.energy, obj.data.energy],
                             "specular": [obj.data.energy, obj.data.energy, obj.data.energy]}
                              # Si el objeto tiene una malla, agrega el atributo "MeshRenderer"
    elif obj.data is not None and obj.type == "MESH":
        attributes["meshRenderer"] = obj.data.name

    # Itera a través de todas las propiedades personalizadas del objeto y crea los atributos correspondientes
    for prop_name in obj.keys():
        prop_value = obj[prop_name]
        attributes[prop_name] = prop_value

    # Agrega el objeto y sus atributos al diccionario de entidades
    entities[obj.name] = attributes

# Crea un diccionario con las entidades
data = {"Entities": entities}

# Abre un archivo para escritura y guarda el diccionario en formato JSON con indentación
with open("scene.json", "w") as file:
    json.dump(data, file, indent=4)
    

