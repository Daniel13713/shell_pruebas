#!/bin/bash

simple_shell=$(cat test1 | ./hsh);
sh=$(cat test1 | sh);

if [ "${simple_shell}" == "${sh}" ]
then
    echo Check 0 ok 
else
    echo Check 0 fail
fi

