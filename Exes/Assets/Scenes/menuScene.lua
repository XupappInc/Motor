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
	Floor_6 = {
		transform = {
			pos = {-0.6212728023529053, 1.8466160297393799, -7.592611312866211},
			rot = {1.0, 0.0, -0.0, -1.6292068494294654e-07},
			scale = {0.01795569434762001, 0.01795569434762001, 0.01795569434762001}
		},
		meshRenderer = {
			meshName = "Mesh.098"
		},
		collider = {
			dim = {39.052555084228516, 4.317275047302246, 39.07554626464844},
		},
		rigidbody = {
			type = 2
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