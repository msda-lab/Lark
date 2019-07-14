#!/bin/bash

arg="$1"
argc=$#

SRC_DIR="./src"
PARSER_DIR="${SRC_DIR}/parser"

BUILD_DIR="./build"

function make_all
{
    if [ ! -d $BUILD_DIR ]
    then
        mkdir $BUILD_DIR
    fi

    cd ${PARSER_DIR} && make && cd -
    make
}

function clean_all
{
    make clean
    cd ${PARSER_DIR} && make clean && cd -
}


if [ $argc -eq 0 ]
then
    echo "Starting make ..."
    make_all
elif [ $arg == "clean" ]
then
    echo "Starting clean ..."
    clean_all
else
    echo "Invalid command ..."
    echo "Compile: ./Make.sh"
    echo "Clean: ./Make.sh clean"
fi


