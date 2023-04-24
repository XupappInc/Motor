Entities = {
	Camera = {
		transform = {
			pos = {0.0, 14.724569320678711, 16.61865997314453},
			rot = {0.6108472943305969, 0.0, -0.0, 0.7917484641075134},
			scale = {1.0, 1.0, 1.0}
		},
		camera = {
		}
	},
	Play={
		button = {
			overlay = "BotonPlay",
			x = 50,
			y = 50,
			width = 512,
			height = 140,
			iniTex = "iniMat",
			hoverTex="hoverMat",
			clickedTex="clickedMat"
		},
		script={
			name="buttonMenu"
		}
	},
	Quit={
		button = {
			overlay = "BotonQuit",
			x = 0,
			y = 50,
			width = 256,
			height = 140,
			iniTex = "QuitIni",
			hoverTex="QuitHover",
			clickedTex="QuitClick"
		},
		script={
			name="quitMenu"
		}
	},
	Image={
		image = {
			overlay = "Imagen",
			x = 50,
			y = 0,
			width = 100,
			height = 100,
			texture = "crazyU"
		}
	}
}