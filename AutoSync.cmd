call 0clr.cmd
del /f /s /q .git
xcopy /E /V /F /H /K /Y %~dp0* E:\NutStorePrivate\TMP\CppProgram\*
pause