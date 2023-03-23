
Behaviour = {}
Behaviour.__index = Behaviour

function Behaviour:new()
    local obj = {}
    setmetatable(obj, Behaviour)
    return obj
end

function Behaviour:update()
    print('Se llama al update del script de Lua')
    -- tranform.translate({x = 0, y = 0, z = 0})
end

behaviour = Behaviour:new()