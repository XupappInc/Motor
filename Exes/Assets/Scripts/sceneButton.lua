--Definicion de la clase en Lua
sceneButton = {}

sceneButton.__index = sceneButton

--Constructor de la clase en Lua
function sceneButton:new()
	local obj={}
	setmetatable(obj, sceneButton)
	return obj
end

--Metodo Awake, llamado al comienzo de la ejecucion
function sceneButton:awake()

end

--Metodo Start, llamado tras Awake
function sceneButton:start()

end

--Metodo Update, llamado en cada frame
function sceneButton:update()

end

--Metodo OnCollisionEnter, llamado al comenzar una colision
function sceneButton:onCollisionEnter()

end

--Metodo OnCollisionStay, llamado mientras se mantenga una colision
function sceneButton:onCollisionStay()

end

--Metodo OnCollisionExit, llamado al salir de una colision
function sceneButton:onCollisionExit()

end

--Metodo OnButtonClicked, llamado al salir de una colision
function sceneButton:onButtonClick()
	print("Has pulsado para ir a la escena\n");
	SceneManager:changeScene("scene.lua");
end

--Variable global de la clase (para Luabridge)
sceneButtonLua = sceneButton:new()
