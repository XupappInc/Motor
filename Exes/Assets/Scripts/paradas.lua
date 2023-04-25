--Definicion de la clase en Lua
paradas = {}

paradas.__index = paradas

--Constructor de la clase en Lua
function paradas:new()
	local obj={}
	setmetatable(obj, paradas)
	return obj
end

--Metodo Awake, llamado al comienzo de la ejecucion
function paradas:awake()

end

--Metodo Start, llamado tras Awake
function paradas:start()

end

--Metodo Update, llamado en cada frame
function paradas:update()

end

--Metodo OnCollisionEnter, llamado al comenzar una colision
function paradas:onCollisionEnter()

    if other ~= nil then
		--Funcionalidades futuras, sumar puntos al pasar por una parada,
		--En un futuro se llamará al gameManager pero aún no existe
        print('Chocando con Parada')
    else
        print('Parada no detectada')
	end
end

--Metodo OnCollisionStay, llamado mientras se mantenga una colision
function paradas:onCollisionStay()

end

--Metodo OnCollisionExit, llamado al salir de una colision
function paradas:onCollisionExit()

end

--Metodo OnButtonClick, llamado al pulsar el boton de esta entidad
function paradas:onButtonClick()

end

--Metodo OnButtonReleased, llamado al soltar el boton de esta entidad
function paradas:onButtonReleased()

end

--Metodo OnButtonHover, llamado al posar el raton sobre el boton de esta entidad
function paradas:onButtonHover()

end

--Metodo OnButtonUnhover, llamado al dejar de posar el raton sobre el boton de esta entidad
function paradas:onButtonUnhover()

end

--Variable global de la clase (para Luabridge)
paradasLua = paradas:new()
