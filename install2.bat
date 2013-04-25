@ECHO OFF
set programFiles64="C:\Program Files (x86)\"
set programFiles="C:\Program Files"
set miktex9="Miktex 2.9"
set miktex8="Miktex 2.8"

If Dir(%programFiles64%) 
	if Dir(%programFiles64% + %miktex9%)
		echo cos
