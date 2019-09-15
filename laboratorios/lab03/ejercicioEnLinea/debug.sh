echo "<-> Cleaning up..."

rm -r ./bin/Debug/*
rm -r ./obj/Debug/*
rm Lab03.make
rm Makefile

echo "<-> Running premake..."
premake5 gmake2
echo "<-> Running make..."
make
echo "<-> Copying datasets..."
cp -r ./datasets ./bin/Debug/datasets/
echo "<-> Starting program..."
./bin/Debug/Lab03
echo "<-> Done!"
