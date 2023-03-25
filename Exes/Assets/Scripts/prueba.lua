Prueba = {}
Prueba.__index = Prueba

function Prueba:new()
    local obj = {}
    setmetatable(obj, Prueba)
    return obj
end

function Prueba:update()
    print('Se llama al update del script de Lua')
    prueba.transform:print()
end

pruebaLua = Prueba:new()