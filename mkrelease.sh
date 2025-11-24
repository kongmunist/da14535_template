#!/bin/bash

# Input build version in form x.x(x)
# If no input specified autoincrement last tag

SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"


regex="([0-9]+).([0-9]+).([0-9]+)"

lastVersion=$(git tag | tail -n 1)

if [[ $1 =~ $regex ]]; then
	version=$1
elif [[ $lastVersion =~ $regex ]]; then 
	echo "Updating build version off last build tag"
	version=$(echo $lastVersion | awk -F. -v OFS=. 'NF==1{print ++$NF}; NF>1{if(length($NF+1)>length($NF))$(NF-1)++; $NF=sprintf("%0*d", length($NF), ($NF+1)%(10^length($NF))); print}') 
 else
	echo "No Build version given and last tag invalid. Exiting.."
	exit 1
fi

if [[ $version =~ $regex ]]; then
	major="${BASH_REMATCH[1]}"
	minor="${BASH_REMATCH[2]}"
	build="${BASH_REMATCH[3]}"
else 
	echo "Something Wrong with build versioning. Exiting..."
	exit 1
fi

git tag $version
git push origin $version

cd build/release

make clean && make -j12

zip -r -q da14531.zip da14531

cd ../../

gh release create "$version" build/release/da14531.zip

rm -r build/release/da14531.zip

