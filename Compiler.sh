#!/bin/bash

#	Correct location
cd /Users/juanbeccaceci/Documents/GitHub/OpenCV-PlateRecognition

#	File name
fileName=$1

#	Check param
if [[ -n "$fileName" ]]; then

	#	Compile...
	echo "Compilando proyecto: $fileName..."

	#	G++
	g++ -o $fileName main.cpp Source/Config/ConfigManagement.cpp Source/Video/VideoProcess.cpp Source/Detector/CPUDetection.cpp Source/Detector/DetectorFactory.cpp Source/Detector/OPENCLDetection.cpp Source/Detector/PlateDetection.cpp Source/General/Utility.cpp Source/Console/Console.cpp Source/Detector/GPUDetection.cpp `pkg-config --cflags --libs opencv`
	
	#	OK!
	echo -e "\033[1;32m Proyecto compilado con el nombre de:\033[0m $fileName."
else

	#	No arguments
	echo "Ingrese un argumento"

fi

exit 0