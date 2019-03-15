emcc -O2 -std=c++14 -I./eigen337 svd.cpp -o svd.js -s MODULARIZE=1 -s EXPORTED_FUNCTIONS='["_polar2","_svd2","_polar3","_svd3"]' -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]'
