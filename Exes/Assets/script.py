import bpy

# Obtiene una referencia a la escena actual
scene = bpy.context.scene

# Itera a través de todos los objetos en la escena
for obj in scene.objects:
    # Obtiene la posición del objeto
    pos = obj.location

    # Imprime la posición del objeto
    print(f"La posición del objeto {obj.name} es: {pos}")
