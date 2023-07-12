#! /usr/bin/bash

git add .
echo "All changes have been added"

echo "Commiting with the message: $1"
git commit -m "$1"


