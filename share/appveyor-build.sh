#!/bin/sh

app_env=/appveyor.environment
if test -f $app_env; then
	source $app_env
	export MSYSTEM
fi

cd ..
./autogen.sh
./configure --prefix /tmp/inst/

v=$(grep goffice_full_version config.h | cut -f2 -d '"')

if test -f $app_env; then
	v="$v-$(date +'%Y.%m.%d-%H')"
	powershell.exe -command "Update-AppveyorBuild -Version \"$v\""
fi

echo "Version=$v"

make -j 2
make install

if test -f $app_env; then
	if [ $MSYSTEM = "MINGW32" ]; then
		bits="32bit"
	else
		bits="64bit"
	fi

	fn="goffice-$bits-$v-archive.zip"

	zip -9r  $fn /tmp/inst/*

	powershell.exe -command "Push-AppveyorArtifact \"$fn\" -DeploymentName \"goffice\""
fi
