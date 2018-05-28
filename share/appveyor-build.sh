#!/bin/sh

source /appveyor.environment
export MSYSTEM

cd /c/projects/src
./autogen.sh

./configure --prefix /inst/

v=$(grep goffice_full_version config.h | cut -f2 -d '"')
v="$v-$(date +'%Y.%m.%d-%H')"
powershell.exe -command "Update-AppveyorBuild -Version \"$v\""
echo "Version=$v"

make -j 2
make install

if [ $MSYSTEM = "MINGW32" ]; then
	bits="32bit"
else
	bits="64bit"
fi

fn="goffice-$bits-$v-archive.zip"

zip -9r  $fn /inst/*

powershell.exe -command "Push-AppveyorArtifact \"$fn\" -DeploymentName \"goffice\""
