import json

# Carga el archivo JSON
with open("scene.json", "r") as file:
    data = json.load(file)

# Convierte el diccionario JSON en una cadena con formato LUA
lua_string = "return " + str(data).replace("{", "{\n").replace("}", "\n}").replace("[", "{").replace("]", "}").replace("'", "\"").replace(":"," =").replace("\"","").replace("}, ", "},\n")

# Guarda la cadena con formato LUA en un archivo
with open("scene.lua", "w") as file:
    file.write(lua_string)

