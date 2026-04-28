#!/bin/bash
mkdir -p build
make
cp bin/refinder /usr/local/bin/
echo "Installed refinder to /usr/local/bin/"