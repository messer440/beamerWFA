@ECHO OFF
xcopy /e "%cd%\texmf\*" C:\Users\%username%\AppData\Roaming\Miktex\2.9\ /Y /f /i /e /s /t
cd C:\"Program Files (x86)"\"MiKTeX 2.9"\miktex\bin\
texhash.exe
