rm -R build 
mkdir build
 cp -R images/ build/
  cp -R fonts/ build/
cd build
cmake ../
make
#./PETest -dev -m ../test2.map

./PETest -dev -3d
