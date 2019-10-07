echo "<-> Cleaning up..."

rm ./bin/Debug/*
rm ./obj/Debug/*
rm ./src/*.h
rm lab.make
rm Makefile

echo "<-> Making headers..."
for file in $(find ./src/ -name "*.[ch]")
do
  makeheaders $file
  echo "<!> Headers for" $file "made"
done

echo "<-> Adding header guards..."
for file in $(find ./src/ -name "*.[h]")
do
  fbname=$(basename "$file" .h)
  upper=${fbname^^}
  echo -e "#ifndef" "$upper" "\n""#define" "$upper" "\n" "$(<$file)" "\n""#endif" > $file
  echo "<!> Headers guards for" $file "made"
done

echo "<-> Running premake..."
premake5 gmake2
echo "<-> Running make..."
make
echo "<-> Copying datasets..."
cp -r ./datasets ./bin/Debug/datasets
echo "<-> Starting program..."
./bin/Debug/lab
echo "<-> Done!"
