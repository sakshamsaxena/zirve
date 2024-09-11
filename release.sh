#!/bin/bash
ZIRVE_DIR=$(pwd)
npm run release
cd $(mktemp -d)
pwd
git clone git@github.com:sakshamsaxena/zirve.git
cd zirve
git checkout master
cp $ZIRVE_DIR/dist/bundle.js ./dist/bundle.js
git commit -am "[AUTO-UPDATE] Update App"
git push
