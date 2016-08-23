rm -R build 
mkdir build
 cp -R images/ build/
cd build
cmake ../
make
./PETest -dev -m ../test.map

