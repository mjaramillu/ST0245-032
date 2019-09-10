echo "<-> Cleaning up..."

rm ./bin/Debug/*
rm ./obj/Debug/*
rm ./src/*.h
rm Lab03.make
rm Makefile

echo "<-> Running premake..."
premake5 gmake2
echo "<-> Running make..."
make
echo "<-> Starting program..."
./bin/Debug/Lab03
echo "<-> Done!"
