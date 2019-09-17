echo "<-> Cleaning up..."

rm ./bin/Debug/*
rm ./obj/Debug/*
rm Taller09.make
rm Makefile

echo "<-> Running premake..."
premake5 gmake2
echo "<-> Running make..."
make
echo "<-> Starting program..."
./bin/Debug/Taller09
echo "<-> Done!"
