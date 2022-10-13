@echo off
pushd %~dp0\..\..\
call Building\Premake-bin\premake5.exe vs2022
popd
PAUSE