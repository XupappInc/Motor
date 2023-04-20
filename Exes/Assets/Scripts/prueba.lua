Prueba = {}
Prueba.__index = Prueba

local collisionStayCalled = true;

function Prueba:new()
    local obj = {}
    setmetatable(obj, Prueba)
    return obj
end

function Prueba:update()
    -- print('Se llama al update del script de Lua')
    local s = prueba.entity:getTag()
    print(s)
end

function Prueba:onCollisionEnter()
    print('OnCollisionEnter de Sinbad')

    if other ~= nil then
        print('Other not nil!!!!')
    else
        print('Other is nil')
    end
end

function Prueba:onCollisionExit(other)
    print('OnCollisionExit de Sinbad')
end

function Prueba:onCollisionStay(other)
    if collisionStayCalled then
        print('OnCollisionStay de Sinbad')
        collisionStayCalled = false
    end
end

pruebaLua = Prueba:new()
