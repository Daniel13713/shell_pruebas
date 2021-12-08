#!/bin/bash

l=$(echo "ps" | ./hsh);
sh=$(echo "ps" | sh);
if [ "${l}" == "${sh}" ]
then
    echo Check ps ok
else
    echo Check ps fail
fi

l=$(echo "which ls" | ./hsh);
sh=$(echo "which ls" | sh);
if [ "${l}" == "${sh}" ]
then
    echo Check which ls ok
else
    echo Check which ls fail
fi

l=$(echo "du" | ./hsh);
sh=$(echo "du" | sh);
if [ "${l}" == "${sh}" ]
then
    echo Check du ok
else
    echo Check du fail
fi

l=$(echo "pwd" | ./hsh);
sh=$(echo "pwd" | sh);
if [ "${l}" == "${sh}" ]
then
    echo Check pwd ok
else
    echo Check pwd fail
fi

l=$(echo "env" | ./hsh);
sh=$(echo "env" | sh);
if [ "${l}" == "${sh}" ]
then
    echo Check env ok
else
    echo Check env fail
fi

l=$(echo "ls" | ./hsh);
sh=$(echo "ls" | sh);
if [ "${l}" == "${sh}" ]
then
    echo Check ls ok
else
    echo Check ls fail
fi

l=$(echo "/usr/bin/ls" | ./hsh);
sh=$(echo "/usr/bin/ls" | sh);
if [ "${l}" == "${sh}" ]
then
    echo Check /usr/bin/ls ok
else
    echo Check /usr/bin/ls fail
fi

