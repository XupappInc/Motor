Behaviour = {}
Behaviour.__index = Behaviour

function Behaviour:new()
    local obj = {}
    setmetatable(obj, Behaviour)
    return obj
end

function Behaviour:update()
    print('Se llama al update del script de Lua')
end

behaviour = Behaviour:new()