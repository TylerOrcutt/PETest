rm -R build 
mkdir build
cp -R images/ build/
cp -R fonts/ build/
cp -R Maps/ build/
cp -R Props/ build/
cd build
cmake ../
make
./PETest -dev -m "Maps/map001.map"

#./PETest -dev -3d
