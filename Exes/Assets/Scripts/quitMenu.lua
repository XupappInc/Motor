--Definicion de la clase en Lua
quitMenu = {}

quitMenu.__index = quitMenu

--Constructor de la clase en Lua
function quitMenu:new()
	local obj={}
	setmetatable(obj, quitMenu)
	return obj
end

--Metodo Awake, llamado al comienzo de la ejecucion
function quitMenu:awake()

end

--Metodo Start, llamado tras Awake
function quitMenu:start()
	
end

--Metodo Update, llamado en cada frame
function quitMenu:update()
	--print("Update boton");
	--local butt=quitMenu.entity:getButton();
	--butt:setVisible();
end

--Metodo OnCollisionEnter, llamado al comenzar una colision
function quitMenu:onCollisionEnter()

end

--Metodo OnCollisionStay, llamado mientras se mantenga una colision
function quitMenu:onCollisionStay()

end

--Metodo OnCollisionExit, llamado al salir de una colision
function quitMenu:onCollisionExit()

end

--Metodo OnButtonClicked
function quitMenu:onButtonClick()
	
	--SceneManager:changeScene("scene2.lua");
end
function quitMenu:onButtonReleased()
	InputManager:setCloseWindow();
end
--Metodo OnButtonHover
function quitMenu:onButtonHover()
		
end
--Metodo OnButtonUnhover
function quitMenu:onButtonUnhover()

	
end
--Variable global de la clase (para Luabridge)
quitMenuLua = quitMenu:new()
