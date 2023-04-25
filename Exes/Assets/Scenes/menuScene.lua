Entities = {

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
			y = 60,
			width = 512,
			height = 140,
			iniTex = "iniMat",
			hoverTex="hoverMat",
			clickedTex="clickedMat",
			zorder=2
		},
		script = {
			name = "soundButton"
		}
	},
	Quit={
		button = {
			overlay = "BotonQuit",
			x = 50,
			y = 80,
			width = 256,
			height = 140,
			iniTex = "QuitIni",
			hoverTex="QuitHover",
			clickedTex="QuitClick",
			zorder=2
		},
		script={
			name="quitMenu"
		}
	},
	CrazyUImage={
		image = {
			overlay = "CrazyUImage",
			x = 50,
			y = 20,
			width = 600,
			height = 600,
			texture = "crazyU",
			zorder=2
		}
	},
	FondoUI={
		image = {
			overlay = "Fondo",
			x = 50,
			y = 50,
			width = 1302*1.5,
			height = 920*1.5,
			texture = "londres",
			zorder=0
		}
	}
}