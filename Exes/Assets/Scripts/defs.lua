local luabridge = require("luabridge")

local defs = {}

-- Define the Transform class
defs.Transform = luabridge.class("Transform")
Transform:addFunction("translate", function(self, translation)
    -- Calculate the new position
    local newPosition = {self.position[1] + translation[1],
                         self.position[2] + translation[2],
                         self.position[3] + translation[3]}
    -- Update the position
    self.position = newPosition
end)


-- Define the RigidBody class
defs.RigidBody = luabridge.class("RigidBody")
RigidBody:addFunction("addForce", function(self, force)
    local btVector3 = luabridge.class("btVector3")
    local fuerza = btVector3(force.x, force.y, force.z)
    local posicion = btVector3(0, 0, 0)
    self.rb_:applyForce(fuerza, posicion)
end)

-- Export the module
return defs