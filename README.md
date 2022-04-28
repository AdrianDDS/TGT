# TGT
 
LipSync test for 2D/3D animation.

Demo hecha para probar las capacidades del plugin de Oculus Lipsync en UE4. 

## Oculus Lipsync:

Información importante del plugin en: https://developer.oculus.com/documentation/unreal/audio-ovrlipsync-unreal/

## C++:

Las principales clases de este proyecto son:


AnimationTests/
-Source/
--AnimationTest/
--- Camera/
---- CameraPawn.cpp
---- CameraPawn.h
--- Controllers/
---- TGTController.cpp
---- TGTController.h
--- TGTGameModeBase.cpp
--- TGTGameModeBase.h
-README

 - AnimationTests/
	 - Source/
		 - AnimationTest/
			 - Camera/
				 - CameraPawn.cpp
				 - CameraPawn.h
 			 - Controllers/
				 - TGTController.cpp
				 - TGTController.h
			 - TGTGameModeBase.cpp
			 - TGTGameModeBase.h
	 - README.md

Dónde el camera pawn es la clase desde la que se deberá interactuar en editor con el resto de herramientas; es creado en el método BeginPlay del TGTGameModeBase y se le asigna ahí el TGTController como su controllador. Esta lógica deberá ser desplazada a otro método que se invoque desde el editor.

## Blueprints:

Las principales clases de Blueprints son Goober_occulus_LS_blendShapes y Goober_occulus_LS_flipbook.

La primera para actores que requieren blendshapes con lipsync y la segunda para los que lo requieren con flipbooks.

