echo "<-> Cleaning up..."

rm ./bin/Debug/*
rm ./obj/Debug/*
rm ./src/*.h
rm Taller08.make
rm Makefile

echo "<-> Running premake..."
premake5 gmake2
echo "<-> Running make..."
make
echo "<-> Starting program..."
./bin/Debug/Taller08
echo "<-> Done!"
