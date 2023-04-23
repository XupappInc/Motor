--Definicion de la clase en Lua
buttonMenu = {}

buttonMenu.__index = buttonMenu

--Constructor de la clase en Lua
function buttonMenu:new()
	local obj={}
	setmetatable(obj, buttonMenu)
	return obj
end

--Metodo Awake, llamado al comienzo de la ejecucion
function buttonMenu:awake()

end

--Metodo Start, llamado tras Awake
function buttonMenu:start()

end

--Metodo Update, llamado en cada frame
function buttonMenu:update()
	--print("Update boton");
end

--Metodo OnCollisionEnter, llamado al comenzar una colision
function buttonMenu:onCollisionEnter()

end

--Metodo OnCollisionStay, llamado mientras se mantenga una colision
function buttonMenu:onCollisionStay()

end

--Metodo OnCollisionExit, llamado al salir de una colision
function buttonMenu:onCollisionExit()

end

--Metodo OnButtonClicked, llamado al salir de una colision
function buttonMenu:onButtonClick()
	print("Has pulsado para ir al menu\n");
	--local sceneManager=buttonMenu.entity:getRigidbody();
	SceneManager:changeScene("scene2.lua");
	--SceneManager:prueba();
end
--Variable global de la clase (para Luabridge)
buttonMenuLua = buttonMenu:new()
