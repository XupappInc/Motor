import os

DIRECTORIO_ASSETS = "./"

def writeTemplate(script, name):

    # nombre con mayuscula al principio
    nameCap = name
    nameCap[0].upper()

    # definicion de clase de Lua
    script.write("--Definicion de la clase en Lua\n" +
                 nameCap + " = {}\n\n" + 
                 nameCap + ".__index = Prueba\n\n")
    
    # constructor de clase
    script.write("--Constructor de la clase en Lua\n" +
                 "function " + nameCap + ":new()\n" +
                 "\tlocal obj={}\n" +
                 "\tsetmetatable(obj, " + nameCap + ")\n" +
                 "\treturn obj\n" +
                 "end\n\n")
    
    # funciones vacias
    script.write("--Metodo Awake, llamado al comienzo de la ejecucion\n" + 
                 "function " + nameCap + ":awake()\n\n"
                 "end\n\n")
    script.write("--Metodo Start, llamado tras Awake\n" + 
                 "function " + nameCap + ":start()\n\n"
                 "end\n\n")
    script.write("--Metodo Update, llamado en cada frame\n" + 
                 "function " + nameCap + ":update()\n\n"
                 "end\n\n")
    script.write("--Metodo OnCollisionEnter, llamado al comenzar una colision\n" + 
                 "function " + nameCap + ":onCollisionEnter()\n\n"
                 "end\n\n")
    script.write("--Metodo OnCollisionStay, llamado mientras se mantenga una colision\n" + 
                 "function " + nameCap + ":onCollisionStay()\n\n"
                 "end\n\n")
    script.write("--Metodo OnCollisionExit, llamado al salir de una colision\n" + 
                 "function " + nameCap + ":onCollisionExit()\n\n"
                 "end\n\n")
    
    # variable global clase
    script.write("--Variable global de la clase (para Luabridge)\n" + 
                 name + "Lua = " + nameCap + ":new()\n")

def createScript(name, directory):

    return open(directory + name + ".lua", "w")


def handleInput():

    # limpia la consola
    os.system("CLS")

    return input("Nombre del script (sin extension .lua): ")


def main():

    scriptName = handleInput()

    script = createScript(scriptName, DIRECTORIO_ASSETS)

    writeTemplate(script, scriptName)

    script.close()

if __name__ == '__main__':
    main()
